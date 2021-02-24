#include "stackLinkedList.hpp"

struct node
{
	struct node *left = nullptr;
	int data;
	struct node *right = nullptr;
};
struct node *root=nullptr;

class binarySearchTree
{
	stackLinkedList<node *> stack;

    public:
		struct node *construct_BST(int *, int, int);

		int *rec_post_order(int *, int);
        int *rec_post_order_helper(node *, int *, int);
		int *itr_post_order(int *, int);
        int *itr_post_order_helper(node *, int *, int);
};

struct node *binarySearchTree::construct_BST(int *array, int start, int end)
{
	if(start > end)
		return nullptr;

	int mid = (start + end) / 2;

	node *temp = (struct node *)new struct node;
	temp -> data = array[mid];

	node *leftSubTree = construct_BST(array, start, mid - 1);
	node *rightSubTree = construct_BST(array, mid + 1, end);

	temp -> left = leftSubTree;
	temp -> right = rightSubTree;

	return temp;
}
/*
int *binarySearchTree::rec_post_order_helper(node *temp, int *array, int i)
{
	if(temp != nullptr)
	{
		array = rec_post_order_helper(temp -> left, array, i);
		array = rec_post_order_helper(temp -> right, array, i);
		array[++i] = temp -> data;
	}

    return array;
}

int *binarySearchTree::rec_post_order(int *array, int size)
{
    root = construct_BST(array, 1, size);
	return rec_post_order_helper(root, array, 1);
}
*/
int *binarySearchTree::itr_post_order(int *array, int size)
{
    root = construct_BST(array, 1, size);
	return itr_post_order_helper(root, array, 1);
}

int *binarySearchTree::itr_post_order_helper(node *temp, int *array, int i)
{
	do
	{
		while(temp)
		{
			if(temp -> right)
				stack.push(temp -> right);
			stack.push(temp);
			temp = temp -> left;
		}
		temp = stack.pop();
		if(!stack.isEmpty() && temp -> right == stack.peek())
		{
			stack.pop();
			stack.push(temp);
			temp = temp -> right;
		}
		else
		{
			array[i++] = temp -> data;
			temp = nullptr;
		}
	}while(!stack.isEmpty());

	return array;
}