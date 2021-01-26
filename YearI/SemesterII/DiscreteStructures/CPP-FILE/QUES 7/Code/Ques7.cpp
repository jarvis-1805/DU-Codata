#include <iostream>

using namespace std;

int BinarySearch(int arr[], int num, int beg, int end)
{
	int mid;
 
	if (beg > end)
	{
		cout << "\nNumber is not found";
		return 0;
	}
	
	else
	{
		mid = (beg + end) / 2;
		if(arr[mid] == num)
		{
			cout << "\nNumber is found at " << mid+1 << " position.\n";
			return 0;
		}
		
		else if (num > arr[mid])
		{
			BinarySearch (arr, num, mid+1, end);
		}
		
		else if (num < arr[mid])
		{
		BinarySearch (arr, num, beg , mid-1);
		}	
	}
}

int main()
{
	int arr[100], num, i, n, beg, end;
 
	cout <<"\nEnter the size of an array (Max 100): ";
	cin >> n;
 
	cout <<"\nEnter the sorted values: ";
 
	for(i=0; i<n; i++)
	{
		cin >> arr[i];
	}
 
	cout <<"\nEnter a value to be search: ";
	cin >> num;
 
	beg = 0;
	end = n-1;
 
	BinarySearch (arr, num, beg, end);
 
	return 0;
}