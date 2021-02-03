#include<iostream>
#define size 1000

using namespace std;

class stackDelimiterMatching
{
	public:
		
		int top;
		string exp;
		string stack[size];
		
		stackDelimiterMatching();
		
		void push(string);
		string pop();
		string peek();
		
		void takeExp();
		void stackEvaluation();
};

stackDelimiterMatching::stackDelimiterMatching()
{
	this -> top = -1;
}

void stackDelimiterMatching::push(string data)
{
	stack[++top] = data;
}

string stackDelimiterMatching::pop()
{
	string ele = stack[top--];
	return ele;
}

string stackDelimiterMatching::peek()
{
	if(top != -1)
		return stack[top];
	return "NULL";
}

void stackDelimiterMatching::takeExp()
{
	getline(cin, exp);
}

void stackDelimiterMatching::stackEvaluation()
{
	string str, c;
	bool flag = true;
	exp += ' ';
	for(int i=0; i<exp.length(); i++)
	{
		str = "";
		while(exp.at(i) != ' ')
		{
			str += exp.at(i);
			i++;
		}
		if(str == "[")
		{
			push("]");
		}
		else if(str == "{")
		{
		push("}");
		}
		else if(str == "(")
		{
			push(")");
		}
		else if(str == "/*")
		{
			push("*/");			
		}
		else if(str == "]")
		{
			c = pop();
			if(c == "]")
				continue;
			else
			{
				flag = false;
				break;
			}
		}
		else if(str == "}")
		{
			c = pop();
			if(c == "}")
				continue;
			else
			{
				flag = false;
				break;
			}
		}
		else if(str == ")")
		{
			c = pop();
			if(c == ")")
				continue;
			else
			{
				flag = false;
				break;
			}
		}
		else if(str == "*/")
		{
			c = pop();
			if(c == "*/")
				continue;
			else
			{
				flag = false;
				break;
			}
		}
	}
	if(flag && peek() == "NULL")
		cout << "\nThe Expression Is Balanced\n";
	else
		cout << "\nThe Expression Is Not Balanced\n";
}

int main()
{
	cout << "\n=========== STACK DELIMITER MATCHING ===========\n";
	stackDelimiterMatching ob1;
	cout << "\nENTER THE EXPRESSION (with space in b/w only): ";
	ob1.takeExp();
	ob1.stackEvaluation();
}