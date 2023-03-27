#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;
int n;
int adj[MAXN][MAXN]; 
int color[MAXN];
int m = 3;

bool isSafe(int v, int c) {
    for(int i = 0; i < n; i++) {
        if(adj[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool solve(int v) {
    if(v == n) {
        return true; 
    }
    for(int i = 1; i <= m; i++) {
        if(isSafe(v, i)) {
            color[v] = i;
            if(solve(v + 1) == true) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

void print() {
    cout << "Assigned colors are\n";
    for(int i = 0; i < n; i++) {
        cout << "Vertex " << i << "-> " << color[i] << "\n";
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    int m;
    cin >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    cout << "Enter the edges (vertex 1 and vertex 2): " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] =adj[v][u]= 1;
    }
    
    for(int i = 0; i < n; i++) {
        color[i] = 0;
    }
    solve(0);
    print();
    
    return 0;
}