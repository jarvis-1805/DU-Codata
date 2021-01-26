#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

int i,j,k;
void insertionSort(int*, int);

int main()
{
	int size,ele;
	
	cout << "\nEnter the size of array: ";
	cin >> size;
	
	int array[size];
	
	cout << "\nWORST CASE:";
	cout << "\n-------------\n";
	for(i=0; i<size; i++)
		array[i] = size - i;
	
	insertionSort(array, size);
	
	cout << "\n\nBEST CASE:";
	cout << "\n-------------\n";
	for(i=0; i<size; i++)
		array[i] = i+1;
	
	insertionSort(array, size);
	
	cout << "\n\nAVERAGE CASE:";
	cout << "\n-------------\n";
	for(i=0; i<size; i++)
	{
		ele = ((int)rand()%10);
		if(ele == 0)
			continue;
		else
			array[i] = ele;
	}
	
	insertionSort(array, size);
	
	return 0;
}

void insertionSort(int* array, int size)
{
	int temp=0;
	int ctr = 0;
	int totalCom = 0;
	
	cout << "Array: ";
	for(i=0; i<size; i++)
		cout << array[i] << " ";
	cout << endl << endl;
	
	for(i=1; i<size; i++)
	{
		temp = array[i];
		ctr = 0;
		for(j=i-1; j>=0; j--)
		{
			ctr++;
			totalCom++;
			if(array[j] > temp)
			{
				array[j+1] = array[j];
			}
			else
				break;
		}
		array[j+1] = temp;
		cout << "After pass " << i << ": ";
		for(k=0; k<size; k++)
			cout << array[k] << " ";
				cout << "\nComparisions made in pass " << i << ": " << ctr;
		cout << endl << endl;
	}
	cout << "Total comparisions: "  << totalCom;
}