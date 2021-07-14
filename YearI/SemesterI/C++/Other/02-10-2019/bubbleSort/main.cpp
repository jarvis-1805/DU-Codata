#include <iostream>
#define MAX_SIZE 255

using namespace std;

void swap(int *, int *);
void bubbleSort(int[], int);
void binarySearch(const int[], int, int);

int main()
{
    int size = 0;
    cout << "Enter array size: ";
    cin >> size;

    int array[MAX_SIZE] = {0};
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    bubbleSort(array, size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    int key = 0;
    cout << "Enter number to search: ";
    cin >> key;

    binarySearch(array, size, key);

    return 0;
}

void swap(int *p, int *q)
{
    int temp = *q;
    *q = *p;
    *p = temp;
    return;
}

void bubbleSort(int a[], int b)
{
    for (int i = 0; i < b - 1; i++)
        for (int j = 0; j < b - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
    return;
}

void binarySearch(const int a[], int b, int c)
{
    if (b <= 0)
        return;

    int first = 0, last = b, mid = 0;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (c > a[mid])
            first = mid + 1;
        else if (c < a[mid])
            last = mid - 1;
        else
        {
            cout << "Element found at "
                 << "index " << mid << "\n";
            return;
        }
    }

    cout << "Element not found";
    return;
}
