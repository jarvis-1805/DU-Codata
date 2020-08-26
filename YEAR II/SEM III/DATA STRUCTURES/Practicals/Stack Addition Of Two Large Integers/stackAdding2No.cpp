#include<iostream>
#define size 1000

using namespace std;

class stackAdding2No
{
	public:
		
		int top;
		string num;
		int stack[size];
		
		stackAdding2No();
		
		void takeNum();
		void convertingToStack();
		
		void push(int);
		int pop();
		void traverse();
		
		void operator +(stackAdding2No);
		
		bool isEmpty();
};

stackAdding2No::stackAdding2No()
{
	this -> top = -1;
}

void stackAdding2No::takeNum()
{
	cin >> num;
}

void stackAdding2No::convertingToStack()
{
	char c;
	int n;
	for(int i=0; i<num.length(); i++)
	{
		c = num.at(i);
		n = (int)c;
		push(n-48);
	}
}

void stackAdding2No::push(int data)
{
	stack[++top] = data;
}

int stackAdding2No::pop()
{
	if(top != -1)
	{
	  int ele = stack[top--];
	  return ele;
	}
	else
		return 0;
}

void stackAdding2No::traverse()
{
	cout << "\nRESULT : ";
	for(int i=top; i>=0; i--)
	{
		cout << stack[i];
	}
	cout << "\n";
}

void stackAdding2No::operator + (stackAdding2No ob2)
{
	stackAdding2No ob;
	int ele1, ele2, ele, carry=0;
	while(this -> top != -1 || ob2.top != -1)
	{
		ele1 = this -> pop();
		ele2 = ob2.pop();
		ele = ele1 + ele2 + carry;
		if(ele >= 10 || ele <= 99)
		{
			carry = ele/10;
			ele = ele%10;
		}
		ob.push(ele);
	}
	ob.traverse();
}

int main()
{
	cout << "\n=========== STACK ADDITION OF TWO LARGE INTEGERS ===========\n";
	stackAdding2No ob1, ob2;
	cout << "\nENTER THE FIRST NUMBER : ";
	ob1.takeNum();
	cout << "\nENTER THE SECOND NUMBER : ";
	ob2.takeNum();
	ob1.convertingToStack();
	ob2.convertingToStack();
	ob1 + ob2;
}