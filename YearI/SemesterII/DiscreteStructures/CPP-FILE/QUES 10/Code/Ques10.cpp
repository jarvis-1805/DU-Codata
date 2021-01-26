#include<iostream>
#include<stdio.h>
#include<conio.h>
#define MAX_DIM 100

using namespace std;


void withRepetition(int*, int);
void withoutRepetition(int*, int);
void printWithRepetition(int*, int, int*, int, int);
void printWithoutRepetition(int*, int, int, int);
void swap(int &, int &);

int main()
{
	int size;
	char ch;
	
	cout << "Enter the size of set: ";
	cin >> size;
	
	int array[MAX_DIM];
	cout << "Enter the elements: ";
	for(int i=0; i<size; i++)
		cin >> array[i];
	
	cout << "\nIs repetition allowed (Y/N): ";
	cin >> ch;
	
	switch(ch)
	{
		case 'Y':
			withRepetition(array, size);
			break;
		case 'N':
			withoutRepetition(array, size);
			break;
		default:
			cout << "\nWrong Choice";
	}
		
	return 0;
}

void withRepetition(int* array, int size)
{
	int data[MAX_DIM] = {0};
	printWithRepetition(array, size, data, size-1, 0);
	cout << endl;
}

void printWithRepetition(int* array, int size, int *data, int last, int index)
{
	for(int i=0; i<size; i++)
	{
		data[index] = array[i];
		if(index == last)
		{
			cout << "{";
			for(int j=0; j<index+1; j++)
				cout << data[j] << " ";
			cout << "}";
		}
		
		else
		{
			printWithRepetition(array, size, data, last, index+1);
		}
	}
}

void withoutRepetition(int* array, int size)
{
	printWithoutRepetition(array, size, 0, size-1);
	cout << endl;
}

void printWithoutRepetition(int* array, int size, int start, int end)
{
	if(start == end)
	{
		cout << "{";
		for(int i=0; i<size; i++)
			cout << array[i] << " ";
		cout << "}";
	}
	
	else
	{
		for(int i=start; i<end+1; i++)
		{
			swap(array[start], array[i]);
			printWithoutRepetition(array, size, start+1, end);
			swap(array[start], array[i]);
		}
	}
}

void swap(int &a, int &b)
{
	int t = b;
	b = a;
	a = t;
}