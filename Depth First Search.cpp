#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;    // No. of vertices


    list<int>* adj;   // Pointer to an array containing adjacency lists


    void DFSUtil(int v, bool visited[]);  // A recursive function used by DFS

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}


void Graph::DFS(int v)
{

    bool* visited = new bool[V];  // Mark all the vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;


    DFSUtil(v, visited);
}

// Driver code
int main()
{

    Graph g(4);    // Construct a graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal is ";
    g.DFS(2);

    return 0;
}
