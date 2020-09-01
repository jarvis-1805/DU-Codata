#include<iostream>

using namespace std;

class queueCircularLinkedList
{
	public:
		struct node
		{
			int data;
			struct node *next;
		};
		struct node *front, *rear, *newNode, *temp;
		int ch;
		
		queueCircularLinkedList();
		~queueCircularLinkedList();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void enqueue(int);
		int dequeue();
		int frontEle();
		void traverse();
		void clear();
		bool isEmpty();
};

queueCircularLinkedList::queueCircularLinkedList()
{
	this -> front = NULL;
	this -> rear = NULL;
}

queueCircularLinkedList::~queueCircularLinkedList()
{
	while(!isEmpty())
		dequeue();
}

void queueCircularLinkedList::options()
{
	cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE"
		<<	"\n2. DEQUEUE"
		<<	"\n3. FRONT"
		<<	"\n4. DISPLAY"
		<<	"\n5. CLEAR"
		<<	"\n0. EXIT";
}

int queueCircularLinkedList::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void queueCircularLinkedList::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			int n;
			cout << "\nEnter the new data : ";
			cin >> n;
			enqueue(n);
			break;
		case 2:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				this -> front = NULL;
				this -> rear = NULL;
				break;
			}
			int x;
			x = dequeue();
			cout << "\nDequeued : " << x << endl;
			break;
		case 3:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				break;
			}
			int y;
			y = frontEle();
			cout << "\nFront : " << y << endl;
			break;
		case 4:
			traverse();
			break;
		case 5:
			clear();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void queueCircularLinkedList::enqueue(int n)
{
	newNode = new struct node;
	newNode -> data = n;
	newNode -> next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = newNode;
		rear -> next = front;
	}
	else
	{
		rear -> next = newNode;
		rear = newNode;
		rear -> next = front;
	}
	cout << "\nEnqueued : " << n << endl;
}

int queueCircularLinkedList::dequeue()
{
	int x;
	temp = front;	
	if(front == rear)
	{
		x = front -> data;
		front = rear = NULL;
	}
	else
	{
		x = temp -> data;
		front = temp -> next;
		rear -> next = front;
	}
	delete(temp);
	return x;
}

int queueCircularLinkedList::frontEle()
{
	return front -> data;
}

void queueCircularLinkedList::traverse()
{
	temp = front;
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "Empty\n";
		return;
	}
	do
	{
		cout << temp -> data;
		temp = temp -> next;
		if(temp != front)
			cout << " : ";
	}while(temp != front);
	cout << endl;
}

void queueCircularLinkedList::clear()
{
	if(isEmpty())
	{
		cout << "\nThe queue is empty\n";
		return;
	}
	this -> ~queueCircularLinkedList();
	this -> front = NULL;
	this -> rear = NULL;
	cout << "\nSuccessfully cleared the Queue!\n";
}

bool queueCircularLinkedList::isEmpty()
{
	if(front == NULL)
		return true;
	return false;
}

int main()
{
	int choice;
	queueCircularLinkedList ob;
	cout << "\n=========== QUEUE CIRCULAR LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	cout << "\n########### MEMORY IS FREED ###########\n";
	return 0;
}