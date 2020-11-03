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
        void lower_triangular_matrix(lowerTriangular, int);
        void upper_triangular_matrix(upperTriangular, int);
        void symmetric_matrix(symmetric, int);
};

void matrixNarray::options()
{
    cout << "\n----------- MENU -----------";
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
            cout << "\n======= DIAGONAL MATRIX ======\n";
            int c;
            diagonal d;
            system("clear");
            while(true)
            {
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n======= DIAGONAL MATRIX ======\n";
                sub_options();
                c = choice();
                if(c == 0)
                {
                    delete[] d.array;
                    break;
                }
                system("clear");
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n======= DIAGONAL MATRIX ======\n";
                diagonal_matrix(d, c);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                getchar();
                system("clear");
            }
        }
            break;
        case 2:
        {
            cout << "\n=== LOWER TRIANGULAR MATRIX ===\n";
            int c;
            lowerTriangular l;
            system("clear");
            while(true)
            {
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n=== LOWER TRIANGULAR MATRIX ===\n";
                sub_options();
                c = choice();
                if(c == 0)
                {
                    delete[] l.array;
                    break;
                }
                system("clear");
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n=== LOWER TRIANGULAR MATRIX ===\n";
                lower_triangular_matrix(l, c);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                getchar();
                system("clear");
            }
        }
            break;
        case 3:
        {
            cout << "\n=== UPPER TRIANGULAR MATRIX ===\n";
            int c;
            upperTriangular u;
            system("clear");
            while(true)
            {
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n=== UPPER TRIANGULAR MATRIX ===\n";
                sub_options();
                c = choice();
                if(c == 0)
                {
                    delete[] u.array;
                    break;
                }
                system("clear");
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n=== UPPER TRIANGULAR MATRIX ===\n";
                upper_triangular_matrix(u, c);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                getchar();
                system("clear");
            }
        }
            break;
        case 4:
        {
            cout << "\n====== SYMMETRIC MATRIX =====\n";
            int c;
            symmetric s;
            system("clear");
            while(true)
            {
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n====== SYMMETRIC MATRIX =====\n";
                sub_options();
                c = choice();
                if(c == 0)
                {
                    delete[] s.array;
                    break;
                }
                system("clear");
                cout << "\n=========== MATRIX 1D ===========\n";
                cout << "\n====== SYMMETRIC MATRIX =====\n";
                symmetric_matrix(s, c);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                getchar();
                system("clear");
            }
        }
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
        cout << "\nDiagonal Matrix\n===============\n";
        d.show();
    }
    else if(c == 0)
        return;
    else
        cout << "\n########### WRONG CHOICE... ###########\n";
}

void matrixNarray::lower_triangular_matrix(lowerTriangular l, int c)
{
    if(c == 1)
    {
        int row, column, key;
        cout << "\nEnter the retrieval Row: ";
        cin >> row;
        cout << "Enter the retrieval comlumn: ";
        cin >> column;
        key = l.retrieve(row, column);
        if(key != -99999)
            cout << "\nRetrieved key at row " << row << " and column " << column << ": " << key << endl;
    }
    else if(c == 2)
    {
        cout << "\nLower Triangular Matrix\n=======================\n";
        l.show();
    }
    else if(c == 0)
        return;
    else
        cout << "\n########### WRONG CHOICE... ###########\n";
}

void matrixNarray::upper_triangular_matrix(upperTriangular u, int c)
{
    if(c == 1)
    {
        int row, column, key;
        cout << "\nEnter the retrieval Row: ";
        cin >> row;
        cout << "Enter the retrieval comlumn: ";
        cin >> column;
        key = u.retrieve(row, column);
        if(key != -99999)
            cout << "\nRetrieved key at row " << row << " and column " << column << ": " << key << endl;
    }
    else if(c == 2)
    {
        cout << "\nUpper Triangular Matrix\n=======================\n";
        u.show();
    }
    else if(c == 0)
        return;
    else
        cout << "\n########### WRONG CHOICE... ###########\n";
}

void matrixNarray::symmetric_matrix(symmetric s, int c)
{
    if(c == 1)
    {
        int row, column, key;
        cout << "\nEnter the retrieval Row: ";
        cin >> row;
        cout << "Enter the retrieval comlumn: ";
        cin >> column;
        key = s.retrieve(row, column);
        if(key != -99999)
            cout << "\nRetrieved key at row " << row << " and column " << column << ": " << key << endl;
    }
    else if(c == 2)
    {
        cout << "\nSymmetric Matrix\n================\n";
        s.show();
    }
    else if(c == 0)
        return;
    else
        cout << "\n########### WRONG CHOICE... ###########\n";
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