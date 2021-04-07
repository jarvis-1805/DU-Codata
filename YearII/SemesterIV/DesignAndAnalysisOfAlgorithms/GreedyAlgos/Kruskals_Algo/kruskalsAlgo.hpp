#include <stdlib.h>
#include <tuple>

#include "../Graph/Graph.hpp"

class Kruskals_Algo
{
    private:
        struct subset
        {
            int parent;
            int rank;
        };

        void make_set(subset*, int);
        int find_set(subset*, int);
        void _union(subset*, int, int);
    
    public:
        std::tuple <Edge*, int>kruskal(Graph*);
        void print_kruskals_MST(Edge*, int);
};

void Kruskals_Algo::make_set(subset* subsets, int V)
{
    subsets[V].parent = V;
    subsets[V].rank = 0;
}

int Kruskals_Algo::find_set(subset* subsets, int V)
{
    if(subsets[V].parent != V)
        subsets[V].parent = find_set(subsets, subsets[V].parent);
    
    return subsets[V].parent;
}

void Kruskals_Algo::_union(subset* subsets, int x, int y)
{
    int xroot = find_set(subsets, x);
    int yroot = find_set(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

inline int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

std::tuple <Edge*, int>Kruskals_Algo::kruskal(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph -> edge, graph -> E, sizeof(graph -> edge[0]), myComp);

    subset* subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v)
        make_set(subsets, v);
    
    while(e < V - 1 && i < graph -> E)
    {
        Edge next_edge = graph -> edge[i++];
 
        int x = find_set(subsets, next_edge.source);
        int y = find_set(subsets, next_edge.destination);

        if (x != y)
        {
            result[e++] = next_edge;
            _union(subsets, x, y);
        }
    }
    Edge* res = result;
    return std::make_tuple(res, e);
}

void Kruskals_Algo::print_kruskals_MST(Edge* result, int e)
{
    int minimumCost = 0;
    for(int i=0; i<e; ++i)
    {
        std::cout << result[i].source << " -- " << result[i].destination << " == " << result[i].weight << std::endl;
        minimumCost = minimumCost + result[i].weight;
    }
    
    std::cout << "Minimum Cost Spanning Tree: " << minimumCost << std::endl;
}