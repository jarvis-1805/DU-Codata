#include <iostream>
#include <climits>
#include <iomanip>
#define MAX 10

using namespace std;

class dijkstra_algo
{
    private:
        int routers;
        int paths;

    public:
        bool visited[MAX];
        int distance[MAX];
        int ADJmatrix[MAX][MAX];

        dijkstra_algo(int, int);

        void ADJgraph(int, int);
        void show_graph(int);
        void dijkstra(int);
};

dijkstra_algo::dijkstra_algo(int r, int p)
{
    routers = r;
    paths = p;
}

void dijkstra_algo::ADJgraph(int r, int p)
{
    int src, des, dis;
    for(int i=0; i<p; i++)
    {
        cout << "\nRouter " << i+1;
        cout << "\n========";
        cout << "\nEnter source router: ";
        cin >> src;
        cout << "\nEnter destination router: ";
        cin >> des;
        cout << "\nEnter distace of path: ";
        cin >> dis;
        ADJmatrix[src-1][des-1] = dis;
        ADJmatrix[des-1][src-1] = dis;
    }
}

void dijkstra_algo::show_graph(int r)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
            cout << setw(5) << ADJmatrix[i][j];
        cout << endl;
    }
}

void dijkstra_algo::dijkstra(int src)
{
    for(int i=0; i<routers; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    path[src] = -1;
    
}

int main()
{
    int r, p;
    cout << "\nEnter the number of routers: ";
    cin >> r;
    cout << "\nEnter the number of paths: ";
    cin >> p;

    dijkstra_algo ob(r, p);
    ob.ADJgraph(r, p);
    ob.show_graph(r);

    cout << "\nEnter the source router: ";
    cin >> r;
    ob.dijkstra(r);
}