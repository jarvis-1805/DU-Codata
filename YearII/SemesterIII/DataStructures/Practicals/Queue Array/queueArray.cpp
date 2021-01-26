#include<iostream>
#define size 5

using namespace std;

class queueArray
{
	public:
		int queue[size];
		int front, rear;
		int ch;
		
		queueArray();
		~queueArray();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void enqueue(int);
		int dequeue();
		int frontEle();
		void traverse();
		void clear();
		
		bool isFull();
		bool isEmpty();
};

queueArray::queueArray()
{
	this -> front = -1;
	this -> rear = -1;
}

queueArray::~queueArray()
{
	while(!isEmpty())
		dequeue();
}

void queueArray::options()
{
	cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE"
		<<	"\n2. DEQUEUE"
		<<	"\n3. FRONT"
		<<	"\n4. DISPLAY"
		<<	"\n5. CLEAR"
		<<	"\n0. EXIT";
}

int queueArray::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void queueArray::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			if(isFull())
			{
				cout << "\nQueue is FULL!\n";
				break;
			}
			int n;
			cout << "\nEnter the new data : ";
			cin >> n;
			enqueue(n);
			break;
		case 2:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				this -> front = -1;
				this -> rear = -1;
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

void queueArray::enqueue(int n)
{
	if(isEmpty())
	{
		front = 0;
		rear = 0;
		queue[rear] = n;
	}
	else
		queue[++rear] = n;
	
	cout << "\nEnqueued : " << n << endl;
}

int queueArray::dequeue()
{
	int x;
	if(front == rear)
	{
		x = queue[front];
		front = rear = -1;
	}
	else
		x = queue[front++];
	
	return x;
}

int queueArray::frontEle()
{
	return queue[front];
}

void queueArray::traverse()
{
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "Empty\n";
		return;
	}
	for(int i=front; i<=rear; i++)
	{
		cout << queue[i];
		if(i != rear)
			cout << " : ";
	}
	cout << endl;
}

void queueArray::clear()
{
	if(isEmpty())
	{
		cout << "\nThe queue is empty\n";
		return;
	}
	this -> ~queueArray();
	this -> front = -1;
	this -> rear = -1;
	cout << "\nSuccessfully cleared the Queue!\n";
}

bool queueArray::isFull()
{
	if(rear == size-1)
		return true;
	return false;
}

bool queueArray::isEmpty()
{
	if(front == -1 && rear == -1)
		return true;
	return false;
}

int main()
{
	int choice;
	queueArray ob;
	cout << "\n=========== QUEUE ARRAY ===========\n";
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