#pragma once

struct Edge
{
    int source;
    int destination;
    int weight;
};

struct Graph
{
    int V;
    int E;

    Edge* edge;
};

Graph* create_graph(int V, int E)
{
    Graph* graph = new Graph;
    graph -> V = V;
    graph -> E = E;

    graph -> edge = new Edge[E];

    return graph;
}