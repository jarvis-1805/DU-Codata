#include <iostream>
#include <math.h>
#include <fstream>
#define MAX 1001

using namespace std;

class Heap_Sort
{
    public:
        int i;
        int size = 10;
        int array[MAX];

        void best_case();
        void average_case();
        void worst_case();

        int max_heapify(int *, int);
        int build_max_heap(int *);
        int heap_sort(int *);

        int *swap(int *, int, int);
        void display(int *);
};

void Heap_Sort::best_case()
{
    ofstream fout;
    int comparisions;

    for(i=1; i<=size; i++)
        array[i] = i;
    comparisions = 0;
    cout << "\nBEST CASE:\n==========";
    display(array);
    comparisions = heap_sort(array);
    display(array);
    cout << "\nTotal comparisions: "
        << comparisions << endl;
    
    fout.open("comp.csv", ios::app);
    fout << comparisions << ", ";
    fout.close();
}

void Heap_Sort::average_case()
{
    ofstream fout;
    int comparisions;

    // Generating randomm numbers in the array
    for(i=1; i<=size; i++)
        array[i] = rand() % 1000;
    comparisions = 0;
    cout << "\nAVERAGE CASE:\n=============";
    display(array);
    comparisions = heap_sort(array);
    display(array);
    cout << "\nTotal comparisions: "
        << comparisions << endl;
    
    fout.open("comp.csv", ios::app);
    fout << comparisions << ", ";
    fout.close();
}

void Heap_Sort::worst_case()
{
    ofstream fout;
    int comparisions;

    for(i=1; i<=size; i++)
        array[i] = size - i;
    comparisions = 0;
    cout << "\nWORST CASE:\n===========";
    display(array);
    comparisions = heap_sort(array);
    display(array);
    cout << "\nTotal comparisions: "
        << comparisions << endl;
    
    fout.open("comp.csv", ios::app);
    fout << comparisions << "\n";
    fout.close();
}

int Heap_Sort::max_heapify(int *array, int i)
{
    int left = 2*i;
    int right = 2*i + 1;
    int maxim, comparisions = 0;

    comparisions++;
    if(left <= size && array[left] > array[i])
        maxim = left;
    else
        maxim = i;
    
    comparisions++;
    if(right <= size && array[right] > array[maxim])
        maxim = right;
    
    if(maxim != i)
    {
        array = swap(array, maxim, i);
        comparisions += max_heapify(array, maxim);
    }

    return comparisions;
}

int Heap_Sort::build_max_heap(int *array)
{
    int comparisions = 0;
    for(int i=floor(size/2); i>=1; i--)
        comparisions += max_heapify(array, i);
    
    return comparisions;
}

int Heap_Sort::heap_sort(int *array)
{
    int s = size, comparisions = 0;
    comparisions += build_max_heap(array);
    for(int i=size; i>=2; i--)
    {
        array = swap(array, 1, i);
        size--;
        comparisions += max_heapify(array, 1);
    }
    size = s;

    return comparisions;
}

int *Heap_Sort::swap(int *array, int maxim, int i)
{
    int temp = array[maxim];
    array[maxim] = array[i];
    array[i] = temp;

    return array;
}

void Heap_Sort::display(int *array)
{
    cout << "\nArray: ";
    if(size != 0)
        for(int x=1; x<=size; x++)
            cout << array[x] << " ";
    else
        cout << "Empty!";
    cout << endl;
}

int main()
{
    ofstream fout;
    Heap_Sort hs;

    cout << "\n=========== HEAP SORT ===========";
    
    fout.open("comp.csv", ios::app);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(hs.size=10; hs.size<=1000; hs.size=hs.size+10)
    {
        cout << "\nSize: " << hs.size;
        //hs.array[hs.size];
        for(int i=1; i<=hs.size; i++)
            hs.array[i] = 0;

        //Best Case
        hs.best_case();
        
        // Average Case
        hs.average_case();
        
        // Worst Case
        hs.worst_case();
    }
    
    return 0;
}