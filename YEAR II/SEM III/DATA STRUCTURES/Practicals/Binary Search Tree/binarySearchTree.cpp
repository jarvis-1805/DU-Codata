#include<iostream>
#include "queueLinkedList.hpp"
#include "stackLinkedList.hpp"

using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root, *newNode, *temp;
struct node *insert(node *, int);

class binarySearchTree
{
	queueLinkedList<node *> q;
	stackLinkedList<node *> s;
    public:
	    int ch, ch1;

		binarySearchTree();

        void options();
		int choice();
		void choiceCalling(int);

		void sub_options();
		void sub_choiceCalling(int, int);

        void search(int);
		void rec_pre_order(node *);
		void rec_post_order(node *);
		void rec_in_order(node *);
		void itr_pre_order(node *);
		void itr_post_order(node *);
		void itr_in_order(node *);
		void breadth_first_search();
		void mirror_image();
		void nodes_counter();
		void height_counter();
		bool isEmpty();
};

binarySearchTree::binarySearchTree()
{
	root = nullptr;
}

void binarySearchTree::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. INSERT A NODE"
		<< "\n2. SEARCH A NODE"
		<< "\n3. PREORDER TRAVERSAL"
		<< "\n4. POST ORDER TRAVERSAL"
		<< "\n5. INORDER TRAVERSAL"
		<< "\n6. BREADTH FIRST SEARCH"
		<< "\n7. MIRROR IMAGE"
		<< "\n8. COUNT NODES"
		<< "\n9. COUNT HEIGHT"
		<<	"\n0. EXIT";
}

int binarySearchTree::choice()
{
    cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void binarySearchTree::choiceCalling(int ch)
{
	int k;
    switch(ch)
	{
		case 1:
			cout << "\nEnter the data: ";
		    cin >> k;
			root = insert(root, k);
			break;
		case 2:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nEnter the node to be searched: ";
				cin >> k;
				search(k);
			}
			break;
		case 3:
		case 4:
		case 5:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				sub_options();
				ch1 = choice();
				sub_choiceCalling(ch1, ch);
			}
			break;
		case 6:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nBreadth First Search Traversal(BFS): ";
				breadth_first_search();
				cout << endl;
			}
			break;
		case 7:
			if(isEmpty())
				cout << "\nTree is empty!\n";
			else
			{
				cout << "\nMirror Image: ";
				mirror_image();
				cout << endl;
			}
			break;
		case 8:
			nodes_counter();
			break;
		case 9:
			height_counter();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void binarySearchTree::sub_options()
{
	cout << "\n------- SUB MENU -------";
    cout << "\n1. RECURSIVE METHOD"
		<< "\n2. ITERATIVE METHOD";
}

void binarySearchTree::sub_choiceCalling(int ch1, int ch)
{
	temp = root;
	if(ch1 == 1 && ch == 3)
	{
		cout << "\nPre Order Recursive: ";
		rec_pre_order(temp);
	}
	else if(ch1 == 1 && ch == 4)
	{
		cout << "\nPost Order Recursive: ";
		rec_post_order(temp);
	}
	else if(ch1 == 1 && ch == 5)
	{
		cout << "\nIn Order Recursive: ";
		rec_in_order(temp);
	}
	else if(ch1 == 2 && ch == 3)
	{
		cout << "\nPre Order Iterative: ";
		itr_pre_order(temp);
	}
	else if(ch1 == 2 && ch == 4)
	{
		cout << "\nPost Order Iterative: ";
		itr_post_order(temp);
	}
	else if(ch1 == 2 && ch == 5)
	{
		cout << "\nIn Order Iterative: ";
		itr_in_order(temp);
	}
	else
	{
		cout << "\n########### WRONG CHOICE... ###########\n";
	}
	cout << endl;
}

struct node *insert(node *root, int k)
{
	if(root == nullptr)
	{
		newNode = (struct node *)malloc(sizeof(newNode));
		newNode -> left = newNode -> right = nullptr;
		newNode -> data = k;
		return newNode;
	}
	if(k == root -> data)
		cout << "\n" << k << " is already present in tree!\n";
	if(k < root -> data)
	{
		root -> left = insert(root -> left, k);
	}
	if(k > root -> data)
	{
		root -> right = insert(root -> right, k);
	}
	return root;
}

