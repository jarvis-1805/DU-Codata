#include<iostream>
#define size 100

using namespace std;

template<class Type>
class queueArray
{
	public:
		Type queue[size];
		int front, rear;
		
		queueArray();
		~queueArray();
		
		void enqueue(Type);
		Type dequeue();
		Type frontEle();
		
		bool isEmpty();
};

template<class Type>
queueArray<Type>::queueArray()
{
	this -> front = -1;
	this -> rear = -1;
}

template<class Type>
queueArray<Type>::~queueArray()
{
	while(!isEmpty())
		dequeue();
}

template<class Type>
void queueArray<Type>::enqueue(Type n)
{
	if(isEmpty())
	{
		front = 0;
		rear = 0;
		queue[rear] = n;
	}
	else
		queue[++rear] = n;
}

template<class Type>
Type queueArray<Type>::dequeue()
{
	Type x;
	if(front == rear)
	{
		x = queue[front];
		front = rear = -1;
	}
	else
		x = queue[front++];
	
	return x;
}

template<class Type>
Type queueArray<Type>::frontEle()
{
	return queue[front];
}

template<class Type>
bool queueArray<Type>::isEmpty()
{
	if(front == -1 && rear == -1)
		return true;
	return false;
}