#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

class Heap_Sort
{
    public:
        int i;
        int size = 10;
        int comparisions;

        void best_case(int *);
        void average_case(int *);
        void worst_case(int *);

        int max_heapify(int *, int);
        int build_max_heap(int *);
        int heap_sort(int *);

        int *swap(int *, int, int);
        void display(int *);
};

void Heap_Sort::best_case(int *array)
{
    ofstream fout;

    for(i=0; i<size; i++)
        array[i] = i;
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

void Heap_Sort::average_case(int *array)
{
    ofstream fout;

    // Generating randomm numbers in the array
    for(i=0; i<size; i++)
        array[i] = rand() % 1000;
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

void Heap_Sort::worst_case(int *array)
{
    ofstream fout;

    for(i=0; i<size; i++)
        array[i] = size - i;
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
    int maxim;

    if(left <= size && array[left] > array[i])
        maxim = left;
    else
        maxim = i;
    
    if(right <= size && array[right] > array[maxim])
        maxim = right;
    
    if(maxim != i)
    {
        array = swap(array, maxim, i);
        max_heapify(array, maxim);
    }
}

int Heap_Sort::build_max_heap(int *array)
{
    for(int i=floor(size/2); i>=1; i--)
        max_heapify(array, i);
}

int Heap_Sort::heap_sort(int *array)
{
    int s = size;
    build_max_heap(array);
    for(int i=size; i>=2; i--)
    {
        array = swap(array, 1, i);
        size--;
        max_heapify(array, 1);
    }
    size = s;

    return 0;
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
        for(int x=0; x<size; x++)
            cout << array[x] << " ";
    else
        cout << "Empty!";
    cout << endl;
}

int main()
{
    ofstream fout;
    Heap_Sort hs;

    int i, comparisions;
    cout << "\n=========== HEAP SORT ===========";
    
    fout.open("comp.csv", ios::app);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    //for(hs.size=10; hs.size<=10; hs.size=hs.size+10)
    //{
        cout << "\nSize: " << hs.size;
        int array[hs.size];
        for(i=0; i<10; i++)
            array[i] = 0;

        //Best Case
        hs.best_case(array);
        
        // Average Case
        hs.average_case(array);
        
        // Worst Case
        hs.worst_case(array);
    //}
    
    return 0;
}

/*
int merge(int *array, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    int i=0, j=0, k=l;
    int comparisions = 0;

    while(i < n1 && j < n2)
    {
        comparisions += 1;
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }

    return comparisions;
}

int merge_sort(int *array, int si, int ei)
{
    // si => start index
    // ei => end index
    if(si >= ei)
        return 0;
    
    int mid = (si+ei-1)/2;
    int comparisions = 0;

    comparisions += merge_sort(array, si, mid);
    comparisions += merge_sort(array, mid+1, ei);

    comparisions += merge(array, si, mid, ei);

    return comparisions;
}*/