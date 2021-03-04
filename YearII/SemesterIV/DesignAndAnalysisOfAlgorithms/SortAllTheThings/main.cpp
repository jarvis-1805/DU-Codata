#include <iostream>
#include <fstream>
#include <vector>

//#include "Plot_Graphs/matplotlibcpp.h"
#include "Other_Headers/BinarySearchTree.hpp"
#include "Insertion_Sort/insertionSort.hpp"
//#include "Merge_Sort/mergeSort.hpp"
//#include "Heap_Sort/heapSort.hpp"
#include "Quick_Sort/quickSort.hpp"
#include "Randomised_Quick_Sort/randomisedQuickSort.hpp"
#include "Counting_Sort/countingSort.hpp"
#include "Radix_Sort/radixSort.hpp"
#include "Bucket_Sort/bucketSort.hpp"

#define MAX 1000        //Array indexing starts from 1, 2, 3...

using namespace std;

class Sortings
{
    private:
        int size;
        int array[MAX];
        float array2[MAX];
        std::string array3[MAX];
        
    public:
        int ch;
        void options();
        int choice();
        void choiceCalling(int);

        void best_case(int);
        void average_case(int);
        void worst_case(int);

        void insertion_sort(int *);
        void merge_sort();
        void heap_sort();
        void quick_sort(int *);
        void randomised_quick_sort(int *);
        void counting_sort(int *);
        void radix_sort(int *);
        void radix_sort(std::string *);
        void bucket_sort(float *);
        void bucket_sort(int *);

        void input(int *);
        void input(std::string *);
        void input(float *);
        void display(int *, int);
        void display(std::string *, int);
        void display(float *, int);
        void file_writer(string, string, int);
};

void Sortings::options()
{
    cout << "\n------- MENU -------";
    cout << "\n1. INSERTION SORT"
        << "\n2. MERGE SORT"
        << "\n3. HEAP SORT"
        << "\n4. QUICK SORT"
        << "\n5. RANDOMISED QUICK SORT"
        << "\n6. COUNTING SORT"
        << "\n7. RADIX SORT (Integer)"
        << "\n8. RADIX SORT (String)"
        << "\n9. BUCKET SORT (Float 0-1)"
        << "\n10. BUCKET SORT (Integer)"
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
            insertion_sort(array);
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            quick_sort(array);
            break;
        case 5:
            randomised_quick_sort(array);
            break;
        case 6:
            counting_sort(array);
            break;
        case 7:
            radix_sort(array);
            break;
        case 8:
            radix_sort(array3);
            break;
        case 9:
            bucket_sort(array2);
            break;
        case 10:
            bucket_sort(array);
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

void Sortings::insertion_sort(int *array)
{
    Insertion_Sort insert;
    ofstream fout;

    cout << "\n=========== INSERTION SORT ===========";

    fout.open("Insertion_Sort/comp.csv", ios::trunc);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();

    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        best_case(size);

        comparisons = insert.insertion_sort(array, size);
        file_writer("Insertion_Sort/comp.csv", "best", comparisons);
        
        //Average Case
        average_case(size);

        comparisons = insert.insertion_sort(array, size);
        file_writer("Insertion_Sort/comp.csv", "average", comparisons);
            
        //Worst Case
        worst_case(size);

        comparisons = insert.insertion_sort(array, size);
        file_writer("Insertion_Sort/comp.csv", "worst", comparisons);
    }
    
    cout << "\nCompleted INSERTION SORT!\n";
}

void Sortings::quick_sort(int *array)
{
    Quick_Sort quick;
    ofstream fout;

    cout << "\n=========== QUICK SORT ===========";
    
    fout.open("Quick_Sort/comp.csv", ios::trunc);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        /**
         * @brief We use Binary Search Tree to construct post-order of sorted array in ascending
         *        order. Since post-order partitions' the array in exactly two halves, i.e.,
         *        from the median.
         * 
         *        Time Complexity: O(nlog(n))
         * 
         */
        binarySearchTree binary;
        best_case(size);
        array = binary.itr_post_order(array, size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "best", comparisons);
        
        // Average Case:    Time Complexity: O(nlog(n))
        average_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "average", comparisons);
        
        // Worst Case
        /**
         * @brief The worst case occurs when the partition process always picks greatest or
         *        smallest element as pivot. If we consider above partition strategy where
         *        last element is always picked as pivot, the worst case would occur when the
         *        array is already sorted in increasing or decreasing order.
         * 
         *        Time Complexity: O(n^2)
         * 
         */
        worst_case(size);
        
        comparisons = quick.quick_sort(array, 1, size);
        file_writer("Quick_Sort/comp.csv", "worst", comparisons);
    }

    cout << "\nCompleted QUICK SORT!\n";
}

