#include<iostream>

using namespace std;

int countPaths(int graph[][100], int n, int src, int dest, int len)
{
	int count[n][n][len + 1];
	for(int e=0; e<=len; e++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				count[i][j][e] = 0;
				if(e == 0 && i == j)
					count[i][j][e] = 1;
				
				if(e == 1 && graph[i][j])
					count[i][j][e] = 1;
				
				if(e > 1)
					for(int a=0; a<n; a++)
						if(graph[i][a])
							count[i][j][e] += count[a][j][e - 1];
			}
		}
	}
	
	return count[src][dest][len];
}

int main()
{
	int v;
	cout << "\nEnter the nunber of vertices: ";
	cin >> v;
	
	int matrix[100][100];
	cout << "Enter the adjacency matrix:\n";
	for(int i=0; i<v; i++)
		for(int j=0; j<v; j++)
			cin >> matrix[i][j];
		
	int src, dest;
	cout << "Enter the source node: ";
	cin >> src;
	cout << "Enter the destinastion node: ";
	cin >> dest;
	
	int len;
	cout << "Enter the path lemgth: ";
	cin >> len;
	
	cout << "Total paths from node " << src 
		<< " to node " << dest << " having " 
		<< len << " edges: " 
		<< countPaths(matrix, v, src-1, dest-1, len);
		
	return 0;
}