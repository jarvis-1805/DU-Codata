#include<iostream>

using namespace std;

template <typename T>
class circularDoublyLinkedList
{
	public:
		struct node
		{
			struct node *prev;
			T data;
			struct node *next;
		};
		struct node *head=NULL, *tail=NULL, *newNode, *temp;
		int ch;
		bool emp;
		
		~circularDoublyLinkedList();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void create();
		void traverse();
		void insert_at_beginning();
		void insert_at_location();
		void insert_at_end();
		void delete_at_beginning();
		void delete_at_location();
		void delete_at_end();
		void search_in_list();
		void reverse_the_list();
		
		int countList();
		int countDoubleDigit();
		bool emptyListChecker();
};

template <typename T>
circularDoublyLinkedList<T>::~circularDoublyLinkedList()
{
	struct node *temp1;
	temp = head;
	do
	{
		if(head == NULL)
			break;
		temp1 = temp -> next;
		delete(temp);
		temp = temp1;
	}while(temp != head);
	cout << "\n########### MEMORY IS FREED ###########\n";
}

template <typename T>
void circularDoublyLinkedList<T>::options()
{
	cout << "\n1. CREATE"
		<<	"\n2. TRAVERSE"
		<<	"\n3. INSERT AT BEGINNING"
		<<	"\n4. INSERT AT LOCATION"
		<<	"\n5. INSERT AT END"
		<<	"\n6. DELETE AT BEGINNING"
		<<	"\n7. DELETE AT LOCATION"
		<<	"\n8. DELETE AT END"
		<<	"\n9. SEARCH IN LIST"
		<<	"\n0. EXIT";
}

template <typename T>
int circularDoublyLinkedList<T>::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

template <typename T>
void circularDoublyLinkedList<T>::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			create();
			break;
		case 2:
			cout << "\n------------ TRAVERSING LIST ------------\n";
			traverse();
			break;
		case 3:
			insert_at_beginning();
			break;
		case 4:
			insert_at_location();
			break;
		case 5:
			insert_at_end();
			break;
		case 6:
			delete_at_beginning();
			break;
		case 7:
			delete_at_location();
			break;
		case 8:
			delete_at_end();
			break;
		case 9:
			search_in_list();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

template <typename T>
void circularDoublyLinkedList<T>::create()
{
	cout << "\n------------ CREATING NEW LIST ------------\n";
	head = NULL;
	char ch;
	do
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		if(head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail -> next = newNode;
			newNode -> prev = tail;
			tail = newNode;
		}
		tail -> next = head;
		head -> prev = tail;
		cout << "\nDo you want to enter more nodes? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	traverse();
}

template <typename T>
void circularDoublyLinkedList<T>::traverse()
{
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		temp = head;
		cout << endl << "List: ";
		do
		{
			cout << temp -> data;
			temp = temp -> next;
			if(temp != head)
				cout << " <-> ";
		}while(temp != head);
		cout << endl;
		cout << "      ^";
		int c=countList();
		for(int i=1; i<=((5*(c-1))+(c-2)); i++)
			cout << "_";
		int x=countDoubleDigit();
		if(x != 0)
			for(int j=1; j<=x; j++)
				cout << "_";
		cout << "^\n";
	}
}

template <typename T>
void circularDoublyLinkedList<T>::insert_at_beginning()
{
	cout << "\n------------ INSERTING AT BEGINNING ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		head -> prev = newNode;
		newNode -> next = head;
		head = newNode;
		tail -> next = head;
		head -> prev = tail;
		cout << "\nSuccessfully inserted the node at beginning\n";
		traverse();
	}
}

template <typename T>
void circularDoublyLinkedList<T>::insert_at_location()
{
	cout << "\n------------ INSERTING AT LOCATION ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int loc, i=1, count;
		count = countList();
		while(1)
		{
			cout << "Enter the new node's location: ";
			cin >> loc;
			if(loc > count || loc == 0)
			{
				cout << "\n########### WRONG LOCATION... ###########\n";
				break;
			}
			if(loc == 1)
			{
				insert_at_beginning();
				break;
			}
			else
			{
				newNode = (struct node *)new struct node;
				cout << "Enter the new node's data : ";
				cin >> newNode -> data;
				temp = head;
				while(i < loc-1)
				{
					temp = temp -> next;
					++i;
				}
				newNode -> next = temp -> next;
				temp -> next = newNode;
				newNode -> prev = temp;
				newNode -> next -> prev = newNode;
				cout << "\nSuccessfully inserted the node at " << loc << endl;
				traverse();
				break;
			}
		}
	}
}

