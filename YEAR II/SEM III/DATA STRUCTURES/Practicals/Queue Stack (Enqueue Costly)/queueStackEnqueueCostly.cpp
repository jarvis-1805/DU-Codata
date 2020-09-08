#include<iostream>
#define MAX 100

using namespace std;

class queueStackEnqueueCostly
{
	public:
		int top;
		int stack[MAX];
		int ch;
		
		queueStackEnqueueCostly();
		
		void options();
		int choice();
		void choiceCalling(int, queueStackEnqueueCostly);
		
		void push(int);
		int pop();
		void traverse();
		
		void enqueue(int, queueStackEnqueueCostly);
		int dequeue();
		void clear(queueStackEnqueueCostly);
		
		bool isEmpty();
};

queueStackEnqueueCostly::queueStackEnqueueCostly()
{
	this -> top = -1;
}

void queueStackEnqueueCostly::options()
{
  cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE"
		<<	"\n2. DEQUEUE"
		<<	"\n3. CLEAR"
		<<	"\n0. EXIT";
}

int queueStackEnqueueCostly::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void queueStackEnqueueCostly::choiceCalling(int ch, queueStackEnqueueCostly ob2)
{
	switch(ch)
	{
		case 1:
			int n;
			cout << "\nEnter the new data : ";
			cin >> n;
			this -> enqueue(n, ob2);
			this -> traverse();
			break;
		case 2:
			if(this -> isEmpty())
			{
				cout << "\n########### The queue is empty ###########\n";
				break;
			}
			int a;
			a = this -> dequeue();
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

void queueStackEnqueueCostly::enqueue(int n, queueStackEnqueueCostly ob2)
{
	if(this -> isEmpty())
		this -> push(n);
	else
	{
    
		while(this -> isEmpty() != true)
		{
			ob2.push(this -> pop());
		}
		ob2.push(n);
		while(ob2.isEmpty() != true)
		{
			this -> push(ob2.pop());
		}
	}
	cout << "\nEnqueued2: " << n << "\n";
}

int queueStackEnqueueCostly::dequeue()
{
	return pop();
}

void queueStackEnqueueCostly::clear(queueStackEnqueueCostly ob2)
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
			int ele = dequeue();
			cout << "\nDequeued : " << ele << "\n";
		}
		cout << "\n########### The queue is cleared ###########\n";
		traverse();
	}
}

void queueStackEnqueueCostly::push(int n)
{
	stack[++top] = n;
	return;
}

int queueStackEnqueueCostly::pop()
{
	int ele = stack[top--];
	return ele;
}

void queueStackEnqueueCostly::traverse()
{
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "EMPTY\n";
	}
	else
	{
		for(int i=top; i>=0; i--)
		{
			cout << stack[i];
      if(i != 0)
        cout << " : ";
		}
    cout << endl;
	}
}

bool queueStackEnqueueCostly::isEmpty()
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
	queueStackEnqueueCostly ob1, ob2;
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