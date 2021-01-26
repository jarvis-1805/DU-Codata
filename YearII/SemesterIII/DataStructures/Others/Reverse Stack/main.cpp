#include<iostream>
#define MAX 50

using namespace std;

class stackArray
{
	public:
		
		int top;
		int size;
		int stack[MAX];
		
		stackArray();
				
		void push(int);
		int pop();
		void traverse();
};

stackArray::stackArray()
{
	top = -1;
}

void stackArray::push(int data)
{
	stack[++top] = data;
}

int stackArray::pop()
{
	int ele = stack[top--];
	return ele;
}

void stackArray::traverse()
{
	cout << endl << "Stack: ";
	if(top == -1)
	{
		cout << "EMPTY\n";
	}
	else
	{
		int x=1;
		for(int i=top; i>=0; i--)
		{
			cout << stack[i];
			if(x == 1)
			{
				cout << "  <-- Top";
				x = 0;
			}
			cout << "\n       ";
		}
	}
}

int main()
{
	cout << "\n======== REVERSING THE STACK ========\n";
    int ele;
    stackArray ob, ob1, ob2;

    //Input the stack
	cout << "\nEnter the size of the stack : ";
    cin >> ob.size;
    for (int i = 0; i < ob.size; i++)
    {
        cout << "\nEnter the element " << i+1 << ": ";
        cin >> ele;
        ob.push(ele);
    }
    cout << "\nOriginal stack";
    ob.traverse();

    //Reversing the stack in new stack (stack 1)
    for (int i = 0; i < ob.size; i++)
    {
        ele = ob.pop();
        ob1.push(ele);
    }
    cout << "\nStack 1";
    ob1.traverse();
    
    //Creating another stack same as original stack (stack 2)
    for (int i = 0; i < ob.size; i++)
    {
        ele = ob1.pop();
        ob2.push(ele);
    }
    cout << "\nStack 2";
    ob2.traverse();

    //Transferring in original stack
    for (int i = 0; i < ob.size; i++)
    {
        ele = ob2.pop();
        ob.push(ele);
    }
    cout << "\nOriginal stack";
    ob.traverse();
}