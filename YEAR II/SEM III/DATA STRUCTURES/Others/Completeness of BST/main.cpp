#include <iostream>
#include <math.h>

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
	    int ch, ch1;

		binarySearchTree();

		void rec_in_order(node *);
        int height(node *);
};

binarySearchTree::binarySearchTree()
{
	root = nullptr;
}

struct node *insert(node *temp, int key)
{
	if(temp == nullptr)
	{
		newNode = (struct node *)malloc(sizeof(newNode));
		newNode -> left = newNode -> right = nullptr;
		newNode -> data = key;
		return newNode;
	}
	if(key == temp -> data)
		cout << "\n" << key << " is already present in tree!\n";
	if(key < temp -> data)
	{
		temp -> left = insert(temp -> left, key);
	}
	if(key > temp -> data)
	{
		temp -> right = insert(temp -> right, key);
	}
	return temp;
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

int binarySearchTree::height(node *root)
{
    if(root == nullptr)
        return 0;
    int lHeight = height(root -> left);
    int rHeight = height(root -> right);
	if(lHeight > rHeight)
		return (lHeight+1);
	else
		return (rHeight+1);
}

int main()
{
	cout << "\n======== COMPLETENESS OF BST ========\n";
    int key, totalNodes=0, totalHeight;
    char c = 'y';
    binarySearchTree ob;

	//Input the tree
    do
    {
        cout << "\nEnter the data: ";
		cin >> key;
        root = insert(root, key);
		totalNodes++;				//calculating total number of nodes entered in BST
        cout << "\nWant to enter more nodes? (y/n): ";
        cin >> c;
    }while(c == 'y' || c == 'Y');

	//Inoder Traversal
	cout << endl << "Inorder Traversal: ";
	ob.rec_in_order(root);
	cout << endl;

	//Calculate the height of BST
	totalHeight = ob.height(root);
	cout << endl << "Total height " << totalHeight <<
				"\nTotal nodes " << totalNodes << endl;

	/**
	 * @brief We can calculate the total number of nodes in BST using the formula
	 * 2^(totalHeight) - 1
	 * if it is equal to the total number of nodes (totalNodes) that we have
	 * calculated at the time of insertion, a BST tree is considered COMPLETE
	 * else NOT COMPLETE!
	 * 
	 */
	if((pow(2, totalHeight) - 1) == totalNodes)
		cout << "\nTree is COMPLETE!\n";
	else
		cout << "\nTree is NOT COMPLETE!\n";
}