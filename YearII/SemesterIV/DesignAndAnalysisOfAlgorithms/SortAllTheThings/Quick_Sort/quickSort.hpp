#include <tuple> 

class Quick_Sort
{
    public:
        int quick_sort(int *, int, int);
        std::tuple <int, int>partition(int *, int, int);

        int *swap(int *, int, int);
};

int Quick_Sort::quick_sort(int *array, int startIndex, int endIndex)
{
    int comparisons=0;
    if(startIndex < endIndex)
    {
        int pivotIndex, comparisonFromPartition;
        std::tie(pivotIndex, comparisonFromPartition) = partition(array, startIndex, endIndex);
        comparisons += comparisonFromPartition;
        comparisons += quick_sort(array, startIndex, pivotIndex - 1);
        comparisons += quick_sort(array, pivotIndex + 1, endIndex);
    }

    return comparisons;
}

std::tuple <int, int>Quick_Sort::partition(int *array, int startIndex, int endIndex)
{
    int comparisons = 0;
    int pivot = array[endIndex];
    int i = (startIndex -1);

    for(int j=startIndex; j<=endIndex-1; j++)
    {
        if(array[j] < pivot)
        {
            comparisons++;
            i++;
            array = swap(array, i, j);
        }
    }
    array = swap(array, i+1, endIndex);
    return std::make_tuple(i+1, comparisons);
}

int *Quick_Sort::swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    return array;
}