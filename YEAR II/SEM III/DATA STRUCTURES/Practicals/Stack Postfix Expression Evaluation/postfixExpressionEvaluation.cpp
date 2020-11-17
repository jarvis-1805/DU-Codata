#include<iostream>
#define size 1000

using namespace std;

class postfixExpressionEvaluation
{
	public:
		
		int top;
		string exp;
		int stack[size];
		
		postfixExpressionEvaluation();
		
		void push(int);
		int pop();
		int peek();
		
		void takeExp();
		void stackEvaluation();
};

postfixExpressionEvaluation::postfixExpressionEvaluation()
{
	this -> top = -1;
}

void postfixExpressionEvaluation::push(int data)
{
	stack[++top] = data;
}

int postfixExpressionEvaluation::pop()
{
	int ele = stack[top--];
	return ele;
}

int postfixExpressionEvaluation::peek()
{
	return stack[top];
}

void postfixExpressionEvaluation::takeExp()
{
	getline(cin, exp);
}

void postfixExpressionEvaluation::stackEvaluation()
{
	string str;
	char c;
	int n, n1, n2, x;
	exp += ' ';
	for(int i=0; i<exp.length(); i++)
	{
		str = "";
		while(exp.at(i) != ' ')
		{
			str += exp.at(i);
			i++;
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
			n = n2-n1;
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
			n = n2/n1;
		}
		else
		{
			n = 0;
			for(int j=0; j<str.length(); j++)
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
	cout << "\n=========== STACK POSTFIX EXPRESSION EVALUATION ===========\n";
	postfixExpressionEvaluation ob1;
	cout << "\nENTER THE EXPRESSION (with space in b/w only): ";
	ob1.takeExp();
	ob1.stackEvaluation();
}