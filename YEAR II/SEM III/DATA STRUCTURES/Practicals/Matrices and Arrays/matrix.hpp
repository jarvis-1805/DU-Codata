#include <iostream>
#define MAX 100

using namespace std;

class diagonal
{
    private:
        int rows;
        int columns;

    public:
        int *array;

        diagonal();

        bool store(int, int, int);
        int retrieve(int, int);
        void show();
};

class lowerTriangular
{
    private:
        int rows;
        int columns;
    
    public:
        int *array;
        
        lowerTriangular();

        bool store(int, int, int);
        int retrieve(int, int);
        void show();
};

class upperTriangular
{
    private:
        int rows;
        int columns;
    
    public:
        int *array;

        upperTriangular();

        bool store(int, int, int);
        int retrieve(int, int);
        void show();
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
        cout << "Enter the number of columns: ";
        cin >> columns;
    if(rows != columns)
    {
        cout << "\nRows and Columns must be equal!\n";
        goto label;
    }

    array = new int[rows];

    label_1:
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                cout << "\nRow " << i+1 << "\nColumn " <<  j+1;
                cout << "\nEnter the data: ";
                cin >> key;
                if(store(key, i, j))
                    true;
                else
                    goto label_1;
            }
        }
}

bool diagonal::store(int key, int i, int j)
{
    if(i != j && key != 0)
    {
        cout << "\nData must be zero!\nTry again!\n";
        return false;
    }
    else if(i == j)
    {
        array[i] = key;
        return true;
    }
    return true;
}

int diagonal::retrieve(int row, int column)
{
    if(row < 0 || column < 0 || row > rows-1 || column > columns-1)
    {
        cout << "\nInvalid Entry!\nTry again!\n";
        return -99999;
    }
    else if(row == column)
    {
        int key = array[row];
        return key;
    }
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

lowerTriangular::lowerTriangular()
{
    int key;
    label:
        cout << "\nEnter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> columns;
    if(rows != columns)
    {
        cout << "\nRows and Columns must be equal!\n";
        goto label;
    }

    array = new int[rows*(rows+1)/2];

    label_1:
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                cout << "\nRow " << i << "\nColumn " <<  j;
                cout << "\nEnter the data: ";
                cin >> key;
                if(store(key, i, j))
                    true;
                else
                    goto label_1;
            }
        }
}

bool lowerTriangular::store(int key, int i, int j)
{
    if(i < j && key != 0)
    {
        cout << "\nData must be zero!\nTry again!\n";
        return false;
    }
    else if(i >= j)
    {
        int k = (i * (i - 1) / 2 + j - 1);
        array[k] = key;
        return true;
    }
    return true;
}

int lowerTriangular::retrieve(int row, int column)
{
    if(row <= 0 || column <= 0 || row > rows || column > columns)
    {
        cout << "\nInvalid Entry!\nTry again!\n";
        return -99999;
    }
    else if(row < column)
        return 0;
    else
    {
        int key = array[row * (row - 1) / 2 + column - 1];
        return key;
    }
}

void lowerTriangular::show()
{
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=columns; j++)
        {
            if(i < j)
                cout << "0\t";
            else
            {
                int k = (i * (i - 1) / 2 + j - 1);
                cout << array[k] << "\t";
            }
        }
        cout << endl;
    }
}

upperTriangular::upperTriangular()
{
    int key;
    label:
        cout << "\nEnter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> columns;
    if(rows != columns)
    {
        cout << "\nRows and Columns must be equal!\n";
        goto label;
    }

    array = new int[rows*(rows+1)/2];

    label_1:
        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=columns; j++)
            {
                cout << "\nRow " << i << "\nColumn " <<  j;
                cout << "\nEnter the data: ";
                cin >> key;
                if(store(key, i, j))
                    true;
                else
                    goto label_1;
            }
        }
}

bool upperTriangular::store(int key, int i, int j)
{
    if(i > j && key != 0)
    {
        cout << "\nData must be zero!\nTry again!\n";
        return false;
    }
    else if(i <= j)
    {
        int k = (i * (i - 1) / 2 + j - 1);
        array[k] = key;
        return true;
    }
    return true;
}

int upperTriangular::retrieve(int row, int column)
{
    if(row <= 0 || column <= 0 || row > rows || column > columns)
    {
        cout << "\nInvalid Entry!\nTry again!\n";
        return -99999;
    }
    else if(row > column)
        return 0;
    else
    {
        int key = array[row * (row - 1) / 2 + column - 1];
        return key;
    }
}

void upperTriangular::show()
{
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=columns; j++)
        {
            if(i > j)
                cout << "0\t";
            else
            {
                int k = (i * (i - 1) / 2 + j - 1);
                cout << array[k] << "\t";
            }
        }
        cout << endl;
    }
}