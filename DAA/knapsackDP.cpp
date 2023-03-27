#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int res = dp[n][W];
    cout << "Maximum profit: " << res << endl;

    int w = W;
    cout << "Selected items: ";
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][w])
            continue;
        else {
            cout << i << " ";
            res -= val[i-1];
            w -= wt[i-1];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int i=1;
    int wt[n], val[n];
    cout << "Enter the weights and profits of the item "<<i<<": " << endl;
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    knapsack(W, wt, val, n);

    return 0;
}