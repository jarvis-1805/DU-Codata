#include<iostream>

using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root, *newNode;
struct node *insert(node *, int);

class binarySearchTree
{
    public:
	    int ch;

		binarySearchTree();

        void options();
		int choice();
		void choiceCalling(int);

        
};

binarySearchTree::binarySearchTree()
{
	root = NULL;
}

void binarySearchTree::options()
{
    cout << "\n1. INSERT"
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
    switch(ch)
	{
		case 1:
			int k;
			cout << "\nEnter the data: ";
		    cin >> k;
			root = insert(root, k);
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

struct node *insert(node *root, int k)
{
	if(root == NULL)
	{
		newNode = (struct node *)malloc(sizeof(newNode));
		newNode -> left = newNode -> right = NULL;
		newNode -> data = k;
		return newNode;
	}
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

int main()
{
    int choice;
	cout << "\n=========== BINARY SEARCH TREE ===========\n";
	binarySearchTree ob;
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		ob.choiceCalling(choice);
	}while(1);
	
	return 0;
}