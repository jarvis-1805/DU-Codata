#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Edge {
    int src, dest;
};

class Graph
{
    public:
        vector<vector<int>> adjList;

        Graph(vector<Edge> const &edges, int N)
        {
            adjList.resize(N+1);

            for (auto &edge: edges)
            {
                adjList[edge.src].push_back(edge.dest);
                adjList[edge.dest].push_back(edge.src);
            }
        }
};

struct Node {
    int vertex, parent;
};

bool BFS(Graph const &graph, int src, int N)
{
    vector<bool> visited(N, false);
    vector<int> par(N+1);

    visited[src] = true;

    queue<Node> q;
    q.push({src, -1});

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        // do for every edge `v —> u`
        for (int u: graph.adjList[node.vertex])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push({ u, node.vertex });
                par[u] = node.vertex;
            }

            // `u` is visited, and `u` is not a parent
            else if (u != node.parent)
            {
                Node newNode;
                int commonParent = findCommonParent(visited[u], newNode);

                string result = "";

                Node current;

                current =  visited[u];
                while(current.v != commonParent) {
                    result = current.parent.v + "--" + current.v + ", " + result;
                    current = current.parent;
                }

                current = newNode;
                while(current.v != commonParent) {
                    result = result + current.v + "--" + current.parent.v + ", ";
                    current = current.parent;
                }
                result = result.substring(0, result.length() - 2);

                cout << result << endl;
                return true;
            }
        }
    }

    return false;
}

int findCommonParent(Node n1, Node n2) {     
    vector<int> n1Parents = new HashSet<Integer>();
    Node temp = n1.parent;
    while(temp != null) {
        n1Parents.add(temp.v);
        temp = temp.parent;
    }       
    temp = n2.parent;
    while(temp != null) {
        if(n1Parents.contains(temp.v)) {
            break;
        }
        temp = temp.parent;
    }

    return temp.v;
}

void printGraph(Graph const &graph, int N)
{
    cout << "Src :Source Node  adj :Adjacent Nodes\n" << "Src---adj adj\n";
    for (int i = 1; i <=N; i++)
    {
        cout << i << "----- ";

        for (int v: graph.adjList[i]) {
            cout << v << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int N, source, destination, e;
    vector<Edge> edges;

    cout << "Enter the number of vertices : ";
    cin >> N;
    cout << "Enter the number of edges:";
    cin >> e;
    for(int i=1; i<=e; i++) {
        cout << "\nFor edge "<< i <<":\n";
        cout << "Source vertex : ";
        cin >> source;
        cout << "Destination vertex : ";
        cin >> destination;
        edges.push_back({source, destination});
    }

    Graph graph(edges, N);
    
    if (BFS(graph, 1, N)) {
        cout << "The graph contains a cycle\n";
        printGraph(graph, N);
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }

    return 0;
}