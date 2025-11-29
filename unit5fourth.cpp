#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter source vertex: ";
    cin >> start;

    int dist[20], visited[20];

    // initialize
    for (int i = 0; i < n; i++)
    {
        dist[i] = 9999; // infinity
        visited[i] = 0;
    }

    dist[start] = 0;

    // Dijkstra
    for (int c = 0; c < n - 1; c++)
    {
        int u = -1;

        // pick unvisited node with minimum distance
        int minVal = 9999;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minVal)
            {
                minVal = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // relax edges
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v])
            {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    return 0;
}
