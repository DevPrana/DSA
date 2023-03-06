#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
  string s1 = "speedy";
  string s2 = "steady";
  int m = s1.size();
  int n = s2.size();
  int dp[m+1][n+1];
  int seq[m+1][n+1];
  for(int i=0;i<m+1;i++)
    for(int j=0;j<n+1;j++)
    {
      dp[i][j]=0;
      seq[i][j]=0;
    }
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(s1.at(i-1)==s2.at(j-1))
      {
        dp[i][j]= 1+dp[i-1][j-1];
        seq[i][j]=3; //to denote that the value is obtained from diagonal
        }
      else{
        int first=dp[i][j-1];
        int second=dp[i-1][j];
        dp[i][j]= first>second?first:second;
        seq[i][j]= first>second?1:2; //1 to denote that the value is obtained from left   
      }                              // 2 to denote that the value is obtained from top cell
    }                                
  }
for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
cout<<dp[i][j]<<" ";
}
cout<<"\n";
}
cout<<"seq\n";
for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
cout<<seq[i][j]<<" ";
}
cout<<"\n";
}
int last=seq[m][n];
string substring="";
int i=m,j=n;


while(i!=0 && j!=0)
{
      if(last==3) // if 3, the characters in both strings match; 
      {
      	
        substring.append(s1.substr(i-1,1)); //  so add that char to the substring
        i--; j--;                  //this is to move to the diagonally previous cell 
      }
      else if(last==1) //if 1, it means that value has come from the left cell
         j--;          // so, decrement j to move to the left cell
      else if(last==2) //if 2, it means that value has come from the top cell
         i--;          // so, decrement i to move to the top cell
      last=seq[i][j];  // value stored in that i-j th cell should be checked in the next iteration
}
cout<<"common subsequence before reversing is    "<<substring<<"\n";
reverse(substring.begin(), substring.end());
cout<<"common subsequence after reversing is    "<<substring;
}