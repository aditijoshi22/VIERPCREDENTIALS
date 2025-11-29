#include <iostream>
using namespace std;

struct Node
{
    int v, w; // vertex, weight
    Node *next;
};

Node *adj[20]; // adjacency lists
int n;         // number of vertices

void addEdge(int u, int v, int w)
{
    Node *t = new Node;
    t->v = v;
    t->w = w;
    t->next = adj[u];
    adj[u] = t;

    // Undirected graph
    t = new Node;
    t->v = u;
    t->w = w;
    t->next = adj[v];
    adj[v] = t;
}

int main()
{
    int e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    cout << "Enter edges (u v w): \n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    int selected[20] = {0};
    selected[0] = 1; // start at vertex 0

    int edges = 0;
    int cost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int minWt = 9999;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                Node *t = adj[i];
                while (t)
                {
                    if (!selected[t->v] && t->w < minWt)
                    {
                        minWt = t->w;
                        a = i;
                        b = t->v;
                    }
                    t = t->next;
                }
            }
        }

        selected[b] = 1;
        edges++;
        cost += minWt;

        cout << a << " - " << b << " (weight = " << minWt << ")\n";
    }

    cout << "\nTotal Minimum Cost: " << cost << endl;

    return 0;
}
