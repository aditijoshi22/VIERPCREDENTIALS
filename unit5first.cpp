#include <iostream>
#include <queue>
using namespace std;

int graph[20][20]; // adjacency matrix
int visited[20];   // for DFS
int n;             // number of vertices

void dfs(int v)
{
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int start)
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

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && !vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
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
    bfs(start);

    return 0;
}
