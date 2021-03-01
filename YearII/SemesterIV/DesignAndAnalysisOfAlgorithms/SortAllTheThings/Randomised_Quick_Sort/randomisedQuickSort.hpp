#include <tuple> 

class Randomised_Quick_Sort
{
    public:
        int randomised_quick_sort(int *, int, int);
        std::tuple <int, int>randomised_partition(int *, int, int);
        std::tuple <int, int>partition(int *, int, int);

        int random(int, int);
        int *swap(int *, int, int);
};

int Randomised_Quick_Sort::randomised_quick_sort(int *array, int startIndex, int endIndex)
{
    int comparisons=0;
    if(startIndex < endIndex)
    {
        int pivotIndex, comparisonFromPartition;
        std::tie(pivotIndex, comparisonFromPartition) = randomised_partition(array, startIndex, endIndex);
        comparisons += comparisonFromPartition;
        comparisons += randomised_quick_sort(array, startIndex, pivotIndex - 1);
        comparisons += randomised_quick_sort(array, pivotIndex + 1, endIndex);
    }

    return comparisons;
}

std::tuple <int, int>Randomised_Quick_Sort::randomised_partition(int *array, int startIndex, int endIndex)
{
    int pivotIndex = random(startIndex, endIndex);
    array = swap(array, endIndex, pivotIndex);
    return partition(array, startIndex, endIndex);
}

std::tuple <int, int>Randomised_Quick_Sort::partition(int *array, int startIndex, int endIndex)
{
    int comparisons = 0;
    int pivot = array[endIndex];
    int i = (startIndex -1);

    for(int j=startIndex; j<=endIndex-1; j++)
    {
        comparisons++;
        if(array[j] < pivot)
        {
            i++;
            array = swap(array, i, j);
        }
    }
    array = swap(array, i+1, endIndex);
    return std::make_tuple(i+1, comparisons);
}

int Randomised_Quick_Sort::random(int startIndex, int endIndex)
{
    srand(time(NULL));
    return (startIndex + rand() % (endIndex - startIndex));
}

int *Randomised_Quick_Sort::swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    return array;
}