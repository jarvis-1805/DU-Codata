#include <algorithm>
#pragma once

class Counting_Sort
{
    private:
        int max, min;
        int range;

    public:
        Counting_Sort();

        int *counting_sort(int *, int);
        int *counting_sort(int *, int, int);
        std::string *counting_sort(std::string *, int, int);
};

Counting_Sort::Counting_Sort()
{
    max = 0;
    min = 0;
}

int *Counting_Sort::counting_sort(int *array, int size)
{
    max = *std::max_element(array, array + size);
    min = *std::min_element(array, array + size);
    range = max - min + 1;

    int count[range];
    int output[size];

    for(int i=0; i<range; i++)
        count[i] = 0;

    for(int i=0; i<size; i++)
        count[array[i] - min]++;
    
    for(int i=1; i<range; i++)
        count[i] += count[i-1];
    
    for(int i=size-1; i>=0; i--)
    {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    for (int i=0; i<size; i++)
        array[i] = output[i];

    return array;
}

int *Counting_Sort::counting_sort(int *array, int size, int place)
{
    int output[size];
    int count[10] = {0};

    for(int i=0; i<size; i++)
        count[(array[i] / place) % 10]++;

    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    for(int i=size-1; i>=0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i=0; i<size; i++)
        array[i] = output[i];

    return array;
}

std::string *Counting_Sort::counting_sort(std::string *array, int length, int place)
{
    int count[256] = {0};
    std::string output[length];

    for(int i=0; i<length; i++)
        count[array[i][place] + 1]++;

    for (int i=1; i<256; i++)
        count[i] += count[i-1];

    for(int i=0; i<length; i++)
        output[count[array[i][place]]++] = array[i];

    for (int i=0; i<length; i++)
        array[i] = output[i];

    return array;
}