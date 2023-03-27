#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    // Input values for a
    int a[2][n];
    cout << "Enter processing times for each station on assembly line 1: ";
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    cout << "Enter processing times for each station on assembly line 2: ";
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }

    // Input values for t
    int t[2][n-1];
    cout << "Enter transfer times between stations on assembly line 1: ";
    for (int i = 0; i < n-1; i++) {
        cin >> t[0][i];
    }
    cout << "Enter transfer times between stations on assembly line 2: ";
    for (int i = 0; i < n-1; i++) {
        cin >> t[1][i];
    }

    // Input values for e
    int e[2];
    cout << "Enter entry times for each assembly line: ";
    cin >> e[0] >> e[1];

    // Input values for x
    int x[2];
    cout << "Enter exit times for each assembly line: ";
    cin >> x[0] >> x[1];

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