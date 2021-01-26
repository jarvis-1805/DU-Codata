#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int v, nin, nout, inver, outver;
	cout << "\nEnter the no. of vertices: ";
	cin >> v;
	
	int matrix[v][v];
	for(int i=0; i<v; i++)
		for(int j=0; j<v; j++)
			 matrix[i][j] = 0;
	
	for(int i=0; i<v; i++)
	{
		cout << "Enter the no. of edges incoming to vertex " << i+1 << ": ";
		cin >> nin;
		for(int x=0; x<nin; x++)
		{
			cout << "Enter the vertex from which incoming edge to vertex " << i+1 << " is emerging from: ";
			cin >> inver;
			matrix[i][inver -1] = -1;
		}
		
		cout << "Enter the no. of edges outgoing from vertex " << i+1 << ": ";
		cin >> nout;
		for(int y=0; y<nout; y++)
		{
			cout << "Enter the vertex to which outgoing edge from vertex " << i+1 << " is ending at: ";
			cin >> outver;
			matrix[i][outver -1] = 1;
		}
	}
	
	for(int i=0; i<v; i++)
	{
		int indegree=0, outdegree=0;
		for(int j=0; j<v; j++)
		{
			if(matrix[i][j] == 1)
				outdegree += matrix[i][j];
			
			if(matrix[i][j] == -1)
				indegree += matrix[i][j];
		}
		
		cout << "\n\nIn-degree of vertex " << i+1 << " is " << abs(indegree)
			 << "\tOut-degree of vertex " << i+1 << " is " << outdegree;
	}
	
	return 0;
}