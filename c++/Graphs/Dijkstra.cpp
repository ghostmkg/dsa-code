//Dijkstra algorithm optimal implementation using priority queues
#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>

using namespace std;
class node
{
public:
    int data;
    int weight;
    node(int data, int weight) : data(data), weight(weight)
    {
    }
};
class Graph
{
public:
    vector<list<node>> G;
    int n;
    Graph(int n) : n(n), G(n)
    {
    }
    int weight(int u, int v)
    {
        for (auto node : G[u])
        {
            if (node.data == v)
                return node.weight; // If there exists edge between two vertices we return the weight of edge
        }
        return INT_MAX; // If there is no edge between two vertices we return INT_MAX
    }
    void addEdge(int u, int v, int w, bool undirected = true)
    {
        if (weight(u, v) != INT_MAX)
            return; // Before adding a edge to a vertex we check if there already exists that edge
        G[u].push_back(node(v, w));
        if (undirected) // When graph is undirected
            G[v].push_back(node(u, w));
    }
    void print()
    {

        for (int i = 0; i < n; i++)
        {
            cout << "Node " << i << " -> ";
            for (auto &node : G[i])
            {
                cout << "(" << node.data << ", w=" << node.weight << ") ";
            }
            cout << "\n";
        }
    }
};

vector<int> Dijkstra(Graph G)
{
    vector<int> d(G.n, INT_MAX);
    int source = 0; // We considered 0 as node here
    d[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //We store distance in first, vertex in second
    pq.push({d[source],source});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(dis>d[v])continue; //When the distance is more than the shortest distance that means we have already visited that node with shortest distance, so its not required to reprocess
        for(auto n:G.G[v])
        {
            int vertex=n.data;
            int distance=n.weight;
            if(d[v]+distance<d[vertex])
            {
                d[vertex]=d[v]+distance;
                pq.push({d[vertex],vertex});
            }
        }
    }
    return d;
}

int main()
{
    Graph G(6);
    G.addEdge(0, 1, 50, false);
    G.addEdge(0, 2, 45, false);
    G.addEdge(1, 2, 10, false);
    G.addEdge(1, 3, 15, false);
    G.addEdge(3, 4, 15, false);
    G.addEdge(2, 4, 30, false);
    G.addEdge(4, 2, 35, false);
    G.addEdge(5, 4, 3, false);
    G.addEdge(4, 1, 20, false);
    G.addEdge(0, 3, 10);
    vector<int> d = Dijkstra(G);
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] != INT_MAX)
            cout << i << ":" << d[i] << endl;
        else
            cout << i << ":Infinte(Path doesn't exist)" << endl;
    }
    return 0;
}

/*
Complexity analysis
T.C=O((E+V)logV)
S.C
O(E)
*/