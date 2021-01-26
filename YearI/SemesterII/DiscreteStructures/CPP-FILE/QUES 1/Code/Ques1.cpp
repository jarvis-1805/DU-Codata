#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

bool ismember(int size,int A[])
{
    int a;
    cout << "\nEnter the element to be searched: ";
    cin >> a;

    for(int i=0;i<size;i++)
    {
        if(A[i]==a)
            return true;
    }

    return false;
}

void print(char code[],int arr[], int n)
{

    int i;

    cout << "\t{";
    for(i=0; i<n; i++)
    {
        if(code[i] == '1')
            cout << arr[i] << " ";
    }
    cout << "}";

    cout << "        {";
    for(i=0; i<n; i++)
    {
        if(code[i] == '0')
            cout << arr[i] << " ";
    }
    cout << "}\n";
}

void genUnionSet(int arr[], int n)
{
    int i,r,l;
    char binary[n];
    r=pow(2,n-1);

    for(i=0; i<n; i++)
        binary[i]='0';

    for(i=0; i<r; i++)
    {
        print(binary, arr, n);
        l=n-1;

        h:
            if(binary[l] == '0')
                binary[l]='1';

            else
            {
                binary[l]='0';
                l--;
                goto h;
            }
    }
}

int main()
{
    bool x;
    int size;
	char ch = 'Y';
	
	while(ch == 'Y')
	{
		cout << "\nEnter the size of set: ";
		cin >> size;

		int A[size];
		cout << "\nEnter the elements: ";
		for(int i=0;i<size;i++)
		{
			cin >> A[i];
		}

		x=ismember(size,A);
		if(x==true)
			cout << "\n\tValue is present!!!";

		else
			cout << "\n\tValue is not present!!!";

		cout << "\n\nThe possible subset pairs\n" << endl;
		genUnionSet(A,size);
		
		cout << "\nDo you want to continue? (Y/N): ";
		cin >> ch;
	}
	
	cout << "\n@@@@EXITING@@@";
	
    return 0;
}