template <typename T>
void circularDoublyLinkedList<T>::insert_at_end()
{
	cout << "\n------------ INSERTING AT END ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		newNode -> next = head;
		head -> prev = newNode;
		tail -> next = newNode;
		newNode -> prev = tail;
		tail = newNode;
		cout << "\nSuccessfully inserted the node at end\n";
		traverse();
	}
}

template <typename T>
void circularDoublyLinkedList<T>::delete_at_beginning()
{
	cout << "\n------------ DELETING AT BEGINNING ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int c = countList();
		temp = head;
		if(c == 1)
		{
			delete(temp);
			head = tail = NULL;
		}
		else
		{
			head = head -> next;
			head -> prev = tail;
			tail -> next = head;
			delete(temp);
		}
		cout << "\nSuccessfully deleted the node at beginning\n";
		traverse();
	}
}

template <typename T>
void circularDoublyLinkedList<T>::delete_at_location()
{
	cout << "\n------------ DELETING AT LOACTION ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int loc, i=1, count;
		count = countList();
		while(1)
		{
			cout << "Enter the to be deleted node's location: ";
			cin >> loc;
			if(loc > count || loc == 0)
			{
				cout << "\n########### WRONG LOCATION... ###########\n";
				break;
			}
			if(loc == 1)
			{
				delete_at_beginning();
				break;
			}
			if(loc == count)
			{
				delete_at_end();
				break;
			}
			else
			{
				temp = head;
				while(i < loc)
				{
					temp = temp -> next;
					++i;
				}
				temp -> prev -> next = temp -> next;
				temp -> next -> prev = temp -> prev;
				delete(temp);
				cout << "\nSuccessfully deleted node at " << loc << endl;
				traverse();
				break;
			}
		}
	}
}

template <typename T>
void circularDoublyLinkedList<T>::delete_at_end()
{
	cout << "\n------------ DELETING AT END ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int c = countList();
		temp = tail;
		if(c == 1)
		{
			delete(temp);
			head = tail = NULL;
		}
		else
		{
			tail = tail -> prev;
			tail -> next = head;
			head -> prev = tail;
			delete(temp);
		}
		cout << "\nSuccessfully deleted the node at end\n";
		traverse();
	}
}

template <typename T>
void circularDoublyLinkedList<T>::search_in_list()
{
	bool flag=false;
	T ele, count=0;
	cout << "\n------------ SEARCHING IN LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		cout << "Enter the element to be searched: ";
		cin >> ele;
		temp = head;
		do
		{
			if(temp -> data == ele)
			{
				flag = true;
				break;
			}
			temp = temp -> next;
			count++;
		}while(temp != head);
		if(flag == true)
			cout << endl << ele << " found at position " << count+1 << " in the list\n";
		else
			cout << endl << ele << " not found in the list\n";
	}
}

template <typename T>
void circularDoublyLinkedList<T>::reverse_the_list()
{
	cout << "\n------------ REVERSING THE LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *currNode, *nextNode;
		currNode = head;
		do
		{
			nextNode = currNode -> next;
			currNode -> next = currNode -> prev;
			currNode -> prev = nextNode;
			currNode = nextNode;
		}while(currNode != head);
		temp = head;
		head = tail;
		tail = temp;
		traverse();
	}
}

template <typename T>
int circularDoublyLinkedList<T>::countList()
{
	int count=0;
	temp = head;
	do
	{
		temp = temp -> next;
		count ++;
	}while(temp != head);
	return count;
}

template <typename T>
int circularDoublyLinkedList<T>::countDoubleDigit()
{
	int count=0;
	temp = head;
	do
	{
		if((temp -> data >= 10) && (temp -> data <=99))
			count ++;
		temp = temp -> next;
	}while(temp != head);
	return count;
}

template <typename T>
bool circularDoublyLinkedList<T>::emptyListChecker()
{
	if(head == NULL)
	{
		cout << "\n########### The list is empty ###########\n";
		return false;
	}
	return true;
}

int main()
{
	int choice;
	circularDoublyLinkedList<int> ob;
	cout << "\n=========== CIRCULAR DOUBLY LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		if(choice == 1)
			ob.~circularDoublyLinkedList();
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	return 0;
}