#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class orderedLinkedList
{
	public:
		struct node
		{
			int data;
			//int exp;
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
		void merge();
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
			merge();
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
		//cout << "Enter the exponent of x : ";
		//cin >> newNode -> exp;
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

void orderedLinkedList::merge()
{
	cout << "\n------------ MERGING NEW LIST ------------\n";
}
/*
void orderedLinkedList::operator + (orderedLinkedList ob2)
{
	cout << "\n------------ RESULT ------------\n";
	
	orderedLinkedList ob3;
	struct node *temp1, *temp2, *temp3=NULL;
	temp1 = this -> head;
	temp2 = ob2.head;
	ob3.head = NULL;
	do
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode -> next = NULL;
		if(ob3.head == NULL)
		{
			temp3 = ob3.temp = newNode;
			ob3.head = temp3;
		}
		else
		{
			temp3 -> next = newNode;
			temp3 = newNode;
		}
		if(temp1 -> exp > temp2 -> exp)
		{
			temp3 -> data = temp1 -> data;
			temp3 -> exp = temp1 -> exp;
			temp1 = temp1 -> next;
		}
		else if(temp1 -> exp < temp2 -> exp)
		{
			temp3 -> data = temp2 -> data;
			temp3 -> exp = temp2 -> exp;
			temp2 = temp2 -> next;
		}
		else
		{
			temp3 -> data = temp1 -> data + temp2 -> data;
			temp3 -> exp = temp1 -> exp;
			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		}
		
	}while(temp1 && temp2);
	
	while(temp1 || temp2)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode -> next = NULL;
		temp3 -> next = newNode;
		temp3 = newNode;
		if(temp1)
		{
			temp3 -> exp = temp1 -> exp;
			temp3 -> data = temp1 -> data;
			temp1 = temp1 -> next;
		}
		if(temp2)
		{
			temp3 -> exp = temp2 -> exp;
			temp3 -> data = temp2 -> data;
			temp2 = temp2 -> next;
		}
	}
	//this -> traverse();
	//ob2.traverse();
	
	ob3.traverse();
}
*/
int main()
{
	int choice, ch;
	orderedLinkedList ob1, ob2;
	cout << "\n=========== ORDERED LINKED LIST ===========\n";
	
	ob1.create();
	//ob1.traverse();
	do
	{
		ob1.options();
		choice = ob1.choice();
		if(choice == 0)
			break;
		//if(choice == 1)
			//ob.~singlyLinkedList();
		//if(choice == 11)
		//{
			//ob1.create();
			//ob + ob1;
		//}
		ob1.choiceCalling(choice);
	}while(1);
	//ob2.create();
	//ob1 + ob2;
	
	cout << "\n########### EXITING... ###########\n";
	cout << "\n########### MEMORY IS FREED ###########\n";
	return 0;
}