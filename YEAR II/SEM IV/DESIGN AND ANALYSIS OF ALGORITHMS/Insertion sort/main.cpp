#include <iostream>
#include <cstdlib>

using namespace std;

int i, j, k;
void insertion_sort(int*, int);

int main()
{
    int n;
    cout << "\nEnter the size: ";
    cin >> n;
    int array[n];
    
    //Best Case
    for(int i=0; i<n; i++)
        array[i] = i;
    cout << "\nBEST CASE:\n=========";
    insertion_sort(array, n);
    
    //Average Case
    //Generating randomm numbers in the array
    for(int i=0; i<n; i++)
        array[i] = rand() % 1000;
    cout << "\nAVERAGE CASE:\n=========";
    insertion_sort(array, n);
        
    //Worst Case
    for(i=0; i<n; i++)
		array[i] = n - i;
    cout << "\nWORST CASE:\n=========";
    insertion_sort(array, n);

    return 0;
}

void insertion_sort(int *array, int n)
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
}