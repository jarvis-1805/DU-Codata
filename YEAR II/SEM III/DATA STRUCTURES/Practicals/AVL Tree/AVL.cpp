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
        void deletion();
        void left_rotate(node *, node *);
        void right_rotate(node *, node *);
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
            key = height_counter(root);
            cout << key;
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
                    if(temp -> parent -> right == nullptr)
                        temp1 -> height += 1;
                    if(temp1 -> right == nullptr)
                        temp1 -> balanceFactor = 0 - temp1 -> left -> height;
                    else
                        temp1 -> balanceFactor = temp1 -> right -> height - temp1 -> left -> height;
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
                    if(temp -> parent -> left == nullptr)
                        temp1 -> height += 1;
                    if(temp1 -> left == nullptr)
                        temp1 -> balanceFactor = temp1 -> right -> height - 0;
                    else
                        temp1 -> balanceFactor = temp1 -> right -> height - temp1 -> left -> height;
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
        temp1 = criticalNext;
        //to check for inserted node in right subtree
        if(temp1 -> right != nullptr)
        {
            while(temp1 != nullptr)
                if(temp1 == temp)
                {
                    flag = true;
                    break;
                }
                else
                    temp1 = temp1 -> right;
            if(flag)
            {
                //case 1 right subtree of right child
                cout << criticalNode -> data << "*&" << criticalNext -> data;
                traverse_path(temp);
                left_rotate(criticalNode, criticalNext);
            }
        }
        //to check for inserted node in left subtree
        if(temp1 -> left != nullptr && !flag)
        {
            while(temp1 != nullptr)
                if(temp1 == temp)
                {
                    flag = true;
                    break;
                }
                else
                    temp1 = temp1 -> left;
            if(flag)
            {
                //case 2 left subtree of right child
            }
        }
    }
    //to check for left child of critical node
    else if(criticalNode -> left == criticalNext)
    {
        temp1 = criticalNext;
        //to check for inserted node in left subtree
        if(temp1 -> left != nullptr)
        {
            while(temp1 != nullptr)
                if(temp1 == temp)
                {
                    flag = true;
                    break;
                }
                else
                    temp1 = temp1 -> left;
            if(flag)
            {
                //case 3 left subtree of left child
                cout << criticalNode -> data << "*&" << criticalNext -> data;
                traverse_path(temp);
                right_rotate(criticalNode, criticalNext);
            }
        }
        //to check for inserted node in right subtree
        if(temp1 -> right != nullptr && !flag)
        {
            while(temp1 != nullptr)
                if(temp1 == temp)
                {
                    flag = true;
                    break;
                }
                else
                    temp1 = temp1 -> right;
            if(flag)
            {
                //case 4 right subtree of left child
            }
        }
    }
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
        P -> parent -> right = P -> right;
    }
    P -> right = Q -> left;
    Q -> left = P;

    //updating height and balance factor
    int height;
    node *temp1;
    while(!q1.isEmpty())
    {
        temp1 = q1.frontEle();
        height = height_counter(temp1);
        temp1 -> height = height;

        if(temp1 -> left == nullptr && temp1 -> right == nullptr)
            temp1 -> balanceFactor = 0;
        else if(temp1 -> left == nullptr)
            temp1 -> balanceFactor = temp1 -> right -> height - 0;
        else
            temp1 -> balanceFactor = temp1 -> right -> height - temp1 -> left -> height;
        
        q1.dequeue();
    }
    Q -> balanceFactor = temp1 -> right -> height - temp1 -> left -> height;
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
        P -> parent -> left = P -> left;
    }
    P -> left = Q -> right;
    Q -> right = P;

    //updating height and balance factor
    int height;
    node *temp1;
    while(!q1.isEmpty())
    {
        temp1 = q1.frontEle();
        height = height_counter(temp1);
        temp1 -> height = height;

        if(temp1 -> left == nullptr && temp1 -> right == nullptr)
            temp1 -> balanceFactor = 0;
        else if(temp1 -> right == nullptr)
            temp1 -> balanceFactor = 0 - temp1 -> left -> height;
        else
            temp1 -> balanceFactor = temp1 -> right -> height - temp1 -> left -> height;
        
        q1.dequeue();
    }
    Q -> balanceFactor = temp1 -> right -> height - temp1 -> left -> height;
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