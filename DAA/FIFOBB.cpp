#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int n;
int w[MAX], p[MAX], limit;
bool visited[MAX][MAX];
queue<pair<int, int>> Q;

void bfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    if (i < n - 1) Q.push(make_pair(i + 1, j));
    if (j + w[i] <= limit) Q.push(make_pair(i + 1, j + w[i]));
}

int knapsack() {
    int best = 0;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        pair<int, int> current = Q.front();
        Q.pop();
        int i = current.first;
        int j = current.second;
        best = max(best, j);
        bfs(i, j);
    }
    return best;
}

int main() {
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the weight and profit of each item: \n";
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }
    cout << "Enter the knapsack capacity: ";
    cin >> limit;
    int result = knapsack();
    cout << "Maximum profit that can be obtained = " << result << endl;
    return 0;
}