#include <bits/stdc++.h>

#define n 4

#define cap 5

using namespace std;

int wt[] = {1,2,4,5};

  int val[] = {5,4,8,6};

int dp[n+1][cap+1];

int main() {

 for(int i=0;i<n+1;i++)

   dp[i][0]=0;

   for(int j=0;j<cap+1;j++)

      dp[0][j]=0;

 for(int i=1;i<n+1;i++) 

    for(int j=1;j<cap+1;j++)

    {

     int arr_index=i-1;  //in dp array, 0th row & 0th col store only zeroes. But wt[] & val[] arrays, actual values start from 0th index itself

     int notinclude = 0 + dp[i-1][j];

    int include = INT_MIN;

    if(wt[arr_index] <= j)

        include = val[arr_index] + dp[i-1][cap-wt[arr_index]];

    dp[i][j] = include>notinclude?include:notinclude;

  	}

	for(int i=0;i<n+1;i++) 

	{

    for(int j=0;j<cap+1;j++)

      cout<<dp[i][j]<<"  ";

    cout<<"\n";

    }

                                

  cout<<"The Maximum value of items is " <<dp[n][cap]<<"\n";

  cout<<"included items are \n";

  int row=n,col=cap;

  while(row>0 || col>0)

  {

  	if(dp[row][col]!=dp[row-1][col])  //if the value in the last row & last col == value in the previous row

  	{

  	  int arr_index=row-1; 

	  cout<<"item "<<row<<" with weight "<<wt[arr_index]<<"\n";

	  //if the item is included, the col to be explored next is current capacity-wt of this item

	  col-=wt[arr_index]; 

    }

  	row--; //for the next time, row-1 should be explored regardless of whether the current item is included or not

  }

}