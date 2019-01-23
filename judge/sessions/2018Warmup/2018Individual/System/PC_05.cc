// borrowed from https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
// C++ program to print connected components in
// an undirected graph
#include<iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    
    // Pointer to an array containing adjacency lists
    list<int> *adj;
    
    // A function used by DFS
    int DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void connectedComponents(vector<int>& c);
};

// Method to print connected components in an
// undirected graph
void Graph::connectedComponents(vector<int>& c)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
    
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            // print all reachable vertices
            // from v
            c.push_back(DFSUtil(v, visited));
        }
    }
}

int Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    int sum = 1;
    
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i]) {
            sum += DFSUtil(*i, visited);
        }
    return sum;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Drive program to test above
int main()
{
    int t;
    cin >> t;
    int n, l, k;
    int a, b;
    for (int z = 0; z < t; z++) {
        cin >> n >> l >> k;
        Graph g(n);
        for (int i = 0; i < l; i++) {
            cin >> a >> b;
            g.addEdge(a-1, b-1);
        }
        vector<int> c;
        g.connectedComponents(c);
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
    
        int large = 0;
        int j = -1;
        auto i = c.begin();
        for (; i != c.end(); i++ ) {
            if (j < k) {
                large += *i;
            } else {
                break;
            }
            j++;
        }
        int sum = (large * (large-1)) / 2;
        
        while (i != c.end()) {
            sum += ((*i) * ((*i)-1)) / 2;
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}
