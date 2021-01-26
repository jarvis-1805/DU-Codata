#include <iostream>

using namespace std;

class SET
{
	private:
		int i,j;
	
	public:	
	void Subset(int *arrA, int sizeA, int *arrB, int sizeB)
	{
		int c=0;

		for(i=0; i<sizeA; i++)
			for(j=0; j<sizeB; j++)
				if(arrA[i] == arrB[j])
					c++;
				
		if(c != sizeA)
			cout << "SET A is not a subset of SET B" << endl;
		
		else
			cout << "SET A is a subset of SET B" << endl;
		
		int c1=0;
		
		for(i=0; i<sizeB; i++)
			for(j=0; j<sizeA; j++)
				if(arrB[i] == arrA[j])
					c1++;
				
		if(c != sizeB)
			cout << "SET B is not a subset of SET A" << endl;
		
		else
			cout << "SET B is a subset of SET A" << endl;
		
		cout << "-------------------------------------------------" << endl;
	}
	
	void UnionInter(int *setA, int sizeA, int *setB, int sizeB)
	{
		int uSize=sizeA+sizeB;
		int uSet[uSize];
		int unionSet[uSize];
		int iSet[uSize];
		int x=0,y=0;
		
		for(i=0; i<sizeA; i++)
		{
			uSet[x]=setA[i];
			x++;
		}
		
		for(i=0; i<sizeB; i++)
		{
			uSet[x]=setB[i];
			x++;
		}
		
		for(i=0; i<x; i++)
		{
			for(j=i+1; j<x; j++)
			{
				if(uSet[i] == uSet[j])
				{
					iSet[y]=uSet[i];
					y++;
					
					for(int k=j; k<x-1; k++)
						uSet[k]=uSet[k+1];
						x--;
				}
				
				else
					continue;
			}
		}
		
		cout << "Union of two sets is : {";
		for(i=0; i<x; i++)
			cout << uSet[i] << " ";
		cout << "}";
		
		cout << endl;
		
		if(y != 0)
		{
			cout << "Intersection of two sets is : {";
			
			for(i=0; i<y; i++)
				cout << iSet[i] << " ";
			cout << "}";
		}
		
		else
			cout << "No intersection found";
		
		cout << endl;
		cout << "-------------------------------------------------" << endl;
	}
	
	void Complement(int *setA, int sizeA, int *setB, int sizeB)
	{
		int sizeU;
		cout << "Enter the no. of elements of universal set : ";
		cin >> sizeU;
		
		cout << "Enter the elemnts of universal set : ";
		int U[sizeU];
		
		for(i=0; i<sizeU; i++)
			cin >> U[i];
		
		int AC[sizeU],p=0,c=0;
		
		for(i=0; i<sizeU; i++)
		{
			for(j=0; j<sizeA; j++)
			{
				if(U[i] == setA[j])
					c++;
				
				else
					continue;
			}
			
			if(c == 0)
			{
				AC[p]=U[i];
				p++;
			}
			c=0;
		}
		cout << endl;
		
		cout << "Complement of SET A is : {";
		for(i=0; i<p; i++)
			cout << AC[i] << " ";
		cout << "}" << endl;
		
		int BC[sizeU],q=0,ctr=0;
		
		for(i=0; i<sizeU; i++)
		{
			for(j=0; j<sizeB; j++)
			{
				if(U[i] == setB[j])
					ctr++;
				
				else
					continue;
			}
			
			if(ctr == 0)
			{
				BC[q]=U[i];
				q++;
			}
			
			ctr=0;
		}
		
		cout << "Complement of SET B is : {";
		for(i=0; i<q; i++)
			cout << BC[i] << " ";
		cout << "}" << endl;
		
	cout << "-------------------------------------------------" << endl;
	}
	
