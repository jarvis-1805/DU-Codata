#include<iostream>

using namespace std;

template <typename T>
class stackArray
{
	public:
		
		int top;
		int ch;
		int size;
		T stack[];
		
		stackArray();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void push(T);
		T pop();
		void clear();
		void traverse();
		
		bool isEmpty();
};

template <typename T>
stackArray<T>::stackArray()
{
	cout << "\nEnter the size of the stack : ";
	cin >> size;
	this -> size = size;
	this -> stack[size];
	top = -1;
}

template <typename T>
void stackArray<T>::options()
{
	cout << "\n1. PUSH"
		<<	"\n2. POP"
		<<	"\n3. CLEAR"
		<<	"\n0. EXIT";
}

template <typename T>
int stackArray<T>::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

template <typename T>
void stackArray<T>::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			T data;
			if(isEmpty())
			{
				cout << "\n------------ PUSHING IN STACK ------------\n";
				cout << "Enter the data : ";
				cin >> data;
				push(data);
			}
			else
			{
			cout << "\n########### The stack is full ###########\n";
			}
			break;
		case 2:
			if(top == -1)
			{
				cout << "\n########### The stack is empty ###########\n";
			}
			else
			{
				cout << "\n------------ POPING FROM STACK ------------\n";
				T ele = pop();
				cout << "\nPoped : " << ele << "\n";
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

template <typename T>
void stackArray<T>::push(T data)
{
	stack[++top] = data;
	cout << "\nPushed : " << stack[top] << "\n";
	traverse();
}

template <typename T>
T stackArray<T>::pop()
{
	T ele = stack[top--];
	return ele;
}

template <typename T>
void stackArray<T>::clear()
{
	if(top == -1)
	{
		cout << "\n########### The stack is empty ###########\n";
	}
	else
	{
		cout << "\n------------ CLEARING THE STACK ------------\n";
		while(top != -1)
		{
			T ele = pop();
			cout << "Poped : " << ele << "\n";
		}
		cout << "\n########### The stack is cleared ###########\n";
		traverse();
	}
}

template <typename T>
void stackArray<T>::traverse()
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

template <typename T>
bool stackArray<T>::isEmpty()
{
	if(top == size-1)
	{
		return false;
	}
	return true;
}

int main()
{
	int choice, size;
	cout << "\n=========== STACK IN ARRAY ===========\n";
	stackArray<int> ob;
	
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