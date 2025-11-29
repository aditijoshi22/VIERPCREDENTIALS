#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *adj[20]; // adjacency list heads
int visited[20];

void addEdge(int u, int v)
{
    Node *t = new Node;
    t->data = v;
    t->next = adj[u];
    adj[u] = t;

    // Undirected graph: add reverse edge
    t = new Node;
    t->data = u;
    t->next = adj[v];
    adj[v] = t;
}

void dfs(int v)
{
    visited[v] = 1;
    cout << v << " ";

    Node *temp = adj[v];
    while (temp)
    {
        if (!visited[temp->data])
            dfs(temp->data);
        temp = temp->next;
    }
}

void bfs(int start, int n)
{
    int vis[20] = {0};
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        Node *temp = adj[v];
        while (temp)
        {
            if (!vis[temp->data])
            {
                vis[temp->data] = 1;
                q.push(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS: ";
    dfs(start);

    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    cout << "BFS: ";
    bfs(start, n);

    return 0;
}
