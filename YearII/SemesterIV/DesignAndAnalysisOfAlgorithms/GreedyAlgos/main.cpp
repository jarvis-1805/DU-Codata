#include <iostream>
#include <vector>

#include "Graph/Graph.hpp"

#include "Kruskals_Algo/kruskalsAlgo.hpp"
#include "Prims_Algo/primsAlgo.hpp"

using namespace std;

class GreedyAlgos
{        
    public:
        int ch;
        void options();
        int choice();
        void choiceCalling(int);

        void kruskals_mst();
        void prims_mst();
};

void GreedyAlgos::options()
{
    cout << "\n------- MENU -------";
    cout << "\n1. KRUSKAL'S MST"
        << "\n2. PRIM'S MST"
        << "\n0. EXIT";
}

int GreedyAlgos::choice()
{
    cout << "\n\nEnter the number of your choice: ";
    cin >> ch;
    return ch;
}

void GreedyAlgos::choiceCalling(int ch)
{
    switch(ch)
    {
        case 1:
            kruskals_mst();
            break;
        case 2:
            prims_mst();
            break;
        case 0:
            break;
        default:
            cout << "\n########### WRONG CHOICE... ###########\n";
    }
}

void GreedyAlgos::kruskals_mst()
{
    Kruskals_Algo kr;
    
    int V;
    int E;
    int source, destination, weight;
    vector<Edge> result;
    
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;
    
    Graph* graph = new Graph(V, E);

    for(int i=0; i<E; i++)
    {
        cout << "\nEnter source, destinstion and weight: ";
        cin >> source >> destination >> weight;
        graph -> edge[i].source = source;
        graph -> edge[i].destination = destination;
        graph -> edge[i].weight = weight;
    }

    tie(result, E) = kr.kruskal(graph);
    kr.print_kruskals_MST(result, E);
}

void GreedyAlgos::prims_mst()
{
    int V;
    int E;
    int source, destination, weight;
    
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    cout << "\nEnter the number of edges: ";
    cin >> E;

    Prims_Algo pr(V);

    vector<vector<int>> graph1(V, vector<int>(V));
    vector<int> parent;

    for(int i=0; i<E; i++)
    {
        cout << "\nEnter source, destinstion and weight: ";
        cin >> source >> destination >> weight;
        graph1[source][destination] = weight;
        graph1[destination][source] = weight;
        graph1[source][source] = 0;
    }
    
    tie(parent, graph1) = pr.prim(graph1);
    pr.print_prims_MST(parent, graph1);
}

int main()
{
    int choice;
    GreedyAlgos greedy;
    do
    {
        cout << "\n=========== GREEDY ALGORITHMS ===========\n";
        greedy.options();
        choice = greedy.choice();
        if(greedy.ch == 0)
            break;
        system("clear");
        cout << "\n=========== GREEDY ALGORITHMS ===========\n";
        greedy.choiceCalling(choice);
        cout << "\nPress Enter to continue...";
        cin.ignore();
        getchar();
        system("clear");
    }while(1);
    
    return 0;
}