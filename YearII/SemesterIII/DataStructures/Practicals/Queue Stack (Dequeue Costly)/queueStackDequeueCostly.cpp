#include<iostream>
#define MAX 100

using namespace std;

class queueStackDequeueCostly
{
	public:
		int top;
		int stack[MAX];
		int ch;
		
		queueStackDequeueCostly();
		
		void options();
		int choice();
		void choiceCalling(int, queueStackDequeueCostly);
		
		void push(int);
		int pop();
		void traverse();
		
		void enqueue(int);
		int dequeue(queueStackDequeueCostly);
		void clear(queueStackDequeueCostly);
		
		bool isEmpty();
};

queueStackDequeueCostly::queueStackDequeueCostly()
{
	this -> top = -1;
}

void queueStackDequeueCostly::options()
{
  cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE"
		<<	"\n2. DEQUEUE"
		<<	"\n3. CLEAR"
		<<	"\n0. EXIT";
}

int queueStackDequeueCostly::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void queueStackDequeueCostly::choiceCalling(int ch, queueStackDequeueCostly ob2)
{
	switch(ch)
	{
		case 1:
			int n;
			cout << "\nEnter the new data : ";
			cin >> n;
			this -> enqueue(n);
			this -> traverse();
			break;
		case 2:
			if(this -> isEmpty())
			{
				cout << "\n########### The queue is empty ###########\n";
				break;
			}
			int a;
			a = this -> dequeue(ob2);
			cout << "\nDequeued : " << a << endl;
			this -> traverse();
			break;
		case 3:
			clear(ob2);
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void queueStackDequeueCostly::enqueue(int n)
{
	push(n);
	cout << "\nEnqueued : " << n << "\n";
}

int queueStackDequeueCostly::dequeue(queueStackDequeueCostly ob2)
{
	int x;
	while(this -> isEmpty() != true)
	{
		ob2.push(this -> pop());
	}
	x = ob2.pop();
	while(ob2.isEmpty() != true)
	{
		this -> push(ob2.pop());
	}
	return x;
}

void queueStackDequeueCostly::clear(queueStackDequeueCostly ob2)
{
	cout << "\n------------ CLEARING THE QUEUE ------------\n";
	if(isEmpty())
	{
		cout << "\n########### The queue is empty ###########\n";
	}
	else
	{
		while(!isEmpty())
		{
			int ele = dequeue(ob2);
			cout << "\nDequeued : " << ele << "\n";
		}
		cout << "\n########### The queue is cleared ###########\n";
		traverse();
	}
}

void queueStackDequeueCostly::push(int n)
{
	stack[++top] = n;
	return;
}

int queueStackDequeueCostly::pop()
{
	int ele = stack[top--];
	return ele;
}

void queueStackDequeueCostly::traverse()
{
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "EMPTY\n";
	}
	else
	{
		for(int i=0; i<=top; i++)
		{
			cout << stack[i];
      if(i != top)
        cout << " : ";
		}
    cout << endl;
	}
}

bool queueStackDequeueCostly::isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	return false;
}

int main()
{
	int choice, ch;
	queueStackDequeueCostly ob1, ob2;
	cout << "\n=========== QUEUE USING STACK ===========\n";
	do
	{
		ob1.options();
		choice = ob1.choice();
		if(choice == 0)
			break;
		ob1.choiceCalling(choice, ob2);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	
	return 0;
}