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
        int path[MAX];
        bool visited[MAX];
        int distance[MAX];
        int ADJmatrix[MAX][MAX];

        dijkstra_algo(int, int);

        void ADJgraph();
        void show_graph();
        void dijkstra(int);
        int find_min_dist();
        void display_shortest_path(int);
};

dijkstra_algo::dijkstra_algo(int r, int p)
{
    routers = r;
    paths = p;
    for(int i=0; i<routers; i++)
        for(int j=0; j<routers; j++)
            ADJmatrix[i][j] = 0;
}

void dijkstra_algo::ADJgraph()
{
    int src, des, dis;
    for(int i=0; i<paths; i++)
    {
        cout << "\nPath " << i+1;
        cout << "\n======";
        cout << "\nEnter source router: ";
        cin >> src;
        cout << "Enter destination router: ";
        cin >> des;
        cout << "Enter distace of path: ";
        cin >> dis;
        ADJmatrix[src-1][des-1] = dis;
        ADJmatrix[des-1][src-1] = dis;
    }
}

void dijkstra_algo::show_graph()
{
    for(int i=0; i<routers; i++)
    {
        for(int j=0; j<routers; j++)
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
    distance[src] = 0;
    
    for(int i=0; i<routers-1; i++)
    {
        int minim = find_min_dist();
        visited[minim] = true;
        for(int j=0; j<routers; j++)
        {
            if(ADJmatrix[minim][j] && 
               !visited[j] &&
               distance[minim] + ADJmatrix[minim][j] < distance[j])
            {
                path[j] = minim;
                distance[j] = distance[minim] + ADJmatrix[minim][j];
            }
        }
    }
    
    cout << "\nDest Router\tDistance\tShortest Path\n==============================================";
    for(int i=0; i<routers; i++)
    {
        cout << endl << i+1 << "\t\t" << distance[i] << "\t\t" << (src+1);
        display_shortest_path(i);
    }
    cout << endl;
}

int dijkstra_algo::find_min_dist()
{
    int minim = -1;

    for(int i=0; i<routers; i++)
        if(!visited[i] && (minim == -1 || distance[i] < distance[minim]))
            minim = i;
    
    return minim;
}

void dijkstra_algo::display_shortest_path(int indx)
{
    if (path[indx] == -1)
        return;
    display_shortest_path(path[indx]);
    cout << " -> " << (indx + 1);
}

int main()
{
    cout << "\n============ DIJKSTRA'S SHORTEST PATH ============";
    int r, p;
    cout << "\nEnter the number of routers: ";
    cin >> r;
    cout << "Enter the number of paths: ";
    cin >> p;

    dijkstra_algo ob(r, p);
    ob.ADJgraph();
    
    cout << "\nAdjacency Matrix\n================\n";
    ob.show_graph();

    cout << "\nEnter the source router: ";
    cin >> r;
    ob.dijkstra(r-1);
}