#include<iostream>

using namespace std;

template <typename T>
class circularSinglyLinkedList
{
	public:
		struct node
		{
			T data;
			struct node *next;
		};
		struct node *tail=NULL, *newNode, *temp;
		int ch;
		bool emp;
		
		~circularSinglyLinkedList();
		
		void options();
		int choice();
		void choiceCalling(int);
		
		void create();
		void traverse();
		void insert_at_beginning();
		void insert_after_data();
		void insert_at_end();
		void delete_at_beginning();
		void delete_data();
		void delete_at_end();
		struct node *search_in_list();
		void reverse_the_list();
		void operator +(circularSinglyLinkedList);
		
		int countList();
		int countDoubleDigit();
		bool emptyListChecker();
};

template <typename T>
circularSinglyLinkedList<T>::~circularSinglyLinkedList()
{
	struct node *temp1;
	temp = tail;
	do
	{
		if(tail == NULL)
			break;
		temp1 = temp -> next;
		delete(temp);
		temp = temp1;
	}while(temp != tail -> next);
}

template <typename T>
void circularSinglyLinkedList<T>::options()
{
	cout << "\n1. CREATE"
		<<	"\n2. TRAVERSE"
		<<	"\n3. INSERT AT BEGINNING"
		<<	"\n4. INSERT AFTER ANY DATA"
		<<	"\n5. INSERT AT END"
		<<	"\n6. DELETE AT BEGINNING"
		<<	"\n7. DELETE A DATA"
		<<	"\n8. DELETE AT END"
		<<	"\n9. SEARCH IN LIST"
		<<	"\n10. REVERSE THE LIST"
		<<	"\n11. CONCATENATE ANOTHER LIST"
		<<	"\n0. EXIT";
}

template <typename T>
int circularSinglyLinkedList<T>::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

template <typename T>
void circularSinglyLinkedList<T>::choiceCalling(int ch)
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
			insert_after_data();
			break;
		case 5:
			insert_at_end();
			break;
		case 6:
			delete_at_beginning();
			break;
		case 7:
			delete_data();
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

template <typename T>
void circularSinglyLinkedList<T>::create()
{
	cout << "\n------------ CREATING NEW LIST ------------\n";
	tail = NULL;
	char ch;
	do
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		if(tail == NULL)
		{
			tail = newNode;
			tail -> next = newNode;
		}
		else
		{
			newNode -> next = tail -> next;
			tail -> next = newNode;
			tail = newNode;
		}
		cout << "\nDo you want to enter more nodes? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	traverse();
}

template <typename T>
void circularSinglyLinkedList<T>::traverse()
{
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		temp = tail -> next;
		cout << endl << "List: ";
		do
		{
			cout << temp -> data;
			temp = temp -> next;
			if(temp != tail -> next)
				cout << " -> ";
		}while(temp != tail -> next);
		cout << endl;
		cout << "      ^";
		int c=countList();
		for(int i=1; i<=((4*(c-1))+(c-2)); i++)
			cout << "_";
		int x=countDoubleDigit();
		if(x != 0)
			for(int j=1; j<=x; j++)
				cout << "_";
		cout << "|\n";
	}
}

template <typename T>
void circularSinglyLinkedList<T>::insert_at_beginning()
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
		newNode -> next = tail -> next;
		tail -> next = newNode;
		cout << "\nSuccessfully inserted the node at beginning\n";
		traverse();
	}
}

template <typename T>
void circularSinglyLinkedList<T>::insert_after_data()
{
	cout << "\n------------ INSERTING AFTER ANY DATA ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int i=1;
		T dat;
		cout << "Enter the new node's previous data: ";
		cin >> dat;
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		temp = tail -> next;
		do
		{
			if(dat == tail -> next -> data)
				break;
			temp = temp -> next;
			++i;
		}while(temp -> data != dat && temp != tail -> next);
		if(temp == tail)
			tail = newNode;
		newNode -> next = temp -> next;
		temp -> next = newNode;
		cout << "\nSuccessfully inserted the node after " << dat << " at position " << i+1 << endl;
		traverse();
	}
}

template <typename T>
void circularSinglyLinkedList<T>::insert_at_end()
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
		newNode -> next = tail -> next;
		tail -> next = newNode;
		tail = newNode;
		cout << "\nSuccessfully inserted the node at end\n";
		traverse();
	}
}

