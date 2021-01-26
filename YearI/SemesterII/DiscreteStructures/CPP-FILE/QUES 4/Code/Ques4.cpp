#include<iostream>
#include "RELATIONS.hpp"

using namespace std;

class checkRELATION : public RELATION
{
	public:
	int equivalent(int, int, bool);
	int partialOrder(int, bool, bool);
	void neither(int, int);
};

int checkRELATION::equivalent(int r, int s, bool t)
{
	if((r == 0) && (s == 0) && (t == true))
		cout << "\nRelation R is EQUIVALENT relation";
	
	else
		return 0;
		
	return 1;
}

int checkRELATION::partialOrder(int r, bool a, bool t)
{
	if((r == 0) && (a == true) && (t == true))
		cout << "\nRelation R is PARTIAL ORDER relation";
		
	else
		return 0;
	
	return 1;
}

void checkRELATION::neither(int e, int po)
{
	if((e != 1) && (po != 1))
		cout << "\nRelation R is NEITHER equivalent NOR partial order relation";
}
int main()
{
	int p=0,r,s,e,po;
	bool a,t;
	
	checkRELATION ob1;
	
	p = ob1.inputSet();
	
	if(p == 1)
	{
		ob1.empty();
	}
	
	else
	{
		ob1.printSet();
		ob1.inputRelation();
		ob1.printRelation();
		ob1.Matrix();
		r = ob1.reflexive();
		s = ob1.symmetric();
		a = ob1.antiSymmetric();
		t = ob1.transitive();
	}
	
	e = ob1.equivalent(r, s, t);
	po = ob1.partialOrder(r, a, t);
	ob1.neither(e, po);
	
	return 0;
}