#include <iostream>
#include <math.h>
#define size 1000

using namespace std;

class prefixExpressionEvaluation
{
	public:
		
		int top;
		string exp;
		int stack[size];
		
		prefixExpressionEvaluation();
		
		void push(int);
		int pop();
		int peek();
		
		void takeExp();
		void stackEvaluation();
};

prefixExpressionEvaluation::prefixExpressionEvaluation()
{
	this -> top = -1;
}

void prefixExpressionEvaluation::push(int data)
{
	stack[++top] = data;
}

int prefixExpressionEvaluation::pop()
{
	int ele = stack[top--];
	return ele;
}

int prefixExpressionEvaluation::peek()
{
	return stack[top];
}

void prefixExpressionEvaluation::takeExp()
{
	getline(cin, exp);
}

void prefixExpressionEvaluation::stackEvaluation()
{
	string str;
	char c;
	int n, n1, n2, x;
	exp = ' ' + exp;
	for(int i=exp.length()-1; i>=0; i--)
	{
		str = "";
		while(exp.at(i) != ' ')
		{
			str += exp.at(i);
			i--;
		}
		c = str.at(0);
		if(c == '+')
		{
			n1 = pop();
			n2 = pop();
			n = n1+n2;
		}
		else if(c == '-')
		{
			n1 = pop();
			n2 = pop();
			n = n1-n2;
		}
		else if(c == '*')
		{
			n1 = pop();
			n2 = pop();
			n = n1*n2;
		}
		else if(c == '/')
		{
			n1 = pop();
			n2 = pop();
			n = n1/n2;
		}
		else if(c == '^')
		{
			n1 = pop();
			n2 = pop();
			n = (int)(pow(n1, n2) + 0.5);
		}
		else
		{
			n = 0;
			for(int j=str.length()-1; j>=0; j--)
			{
				x = ((int)str.at(j)) - 48;
				n = n*10 + x;
			}
		}
		push(n);
	}
	cout << "\nRESULT : " << peek() << endl;
}

int main()
{
	cout << "\n=========== STACK PREFIX EXPRESSION EVALUATION ===========\n";
	prefixExpressionEvaluation ob1;
	cout << "\nENTER THE EXPRESSION (with space in b/w only): ";
	ob1.takeExp();
	ob1.stackEvaluation();
}