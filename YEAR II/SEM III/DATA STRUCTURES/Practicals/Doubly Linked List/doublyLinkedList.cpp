#include<iostream>

using namespace std;

template <typename T>
class doublyLinkedList
{
	public:
		struct node
		{
			struct node *prev;
			T data;
			struct node *next;
		};
		struct node *head=NULL, *newNode, *temp;
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
		void search_in_list();
		void reverse_the_list();
		
		int countList();
		bool emptyListChecker();
};

template <typename T>
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
	cout << "\n########### MEMORY IS FREED ###########\n";
}

template <typename T>
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
		<<	"\n0. EXIT";
}

template <typename T>
int doublyLinkedList<T>::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	return ch;
}

template <typename T>
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
			search_in_list();
			break;
		case 10:
			reverse_the_list();
			break;
		case 0:
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
	}
}

template <typename T>
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
			head = temp = newNode;
		}
		else
		{
			temp -> next = newNode;
			newNode -> prev = temp;
			temp = newNode;
		}
		cout << "\nDo you want to enter more nodes? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	traverse();
}

template <typename T>
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

template <typename T>
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

template <typename T>
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
		temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
		newNode -> prev = temp;
		cout << "\nSuccessfully inserted the node at end\n";
		traverse();
	}
}

template <typename T>
void doublyLinkedList<T>::delete_at_beginning()
{
	cout << "\n------------ DELETING AT BEGINNING ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		temp = head;
		head = head -> next;
		head -> prev = NULL;
		delete(temp);
		cout << "\nSuccessfully deleted the node at beginning\n";
		traverse();
	}
}

template <typename T>
void doublyLinkedList<T>::delete_at_location()
{
	cout << "\n------------ DELETING AT LOACTION ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *temp1;
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
				temp = temp1 = head;
				while(i < loc-1)
				{
					temp = temp -> next;
					temp1 = temp -> next;
					++i;
				}
				temp -> next = temp1 -> next;
				temp1 -> next -> prev = temp;
				delete(temp1);
				cout << "\nSuccessfully deleted node at " << loc << endl;
				traverse();
				break;
			}
		}
	}
}

template <typename T>
void doublyLinkedList<T>::delete_at_end()
{
	cout << "\n------------ DELETING AT END ------------\n";
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
			head = NULL;
			cout << "\nSuccessfully deleted the node at end\n";
		}
		else
		{
			while(temp -> next -> next != NULL)
			{
				temp = temp -> next;
			}
			delete(temp -> next);
			temp -> next = NULL;
			cout << "\nSuccessfully deleted the node at end\n";
		}
		traverse();
	}
}

template <typename T>
void doublyLinkedList<T>::search_in_list()
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
		}while(temp != NULL);
		if(flag == true)
			cout << endl << ele << " found at position " << count+1 << " in the list\n";
		else
			cout << endl << ele << " not found in the list\n";
	}
}

template <typename T>
void doublyLinkedList<T>::reverse_the_list()
{
	cout << "\n------------ REVERSING THE LIST ------------\n";
	emp = emptyListChecker();
	if(emp != true)
		return;
	else
	{
		struct node *prevNode, *nextNode;
		prevNode = NULL;
		temp = nextNode = head;
		while(nextNode != NULL)
		{
			nextNode = nextNode -> next;
			temp -> next = prevNode;
			prevNode = temp;
			temp = nextNode;
		}
		head = prevNode;
		traverse();
	}
}

template <typename T>
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

template <typename T>
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
	doublyLinkedList<int> ob;
	cout << "\n=========== DOUBLY LINKED LIST ===========\n";
	do
	{
		ob.options();
		choice = ob.choice();
		if(choice == 0)
			break;
		if(choice == 1)
			ob.~doublyLinkedList();
		ob.choiceCalling(choice);
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	return 0;
}