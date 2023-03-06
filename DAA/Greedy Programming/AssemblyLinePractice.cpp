#include<bits/stdc++.h>

int main(){
    int a[2][6] = { {7,9,3,4,8,4},{8,5,6,4,5,7} }; 
    int t[2][5] = { {2,3,1,3,4},{2,1,2,2,1} }; 
    int e[2] = {2,4};
    int x[2] = {3,2};

    int n=6;
    int path[2][n];
    int dp[2][n];

    dp[0][0]=e[0]+a[0][0];
    dp[1][0]=e[1]+a[1][0];

    for(int j=1;j<n;j++){
        int first=dp[0][j-1]+a[0][j];
        int second=dp[1][j-1]+t[1][j-1]+a[0][j];

        if(first<second){
            dp[0][j]=first;
            path[0][j]=0;
        }

        else{
            dp[0][j]=second;
            path[0][j]=1;
        }

        first=dp[1][j-1]+a[1][j];
        second=dp[0][j-1]+t[0][j-1]+a[1][j];

        if(first<=second)
         {
         	dp[1][j]=first;
         	path[1][j]=0;
         }
         else
         {
         	dp[1][j]=second;
         	path[1][j]=1;
		}
    }

    // Here we just check whether last node + exit is smaller for which node which is then printed

    return 0;
}