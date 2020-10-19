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

        int *swap(int *, int, int);
        
        void build_max_heap();
        void max_heapify(int *, int);
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