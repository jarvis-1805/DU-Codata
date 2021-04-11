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

    struct Edge* edge;

    // constructor
    Graph(int V, int E)
    {
        this -> V = V;
        this -> E = E;
        this -> edge = new Edge[E];
    }

    // destructor
    ~Graph()
    {
        // nullify the member variable before deleting its memory is just a safety measure pertaining to multithreading.
        struct Edge* _edge = this -> edge;
        this -> edge = nullptr;
        delete _edge;
    }
};