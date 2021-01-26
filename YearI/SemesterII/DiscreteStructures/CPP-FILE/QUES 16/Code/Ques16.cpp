#include<iostream>

using namespace std;

int main()
{
	int n, c=0, x, p;
	cout << "\nEnter the no. of vertices: ";
	cin >> n;
	int matrix[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			 matrix[i][j] = 0;
	
	for(int i=0; i<n; i++)
	{
		cout << "\nEnter the no. of vertices adjacent to vertex " << i+1 << ": ";
		cin >> x;
		
		for(int j=0; j<x; j++)
		{
			cout << "Enter the vertex adjacent to vertex " << i+1 << ": ";
			cin >> p;
			
			for(int a=0; a<n; a++)
				if(a+1 == p)
				{
					matrix[i][a] = 1;
					break;
				}
		}
	}
	
	cout << "\nADJACENCY MATRIX\n";
	for(int i=0; i<n; i++)
	{
		int sum = 0;
		for(int j=0; j<n; j++)
		{
			cout << matrix[i][j] << " ";
			if(matrix[i][i] == 0)
				sum += matrix[i][j];
		}
		cout << endl;
		if(sum == (n-1))
			c++;
	}
	
	if(c == n)
		cout << "\nGraph is COMPLETE!!!";
	
	else
		cout << "\nGraph is NOT COMPLETE!!!";
	
	return 0;
}