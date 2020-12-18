#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;               // No. of vertices
    list<int> *adj;     // Pointer to an array containing adjacency lists


public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
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

void Graph::BFS(int s)
{

    bool *visited = new bool[V];  // Mark all the vertices as not visited
    for(int i = 0; i < V; i++)
        visited[i] = false;


    list<int> queue;    // Create a queue for BFS


    visited[s] = true;  // Mark the current node as visited and enqueue it
    queue.push_back(s);


    list<int>::iterator i;    // 'i' will be used to get all adjacent vertices of a vertex

    while(!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();


        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}


int main()
{
    // Construct a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout <<" Breadth First Traversal"<<" ";
    g.BFS(2);

    return 0;
}
