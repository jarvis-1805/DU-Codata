#include<iostream>

using namespace std;

template <class T>
class doublyLinkedList
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
		
		~doublyLinkedList();
		
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
		struct node *search_in_list();
		void reverse_the_list();
		void operator +(doublyLinkedList);
		
		int countList();
		bool emptyListChecker();
};

template <class T>
doublyLinkedList<T>::~doublyLinkedList()
{
	struct node *temp1;
	temp = head;
	while(temp != NULL)
	{
		temp1 = temp -> next;
		delete(temp);
		temp = temp1;
	}
}

template <class T>
void doublyLinkedList<T>::options()
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
		<<	"\n10. REVERSE THE LIST"
		<<	"\n11. CONCATENATE ANOTHER LIST"
		<<	"\n0. EXIT";
}

template <class T>
int doublyLinkedList<T>::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

template <class T>
void doublyLinkedList<T>::choiceCalling(int ch)
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
		{
			node *temp1 = search_in_list();
			if(temp1 != NULL)
				cout << "\nPointer: " << temp1 << endl;
			break;
		}
		case 10:
			reverse_the_list();
			break;
		case 11:
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

template <class T>
void doublyLinkedList<T>::create()
{
	cout << "\n------------ CREATING NEW LIST ------------\n";
	head = NULL;
	char ch;
	do
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		newNode -> next = NULL;
		newNode -> prev = NULL;
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
		cout << "\nDo you want to enter more nodes? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	traverse();
}

template <class T>
void doublyLinkedList<T>::traverse()
{
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		temp = head;
		cout << endl << "List: ";
		while(temp != NULL)
		{
			cout << temp -> data;
			temp = temp -> next;
			if(temp != NULL)
				cout << " <-> ";
		}
		cout << endl;
	}
}

template <class T>
void doublyLinkedList<T>::insert_at_beginning()
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
		newNode -> prev = NULL;
		head = newNode;
		cout << "\nSuccessfully inserted the node at beginning\n";
		traverse();
	}
}

template <class T>
void doublyLinkedList<T>::insert_at_location()
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
				newNode -> prev = temp;
				newNode -> next = temp -> next;
				temp -> next = newNode;
				newNode -> next -> prev = newNode;
				cout << "\nSuccessfully inserted the node at " << loc << endl;
				traverse();
				break;
			}
		}
	}
}

template <class T>
void doublyLinkedList<T>::insert_at_end()
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
		newNode -> next = NULL;
		tail -> next = newNode;
		newNode -> prev = tail;
		tail = newNode;
		cout << "\nSuccessfully inserted the node at end\n";
		traverse();
	}
}

template <class T>
void doublyLinkedList<T>::delete_at_beginning()
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
			head = temp = NULL;
		}
		else
		{
			head = head -> next;
			head -> prev = NULL;
			delete(temp);
		}
		cout << "\nSuccessfully deleted the node at beginning\n";
		traverse();
	}
}

template <class T>
void doublyLinkedList<T>::delete_at_location()
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

template <class T>
void doublyLinkedList<T>::delete_at_end()
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
			head = temp = NULL;
		}
		else
		{
			tail -> prev -> next = NULL;
			tail = tail -> prev;
			delete(temp);
		}
		cout << "\nSuccessfully deleted the node at end\n";
		traverse();
	}
}

template <class T>
typename doublyLinkedList<T>::node *doublyLinkedList<T>::search_in_list()
{
	bool flag=false;
	T ele, count=0;
	temp = head;
	cout << "\n------------ SEARCHING IN LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return temp;
	else
	{
		cout << "Enter the element to be searched: ";
		cin >> ele;
		do
		{
			if(temp -> data == ele)
			{
				flag = true;
				break;
			}
			temp = temp -> next;
			count++;
		}while(temp != NULL);
		if(flag == true)
			cout << endl << ele << " found at position " << count+1 << " in the list";
		else
			cout << endl << ele << " not found in the list\n";
	}
	return temp;
}

template <class T>
void doublyLinkedList<T>::reverse_the_list()
{
	cout << "\n------------ REVERSING THE LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *currNode, *nextNode;
		currNode = head;
		while(currNode != NULL)
		{
			nextNode = currNode -> next;
			currNode -> next = currNode -> prev;
			currNode -> prev = nextNode;
			currNode = nextNode;
		}
		temp = head;
		head = tail;
		tail = temp;
		traverse();
	}
}

template <class T>
void doublyLinkedList<T>::operator + (doublyLinkedList ob1)				//operator overloading
{
	cout << "\n------------ CONCATINATING ANOTHER LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
    	struct node *node,
                *temp = head,
                *temp1 = ob1.head;
      	while(temp->next != NULL)
        	temp = temp->next;
		while (temp1 != NULL)
		{
			node = new struct node();
			node->data = temp1->data;
			node->next = NULL;
			temp->next = node;
			node->prev = temp;
			temp = temp->next;
			temp1 = temp1->next;
		}
		traverse();
	}
}

template <class T>
int doublyLinkedList<T>::countList()
{
	int count=0;
	temp = head;
	while(temp != NULL)
	{
		temp = temp -> next;
		count ++;
	}
	return count;
}

template <class T>
bool doublyLinkedList<T>::emptyListChecker()
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
	doublyLinkedList<int> ob, ob1;
	cout << "\n=========== DOUBLY LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		if(choice == 1)
			ob.~doublyLinkedList();
		if(choice == 11)
		{
			ob1.create();
			ob + ob1;
		}
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	cout << "\n########### MEMORY IS FREED ###########\n";
	return 0;
}