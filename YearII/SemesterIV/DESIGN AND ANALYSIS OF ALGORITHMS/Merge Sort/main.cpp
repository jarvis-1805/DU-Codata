#include <iostream>
#include <fstream>

using namespace std;

int merge(int *, int, int, int);
int merge_sort(int *, int, int);

int main()
{
    ofstream fout;

    int i, n, comparisions;
    cout << "\n=========== MERGE SORT ===========";
    
    fout.open("comp.csv", ios::app);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();
    
    for(n=10; n<=1000; n=n+10)
    {
        cout << "\nSize: " << n;
        int *array = new int[n];

        //Best Case
        for(i=0; i<n; i++)
            array[i] = i;
        cout << "\nBEST CASE:\n==========";
        comparisions = merge_sort(array, 0, n-1);
        cout << "\nTotal comparisions: "
            << comparisions << endl;
        
        fout.open("comp.csv", ios::app);
        fout << comparisions << ", ";
        fout.close();
        
        // Average Case
        // Generating randomm numbers in the array
        for(i=0; i<n; i++)
            array[i] = rand() % 1000;
        cout << "\nAVERAGE CASE:\n=============";
        comparisions = merge_sort(array, 0, n-1);
        cout << "\nTotal comparisions: "
            << comparisions << endl;
        
        fout.open("comp.csv", ios::app);
        fout << comparisions << ", ";
        fout.close();
        
        // Worst Case
        for(i=0; i<n; i++)
            array[i] = n - i;
        cout << "\nWORST CASE:\n===========";
        comparisions = merge_sort(array, 0, n-1);
        cout << "\nTotal comparisions: "
            << comparisions << endl;
        
        fout.open("comp.csv", ios::app);
        fout << comparisions << "\n";
        fout.close();
    }
    return 0;
}

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
}