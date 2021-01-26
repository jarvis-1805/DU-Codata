#include<iostream>

using namespace std;

int firstRecurrence(int n)
{
	if(n == 0)
		return 1;
	return firstRecurrence(n-1) + n;
}

int secondRecurrence(int n)
{
	if(n == 0)
		return 1;
	return secondRecurrence(n-1) + n*n;
}

int thirdRecurrence(int n)
{
	if(n == 1)
		return 1;
	return 2 * thirdRecurrence(n/2) + n;
}

int main()
{
	int n,ch;
	cout << "\nChoose recurrence relation to evaluate:\n"
	     << "(1) T(n) = T(n - 1) + n and T(0) = 1\n"
		 << "(2) T(n) = T(n - 1) + n^2 and T(0) = 1\n"
		 << "(3) T(n) = 2 * T(n / 2) + n and T(1) = 1\n";
	cout << "Enter the choice: ";
	cin >> ch;
	
	switch(ch)
	{
		case 1:
			cout << "\nEnter the value of n: ";
			cin >> n;
			cout << "\nValues for T(n) = T(n - 1) + n:\n";
			for(int i=0; i<=n; i++)
			{
				if(i == 0)
					cout << "T(0) = " << firstRecurrence(i) << endl;
				
				else
					cout << "T(" << i << ") = T(" << (i-1) << ") + "
				         << i << " = "
						 << firstRecurrence(i) << endl;
			}
		break;
			
		case 2:
			cout << "\nEnter the value of n: ";
			cin >> n;
			cout << "\nValues for T(n) = T(n - 1) + n^2:\n";
			for(int i=0; i<=n; i++)
			{
				if(i == 0)
					cout << "T(0) = " << secondRecurrence(i) << endl;
				
				else
					cout << "T(" << i << ") = T(" << (i-1) << ") + "
				         << i*i << " = "
						 << secondRecurrence(i) << endl;
			}
		break;
			
		case 3:
			cout << "\nEnter the value of n: ";
			cin >> n;
			cout << "\nValues for T(n) = 2 * T(n / 2) + n:\n";
			for(int i=1; i<=n; i++)
			{
				if(i == 1)
					cout << "T(1) = " << thirdRecurrence(i) << endl;
				
				else
					cout << "T(" << i << ") = 2 * T(" << i << " / 2) + "
				         << i << " = " << "2 * T(" << i/2 << ") + "
						 << i << " = "
						 << thirdRecurrence(i) << endl;
			}
		break;
		
		default:
			cout << "\nWrong choice!!!";
			break;
	}
	
	return 0;
}