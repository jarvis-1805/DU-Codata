#include<iostream>

using namespace std;

class doublyEndedQueueLinkedList
{
	public:
		struct node
		{
			int data;
			struct node *next;
		};
		struct node *front, *rear, *newNode, *temp;
		int ch;
		
		doublyEndedQueueLinkedList();
		~doublyEndedQueueLinkedList();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void enqueue_rear(int);
		int dequeue_front();
        void enqueue_front(int);
		int dequeue_rear();
		int frontEle();
		int rearEle();
		void traverse();
		void clear();
		bool isEmpty();
};

doublyEndedQueueLinkedList::doublyEndedQueueLinkedList()
{
	this -> front = NULL;
	this -> rear = NULL;
}

doublyEndedQueueLinkedList::~doublyEndedQueueLinkedList()
{
	while(!isEmpty())
		dequeue_front();
}

void doublyEndedQueueLinkedList::options()
{
	cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE REAR"
		<<	"\n2. DEQUEUE FRONT"
		<<	"\n3. ENQUEUE FRONT"
		<<	"\n4. DEQUEUE REAR"
		<<	"\n5. FRONT"
		<<	"\n6. REAR"
		<<	"\n7. DISPLAY"
		<<	"\n8. CLEAR"
		<<	"\n0. EXIT";
}

int doublyEndedQueueLinkedList::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void doublyEndedQueueLinkedList::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			int n;
			cout << "\nEnter the new data : ";
			cin >> n;
			enqueue_rear(n);
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
			x = dequeue_front();
			cout << "\nDequeued : " << x << endl;
			break;
		case 3:
			int n1;
			cout << "\nEnter the new data : ";
			cin >> n1;
			enqueue_front(n1);
			break;
		case 4:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				this -> front = NULL;
				this -> rear = NULL;
				break;
			}
			int x1;
			x1 = dequeue_rear();
			cout << "\nDequeued : " << x1 << endl;
			break;
		case 5:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				break;
			}
			int y;
			y = frontEle();
			cout << "\nFront : " << y << endl;
			break;
		case 6:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				break;
			}
			int y1;
			y1 = rearEle();
			cout << "\nFront : " << y1 << endl;
			break;
		case 7:
			traverse();
			break;
		case 8:
			clear();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void doublyEndedQueueLinkedList::enqueue_rear(int n)
{
	newNode = new struct node;
	newNode -> data = n;
	newNode -> next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = newNode;
	}
	else
	{
		rear -> next = newNode;
		rear = newNode;
	}
	cout << "\nEnqueued : " << n << endl;
}

int doublyEndedQueueLinkedList::dequeue_front()
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
	}
	delete(temp);
	return x;
}

void doublyEndedQueueLinkedList::enqueue_front(int n)
{
	newNode = new struct node;
	newNode -> data = n;
	newNode -> next = front;
	if(front == NULL && rear == NULL)
	{
		front = rear = newNode;
	}
	else
	{
		front = newNode;
	}
	cout << "\nEnqueued : " << n << endl;
}

int doublyEndedQueueLinkedList::dequeue_rear()
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
		while(temp -> next != rear)
			temp = temp -> next;
		x = rear -> data;
		rear = temp;
		temp = temp -> next;
		rear -> next = NULL;
	}
	delete(temp);
	return x;
}

int doublyEndedQueueLinkedList::frontEle()
{
	return front -> data;
}

int doublyEndedQueueLinkedList::rearEle()
{
	return rear -> data;
}

void doublyEndedQueueLinkedList::traverse()
{
	temp = front;
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "Empty\n";
		return;
	}
	while(temp != NULL)
	{
		cout << temp -> data;
		temp = temp -> next;
		if(temp != NULL)
			cout << " : ";
	}
	cout << endl;
}

void doublyEndedQueueLinkedList::clear()
{
	if(isEmpty())
	{
		cout << "\nThe queue is empty\n";
		return;
	}
	this -> ~doublyEndedQueueLinkedList();
	this -> front = NULL;
	this -> rear = NULL;
	cout << "\nSuccessfully cleared the Queue!\n";
}

bool doublyEndedQueueLinkedList::isEmpty()
{
	temp = front;
	if(temp == NULL)
		return true;
	return false;
}

int main()
{
	int choice;
	doublyEndedQueueLinkedList ob;
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