#include<iostream>
#define size 1000

using namespace std;

class stackExpressionConversion
{
	public:
		
		int top, ch;
		string exp;
		char stack[size];
		
		stackExpressionConversion();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void push(char);
		char pop();
		char peek();
		bool isEmpty();
		
		void takeExp();
		
		int precedence(char);
		string associativity(char);
		
		void infixToPostfix();
		void infixToPrefix();
		void postfixToInfix();
		void prefixToInfix();
};

stackExpressionConversion::stackExpressionConversion()
{
	this -> top = -1;
}

void stackExpressionConversion::options()
{
	cout << "\n1. INFIX TO POSTFIX"
		<<	"\n2. INFIX TO PREFIX"
		<<	"\n3. POSTFIX TO INFIX"
		<<	"\n4. PREFIX TO INFIX"
		<<	"\n0. EXIT";
}

int stackExpressionConversion::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void stackExpressionConversion::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			infixToPostfix();
			break;
		case 2:
			infixToPrefix();
			break;
		case 3:
			postfixToInfix();
			break;
		case 4:
			prefixToInfix();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void stackExpressionConversion::push(char data)
{
	stack[++top] = data;
}

char stackExpressionConversion::pop()
{
	char ele = stack[top--];
	return ele;
}

char stackExpressionConversion::peek()
{
	return stack[top];
}

bool stackExpressionConversion::isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	return false;
}

void stackExpressionConversion::takeExp()
{
	cin >> exp;
}

int stackExpressionConversion::precedence(char c)
{
    if(c == '^')
		return 3;
    else if(c == '*' || c == '/')
		return 2;
    else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string stackExpressionConversion::associativity(char c)
{
    if(c == '^')
		return "rTl";
    else if(c == '*' || c == '/' || c == '+' || c == '-')
		return "lTr";
	else
		return "";
}

void stackExpressionConversion::infixToPostfix()
{
	string str;
	char c;
	cout << "\nEnter Infix Expression : ";
	takeExp();
	for(int i=0; i<exp.length(); i++)
	{
		c = exp.at(i);
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			str = str + c;
		}
		else if(isEmpty() || peek() == '(')
			push(c);
		else if(c == '(')
			push(c);
		else if(c == ')')
		{
			while(!isEmpty() && peek() != '(')
			{
				str = str + pop();
			}
			if(peek() == '(')
				pop();
		}
		else
		{
			while(!isEmpty() && precedence(c) <= precedence(peek()))
			{
				if(precedence(c) < precedence(peek()))
					str = str + pop();
				else if(precedence(c) == precedence(peek()))
				{
					if(associativity(c) == "lTr")
					{
						str = str + pop();
						break;
					}
					else if(associativity(c) == "rTl")
						break;
				}
			}
			push(c);
		}
	}
	while(!isEmpty()) 
    { 
        str = str + pop(); 
    }
	cout << "The Postfix Expression : " << str << endl;
}

void stackExpressionConversion::infixToPrefix()
{
	
}

void stackExpressionConversion::postfixToInfix()
{
	
}

void stackExpressionConversion::prefixToInfix()
{
	
}

int main()
{
	int choice;
	stackExpressionConversion ob;
	do
	{
		cout << "\n=========== STACK EXPRESSION CONVERSION ===========\n";
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		ob.choiceCalling(choice);
	}while(1);
}