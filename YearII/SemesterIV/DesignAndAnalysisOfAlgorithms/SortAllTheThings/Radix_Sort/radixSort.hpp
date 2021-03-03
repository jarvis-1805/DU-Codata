#include "../Counting_Sort/countingSort.hpp"

class Radix_Sort
{
    private:
        int max;
    
    public:
        Radix_Sort();
        
        int *radix_sort(int *, int);
        std::string *radix_sort(std::string *, int);
};

Radix_Sort::Radix_Sort()
{
    max = 0;
}

int *Radix_Sort::radix_sort(int *array, int size)
{
    Counting_Sort counting;
    
    max = *std::max_element(array, array + size);

    for(int place=1; max / place > 0; place *= 10)
        array = counting.counting_sort(array, size, place);
    
    return array;
}

std::string *Radix_Sort::radix_sort(std::string *array, int length)
{
    Counting_Sort counting;

    for(int place=(array[0].length() - 1); place>=0; place--)
        array = counting.counting_sort(array, length, place);
    
    return array;
}