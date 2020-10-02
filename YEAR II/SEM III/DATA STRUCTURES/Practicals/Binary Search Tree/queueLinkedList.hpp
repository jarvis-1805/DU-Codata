#include<iostream>

using namespace std;

template<class Type>
class queueLinkedList
{
	public:
		
		struct node1
		{
			Type data;
			struct node1 *next;
		};
		struct node1 *front, *rear, *newNode1, *temp1;
		//int ch;
		
		queueLinkedList();
		~queueLinkedList();
		
		//void options();
		//int choice();
		//void choiceCalling(int);
		
		void enqueue(Type);
		Type dequeue();
		Type frontEle();
		void traverse();
		//void clear();
		bool isEmpty();
};

template<class Type>
queueLinkedList<Type>::queueLinkedList()
{
	front = NULL;
	rear = NULL;
}

template<class Type>
queueLinkedList<Type>::~queueLinkedList()
{
	while(!isEmpty())
		dequeue();
}
/*
void queueLinkedList::options()
{
	cout << "\n---------- MENU ----------";
	cout << "\n1. ENQUEUE"
		<<	"\n2. DEQUEUE"
		<<	"\n3. FRONT"
		<<	"\n4. DISPLAY"
		<<	"\n5. CLEAR"
		<<	"\n0. EXIT";
}

int queueLinkedList::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

void queueLinkedList::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			int n;
			cout << "\nEnter the new data : ";
			cin >> n;
			enqueue(n);
			break;
		case 2:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				this -> front = NULL;
				this -> rear = NULL;
				break;
			}
			int x;
			x = dequeue();
			cout << "\nDequeued : " << x << endl;
			break;
		case 3:
			if(isEmpty())
			{
				cout << "\nThe queue is empty\n";
				break;
			}
			int y;
			y = frontEle();
			cout << "\nFront : " << y << endl;
			break;
		case 4:
			traverse();
			break;
		case 5:
			clear();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}
*/
template<class Type>
void queueLinkedList<Type>::enqueue(Type n)
{
	newNode1 = new struct node1;
	newNode1 -> data = n;
	newNode1 -> next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = newNode1;
	}
	else
	{
		rear -> next = newNode1;
		rear = newNode1;
	}
	//cout << "\nEnqueued : " << n << endl;
}

template<class Type>
Type queueLinkedList<Type>::dequeue()
{
	Type x;
	temp1 = front;
	if(front == rear)
	{
		x = front -> data;
		front = rear = NULL;
	}
	else
	{	
		x = temp1 -> data;
		front = temp1 -> next;
	}
	delete(temp1);
	return x;
}

template<class Type>
Type queueLinkedList<Type>::frontEle()
{
	return front -> data;
}

template<class Type>
void queueLinkedList<Type>::traverse()
{
	temp1 = front;
	cout << endl << "Queue: ";
	if(isEmpty())
	{
		cout << "Empty\n";
		return;
	}
	while(temp1 != NULL)
	{
		cout << temp1 -> data;
		temp1 = temp1 -> next;
		if(temp1 != NULL)
			cout << " : ";
	}
	cout << endl;
}
/*
void queueLinkedList::clear()
{
	if(isEmpty())
	{
		cout << "\nThe queue is empty\n";
		return;
	}
	this -> ~queueLinkedList();
	this -> front = NULL;
	this -> rear = NULL;
	cout << "\nSuccessfully cleared the Queue!\n";
}
*/
template<class Type>
bool queueLinkedList<Type>::isEmpty()
{
	temp1 = front;
	if(temp1 == NULL)
		return true;
	return false;
}
/*
int main()
{
	int choice;
	queueLinkedList ob;
	cout << "\n=========== QUEUE CIRCULAR LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	cout << "\n########### MEMORY IS FREED ###########\n";
	return 0;
}*/