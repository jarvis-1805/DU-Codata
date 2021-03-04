#include <vector>
#include <math.h>

#include "../Insertion_Sort/insertionSort.hpp"

class Bucket_Sort
{
    private:
        int hash(int, int, int);

    public:
        float *bucket_sort(float *, int);
        int *bucket_sort(int *, int);
};

float *Bucket_Sort::bucket_sort(float *array, int size)
{
    std::vector<float> buckets[size];

    for(int i=0; i<size; i++)
    {
        int bucket = size * array[i];
        buckets[bucket].push_back(array[i]);
    }

    Insertion_Sort insertion;
    for(int i=0; i<size; i++)
    {
        insertion.insertion_sort(buckets[i], buckets[i].size());
    }

    int index = 0;
    for(int i=0; i<size; i++)
        for(int j=0; j<buckets[i].size(); j++)
            array[index++] = buckets[i][j];

    return array;
}
/*          BUGGY CODE
int *Bucket_Sort::bucket_sort(int *array, int size)
{
    int max = *std::max_element(array, array + size);
    int min = *std::min_element(array, array + size);

    int bucketRange = ceil((max - min) / size);

    std::vector<int> buckets[size];

    for(int i=0; i<size; i++)
    {
        int bucket = hash(array[i], bucketRange, size);
        buckets[bucket].push_back(array[i]);
    }

    Insertion_Sort insertion;
    for(int i=0; i<size; i++)
    {
        insertion.insertion_sort(buckets[i], buckets[i].size());
    }

    int index = 0;
    for(int i=0; i<size; i++)
        for(int j=0; j<buckets[i].size(); j++)
            array[index++] = buckets[i][j];

    return array;
}

int Bucket_Sort::hash(int key, int hashValue, int numberOfBuckets)
{
    int bucketNumber = key / hashValue;

    if (bucketNumber == numberOfBuckets)
        bucketNumber--;
    
    return bucketNumber;
}*/