void binarySearchTree::search(int k)
{
	temp = root;
	while(temp != nullptr)
	{
		if(k == temp -> data)
		{
			cout << "\nNode is present in Tree.\n";
			return;
		}
		else if(k < temp -> data)
		{
			temp = temp -> left;
		}
		else if(k > temp -> data)
		{
			temp = temp -> right;
		}
	}
	cout << "\nNode is absent in Tree.\n";
}

void binarySearchTree::rec_pre_order(node *temp)
{
	if(temp != nullptr)
	{
		cout << temp -> data << " ";
		rec_pre_order(temp -> left);
		rec_pre_order(temp -> right);
	}
}

void binarySearchTree::rec_post_order(node *temp)
{
	if(temp != nullptr)
	{
		rec_post_order(temp -> left);
		rec_post_order(temp -> right);
		cout << temp -> data << " ";
	}
}

void binarySearchTree::rec_in_order(node *temp)
{
	if(temp != nullptr)
	{
		rec_in_order(temp -> left);
		cout << temp -> data << " ";
		rec_in_order(temp -> right);
	}
}

void binarySearchTree::itr_pre_order(node *temp)
{
	while(!s.isEmpty() || temp != nullptr)
	{
		while(temp != nullptr)
		{
			cout << temp -> data << " ";
			if(temp -> right)
				s.push(temp -> right);
			temp = temp -> left;
		}
		if(!s.isEmpty())
		{
			temp = s.peek();
			s.pop();
		}
	}
}

void binarySearchTree::itr_post_order(node *temp)
{
	do
	{
		while(temp)
		{
			if(temp -> right)
				s.push(temp -> right);
			s.push(temp);
			temp = temp -> left;
		}
		temp = s.pop();
		if(!s.isEmpty() && temp -> right == s.peek())
		{
			s.pop();
			s.push(temp);
			temp = temp -> right;
		}
		else
		{
			cout << temp -> data << " ";
			temp = nullptr;
		}
	}while(!s.isEmpty());
}

void binarySearchTree::itr_in_order(node *temp)
{
	while(temp != nullptr || !s.isEmpty())
	{
		while(temp != nullptr)
		{
			s.push(temp);
			temp = temp -> left;
		}
		temp = s.peek();
		s.pop();
		cout << temp -> data << " ";
		temp = temp -> right;
	}
}

void binarySearchTree::breadth_first_search()
{
	q.enqueue(root);
	while(!q.isEmpty())
	{
		temp = q.frontEle();
		cout << temp -> data << " ";
		if(temp -> left != nullptr)
			q.enqueue(temp -> left);
		if(temp -> right != nullptr)
			q.enqueue(temp -> right);
		q.dequeue();
	}
}

void binarySearchTree::mirror_image()
{
	q.enqueue(root);
	while(!q.isEmpty())
	{
		temp = q.frontEle();
		cout << temp -> data << " ";
		if(temp -> right != nullptr)
			q.enqueue(temp -> right);
		if(temp -> left)
			q.enqueue(temp -> left);
		q.dequeue();
	}
}

void binarySearchTree::nodes_counter()
{
	int non_leaf=0, leaf=0;
	q.enqueue(root);
	while(!q.isEmpty())
	{
		temp = q.frontEle();
		if(temp -> left != nullptr || temp -> right != nullptr)
			non_leaf++;
		if(temp -> left == nullptr && temp -> right == nullptr)
			leaf++;
		if(temp -> left != nullptr)
			q.enqueue(temp -> left);
		if(temp -> right != nullptr)
			q.enqueue(temp -> right);
		q.dequeue();
	}
	cout << "\nNon-leaves: " << non_leaf
			 << "\nLeaves: " << leaf
			 << "\nNodes: " << non_leaf+leaf << endl;
}

void binarySearchTree::height_counter()
{
	int size, height=0;
	if(isEmpty())
		true;
	else
	{
		q.enqueue(root);
		while(true)
		{
			size = q.size();
			if(size == 0)
				break;
			while(size > 0)
			{
				temp = q.frontEle();
				if(temp -> left != nullptr)
					q.enqueue(temp -> left);
				if(temp -> right != nullptr)
					q.enqueue(temp -> right);
				q.dequeue();
				size--;
			}
			height++;
		}
	}
	cout << "\nHeight of tree is: " << height << endl;
}

bool binarySearchTree::isEmpty()
{
	if(root == nullptr)
		return true;
	return false;
}

int main()
{
    int choice;
	cout << "\n=========== BINARY SEARCH TREE ===========\n";
	binarySearchTree ob;
	do
	{
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		ob.choiceCalling(choice);
	}while(1);
	
	return 0;
}