template <typename T>
void circularSinglyLinkedList<T>::delete_at_beginning()
{
	cout << "\n------------ DELETING AT BEGINNING ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int c = countList();
		temp = tail -> next;
		
		if(c == 1)
		{
			delete(temp);
			tail = NULL;
		}
		else
		{
			tail -> next = temp -> next;
			delete(temp);
		}
		cout << "\nSuccessfully deleted the node at beginning\n";
		traverse();
	}
}

template <typename T>
void circularSinglyLinkedList<T>::delete_data()
{
	cout << "\n------------ DELETING A DATA ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *temp1;
		int i=1;
		T dat;
		cout << "Enter the to be deleted node's data: ";
		cin >> dat;
		if(dat == tail -> next -> data)
		{
			delete_at_beginning();
		}
		else if(dat == tail -> data)
		{
			delete_at_end();
		}
		else
		{
			temp = tail -> next;
			while(temp->next->data != dat && temp->next!=tail)
			{
				temp = temp -> next;
				++i;
			}
			if(temp -> next != tail)
			{
				temp1 = temp -> next;
				temp -> next = temp1 -> next;
				delete(temp1);
				cout << "\nSuccessfully deleted node " << dat << " at " << i+1 << endl;
				traverse();
			}
			else
			{
				cout << endl << dat << " not present in list!" << endl;
			}
		}
	}
}

template <typename T>
void circularSinglyLinkedList<T>::delete_at_end()
{
	cout << "\n------------ DELETING AT END ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		int c = countList();
		temp = tail -> next;
		if(c == 1)
		{
			delete(temp);
			tail = NULL;
		}
		else
		{
			while(temp -> next -> next != tail -> next)
			{
				temp = temp -> next;
			}
			temp -> next = tail -> next;
			delete(tail);
			tail = temp;
		}
		cout << "\nSuccessfully deleted the node at end\n";
		traverse();
	}
}

template <typename T>
typename circularSinglyLinkedList<T>::node *circularSinglyLinkedList<T>::search_in_list()
{
	bool flag=false;
	T ele, count=0;
	temp = NULL;
	cout << "\n------------ SEARCHING IN LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return temp;
	else
	{
		cout << "Enter the element to be searched: ";
		cin >> ele;
		temp = tail -> next;
		do
		{
			if(temp -> data == ele)
			{
				flag = true;
				break;
			}
			temp = temp -> next;
			count++;
		}while(temp != tail -> next);
		if(flag == true)
		{
			cout << endl << ele << " found at position " << count+1 << " in the list";
			return temp;
		}
		else
		{
			temp = NULL;
			cout << endl << ele << " not found in the list\n";
			return temp;
		}
	}
}

template <typename T>
void circularSinglyLinkedList<T>::reverse_the_list()
{
	cout << "\n------------ REVERSING THE LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *prevNode, *nextNode;
		temp = tail -> next;
		nextNode = temp -> next;
		while(temp != tail)
		{
			prevNode = temp;
			temp = nextNode;
			nextNode = temp -> next;
			temp -> next = prevNode;
		}
		nextNode -> next = tail;
		tail = nextNode;
		traverse();
	}
}

template <class T>
void circularSinglyLinkedList<T>::operator + (circularSinglyLinkedList ob1)				//operator overloading
{
	cout << "\n------------ CONCATINATING ANOTHER LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *node,
					*head = tail->next,
					*head1 = ob1.tail->next,
					*temp = tail,
					*temp1 = ob1.tail->next;
		do
		{
			node = new struct node();
			node->data = temp1->data;
			node->next = head;
			temp->next = node;
			temp = temp->next;
			temp1 = temp1->next;
		}while (temp1 != head1);
		tail = temp;
		traverse();
	}
}

template <typename T>
int circularSinglyLinkedList<T>::countList()
{
	int count=0;
	temp = tail -> next;
	do
	{
		temp = temp -> next;
		count ++;
	}while(temp != tail -> next);
	return count;
}

template <typename T>
int circularSinglyLinkedList<T>::countDoubleDigit()
{
	int count=0;
	temp = tail -> next;
	do
	{
		if((temp -> data >= 10) && (temp -> data <=99))
			count ++;
		temp = temp -> next;
	}while(temp != tail -> next);
	return count;
}

template <typename T>
bool circularSinglyLinkedList<T>::emptyListChecker()
{
	if(tail == NULL)
	{
		cout << "\n########### The list is empty ###########\n";
		return false;
	}
	return true;
}

int main()
{
	int choice;
	circularSinglyLinkedList<int> ob, ob1;
	cout << "\n=========== CIRCULAR SINGLY LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		if(choice == 1)
			ob.~circularSinglyLinkedList();
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
