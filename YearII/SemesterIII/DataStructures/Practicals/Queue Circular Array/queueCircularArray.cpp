#include<iostream>
#define size 5

using namespace std;

class queueCircularArray
{
	public:
		int queue[size];
		int front, rear;
		int ch;
		
		queueCircularArray();
		~queueCircularArray();
		
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

queueCircularArray::queueCircularArray()
{
	this -> front = -1;
	this -> rear = -1;
}

queueCircularArray::~queueCircularArray()
{
	while(!isEmpty())
		dequeue();
}

void queueCircularArray::options()
{
	cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE"
		<<	"\n2. DEQUEUE"
		<<	"\n3. FRONT"
		<<	"\n4. DISPLAY"
		<<	"\n5. CLEAR"
		<<	"\n0. EXIT";
}

int queueCircularArray::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void queueCircularArray::choiceCalling(int ch)
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

void queueCircularArray::enqueue(int n)
{
	if(isEmpty())
	{
		front = rear = 0;
		queue[rear] = n;
	}
	else
	{
		rear = (rear+1)%size;
		queue[rear] = n;
	}
	cout << "\nEnqueued : " << n << endl;
}

int queueCircularArray::dequeue()
{
	int x;
	if(front == rear)
	{
		x = queue[front];
		front = rear = -1;
	}
	else
	{
		x = queue[front];
		front = (front+1)%size;
	}
	return x;
}

int queueCircularArray::frontEle()
{
	return queue[front];
}

void queueCircularArray::traverse()
{
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "Empty\n";
		return;
	}
	int i = front;
	while(i != rear)
	{
		cout << queue[i];
		if(i != rear)
			cout << " : ";
		i = (i+1)%size;
	}
	cout << queue[rear] << endl;
}

void queueCircularArray::clear()
{
	if(isEmpty())
	{
		cout << "\nThe queue is empty\n";
		return;
	}
	this -> ~queueCircularArray();
	this -> front = -1;
	this -> rear = -1;
	cout << "\nSuccessfully cleared the Queue!\n";
}

bool queueCircularArray::isFull()
{
	if((rear+1)%size == front)
		return true;
	return false;
}

bool queueCircularArray::isEmpty()
{
	if(front == -1 && rear == -1)
		return true;
	return false;
}

int main()
{
	int choice;
	queueCircularArray ob;
	cout << "\n=========== QUEUE CIRCULAR ARRAY ===========\n";
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