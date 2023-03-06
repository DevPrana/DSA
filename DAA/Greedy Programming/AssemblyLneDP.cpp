#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    int a[2][6] = { {7,9,3,4,8,4},{8,5,6,4,5,7} }; 
    int t[2][5] = { {2,3,1,3,4},{2,1,2,2,1} }; 
    int e[2] = {2,4};
    int x[2] = {3,2}; 
    int n=6;
    int path[2][n];
   int dp[n][n];
 
    // time taken to reach station 0 in assembly line 0 
    dp[0][0] = e[0] + a[0][0]; 
     
    // time taken to reach station 0 in assembly line 1
    dp[1][0] = e[1] + a[1][0]; 
 
    for(int j = 1; j< n; j++) 
    { 
         int first=dp[0][j - 1] + a[0][j];
         int second=dp[1][j - 1] + t[1][j-1] + a[0][j];
         if(first<=second)
         {
         	dp[0][j]=first;
         	path[0][j]=0;
         }
         else
         {
         	dp[0][j]=second;
         	path[0][j]=1;
		 }
		 first=dp[0][j - 1] + t[0][j-1] + a[1][j];
		 second=dp[1][j - 1] + a[1][j];
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
 
    int last;
    if(dp[0][n-1] + x[0]<dp[1][n-1] + x[1])
     last=0;
	else
	  last=1;
    cout<< min(dp[0][n-1] + x[0], dp[1][n-1] + x[1])<<"\n";
	int i=last;  
	cout<<"exit should be reached from assembly line "<<i <<"\n";
	for(int j = n-1; j>0; j--) 
	{
		i=path[i][j];
		 cout<<"station " <<j <<" should be reached from assembly line "<<i <<"\n";
		
	 } 
    return 0; 
}