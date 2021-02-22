#include <iostream>
#include <fstream>

using namespace std;

int i, j, k;
int insertion_sort(int *, int);

int main()
{
    
    ofstream fout;

    int n, comparisions;
    cout << "\n=========== INSERTION SORT ===========";
    
    fout.open("comp.csv", ios::app);
    fout << "Best, " << "Average, " << "Worst\n";
    fout.close();

    for(n=10; n<=1000; n=n+10)
    {
        cout << "\nSize: " << n;
        int array[n];
        
        //Best Case
        for(i=0; i<n; i++)
            array[i] = i;
        cout << "\nBEST CASE:\n=========";
        comparisions = insertion_sort(array, n);

        fout.open("comp.csv", ios::app);
        fout << comparisions << ", ";
        fout.close();
        
        //Average Case
        //Generating randomm numbers in the array
        for(i=0; i<n; i++)
            array[i] = rand() % 1000;
        cout << "\nAVERAGE CASE:\n=========";
        comparisions = insertion_sort(array, n);

        fout.open("comp.csv", ios::app);
        fout << comparisions << ", ";
        fout.close();
            
        //Worst Case
        for(i=0; i<n; i++)
            array[i] = n - i;
        cout << "\nWORST CASE:\n=========";
        comparisions = insertion_sort(array, n);

        fout.open("comp.csv", ios::app);
        fout << comparisions << "\n";
        fout.close();
    }

    return 0;
}

int insertion_sort(int *array, int n)
{
    int totalComp = 0;
    for(i=1; i<n; i++)
    {
        int key = array[i];
        int ctr = 0;

        for(j=i-1; j>=0; j--)
        {
            ctr++;
            totalComp++;
            if(key < array[j])
                array[j+1] = array[j];
            else
                break;
        }
        cout << "\nComparisions made in pass " << i << ": " << ctr;
        array[j+1] = key;
    }
    cout << "\nTotal comparisions: "  << totalComp << endl;

    return totalComp;
}