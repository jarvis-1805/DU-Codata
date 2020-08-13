#include<iostream>

using namespace std;

template <typename T>
class singlyLinkedList
{
	public:
		struct node
		{
			T data;
			struct node *next;
		};
		struct node *head=NULL, *newNode, *temp;
		int ch;
		
		~singlyLinkedList();
		
		void options();
		void choice();
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
		void emptyListChecker();
};

template <typename T>
singlyLinkedList<T>::~singlyLinkedList()
{
	struct node *temp1;
	temp = temp1 = head;
	while(temp != NULL)
	{
		temp1 = temp1 -> next;
		delete(temp);
		temp = temp1;
	}
	cout << "\n########### MEMORY IS FREED ###########\n";
}

template <typename T>
void singlyLinkedList<T>::options()
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
	
	choice();
}

template <typename T>
void singlyLinkedList<T>::choice()
{
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	choiceCalling(ch);
}

template <typename T>
void singlyLinkedList<T>::choiceCalling(int ch)
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
			options();
	}
}

template <typename T>
void singlyLinkedList<T>::create()
{
	cout << "\n------------ CREATING NEW LIST ------------\n";
	char ch;
	do
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		newNode -> next = NULL;
		if(head == NULL)
		{
			head = temp = newNode;
		}
		else
		{
			temp -> next = newNode;
			temp = newNode;
		}
		cout << "\nDo you want to enter more nodes? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	temp = head;
}

template <typename T>
void singlyLinkedList<T>::traverse()
{
	emptyListChecker();
	temp = head;
	cout << endl << "List: ";
	while(temp != NULL)
	{
		cout << temp -> data;
		temp = temp -> next;
		if(temp != NULL)
			cout << " -> ";
	}
	cout << endl;
}

template <typename T>
void singlyLinkedList<T>::insert_at_beginning()
{
	cout << "\n------------ INSERTING AT BEGINNING ------------\n";
	emptyListChecker();
	newNode = (struct node *)new struct node;
	cout << "Enter the new node's data : ";
	cin >> newNode -> data;
	newNode -> next = head;
	head = newNode;
	cout << "\nSuccessfully inserted the node at beginning\n";
	traverse();
}

template <typename T>
void singlyLinkedList<T>::insert_at_location()
{
	cout << "\n------------ INSERTING AT LOCATION ------------\n";
	emptyListChecker();
	int loc, i=1, count;
	count = countList();
	while(1)
	{
		cout << "Enter the new node's location: ";
		cin >> loc;
		if(loc > count || loc == 0)
		{
			cout << "\n########### WRONG LOCATION... ###########\n";
			continue;
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
			cout << "\nSuccessfully inserted the node at " << loc << endl;
			traverse();
			break;
		}
	}
}

template <typename T>
void singlyLinkedList<T>::insert_at_end()
{
	cout << "\n------------ INSERTING AT END ------------\n";
	emptyListChecker();
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
	cout << "\nSuccessfully inserted the node at end\n";
	traverse();
}

template <typename T>
void singlyLinkedList<T>::delete_at_beginning()
{
	cout << "\n------------ DELETING AT BEGINNING ------------\n";
	emptyListChecker();
	int c = countList();
	if(c == 0)
		cout << "The list is empty";
	else
	{
		temp = head;
		head = head -> next;
		delete(temp);
		cout << "\nSuccessfully deleted the node at beginning\n";
		traverse();
	}
}

template <typename T>
void singlyLinkedList<T>::delete_at_location()
{
	cout << "\n------------ DELETING AT LOACTION ------------\n";
	emptyListChecker();
	struct node *temp1;
	int loc, i=1, count;
	count = countList();
	while(1)
	{
		cout << "Enter the to be deleted node's location: ";
		cin >> loc;
		if(loc == 1)
		{
			delete_at_beginning();
			break;
		}
		if(loc > count || loc == 0)
		{
			cout << "\n########### WRONG LOCATION... ###########\n";
			continue;
		}
		else
		{
			temp = head;
			temp1 = head;
			while(i < loc-1)
			{
				temp = temp -> next;
				temp1 = temp1 -> next;
				++i;
			}
			if(temp -> next -> next == NULL)
			{
				delete_at_end();
				break;
			}
			temp -> next = temp -> next -> next;
			delete(temp1 -> next);
			cout << "\nSuccessfully deleted node at " << loc << endl;
			traverse();
			break;
		}
	}
}

template <typename T>
void singlyLinkedList<T>::delete_at_end()
{
	cout << "\n------------ DELETING AT END ------------\n";
	emptyListChecker();
	int c = countList();
	temp = head;
	if(c == 1)
	{
		delete(temp -> next);
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

template <typename T>
void singlyLinkedList<T>::search_in_list()
{
	bool flag=false;
	T ele, count=0;
	cout << "\n------------ SEARCHING IN LIST ------------\n";
	emptyListChecker();
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

template <typename T>
void singlyLinkedList<T>::reverse_the_list()
{
	cout << "\n------------ REVERSING THE LIST ------------\n";
	emptyListChecker();
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

template <typename T>
int singlyLinkedList<T>::countList()
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
void singlyLinkedList<T>::emptyListChecker()
{
	if(head == NULL)
	{
		cout << "\n########### The list is empty ###########\n";
		options();
	}
}

int main()
{
	singlyLinkedList<char> ob;
	cout << "\n=========== SINGLY LINKED LIST ===========\n";
	do
	{
		ob.options();
		if(ob.ch == 0)
			break;
	}while(1);
	
	cout << "\n########### EXITING... ###########\n";
	return 0;
}