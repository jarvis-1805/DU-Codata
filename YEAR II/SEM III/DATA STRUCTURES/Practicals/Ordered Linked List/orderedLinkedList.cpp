#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class orderedLinkedList
{
	public:
		struct node
		{
			int data;
			struct node *next;
		};
		struct node *head=NULL, *newNode, *temp;
		int ch;
		
		~orderedLinkedList();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void create();
		void traverse();
		void insert();
		void deleting();
		void operator +(orderedLinkedList);
};

orderedLinkedList::~orderedLinkedList()
{
	struct node *temp1;
	temp = head;
	while(temp != NULL)
	{
		temp1 = temp -> next;
		delete(temp);
		temp = temp1;
	}
}

void orderedLinkedList::options()
{
	cout << "\n1. INSERT"
		<<	"\n2. DELETE"
		<<	"\n3. MERGE"
		<<	"\n0. EXIT";
}

int orderedLinkedList::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void orderedLinkedList::choiceCalling(int)
{
	switch(ch)
	{
		case 1:
			insert();
			break;
		case 2:
			deleting();
			break;
		case 3:
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void orderedLinkedList::create()
{
	cout << "\n------------ CREATING NEW LIST ------------\n";
	head = NULL;
	char ch='y';
	while(ch == 'y')
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		if(head == NULL || head -> data >= newNode -> data)
		{
			newNode -> next = head;
			head = newNode;
		}
		else
		{
			temp = head;
			while(temp -> next != NULL && temp -> next -> data < newNode -> data)
			{
				temp = temp -> next;
			}
			newNode -> next = temp -> next;
			temp -> next = newNode;
		}
		cout << "\nDo you want to enter more data? y/n: ";
		cin >> ch;
	}
	traverse();
}

void orderedLinkedList::traverse()
{
		temp = head;
		cout << endl << "LIST: ";
		while(temp != NULL)
		{
			cout << temp -> data;
			temp = temp -> next;
			if(temp != NULL)
				cout << " -> ";
		}
		cout << endl;
}

void orderedLinkedList::insert()
{
	cout << "\n------------ INSERTING NEW DATA ------------\n";
	newNode = (struct node *)malloc(sizeof(struct node));
	cout << "Enter the new node's data : ";
	cin >> newNode -> data;
	if(head -> data >= newNode -> data)
	{
		newNode -> next = head;
		head = newNode;
	}
	else
	{
		temp = head;
		while(temp -> next != NULL && temp -> next -> data < newNode -> data)
		{
			temp = temp -> next;
		}
		newNode -> next = temp -> next;
		temp -> next = newNode;
	}
	traverse();
}

void orderedLinkedList::deleting()
{
	int ele, count=1;
	bool flag=false;
	struct node *temp1;
	cout << "\n------------ DELETING A DATA ------------\n";
	cout << "Enter the data to be deleted : ";
	cin >> ele;
	temp = head;
	temp1 = temp -> next;
	if(temp -> data == ele)
	{
		head = head -> next;
		delete(temp);
		flag = true;
	}
	else
	{
		do
		{
			count++;
			if(temp -> next -> data == ele)
			{
				flag = true;
				break;
			}
			temp = temp -> next;
			temp1 = temp -> next;
		}while(temp -> next != NULL);
	}
	if(flag == true)
	{
		temp -> next = temp1 -> next;
		delete(temp1);
		cout << endl << ele << " deleted at position " << count << " in the list\n";
	}
	else
		cout << endl << ele << " not found in the list\n";
	traverse();
}

void orderedLinkedList::operator + (orderedLinkedList ob1)
{
	cout << "\n------------ MERGING NEW LIST ------------\n";
	ob1.create();
	struct node *temp1 = ob1.head;
	while(temp1 != NULL)
	{
		newNode = temp1;
		temp1 = temp1 -> next;
		if(head -> data >= newNode -> data)
		{
			newNode -> next = head;
			head = newNode;
		}
		else
		{
			temp = head;
			while(temp -> next != NULL && temp -> next -> data < newNode -> data)
			{
				temp = temp -> next;
			}
			newNode -> next = temp -> next;
			temp -> next = newNode;
		}
	}
	cout << "\n------------ RESULT ------------\n";
	traverse();
}

int main()
{
	int choice, ch;
	orderedLinkedList ob, ob1;
	cout << "\n=========== ORDERED LINKED LIST ===========\n";
	
	ob.create();
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		if(choice == 3)
			ob + ob1;
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	cout << "\n########### MEMORY IS FREED ###########\n";
	return 0;
}