void Sortings::randomised_quick_sort(int *array)
{
    Randomised_Quick_Sort random_quick;
    ofstream fout;

    cout << "\n=========== QUICK SORT ===========";
    
    fout.open("Randomised_Quick_Sort/comp.csv", ios::trunc);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(size=10; size<=1000; size=size+10)
    {
        int comparisons = 0;
        for(int i=0; i<=size; i++)
            array[i] = 0;

        //Best Case
        binarySearchTree binary;
        best_case(size);
        array = binary.itr_post_order(array, size);
        
        comparisons = random_quick.randomised_quick_sort(array, 1, size);
        file_writer("Randomised_Quick_Sort/comp.csv", "best", comparisons);
        
        // Average Case
        average_case(size);
        
        comparisons = random_quick.randomised_quick_sort(array, 1, size);
        file_writer("Randomised_Quick_Sort/comp.csv", "average", comparisons);
        
        // Worst Case
        worst_case(size);
        
        comparisons = random_quick.randomised_quick_sort(array, 1, size);
        file_writer("Randomised_Quick_Sort/comp.csv", "worst", comparisons);
    }

    cout << "\nCompleted RANDOMISED QUICK SORT!\n";
}

void Sortings::counting_sort(int *array)
{
    cout << "\n=========== COUNTING SORT ===========";

    input(array);
    
    Counting_Sort counting;
    array = counting.counting_sort(array, size);
    
    display(array, size);

    cout << "\nCompleted COUNTING SORT!\n";
}

void Sortings::radix_sort(int *array)
{
    cout << "\n=========== RADIX SORT (Integer) ===========";

    input(array);
    
    Radix_Sort radix;
    array = radix.radix_sort(array, size);
    
    display(array, size);

    cout << "\nCompleted RADIX SORT!\n";
}

void Sortings::radix_sort(std::string *array3)
{
    cout << "\n=========== RADIX SORT (String) ===========";

    input(array3);
    
    Radix_Sort radix;
    array3 = radix.radix_sort(array3, size);
    
    display(array3, size);

    cout << "\nCompleted RADIX SORT!\n";
}

void Sortings::bucket_sort(float *array2)
{
    cout << "\n=========== BUCKET SORT ===========";

    input(array2);
    
    Bucket_Sort bucket;
    array2 = bucket.bucket_sort(array2, size);
    
    display(array2, size);

    cout << "\nCompleted BUCKET SORT!\n";
}

void Sortings::bucket_sort(int *array)
{
    cout << "\n=========== BUCKET SORT ===========";

    input(array);
    
    Bucket_Sort bucket;
    array = bucket.bucket_sort(array, size);
    
    display(array, size);

    cout << "\nCompleted BUCKET SORT!\n";
}

void Sortings::input(int *array)
{
    cout << "\nEnter the size of array: ";
    cin >> size;

    cout << "\nEnter the elements in the array:\n";
    for(int i=0; i<size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> array[i];
    }
}

void Sortings::input(float *array2)
{
    cout << "\nEnter the size of array: ";
    cin >> size;

    cout << "\nEnter the elements in the array:\n";
    for(int i=0; i<size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> array2[i];
    }
}

void Sortings::input(std::string *array3)
{
    cout << "\nEnter the size of array: ";
    cin >> size;

    cout << "\nEnter the elements in the array:\n";
    for(int i=0; i<size; i++)
    {
        cout << "Element " << i+1 << ": ";
        cin >> array3[i];
    }
}

void Sortings::display(int *array, int size)
{
    cout << "Array: ";
    for(int i=0; i<size; i++)
    {
        cout << array[i];
        if(i != size-1)
            cout << ", ";
        else
            cout << endl;
    }
}

void Sortings::display(float *array2, int size)
{
    cout << "Array: ";
    for(int i=0; i<size; i++)
    {
        cout << array2[i];
        if(i != size-1)
            cout << ", ";
        else
            cout << endl;
    }
}

void Sortings::display(std::string *array3, int size)
{
    cout << "Array: ";
    for(int i=0; i<size; i++)
    {
        cout << array3[i];
        if(i != size-1)
            cout << ", ";
        else
            cout << endl;
    }
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