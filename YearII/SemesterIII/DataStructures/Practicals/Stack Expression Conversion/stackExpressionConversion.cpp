#include<iostream>
#define size 1000

using namespace std;

class stackExpressionConversion
{
	public:
		
		int top, ch;
		string exp;
		string stack[size];
		
		stackExpressionConversion();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void push(string);
		string pop();
		string peek();
		bool isEmpty();
		
		void takeExp();
		
		int precedence(string);
		string associativity(string);
		
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

void stackExpressionConversion::push(string data)
{
	stack[++top] = data;
}

string stackExpressionConversion::pop()
{
	string ele = stack[top--];
	return ele;
}

string stackExpressionConversion::peek()
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

int stackExpressionConversion::precedence(string c)
{
    if(c == "^")
		return 3;
    else if(c == "*" || c == "/")
		return 2;
    else if(c == "+" || c == "-")
		return 1;
	else
		return -1;
}

string stackExpressionConversion::associativity(string c)
{
    if(c == "^")
		return "rTl";
    else if(c == "*" || c == "/" || c == "+" || c == "-")
		return "lTr";
	else
		return "";
}

void stackExpressionConversion::infixToPostfix()
{
	string str;
	string c;
	cout << "\nEnter Infix Expression : ";
	takeExp();
	for(int i=0; i<exp.length(); i++)
	{
		c = exp.at(i);
		if((c >= "a" && c <= "z") || (c >= "A" && c <= "Z") || (c >= "0" && c <= "9"))
		{
			str = str + c;
		}
		else if(isEmpty() || peek() == "(")
			push(c);
		else if(c == "(")
			push(c);
		else if(c == ")")
		{
			while(!isEmpty() && peek() != "(")
			{
				str = str + pop();
			}
			if(peek() == "(")
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
	string str;
	string c;
	cout << "\nEnter Infix Expression : ";
	takeExp();
	for(int i=exp.length()-1; i>=0; i--)
	{
		c = exp.at(i);
		if((c >= "a" && c <= "z") || (c >= "A" && c <= "Z") || (c >= "0" && c <= "9"))
		{
			str = c + str;
		}
		else if(isEmpty() || peek() == ")")
			push(c);
		else if(c == ")")
			push(c);
		else if(c == "(")
		{
			while(!isEmpty() && peek() != ")")
			{
				str = pop() +  str;
			}
			if(peek() == ")")
				pop();
		}
		else
		{
			while(!isEmpty() && precedence(c) <= precedence(peek()))
			{
				if(precedence(c) < precedence(peek()))
					str = pop() +  str;
				else if(precedence(c) == precedence(peek()))
				{
					if(associativity(c) == "lTr")
						break;
					else if(associativity(c) == "rTl")
					{
						str = pop() +  str;
						break;
					}
				}
			}
			push(c);
		}
	}
	while(!isEmpty()) 
    { 
        str = pop() +  str; 
    }
	cout << "The Prefix Expression : " << str << endl;
}

void stackExpressionConversion::postfixToInfix()
{
	string str;
	string c, c1, c2;
	cout << "\nEnter Postfix Expression : ";
	takeExp();
	for(int i=0; i<exp.length(); i++)
	{
		c = exp.at(i);
		if((c >= "a" && c <= "z") || (c >= "A" && c <= "Z") || (c >= "0" && c <= "9"))
		{
			push(c);
		}
		else
		{
			c1 = pop();
			c2 = pop();
			str = '(' + c2 + c + c1 + ')';
			push(str);
		}
	}
	cout << "The Infix Expression : " << peek() << endl;
}

void stackExpressionConversion::prefixToInfix()
{
	string str;
	string c, c1, c2;
	cout << "\nEnter Prefix Expression : ";
	takeExp();
	for(int i=exp.length()-1; i>=0; i--)
	{
		c = exp.at(i);
		if((c >= "a" && c <= "z") || (c >= "A" && c <= "Z") || (c >= "0" && c <= "9"))
		{
			push(c);
		}
		else
		{
			c1 = pop();
			c2 = pop();
			str = '(' + c1 + c + c2 + ')';
			push(str);
		}
	}
	cout << "The Infix Expression : " << peek() << endl;
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