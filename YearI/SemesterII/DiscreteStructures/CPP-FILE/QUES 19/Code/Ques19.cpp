#include<iostream>

using namespace std;

int main()
{
	int n;
	cout << "\nEnter the number of vertices: ";
	cin >> n;
	
	int matrix[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			matrix[i][j] = 0;
		
	cout << "Enter the adjacency matrix:\n";
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> matrix[i][j];
		
	int degree, order = 0;
	for(int i=0; i<n; i++)
	{
		degree = 0;
		for(int j=0; j<n; j++)
			degree += matrix[i][j];
		
		if(degree % 2 != 0)
			order++;
	}
	
	if(order == 0)
		cout << "Graph has an Eulerian Circuit!" << endl;
	
	else if(order == 2)
		cout << "Graph has an Eulerian Path!" << endl;
	
	else
		cout << "Graph is Not Eulerian!" << endl;
	
	return 0;
}