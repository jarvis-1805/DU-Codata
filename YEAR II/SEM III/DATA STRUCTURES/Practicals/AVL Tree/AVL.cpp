#include<iostream>
#include "queueLinkedList.hpp"

using namespace std;

struct node
{
    node *left;
    node *parent;
    int height;
    int balanceFactor;
    int data;
    node *right;
};
struct node *root, *newNode, *criticalNode, *criticalNext, *temp;

class AVL
{
	queueLinkedList<node *> q, q1;

    public:
        int ch;

        AVL();

        void options();
		int choice();
		void choiceCalling(int);

        void insertion(node *, int);
        void deletion(node *, int);
        void left_rotate(node *, node *);
        void right_rotate(node *, node *);
		void delete_no_child(node *, node *);
		void delete_one_child(node *, node *);
        int height_counter(node *);
        void traverse_path(node *);
        void display();
        bool isEmpty();
};

AVL::AVL()
{
    temp = criticalNode = root = nullptr;
}

void AVL::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. INSERT A NODE"
		<< "\n2. DELETE A NODE"
		<< "\n3. DISPLAY"
		<< "\n0. EXIT";
}

int AVL::choice()
{
    cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void AVL::choiceCalling(int ch)
{
	int key;
    switch(ch)
	{
		case 1:
            cout << "\nEnter the Data: ";
            cin >> key;
            temp = root;
            insertion(temp, key);
			break;
		case 2:
            cout << "\nEnter the Data: ";
            cin >> key;
            temp = root;
            deletion(temp, key);
			break;
		case 3:
            display();
            break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void AVL::insertion(node *temp, int key)
{
    do     //remove for recursive
    {
        if(root == nullptr)
        {
            newNode = (struct node *)new struct node;
            newNode -> left = newNode -> parent = newNode -> right = nullptr;
            newNode -> height = 1;
            newNode -> balanceFactor = 0;
            newNode -> data = key;
            root = newNode;
            criticalNode = criticalNext = newNode;
        }
        else if(key == temp -> data)
        {
            cout << "\n" << key << " is already present in tree!\n";
            break;
        }
        else if(key < temp -> data)
        {
            if(temp -> left == nullptr)
            {
                newNode = (struct node *)new struct node;
                newNode -> left = newNode -> right = nullptr;
                newNode -> parent = temp;
                newNode -> height = 1;
                newNode -> balanceFactor = 0;
                newNode -> data = key;
                temp -> left = newNode;
                temp = newNode;
                node* temp1 = temp -> parent;
                while(temp1 != nullptr)
                {
                    temp1 -> height = height_counter(temp1);
                    temp1 -> balanceFactor = height_counter(temp1 -> right) - height_counter(temp1 -> left);
                    temp1 = temp1 -> parent;
                }
                temp = nullptr;     //remove for recursive
            }
            else
                temp = temp -> left;     //remove for recursive
                //insertion(temp -> left, key);
        }
        else if(key > temp -> data)
        {
            if(temp -> right == nullptr)
            {
                newNode = (struct node *)new struct node;
                newNode -> left = newNode -> right = nullptr;
                newNode -> parent = temp;
                newNode -> height = 1;
                newNode -> balanceFactor = 0;
                newNode -> data = key;
                temp -> right = newNode;
                temp = newNode;
                node* temp1 = temp -> parent;
                while(temp1 != nullptr)
                {
                    temp1 -> height = height_counter(temp1);
                    temp1 -> balanceFactor = height_counter(temp1 -> right) - height_counter(temp1 -> left);
                    temp1 = temp1 -> parent;
                }
                temp = nullptr;     //remove for recursive
            }
            else
                temp = temp -> right;     //remove for recursive
                //insertion(temp -> right, key);
        }
    }while(temp != nullptr);     //remove for recursive

    //to find critical node
    temp = newNode;
    node *temp1 = temp;
    bool flag = false;
    while(temp1 -> parent != nullptr)
    {
        if(temp1 -> parent -> balanceFactor != -1 &&
            temp1 -> parent -> balanceFactor != 0 &&
            temp1 -> parent -> balanceFactor != 1)
        {
            criticalNode = temp1 -> parent;
            criticalNext = temp1;
            break;
        }
        temp1 = temp1 -> parent;
    }

    //to check for right child of critical node
    if(criticalNode -> right == criticalNext)
    {
        //to check for inserted node in right subtree
        if(key > criticalNext -> data)
        {
            //case 1 right subtree of right child
            traverse_path(temp);
            left_rotate(criticalNode, criticalNext);
        }
        //to check for inserted node in left subtree
        else if(key < criticalNext -> data)
        {
            //case 2 left subtree of right child
            node *R;
            R = criticalNext -> left;
            traverse_path(temp);
            right_rotate(criticalNext, R);
            traverse_path(temp);
            left_rotate(criticalNode, R);
        }
    }
    //to check for left child of critical node
    else if(criticalNode -> left == criticalNext)
    {
        //to check for inserted node in left subtree
        if(key < criticalNext -> data)
        {
            //case 3 left subtree of left child
            traverse_path(temp);
            right_rotate(criticalNode, criticalNext);
        }
        //to check for inserted node in right subtree
        else if(key > criticalNext -> data)
        {
            //case 4 right subtree of left child
            node *R;
            R = criticalNext -> right;
            traverse_path(temp);
            left_rotate(criticalNext, R);
            traverse_path(temp);
            right_rotate(criticalNode, R);
        }
    }
}

void AVL::deletion(node *temp, int key)
{
    node *parent = temp;
    bool flag = false;
    while(temp != nullptr)
    {
        if(key == temp -> data)
        {
            flag = true;
            break;
        }
        parent = temp;
        if(key < temp -> data)
            temp = temp -> left;
        else if(key > temp -> data)
            temp = temp -> right;
    }

    if(flag == false)
    {
        cout << "\nNode is absent in AVL Tree!";
        return;
    }

    //1> applying deletion by copying and finding the actual node deleted
    
    //Case 1: If the node has no child, i.e., leaf node.
    if((temp -> left == nullptr) && (temp -> right == nullptr))
    {
        cout << parent -> data << "***" << temp -> data << endl;
        delete_no_child(parent, temp);
        cout << "\nSuccessfully deleted the leaf node " << key;
    }

    //Case 2: If the node has one child.
    else if((temp -> left != nullptr && temp -> right == nullptr) || (temp -> left == nullptr && temp -> right != nullptr))
    {
        cout << parent -> data << "***" << temp -> data << endl;
        delete_one_child(parent, temp);
        cout << "\nSuccessfully deleted the node " << key;
    }

    //Case 3: If the node has both left and right child.
    else if((temp -> left != nullptr) && (temp -> right != nullptr))
    {
        node *temp1, *parent1;
        temp1 = temp -> left;
        parent1 = temp1;
        while(temp1 -> right != nullptr)
        {
            parent1 = temp1;
            temp1 = temp1 -> right;
        }
        
        temp -> data = temp1 -> data;
        if(temp1 == parent1)
        {
            if(temp1 -> left != nullptr)
                temp -> left = temp1 -> left;
            else if(temp1 -> left == nullptr)
                temp -> left = nullptr;
            parent = temp1 -> parent;
            delete(temp1);
        }
        else if(temp1 -> left != nullptr && temp1 -> right == nullptr)
        {
            parent = temp1 -> parent;
            delete_one_child(parent1, temp1);
        }
        else if(temp1 -> right == nullptr && temp1 -> left == nullptr)
        {
            parent = temp1 -> parent;
            delete_no_child(parent1, temp1);
        }
    }

    //2 & 3> updating balance factor and height from parent of deleted node to upto root and finding the critical node P
    node *temp1 = parent;
    while(temp1 != nullptr)
    {
        temp1 -> height = height_counter(temp1);
        temp1 -> balanceFactor = height_counter(temp1 -> right) - height_counter(temp1 -> left);
        
        //to find the critical node P
        if(temp1 -> balanceFactor != -1 &&
            temp1 -> balanceFactor != 0 &&
            temp1 -> balanceFactor != 1 &&
            flag == true)
        {
            criticalNode = temp1;
            flag = false;
            //criticalNext = temp1;
        }
        temp1 = temp1 -> parent;
    }
    cout << endl << criticalNode -> data << "***" << endl;
}

void AVL::left_rotate(node *P, node *Q)
{
    Q -> parent = P -> parent;
    if(root == P)
    {
        root = Q;
    }
    if(P -> parent != nullptr)
    {
        if(P -> parent -> right == P)
            P -> parent -> right = P -> right;
        else if(P -> parent -> left == P)
            P -> parent -> left = P -> right;
    }
    P -> parent = Q;
    P -> right = Q -> left;
    if(P -> right != nullptr)
        P -> right -> parent = P;
    Q -> left = P;

    //updating height and balance factor
    int height;
    node *temp1;
    while(!q1.isEmpty())
    {
        temp1 = q1.frontEle();
        height = height_counter(temp1);
        temp1 -> height = height;

        temp1 -> balanceFactor = height_counter(temp1 -> right) - height_counter(temp1 -> left);
        
        q1.dequeue();
    }
    P -> balanceFactor = height_counter(P -> right) - height_counter(P -> left);
    Q -> balanceFactor = height_counter(Q -> right) - height_counter(Q -> left);
}

void AVL::right_rotate(node *P, node *Q)
{
    Q -> parent = P -> parent;
    if(root == P)
    {
        root = Q;
    }
    if(P -> parent != nullptr)
    {
        if(P -> parent -> left == P)
            P -> parent -> left = P -> left;
        else if(P -> parent -> right == P)
            P -> parent -> right = P -> left;
    }
    P -> parent = Q;
    P -> left = Q -> right;
    if(P -> left != nullptr)
        P -> left -> parent = P;
    Q -> right = P;

    //updating height and balance factor
    int height;
    node *temp1;
    while(!q1.isEmpty())
    {
        temp1 = q1.frontEle();
        height = height_counter(temp1);
        temp1 -> height = height;

        temp1 -> balanceFactor = height_counter(temp1 -> right) - height_counter(temp1 -> left);
        
        q1.dequeue();
    }
    P -> balanceFactor = height_counter(P -> right) - height_counter(P -> left);
    Q -> balanceFactor = height_counter(Q -> right) - height_counter(Q -> left);
}

void AVL::delete_no_child(node *parent, node *temp)
{
    //If root is to be deleted
	if(parent == temp)
		root = nullptr;
	else if(parent -> left == temp)
		parent -> left = nullptr;
	else if(parent -> right == temp)
		parent -> right = nullptr;
	delete(temp);
}

void AVL::delete_one_child(node *parent, node *temp)
{
    //If root is to be deleted
    if(parent == temp)
    {
        if(temp -> left != nullptr)
            root = temp -> left;
        else if(temp -> right != nullptr)
            root = temp -> right;
    }
    else if(parent -> left == temp)
    {
        if(temp -> left != nullptr)
        {
            temp -> left -> parent = parent;
            parent -> left = temp -> left;
        }
        else if(temp -> right != nullptr)
        {
            temp -> right -> parent = parent;
            parent -> left = temp -> right;
        }
    }
    else if(parent -> right == temp)
    {
        if(temp -> left != nullptr)
        {
            temp -> left -> parent = parent;
            parent -> right = temp -> left;
        }
        else if(temp -> right != nullptr)
        {
            temp -> right -> parent = parent;
            parent -> right = temp -> right;
        }
    }
    delete(temp);
}

int AVL::height_counter(node *temp1)
{
	if(temp1 == nullptr)
        return 0;
    else
    {
        int leftH, rightH;
		
		//find the height of left subtree
		leftH = height_counter(temp1 -> left);
		
		//find the height of right subtree
		rightH = height_counter(temp1 -> right); 
	
		//return the maximum height
		if (leftH > rightH) 
		    return(leftH + 1); 
		
		else 
		    return(rightH + 1); 
    }
}

void AVL::traverse_path(node *temp1)
{
    while(temp1 != nullptr)
    {
        q1.enqueue(temp1);
        temp1 = temp1 -> parent;
    }
}

void AVL::display()
{
    cout << "\nData\tHeight\tBF\n";
    q.enqueue(root);
    while(!q.isEmpty())
    {
        temp = q.frontEle();
        cout << temp -> data << "\t"
            << temp -> height << "\t"
            << temp -> balanceFactor << endl;
        if(temp -> left != nullptr)
            q.enqueue(temp -> left);
        if(temp -> right != nullptr)
            q.enqueue(temp -> right);
        q.dequeue();
    }
}

bool AVL::isEmpty()
{
    return (root == nullptr);
}

int main()
{
    int choice;
    cout << "\n=========== AVL TREE ===========\n";
	AVL ob;
	do
	{
		//cout << "\n=========== BINARY SEARCH TREE ===========\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		//system("clear");
		//cout << "\n=========== BINARY SEARCH TREE ===========\n";
		ob.choiceCalling(choice);
		//cout << "\nPress Enter to continue...";
		//cin.ignore();
		//getchar();
		//system("clear");
	}while(1);
	
	return 0;
}