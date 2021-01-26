#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class RELATION
{
	private:
	int i,j,k,x,y,z,ctr,iA,iB,nA,nR,*A,*R,**RM,**T;
	
	public:
	void empty();
	int inputSet();
	void inputRelation();
	void printSet();
	void printRelation();
	void Matrix();
	int reflexive();
	int symmetric();
	bool antiSymmetric();
	bool transitive();
};

void RELATION::empty()
{
	cout << "Set A is empty\n";
	printSet();
	cout << "Set A has no member.";
	cout << "\nHence, relation R is empty.\n";
	nR = 0;
	printRelation();
	cout << "Therefore, no matrix notation.";
	cout << "\nRelation R is NOT REFLEXIVE.";
	symmetric();
	antiSymmetric();
	transitive();
}

int RELATION::inputSet()
{
	cout << "Enter the size of SET A : ";
	cin >> nA;
	A = new int[nA];
	
	if(nA == 0)
		return 1;

	cout << "Enter the elements : ";
	for(i=0; i<nA; i++)
		cin >> A[i];
}

void RELATION::inputRelation()
{
	cout << "Enter the no of relations (R on A) : ";
	cin >> nR;
	R = new int[nR * 2];
	cout << "Enter the relations in pair :\n";
	for(i=0; i<nR*2; i++)
		cin >> R[i];
}

void RELATION::printSet()
{
	cout << "A = {";
	for(i=0; i<nA; i++)
		cout << A[i] << " ";
	cout << "}\n";
}

void RELATION::printRelation()
{
	cout << "R = {";
	for(i=0; i<nR*2; i++)
	{
		if(i%2 == 0)
			cout << "(";
		cout << R[i] << " ";
		if(i%2 != 0)
			cout << ")";
	}
	cout << "}\n";
}

void RELATION::Matrix()
{
	cout << "\nMATRIX NOTATION\n\n";
	RM = new int *[nA];
	for(i=0; i<nA; i++)
		RM[i]=new int[nA];
	
	for(i=0; i<nA; i++)
	{
		for(j=0; j<nA; j++)
		{
			RM[i][j]=0;
		}	
	}
	
	for(i=0; i<nR*2; i+=2)
	{
		for(j=0; j<nA; j++)
		{
			if(R[i] == A[j])
			{
				iA=j;
				break;
			}
		}
		for(k=0; k<nA; k++)
		{
			if(R[i+1] == A[k])
			{
				iB=k;
				break;
			}
		}
		RM[iA][iB]=1;
	}
	
	cout << "    ";
	for(int x=0; x<nA; x++)
		cout << " " << A[x] << " ";
	cout << endl << endl;
	for(i=0; i<nA; i++)
	{
		cout << A[i] << "  | ";
		for(j=0; j<nA; j++)
		{
			cout << RM[i][j] << "  ";
		}	
		cout << "|";
		cout << endl;
	}
}

int RELATION::reflexive()
{
	x=0;
	for(i=0; i<nA; i++)
	{
		if(RM[i][i] == 1)
			x++;
	}
	if(x == nA)
	{
		cout << "\nRelation R is REFLEXIVE.";
		return x = 0;
	}
	
	else
	{
		cout << "\nRelation R is NOT REFLEXIVE.";
		return x = 1;
	}
}

int RELATION::symmetric()
{
	ctr = 0;
	
	for(i=0; i<nA; i++)
	{
		for(j=0; j<nA; j++)
		{
			if(RM[i][j] == RM[j][i])
				continue;
			
			else
			{
				ctr++;
				break;
			}
		}
	}

	if(ctr != 0)
		cout << "\nRelation R is NOT SYMMETRIC.";
	
	else
		cout << "\nRelation R is SYMMETRIC.";
	
	return ctr;
}

bool RELATION::antiSymmetric()
{	
	bool flag = true;

	for(i=0; i<nR*2; i+=2)
	{
		for(j=0; j<nR*2; j+=2)
		{
			if((R[i] == R[j+1]) && (R[i+1] == R[j]))
				if(R[i] == R[i+1])
				{
					continue;
				}
				
				else
				{
					flag = false;
				}
		}
	}

	if(flag != true)
		cout << "\nRelation R is NOT ANTI-SYMMETRIC.";
	
	else
		cout << "\nRelation R is ANTI-SYMMETRIC.";
	
	return flag;
}

bool RELATION::transitive()
{
	bool flag = true;
	
	for(i=0; i<nR*2; i+=2)
	{
		for(j=0; j<nR*2; j+=2)
		{
			if(R[i+1] == R[j])
				for(k=0; k<nR*2; k+=2)
				{
				
					if((R[k] == R[i]) && (R[k+1] == R[j+1]))
					{
						flag = true;
						break;
					}
					
					else
						flag = false;
				}
		}
	}
	
	if(flag != true)
		cout << "\nRelation R is NOT TRANSITIVE.";
	
	else
		cout << "\nRelation R is TRANSITIVE.";
	
	return flag;
}

int main()
{
	int p = 0;

	RELATION ob;
	
	p = ob.inputSet();

	if(p == 1)
		ob.empty();
	
	else
	{
		ob.printSet();
		ob.inputRelation();
		ob.printRelation();
		ob.Matrix();
		ob.reflexive();
		ob.symmetric();
		ob.antiSymmetric();
		ob.transitive();
	}
	
	return 0;
}