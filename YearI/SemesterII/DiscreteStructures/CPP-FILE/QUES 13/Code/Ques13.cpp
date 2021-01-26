#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main()
{
	int n;
	char x,y;
	cout << "Enter the no. of trials: ";
	cin >> n;
	bool value[n][2];
	for(int i=0; i<n; i++)
	{
		cout << "Enter the truth value for x" << i+1 << " y" << i+1 << ": ";
		cin >> x >> y;
		value[i][0] = (x == 't' || x == 'T');
		value[i][1] = (y == 't' || y == 'T');
	}
	cout << endl;
	cout << "x\ty\tAND\tOR\tXOR\tx->y\tx<->y\tXNOR\tNOT\tNAND\tNOR";
	cout << "\n-------------------------------------------------------"
	     << "-------------------------------------------------------\n";
	
	for(int i=0; i<n; i++)
	{
		int x = value[i][0], y = value[i][1];
		cout << (x ? "T" : "F") << "\t" << (y ? "T" : "F") << "\t"
			<< ((x && y) ? "T" : "F") << "\t"
			<< ((x || y) ? "T" : "F") << "\t"
			<< (((x || y) && !(x && y)) ? "T" : "F") << "\t"
			<< ((!x || y) ? "T" : "F") << "\t"
			<< (((!x || y) && (!y || x)) ? "T" : "F") << "\t"
			<< ((!((x || y) && !(x && y))) ? "T" : "F") << "\t"
			<< ((!x) ? "T" : "F") << " " << ((!y) ? "T" : "F") << "\t"
			<< (!(x && y) ? "T" : "F") << "\t"
			<< (!(x || y) ? "T" : "F") << "\n";
		cout << endl;
	}
	
	return 0;
}