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

        int *swap(int *, int, int);
        
        void build_max_heap();
        void max_heapify(int *, int);
        void heap_increase_key(int *, int, int);
        void max_heap_insert(int *, int);
        int heap_maximum(int *);
        int heap_extract_max(int *);
};

priorityQueue::priorityQueue()
{
    cout << "\n=========== PRIORITY QUEUE ===========\n";
    cout << "\nEnter the size: ";
    cin >> size;
    cout << "\nEnter the elements: ";
    for(int i=1; i<=size; i++)
        cin >> array[i];
}

void priorityQueue::options()
{
	cout << "\n------- MENU -------";
    cout << "\n1. MAX HEAPIFY"
		<<	"\n2. BUILD MAX HEAP"
		<<	"\n3. MAX PRIORITY QUEUE"
		<<	"\n5. DISPLAY"
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
			cout << "\nEnter index from " << floor(size/2) << " upto 1: ";
		    cin >> i;
			max_heapify(array, i);
            for(int x=1; x<=size; x++)
            {
                cout << array[x] << " ";
            }
			break;
		case 2:
			build_max_heap();
            for(int x=1; x<=size; x++)
            {
                cout << array[x] << " ";
            }
			break;
		case 3:
            sub_options_1();
            ch1 = choice();
			sub_choiceCalling_1(ch1);
			break;
		case 5:
            cout << "\nArray: ";
            for(int x=1; x<=size; x++)
                cout << array[x] << " ";
            cout << endl;
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

void priorityQueue::sub_options_1()
{
	cout << "\n------- SUB MENU -------";
    cout << "\n1. HEAP INCREASE KEY"
		<< "\n2. MAX HEAP INSERT"
		<< "\n3. HEAP MAXIMUM"
		<< "\n4. HEAP EXTRACT MAX";
}

void priorityQueue::sub_choiceCalling_1(int ch1)
{
    int i;
    int key;
    switch(ch1)
	{
		case 1:
			cout << "\nEnter index to be increased: ";
		    cin >> i;
			cout << "\nEnter the data: ";
		    cin >> key;
            heap_increase_key(array, i, key);
			break;
		case 2:
			cout << "\nEnter the data: ";
		    cin >> key;
            max_heap_insert(array, key);
			break;
		case 3:
            key = heap_maximum(array);
            cout << "\nMaximum Key: " << key << endl;
			break;
		case 4:
            key = heap_extract_max(array);
            if(key == -1000)
                cout << "\nHeap Underflow!" << endl;
            else
                cout << "\nExtracted maximum Key: " << key << endl;
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

int main()
{
    int choice;
	priorityQueue ob;
	do
	{
		//cout << "\n=========== PRIORITY QUEUE ===========\n";
		ob.options();
		choice = ob.choice();
		if(ob.ch == 0)
			break;
		//system("clear");
		//cout << "\n=========== PRIORITY QUEUE ===========\n";
		ob.choiceCalling(choice);
		//cout << "\nPress Enter to continue...";
		//cin.ignore();
		//getchar();
		//system("clear");
	}while(1);
	
	return 0;
}