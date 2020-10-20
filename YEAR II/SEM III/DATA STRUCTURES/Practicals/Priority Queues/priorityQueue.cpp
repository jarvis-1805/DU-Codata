#include<iostream>
#include<math.h>
#define MAX 100

using namespace std;

class priorityQueue
{
    int array[MAX];
    
    public:
        int size, ch, ch1;

        priorityQueue();

        void options();
		int choice();
		void choiceCalling(int);
        
		void sub_options_1();
		void sub_choiceCalling_1(int);
		void sub_options_2();
		void sub_choiceCalling_2(int);

        int *swap(int *, int, int);
        
        void max_heapify(int *, int);
        void min_heapify(int *, int);
        void build_max_heap();
        void build_min_heap();
        void heap_increase_key(int *, int, int);
        void max_heap_insert(int *, int);
        int heap_maximum(int *);
        int heap_extract_max(int *);
        void heap_decrease_key(int *, int, int);
        void min_heap_insert(int *, int);
        int heap_minimum(int *);
        int heap_extract_min(int *);
        void heap_sort(int *);
        void display();
};

priorityQueue::priorityQueue()
{
    cout << "\n=========== PRIORITY QUEUE ===========\n";
    cout << "\nEnter the size: ";
    cin >> size;
    if(size != 0)
    {
        cout << "\nEnter the elements: ";
        for(int i=1; i<=size; i++)
            cin >> array[i];
    }
    system("clear");
}

void priorityQueue::options()
{
	cout << "\n------- MENU -------";
    cout <<	"\n1. MAX PRIORITY QUEUE"
		<<	"\n2. MIN PRIORITY QUEUE"
		<<	"\n3. HEAP SORT"
		<<	"\n0. EXIT";
}

