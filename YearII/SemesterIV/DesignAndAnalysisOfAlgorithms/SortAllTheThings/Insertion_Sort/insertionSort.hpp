#include <vector>
#pragma once

class Insertion_Sort
{
    public:
        int insertion_sort(int *, int);
        void insertion_sort(std::vector<float> &, int);
        void insertion_sort(std::vector<int> &, int);
};

int Insertion_Sort::insertion_sort(int *array, int n)
{
    int i, j, totalComp = 0;
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
        array[j+1] = key;
    }

    return totalComp;
}

void Insertion_Sort::insertion_sort(std::vector<float> &array, int size)
{
    int i, j;
    float temp;

    for (i=1; i<size; i++)
    {
        j = i;
        temp = array[i];
        while(j > 0 && temp < array[j - 1])
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}

void Insertion_Sort::insertion_sort(std::vector<int> &array, int size)
{
    int i, j;
    int temp;

    for (i=1; i<size; i++)
    {
        j = i;
        temp = array[i];
        while(j > 0 && temp < array[j - 1])
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}