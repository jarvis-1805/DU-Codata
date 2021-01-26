/*
Sahil is in the mood to attend Geeks Classes. He reaches venue of Geeks Classess.
Now, he is confused about his sitting place.
There are two columns of students sitting in the classes.
Each student has been assigned a score on the basis of their score in Geeks Class Entrance Contest.
Now, he wants to sit in the row which contains students with maximum score.
Help him in finding the desired column.

Input : First line of Input contains testcase "T".
For each testcase "T", there will be 3 lines of input,
first line contains lengths of the columns,
and next two lines contains the scores of students sitting in that column.

Output : For each testcase, Output the column in which Sahil should sit.

Constraints :
1 <= T <= 100
1 <= N1, N2 <= 10000
1 <= score <= 1000000

Example :
Input :
2
5 6
8 4 5 6 7
2 3 4 5 6 7
3 5
100 29 37
100 200 300 400 500
Output :
C1
C2

Explanation :
TestCase 1 : In 1st column sum of score of students is 30
which is more than 2nd column (score = 27).

TestCase 2 : In 2nd column sum of score of students is 1500
which is more than 1st column (score = 166).
*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t, n1, n2, c1[10000], c2[10000], sumC1, sumC2;
    int output[100], x=0;
	cin >> t;
	for(int i=1; i<=t; i++)
	{
        sumC1 = 0, sumC2 = 0;
	    cin >> n1 >> n2;
        for(int j=0; j<n1; j++)
        {
            cin >> c1[j];
            sumC1 += c1[j];
        }
        for(int j=0; j<n2; j++)
        {
            cin >> c2[j];
            sumC2 += c2[j];
        }
        if(sumC1 > sumC2)
        {
            output[x] = 1;
        }
        else
        {
            output[x] = 2;
        }
        x++;
	}
    for(int k=0; k<x; k++)
    {
        cout << "C" << output[k] << endl;
    }
	return 0;
}