#include <iostream>
#include <climits>
using namespace std;

void matrixChainOrder(int p[], int n)
{
    int m[n][n], k[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    ::k[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications is " << m[1][n - 1] << endl;
    cout << "Optimal Parenthesization is : " << endl;
    cout << "( ";
    printOptimalParenthesis(1, n - 1);
    cout << ")" << endl;

    cout << "K table values are:" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) {
                cout << "0\t";
            } else {
                cout << ::k[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void printOptimalParenthesis(int i, int j)
{
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesis(i, ::k[i][j]);
        printOptimalParenthesis(::k[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int n = 3;
    int arr[] = {4, 3, 5, 2};
    matrixChainOrder(arr, n + 1);
    return 0;
}