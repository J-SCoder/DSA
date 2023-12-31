#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph {
    int vertex; // No. of vertices
    list<int> *adjList; // Adjacent lists pointer

public:
    Graph(int V); // Constructor
    void addEdge(int source, int destination); // Add edges to the graph
    void dfs(int startingVertex); // Initialize visited list to false and call dfsUtil
    void dfsUtil(int startingVertex, bool visited[]); // Recursive function to compute dfs
};

// Initialization and creating the adjacent list for 'V' vertices
Graph::Graph(int V) {
    this->vertex = V;
    adjList = new list<int>[V];
}

// Adding the edge to source node's adj list
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
}

// Recursive function to compute the dfs
void Graph::dfsUtil(int currentVertex, bool visited[]) {
    visited[currentVertex] = true;
    cout << currentVertex << " ";
    list<int>::iterator itr;
    for (itr = adjList[currentVertex].begin(); itr != adjList[currentVertex].end(); ++itr)
        if (!visited[*itr])
            dfsUtil(*itr, visited);
}

// Initialize all visited vertex to false and pass the starting vertex to dfsUtil function
void Graph::dfs(int startVertex) {
    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++)
        visited[i] = false;
    dfsUtil(startVertex, visited);
}

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Depth First Traversal (DFS) of the graph starting from vertex 0 : " << endl;
    g.dfs(0);
}

/*
Example graph -

                0
              /   \
             1     2
            / \   / \
           3   4 5   6

       DFS - 0 1 3 4 2 5 6

Time Complexity - O(V + E), where V is the number of vertex and E is the number of edges
*/
