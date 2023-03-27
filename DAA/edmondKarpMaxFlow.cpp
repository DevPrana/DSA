#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int INF = 1000000000;

int n, s, t;             // Number of nodes, source, and sink
int capacity[MAXN][MAXN], flow[MAXN][MAXN], parent[MAXN];
int bfs(int s, int t)     // Find augmenting path
{
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(s);
    parent[s] = -2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                parent[v] = u;
                if (v == t)
                    return 1;
                q.push(v);
            }
        }
    }
    return 0;
}
int maxflow(int s, int t)
{
    int u, v;
    int maxflow = 0;
    while (bfs(s, t)) {         // Edmonds-Karp Algorithm
        int pathflow = INF;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathflow = min(pathflow, capacity[u][v] - flow[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            flow[u][v] += pathflow;
            flow[v][u] -= pathflow;
        }
        maxflow += pathflow;
    }
    return maxflow;
}
int main()
{
    int m, u, v, w;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    for (int i = 0; i < m; i++) {
        cout << "Enter edge " << i+1 << " (u v w): ";
        cin >> u >> v >> w;
        capacity[u][v] = w;
    }
    s = 0;
    t = n - 1;
    cout << "The maximum flow is " << maxflow(s, t) << "." << endl;
    return 0;
}