	void setNSymDiff(int *setA, int sizeA, int *setB, int sizeB)
	{ 
		int ABDif[100],q=0,ctr=0;
		
		for(i=0; i<sizeA; i++)
		{
			for(j=0; j<sizeB; j++)
			{
				if(setA[i] == setB[j])
					ctr++;
				
				else
					continue;
			}
			
			if(ctr == 0)
			{
				ABDif[q]=setA[i];
				q++;
			}
			
			ctr=0;
		}
		
		cout << "Set difference A-B is : {";
		for(i=0; i<q; i++)
			cout << ABDif[i] << " ";
		cout << "}" << endl;
		
		int BADif[100],p=0,c=0;
		
		for(i=0; i<sizeB; i++)
		{
			for(j=0; j<sizeA; j++)
			{
				if(setB[i] == setA[j])
					c++;
				
				else
					continue;
			}
			
			if(c == 0)
			{
				BADif[p]=setB[i];
				p++;
			}
			
			c=0;
		}
		
		cout << "Set difference B-A is : {";
		for(i=0; i<p; i++)
			cout << BADif[i] << " ";
		cout << "}" << endl;
		
		int uSize=q+p;
		int symDif[uSize];
		int x=0,y=0;
		
		for(i=0; i<q; i++)
		{
			symDif[x]=ABDif[i];
			x++;
		}
		
		for(i=0; i<p; i++)
		{
			symDif[x]=BADif[i];
			x++;
		}
		
		cout << "Symmetric difference b/w two sets is : {";
		for(i=0; i<x; i++)
			cout << symDif[i] << " ";
		cout << "}";
		
		cout << endl;
		cout << "-------------------------------------------------" << endl;
	}
	
	void cartesianPro(int *setA, int sizeA, int *setB, int sizeB)
	{
		int sizeAB,sizeBA,x=0,y=0;
		
		sizeAB=sizeA*sizeB;
		sizeBA=sizeAB;
		
		int AB[sizeAB*2],BA[sizeBA*2];
		
		for(i=0; i<sizeA; i++)
		{
			for(j=0; j<sizeB; j++)
			{
				AB[x++]=setA[i];
				AB[x++]=setB[j];
			}
		}
		
		for(i=0; i<sizeB; i++)
		{
			for(j=0; j<sizeA; j++)
			{
				BA[y++]=setB[i];
				BA[y++]=setA[j];
			}
		}
		
		cout << "A X B = { ";
		for(i=0; i<x; i++)
		{
			if(i%2 == 0)
				cout << "(";
			cout << AB[i] << " ";
			
			if(i%2 != 0)
				cout << ")";
		}
		cout << " }" << endl;
		
		cout << "B X A = { ";
		for(i=0; i<y; i++)
		{
			if(i%2 == 0)
				cout << "(";
			cout << BA[i] << " ";
			
			if(i%2 != 0)
				cout << ")";
		}
		cout << " }" << endl;
		
		cout << "-------------------------------------------------" << endl;
	}
};

int main()
{
	cout << endl;
	int i,sizeA,sizeB;
	
	cout << "Enter the no. of elements in SET A : ";
	cin >> sizeA;
	
	int arrA[sizeA];
	
	cout << "Enter the elements : ";
	for(i=0; i<sizeA; i++)
		cin >> arrA[i];
	
	cout << "Enter the no. of elements in SET B : ";
	cin >> sizeB;
	
	int arrB[sizeB];
	
	cout << "Enter the elements : ";
	for(i=0; i<sizeB; i++)
		cin >> arrB[i];

	cout << "-------------------------------------------------" << endl;
	
	SET ob;
	
	cout << "\tSUBSET\n" << endl;
	ob.Subset(arrA, sizeA, arrB, sizeB);
	
	cout << "\tUNION and INTERSECTION\n" << endl;
	ob.UnionInter(arrA, sizeA, arrB, sizeB);
	
	cout << "\tCOMPLEMENT\n" << endl;
	ob.Complement(arrA, sizeA, arrB, sizeB);
	
	cout << "\tSET and SYMMETRIC DIFFERENCE\n" << endl;
	ob.setNSymDiff(arrA, sizeA, arrB, sizeB);
	
	cout << "\tCARTESIAN PRODUCT\n" << endl;
	ob.cartesianPro(arrA, sizeA, arrB, sizeB);
	
	return 0;
}
