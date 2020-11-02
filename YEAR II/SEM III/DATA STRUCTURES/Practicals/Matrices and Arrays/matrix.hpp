#include <iostream>
#define MAX 100

using namespace std;

class diagonal
{
	private:
		int rows;
        int columns;
        int *array = new int[MAX];

    public:
        diagonal();
        ~diagonal();

        void store(int, int, int);
        int retrieve(int, int);
        void show();
};

class lowerTriangular
{
	private:
		int rows;
        int columns;
        int array[MAX];
        
    lowerTriangular();
};

class upperTriangular
{
	private:
		int rows;
        int columns;
        int array[MAX];
        
    upperTriangular();
};

class symmetric
{
	private:
		int rows;
        int columns;
        int array[MAX];
        
    symmetric();
};

diagonal::diagonal()
{
    int key;
    label:
        cout << "\nEnter the number of rows: ";
        cin >> rows;
        cout << "\nEnter the number of columns: ";
        cin >> columns;
    if(rows != columns)
    {
        cout << "\nRows and Columns must be equal!\n";
        goto label;
    }
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cout << "\nRow " << i+1 << "\nColumn " <<  j+1;
            cout << "\nEnter the data: ";
            cin >> key;
            store(key, i, j);
        }
    }
}

diagonal::~diagonal()
{
    delete []array;
}

void diagonal::store(int key, int i, int j)
{
    if(i != j && key != 0)
        cout << "\nData must be zero!\nTry again!";
    else if(i == j)
        array[i] = key;
}

int diagonal::retrieve(int row, int column)
{
    if(row < 0 || column < 0 || row > rows || column > columns)
        cout << "\nInvalid Entry!/nTry againg!";
    else if(row == column)
        return array[row];
    else
        return 0;
}

void diagonal::show()
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(i == j)
                cout << array[i] << "\t";
            else
                cout << "0\t";
        }
        cout << endl;
    }
}