#include <limits.h>
#include <tuple>

class Prims_Algo
{
    private:
        int V;
        int extract_min(std::vector<int>, std::vector<bool>);
    
    public:
        Prims_Algo(int V)
        {
            this -> V = V;
        }

        std::tuple<std::vector<int>, std::vector<std::vector<int>> >  prim(std::vector<std::vector<int>>);
        void print_prims_MST(std::vector<int>, std::vector<std::vector<int>>);
};

int Prims_Algo::extract_min(std::vector<int> key, std::vector<bool> mstSet)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < this -> V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void Prims_Algo::print_prims_MST(std::vector<int> parent, std::vector<std::vector<int>> graph)
{
	std::cout << "Edge \tWeight\n";
	for (int i = 1; i < this -> V; i++)
		std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

std::tuple<std::vector<int>, std::vector<std::vector<int>> >  Prims_Algo::prim(std::vector<std::vector<int>> graph)
{
	std::vector<int> parent(this -> V);

	std::vector<int> key(this -> V);

	std::vector<bool> mstSet(this -> V);

	for (int i = 0; i < this -> V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < this -> V - 1; count++)
	{
		int u = extract_min(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < this -> V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	
	return std::make_tuple(parent, graph);
}