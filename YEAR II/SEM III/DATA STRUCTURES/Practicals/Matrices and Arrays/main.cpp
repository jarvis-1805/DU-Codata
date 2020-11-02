#include <iostream>
#include "matrix.hpp"

using namespace std;

class matrixNarray
{
    public:
        int ch;

        void options();
		int choice();
		void choiceCalling(int);
		void sub_options();

        void diagonal_matrix(diagonal, int);
        void lower_triangular_matrix();
        void upper_triangular_matrix();
        void symmetric_matrix();
};

void matrixNarray::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. DIAGONAL MATRIX"
		<< "\n2. LOWER TRIANGULAR MATRIX"
		<< "\n3. UPPER TRIANGULAR MATRIX"
		<< "\n4. SYMMETRIC MATRIX"
		<< "\n0. EXIT";
}

int matrixNarray::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void matrixNarray::choiceCalling(int ch)
{
    switch(ch)
	{
		case 1:
		{
			int c;
			diagonal d;
			while(true)
			{
				sub_options();
				c = choice();
	            diagonal_matrix(d, c);
				if(c == 0)
				{
					delete[] d.array;
					break;
				}
			}
		}
			break;
		case 2:
			lower_triangular_matrix();
			break;
		case 3:
			upper_triangular_matrix();
            break;
		case 4:
			symmetric_matrix();
            break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void matrixNarray::sub_options()
{
	cout << "\n------- SUB MENU -------";
    cout << "\n1. RETRIEVE"
		<< "\n2. DISPLAY"
		<< "\n0. EXIT";
}

void matrixNarray::diagonal_matrix(diagonal d, int c)
{
	if(c == 1)
	{
		int row, column, key;
		cout << "\nEnter the retrieval Row: ";
		cin >> row;
		cout << "Enter the retrieval comlumn: ";
		cin >> column;
		key = d.retrieve(row-1, column-1);
		if(key != -99999)
			cout << "\nRetrieved key at row " << row << " and column " << column << ": " << key << endl;
	}
	else if(c == 2)
	{
		cout << "\nDiagonal matrix\n===============\n";
		d.show();
	}
	else if(c == 0)
		return;
	else
		cout << "\n########### WRONG CHOICE... ###########\n";
}

void matrixNarray::lower_triangular_matrix()
{

}

void matrixNarray::upper_triangular_matrix()
{
	
}

void matrixNarray::symmetric_matrix()
{
	
}
int main()
{
    int choice;
	matrixNarray ob;
	do
	{
		//cout << "\n=========== MATRIX 1D ===========\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		//system("clear");
		//cout << "\n=========== MATRIX 1D ===========\n";
		ob.choiceCalling(choice);
		//cout << "\nPress Enter to continue...";
		//cin.ignore();
		//getchar();
		//system("clear");
	}while(1);
	
	return 0;
}