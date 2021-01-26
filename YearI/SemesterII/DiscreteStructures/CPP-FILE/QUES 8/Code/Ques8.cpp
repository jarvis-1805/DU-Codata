#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

int i,j,k;
void bubbleSort(int*, int);

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
	
	bubbleSort(array, size);
	
	cout << "\n\nBEST CASE:";
	cout << "\n-------------\n";
	for(i=0; i<size; i++)
		array[i] = i+1;
	
	bubbleSort(array, size);
	
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
	
	bubbleSort(array, size);
	
	return 0;
}

void bubbleSort(int *array, int size)
{
	int temp = 0;
	int ctr = 0;
	int totalCom = 0;
	
	cout << "Array: ";
	for(i=0; i<size; i++)
		cout << array[i] << " ";
	cout << endl << endl;
	
	for(i=0; i<size-1; i++)
	{
		ctr = 0;
		for(j=0; j<size-i-1; j++)
		{
			if(array[j+1] < array[j])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
			ctr++;
			totalCom++;
		}
		cout << "After pass " << i+1 << ": ";
		for(k=0; k<size; k++)
			cout << array[k] << " ";
		cout << "\nComparisions made in pass " << i+1 << ": " << ctr;
		cout << endl << endl;
	}
	
	cout << "Total comparisions: "  << totalCom;
}