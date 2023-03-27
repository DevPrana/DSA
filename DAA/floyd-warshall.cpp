#include<iostream>
#include<climits>
using namespace std;

void floydWarshall(int graph[][100], int V)
{
    int dist[V][V];
    int next[V][V];

    // initialize distance matrix and next matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
            if (dist[i][j] != INT_MAX)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Output shortest path and distance for each pair of vertices
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && next[i][j] != -1)
            {
                cout << "Shortest path from vertex " << i << " to vertex " << j << ": ";
                cout << i << " ";
                int k = next[i][j];
                while (k != j)
                {
                    cout << k << " ";
                    k = next[k][j];
                }
                cout << j << endl;
                cout << "Shortest distance: " << dist[i][j] << endl;
            }
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    int graph[100][100];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cout << "Enter the vertices and weight of edge " << i+1 << ": ";
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    floydWarshall(graph, V);
    return 0;
}