#include<iostream>

using namespace std;

int c=0, x=0;

class stackLinkedList
{
	public:
		struct node
		{
			int data;
			struct node *next;
		};
		struct node *head=NULL, *newNode, *temp, *top=NULL;
		int ch;
		
		~stackLinkedList();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void push();
		void pop();
		void clear();
		void traverse();
		
		bool isEmpty();
};

stackLinkedList::~stackLinkedList()
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

void stackLinkedList::options()
{
	cout << "\n1. PUSH"
		<<	"\n2. POP"
		<<	"\n3. CLEAR"
		<<	"\n0. EXIT";
}

int stackLinkedList::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void stackLinkedList::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			push();
			break;
		case 2:
			cout << "\n------------ POPING FROM STACK ------------\n";
			if(isEmpty())
			{
				cout << "\n########### The stack is empty ###########\n";
			}
			else
			{
				if((top -> data >= 10) && (top -> data <=99))
					x--;
				c--;
				pop();
				cout << "\nSuccessfully poped the top element\n";
				traverse();
			}
			break;
		case 3:
			clear();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void stackLinkedList::push()
{
	cout << "\n------------ PUSHING IN STACK ------------\n";
	newNode = (struct node *)new struct node;
	cout << "Enter the data : ";
	cin >> newNode -> data;
	newNode -> next = NULL;
	if(isEmpty())
	{
		head = top = temp = newNode;
	}
	else
	{
		top -> next = newNode;
		top = temp = newNode;
	}
	cout << "\nSuccessfully pushed the element in stack\n";
	if((top -> data >= 10) && (top -> data <=99))
		x++;
	c++;
	traverse();
}

void stackLinkedList::pop()
{
	if(isEmpty())
	{
		cout << "\n########### The stack is empty ###########\n";
	}
	else
	{
		if(top == head)
		{
			delete(head);
			top = head = NULL;
		}
		else
		{
			temp = head;
			while(temp -> next -> next != NULL)
			{
				temp = temp -> next;
			}
			delete(top);
			temp -> next = NULL;
			top = temp;
		}
	}
}

void stackLinkedList::clear()
{
	cout << "\n------------ CLEARING THE STACK ------------\n";
	if(isEmpty())
	{
		cout << "\n########### The stack is empty ###########\n";
	}
	else
	{
		while(!isEmpty())
			pop();
		cout << "\n########### The stack is cleared ###########\n";
	}
}

void stackLinkedList::traverse()
{
	temp = head;
	cout << endl << "Stack: ";
	if(isEmpty())
	{
		cout << "EMPTY\n";
	}
	else
	{
		while(temp != NULL)
		{
			cout << temp -> data;
			temp = temp -> next;
			if(temp != NULL)
				cout << " -> ";
		}
		cout << endl;
		cout << "        ";
		for(int i=1; i<=((4*(c-1))+(c-2)); i++)
			cout << " ";
		if(x != 0)
			for(int j=1; j<=x; j++)
				cout << " ";
		cout << "^top\n";
	}
}

bool stackLinkedList::isEmpty()
{
	if(top == NULL)
	{
		return true;
	}
	return false;
}

int main()
{
	int choice, ch;
	stackLinkedList ob;
	cout << "\n=========== STACK IN LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	
	return 0;
}