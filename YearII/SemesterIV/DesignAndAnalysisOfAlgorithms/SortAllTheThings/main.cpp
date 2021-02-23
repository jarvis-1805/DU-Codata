#include <iostream>
#include <fstream>

//#include "Plot_Graphs/matplotlibcpp.h"
//#include "Insertion_Sort/insertionSort.hpp"
//#include "Merge_Sort/mergeSort.hpp"
//#include "Heap_Sort/heapSort.hpp"
#include "Quick_Sort/quickSort.hpp"

#define MAX 1001        //Array indexing starts from 1, 2, 3...

using namespace std;

class Sortings
{
    private:
        int size;
        int array[MAX];
        
    public:
        int ch;
        void options();
        int choice();
        void choiceCalling(int);

        void best_case(int);
        void average_case(int);
        void worst_case(int);

        void insertion_sort();
        void merge_sort();
        void heap_sort();
        void quick_sort();

        void file_writer(string, string, int);
};

void Sortings::options()
{
    cout << "\n------- MENU -------";
    cout << "\n1. INSERTION SORT"
        << "\n2. MERGE SORT"
        << "\n3. HEAP SORT"
        << "\n4. QUICK SORT"
        << "\n0. EXIT";
}

int Sortings::choice()
{
    cout << "\n\nEnter the number of your choice: ";
    cin >> ch;
    return ch;
}

void Sortings::choiceCalling(int ch)
{
    int key;
    switch(ch)
    {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            quick_sort();
            break;
        case 0:
            break;
        default:
            cout << "\n########### WRONG CHOICE... ###########\n";
    }
}

void Sortings::best_case(int size)
{
    for(int i=1; i<=size; i++)
        array[i] = i;
}

void Sortings::average_case(int size)
{
    // Generating randomm numbers in the array
    for(int i=1; i<=size; i++)
        array[i] = rand() % 1000;
}

void Sortings::worst_case(int size)
{
    for(int i=1; i<=size; i++)
        array[i] = size - i;
}

void Sortings::file_writer(string fileName, string Case, int comparisons)
{
    ofstream fout;
    
    fout.open(fileName, ios::app);

    if(Case != "worst")
        fout << comparisons << ", ";
    else
        fout << comparisons << endl;

    fout.close();
}

void Sortings::quick_sort()
{
    Quick_Sort quick;
    ofstream fout;

    cout << "\n=========== QUICK SORT ===========";
    
    fout.open("Quick_Sort/comp.csv", ios::app);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        best_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "best", comparisons);
        
        // Average Case
        average_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "average", comparisons);
        
        // Worst Case
        worst_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "worst", comparisons);
    }

    cout << "\nCompleted QUICK SORT!\n";
}

int main()
{
    int choice;
    Sortings sort;
    do
    {
        cout << "\n=========== SORTING TECHNIQUES ===========\n";
        sort.options();
        choice = sort.choice();
        if(sort.ch == 0)
            break;
        system("clear");
        cout << "\n=========== SORTING TECHNIQUES ===========\n";
        sort.choiceCalling(choice);
        cout << "\nPress Enter to continue...";
        cin.ignore();
        getchar();
        system("clear");
    }while(1);
    
    return 0;
}