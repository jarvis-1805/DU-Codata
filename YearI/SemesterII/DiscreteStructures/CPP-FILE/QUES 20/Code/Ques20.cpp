#include<iostream>

using namespace std;

int calcNodes(int m, int I)
{
	int result = 0;
	
	result = I * (m - 1) + 1;
	
	return result;
}

int main()
{
	int m,I,N;
	
	cout << "\nEnter the maximum no. of children in full m-ary tree: ";
	cin >> m;
	
	cout << "Enter the number of internal vertices: ";
	cin >> I;
	
	N = calcNodes(m, I);
	cout << "Number of Leaf Nodes in the full m-ary tree: " << N;
	
	return 0;
}