#include<iostream>

using namespace std;

class singlyLinkedList
{
	public:
		struct node
		{
			bool flg;
			int data;
			int exp;
			struct node *next;
		};
		struct node *head=NULL, *newNode, *temp;
		int ch;
	//	bool emp;
		
		~singlyLinkedList();
		
		void create();
		void traverse();
		void operator +(singlyLinkedList);
		
		//int countList();
		//bool emptyListChecker();
};

singlyLinkedList::~singlyLinkedList()
{
	struct node *temp1;
	temp = head;
	while(temp != NULL)
	{
		temp1 = temp -> next;
		delete(temp);
		temp = temp1;
	}
	cout << "\n########### MEMORY IS FREED ###########\n";
}

void singlyLinkedList::create()
{
	cout << "\n------------ CREATING NEW POLYNOMIAL ------------\n";
	head = NULL;
	char ch='y';
	while(ch == 'y')
	{
		newNode = (struct node *)new struct node;
		newNode -> flg = false;
		cout << "Enter the exponent of x : ";
		cin >> newNode -> exp;
		cout << "Enter the coefficient of x^" << newNode -> exp << " : ";
		cin >> newNode -> data;
		if(head == NULL || head -> exp <= newNode -> exp)
		{
			newNode -> next = head;
			head = newNode;
		}
		else
		{
			temp = head;
			while(temp -> next != NULL && temp -> next -> exp > newNode -> exp)
			{
				temp = temp -> next;
			}
			newNode -> next = temp -> next;
			temp -> next = newNode;
		}
		cout << "\nDo you want to enter more terms? y/n: ";
		cin >> ch;
	}
	traverse();
}

void singlyLinkedList::traverse()
{
	//emp = emptyListChecker();
	//if(emp != true)
	//	return;
	//else
	//{
		temp = head;
		cout << endl << "List: ";
		while(temp != NULL)
		{
			cout << temp -> data << "x^" << temp -> exp;
			temp = temp -> next;
			if(temp != NULL)
				cout << " -> ";
		}
		cout << endl;
	//}
}

void singlyLinkedList::operator + (singlyLinkedList ob2)
{
	cout << "\n------------ CONCATINATING ANOTHER LIST ------------\n";
	//emp = emptyListChecker();
	//if(emp != true)
		//return;
	//else
	//{
		
	struct node *temp1, *temp2, *head2=NULL;
	temp = this -> head;
	while(temp != NULL)
	{
		temp1 = ob2.head;
		newNode = (struct node *)new struct node;
		
		while(temp1 != NULL)
		{
			if(temp -> exp == temp1 -> exp)
			{
				newNode -> data = temp -> data + temp1 -> data;
				newNode -> exp = temp -> exp;
				if(head2 == NULL)
				{
					head2 = temp2 = newNode;
				}
				else
				{
					temp2 -> next = newNode;
					temp2 = newNode;
				}
				break;
			}
			/*else if(temp -> exp > temp1 -> exp)
			{
				newNode -> data = temp -> data;
				newNode -> exp = temp -> exp;
			}
			else if(temp -> exp < temp1 -> exp)
			{
			}*/
				temp1 = temp1 -> next;
		}
		temp = temp -> next;
	}
	head = head2;
	traverse();
	//}
}
/*
template <typename T>
int singlyLinkedList<T>::countList()
{
	int count=0;
	temp = head;
	while(temp != NULL)
	{
		temp = temp -> next;
		count ++;
	}
	return count;
}

template <typename T>
bool singlyLinkedList<T>::emptyListChecker()
{
	if(head == NULL)
	{
		cout << "\n########### The list is empty ###########\n";
		return false;
	}
	return true;
}
*/
int main()
{
	int choice, ch;
	singlyLinkedList ob1, ob2;
	cout << "\n=========== SINGLY LINKED LIST ===========\n";
	
	ob1.create();
	ob2.create();
	ob1 + ob2;
	
	cout << "\n########### EXITING... ###########\n";
	
	return 0;
}