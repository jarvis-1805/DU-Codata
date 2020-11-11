#include <iostream>
#define MAX 100

using namespace std;

class dijkstra
{
    public:
        int n;
        int path[MAX][MAX];

        dijkstra();

        void input();
        void show_path();
};

dijkstra::dijkstra()
{
    cout << "\nEnter the number of routers: ";
    cin >> n;
}

void dijkstra::input()
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            cout << "\nEnter distance b/w routers " << i+1 << " and " << j+1 << ": ";
            cin >> path[i][j];
            path[j][i] = path[i][j];
        }
    }
}

void dijkstra::show_path()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << path[i][j] << "  ";
        cout << endl;
    }
}

int main()
{
    dijkstra ob;
    ob.input();
}