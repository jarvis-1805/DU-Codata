#include <iostream>
#define MAX 100

using namespace std;

template<class T>
class sorting
{
    public:
        int ch;
        int size;
        T array[MAX];

        void options();
        int choice();
        void choice_calling(int);

        sorting();

        void swap(T *, int, int);
        void display(T *);

        void bubble_sort(T *, int);
        void insertion_sort(T *, int);
        void selection_sort(T *, int, int);
        int linear_search(T *, int, int);
        void binary_search(T *, int);
};

template<class T>
sorting<T>::sorting()
{
    cout << "\n============ SORTING TECHNIQUES ============\n";

    label:
        cout << "\nEnter the size: ";
        cin >> size;

    if(size == 0)
        goto label;

    cout << "\nEnter the elements: ";
    for(int i=0; i<size; i++)
        cin >> array[i];
    
    system("clear");
}

template<class T>
void sorting<T>::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. BUBBLE SORT"
		<< "\n2. INSERTION SORT"
		<< "\n3. SELECTION SORT"
		<< "\n4. LINEAR SEARCH"
		<< "\n5. BINARY SEARCH"
		<< "\n6. DISPLAY"
		<< "\n0. EXIT";
}

template<class T>
int sorting<T>::choice()
{
    cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

template<class T>
void sorting<T>::choice_calling(int ch)
{
    int key, pos;
    T arr[size];
    for(int i=0; i<size; i++)
        arr[i] = array[i];
    
    switch(ch)
	{
		case 1:
            bubble_sort(arr, size);
            cout << "\nBubble sorted array: ";
            display(arr);
			break;
		case 2:
            insertion_sort(arr, size);
            cout << "\nInsertion sorted array: ";
            display(arr);
			break;
		case 3:
            selection_sort(arr, size, 0);
            cout << "\nSelection sorted array: ";
            display(arr);
			break;
		case 4:
            cout << "\nEnter the value: ";
            cin >> key;
            pos = linear_search(arr, size, key);
            cout << "\nLinearly Searched element " << key << " is present at: " << pos + 1 << endl;
			break;
		case 5:
			break;
		case 6:
            cout << "\nArray: ";
            display(array);
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

template<class T>
void sorting<T>::swap(T *arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template<class T>
void sorting<T>::display(T *arr)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";    
    cout << endl;
}

template<class T>
void sorting<T>::bubble_sort(T *arr, int size)
{
    if(size == 1)
        return;
    
    for(int i=0; i<size-1; i++)
        if(arr[i] > arr[i+1])
            swap(arr, i, i+1);
    
    bubble_sort(arr, size - 1);
}

template<class T>
void sorting<T>::insertion_sort(T *arr, int size)
{
    if(size <= 1)
        return;
    
    insertion_sort(arr, size-1);

    T key = arr[size-1];
    int i = size - 2;
    while(i >= 0 && arr[i] > key)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = key;
}

template<class T>
void sorting<T>::selection_sort(T *arr, int size, int ind)
{
    if(ind == size)
        return;
    
    int minim = ind;
    for(int i=ind+1; i<size; i++)
        if(arr[i] < arr[minim])
            minim = i;
    
    swap(arr, ind, minim);

    selection_sort(arr, size, ind+1);
}

template<class T>
int sorting<T>::linear_search(T *arr, int size, int key)
{
    if(size < 0)
        return -1;
    if(arr[size] == key)
        return size;
    else
        return linear_search(arr, size - 1, key);
}

int main()
{
    int choice;

    sorting<int> ob;
    do
	{
		cout << "\n============ SORTING AND SEARCHING ============\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		system("clear");
	    cout << "\n============ SORTING AND SEARCHING ============\n";
		ob.choice_calling(choice);
		cout << "\nPress Enter to continue...";
		cin.ignore();
		getchar();
		system("clear");
	}while(1);
	
	return 0;
}