int priorityQueue::choice()
{
    cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void priorityQueue::choiceCalling(int ch)
{
	int i;
    switch(ch)
	{
		case 1:
            system("clear");
            do
            {
                cout << "\n=========== MAX PRIORITY QUEUE ===========\n";
                sub_options_1();
                ch1 = choice();
                if(ch1 == 0)
                    break;
                system("clear");
                cout << "\n=========== MAX PRIORITY QUEUE ===========\n";
                sub_choiceCalling_1(ch1);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                getchar();
		        system("clear");
            }while(ch1 != 0);
			break;
		case 2:
            system("clear");
            do
            {
                cout << "\n=========== MIN PRIORITY QUEUE ===========\n";
                sub_options_2();
                ch1 = choice();
                if(ch1 == 0)
                    break;
                system("clear");
                cout << "\n=========== MIN PRIORITY QUEUE ===========\n";
                sub_choiceCalling_2(ch1);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                getchar();
		        system("clear");
            }while(1);
			break;
		case 3:
            heap_sort(array);
            cout << "\nSuccessfully Sorted Heap!\n";
            display();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void priorityQueue::sub_options_1()
{
	cout << "\n------- MENU -------";
    cout << "\n1. MAX HEAPIFY"
		<< "\n2. BUILD MAX HEAP"
        << "\n3. HEAP INCREASE KEY"
		<< "\n4. MAX HEAP INSERT"
		<< "\n5. HEAP MAXIMUM"
		<< "\n6. HEAP EXTRACT MAX"
		<< "\n7. DISPLAY"
		<< "\n0. EXIT";
}

void priorityQueue::sub_choiceCalling_1(int ch1)
{
    int i;
    int key;
    switch(ch1)
	{
        case 1:
			cout << "\nEnter index from " << floor(size/2) << " upto 1: ";
		    cin >> i;
            if(i <= floor(size/2) && i >= 1)
            {
                max_heapify(array, i);
                cout << "\nSuccessfully Max Heapified at " << i << "!\n";
                display();
            }
            else
                cout << "\n########### WRONG CHOICE... ###########\n";
			break;
		case 2:
			build_max_heap();
            cout << "\nSuccessfully built Max Heap!\n";
            display();
			break;
		case 3:
			cout << "\nEnter index to be increased: ";
		    cin >> i;
            if(i <= size && i >= 1)
            {
                cout << "\nEnter the data: ";
                cin >> key;
                heap_increase_key(array, i, key);
            }
            else
                cout << "\n########### WRONG CHOICE... ###########\n";
			break;
		case 4:
			cout << "\nEnter the data: ";
		    cin >> key;
            max_heap_insert(array, key);
            cout << "\nSuccessfully inserted " << key << endl;
            display();
			break;
		case 5:
            key = heap_maximum(array);
            cout << "\nMaximum Key: " << key << endl;
			break;
		case 6:
            key = heap_extract_max(array);
            if(key == -1000)
                cout << "\nHeap Underflow!" << endl;
            else
                cout << "\nExtracted maximum Key: " << key << endl;
			break;
		case 7:
            display();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void priorityQueue::sub_options_2()
{
	cout << "\n------- MENU -------";
    cout <<	"\n1. MIN HEAPIFY"
		<< "\n2. BUILD MIN HEAP"
        << "\n3. HEAP DECREASE KEY"
		<< "\n4. MIN HEAP INSERT"
		<< "\n5. HEAP MINIMUM"
		<< "\n6. HEAP EXTRACT MIN"
		<< "\n7. DISPLAY"
		<< "\n0. EXIT";
}

void priorityQueue::sub_choiceCalling_2(int ch1)
{
    int i;
    int key;
    switch(ch1)
	{
        case 1:
			cout << "\nEnter index from " << floor(size/2) << " upto 1: ";
		    cin >> i;
            if(i <= floor(size/2) && i >= 1)
            {
                min_heapify(array, i);
                cout << "\nSuccessfully Min Heapified at " << i << "!\n";
                display();
            }
            else
                cout << "\n########### WRONG CHOICE... ###########\n";
			break;
		case 2:
			build_min_heap();
            cout << "\nSuccessfully built Min Heap!\n";
            display();
			break;
		case 3:
			cout << "\nEnter index to be decreased: ";
		    cin >> i;
            if(i <= size && i >= 1)
            {
                cout << "\nEnter the data: ";
                cin >> key;
                heap_decrease_key(array, i, key);
            }
            else
                cout << "\n########### WRONG CHOICE... ###########\n";
			break;
		case 4:
			cout << "\nEnter the data: ";
		    cin >> key;
            min_heap_insert(array, key);
            cout << "\nSuccessfully inserted " << key << endl;
            display();
			break;
		case 5:
            key = heap_minimum(array);
            cout << "\nMinimum Key: " << key << endl;
			break;
		case 6:
            key = heap_extract_min(array);
            if(key == -1000)
                cout << "\nHeap Underflow!" << endl;
            else
                cout << "\nExtracted minimum Key: " << key << endl;
			break;
		case 7:
            display();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

int *priorityQueue::swap(int *array, int maxim, int i)
{
    int temp = array[maxim];
    array[maxim] = array[i];
    array[i] = temp;

    return array;
}

void priorityQueue::build_max_heap()
{
    for(int i=floor(size/2); i>=1; i--)
        max_heapify(array, i);
}

void priorityQueue::build_min_heap()
{
    for(int i=floor(size/2); i>=1; i--)
        min_heapify(array, i);
}

void priorityQueue::max_heapify(int *array, int i)
{
    int left = 2*i;
    int right = 2*i + 1;
    int maxim;
    if(left <= size && array[left] > array[i])
        maxim = left;
    else
        maxim = i;
    
    if(right <= size && array[right] > array[maxim])
        maxim = right;
    
    if(maxim != i)
    {
        array = swap(array, maxim, i);
        max_heapify(array, maxim);
    }
}

void priorityQueue::min_heapify(int *array, int i)
{
    int left = 2*i;
    int right = 2*i + 1;
    int minim;
    if(left <= size && array[left] < array[i])
        minim = left;
    else
        minim = i;
    
    if(right <= size && array[right] < array[minim])
        minim = right;
    
    if(minim != i)
    {
        array = swap(array, minim, i);
        min_heapify(array, minim);
    }
}

void priorityQueue::heap_increase_key(int *array, int i, int key)
{
    if(key < array[i])
    {
        cout << "\nData entered is less than " << i << "th elemnt " << array[i] << endl;
        return;
    }
    int parent = floor(i/2);
    array[i] = key;
    while(i > 1 && array[parent] < array[i])
    {
        array = swap(array, parent, i);
        i = parent;
        parent = floor(i/2);
    }
    cout << "\nSuccessfully increased " << i << "th element to " << key << endl;
    display();
}

void priorityQueue::max_heap_insert(int *array, int key)
{
    array[++size] = -999;
    heap_increase_key(array, size, key);
}

int priorityQueue::heap_maximum(int *array)
{
    return array[1];
}

int priorityQueue::heap_extract_max(int *array)
{
    if(size < 1)
        return -1000;
    
    int maxim = array[1];
    array[1] = array[size--];
    max_heapify(array, 1);
    return maxim;
}

void priorityQueue::heap_decrease_key(int *array, int i, int key)
{
    if(key > array[i])
    {
        cout << "\nData entered is greater than " << i << "th element " << array[i] << endl;
        return;
    }
    int parent = floor(i/2);
    array[i] = key;
    while(i > 1 && array[parent] > array[i])
    {
        array = swap(array, parent, i);
        i = parent;
        parent = floor(i/2);
    }
    cout << "\nSuccessfully decreased " << i << "th element to " << key << endl;
    display();
}

void priorityQueue::min_heap_insert(int *array, int key)
{
    array[++size] = 999;
    heap_decrease_key(array, size, key);
}

int priorityQueue::heap_minimum(int *array)
{
    return array[1];
}

int priorityQueue::heap_extract_min(int *array)
{
    if(size < 1)
        return -1000;
    
    int minim = array[1];
    array[1] = array[size--];
    min_heapify(array, 1);
    return minim;
}

void priorityQueue::heap_sort(int *array)
{
    int s = size;
    build_max_heap();
    for(int i=size; i>=2; i--)
    {
        array = swap(array, 1, i);
        size--;
        max_heapify(array, 1);
    }
    size = s;
}

void priorityQueue::display()
{
    cout << "\nArray: ";
    if(size != 0)
        for(int x=1; x<=size; x++)
            cout << array[x] << " ";
    else
        cout << "Empty!";
    cout << endl;
}

int main()
{
    int choice;
	priorityQueue ob;
	do
	{
		cout << "\n=========== PRIORITY QUEUE ===========\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		system("clear");
		cout << "\n=========== PRIORITY QUEUE ===========\n";
		ob.choiceCalling(choice);
		cout << "\nPress Enter to continue...";
		cin.ignore();
		getchar();
		system("clear");
	}while(1);
	
	return 0;
}