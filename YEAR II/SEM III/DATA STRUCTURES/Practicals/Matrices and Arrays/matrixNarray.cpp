#include <iostream>
#define MAX 100

using namespace std;

class matrixNarray
{
    public:
        int array[MAX];
        int size;
        int ch;

        matrixNarray();
        ~matrixNarray();

        void options();
		int choice();
		void choiceCalling(int);

        void diagonal_matrix();
        void lower_triangular_matrix();
        void upper_triangular_matrix();
        void symmetric_matrix();

        void store(int, int, int);
        void retrieve(int, int);
        void show();
};

matrixNarray::matrixNarray()
{
    size = 0;
}

matrixNarray::~matrixNarray()
{
    delete []array;
}

void matrixNarray::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. DIAGONAL MATRIX"
		<< "\n2. LOWER TRIANGULAR MATRIX"
		<< "\n3. UPPER TRIANGULAR MATRIX"
		<< "\n4. SYMMETRIC MATRIX"
		<< "\n5. DISPLAY"
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
	int key;
    switch(ch)
	{
		case 1:
            cout << "\nEnter the Data: ";
            cin >> key;
			break;
		case 2:
            cout << "\nEnter the Data: ";
            cin >> key;
			break;
		case 3:
            break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

int main()
{
    int choice;
	matrixNarray ob;
	do
	{
		cout << "\n=========== MATRIX 1D ===========\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		system("clear");
		cout << "\n=========== MATRIX 1D ===========\n";
		ob.choiceCalling(choice);
		cout << "\nPress Enter to continue...";
		cin.ignore();
		getchar();
		system("clear");
	}while(1);
	
	return 0;
}