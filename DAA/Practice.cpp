#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s1 = "speedy";
    string s2 = "steady";
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    int seq[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
            seq[i][j]=0;
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1.at(i-1)==s2.at(j-1)){
                dp[i][j]=1+dp[i-1][j-1];
                seq[i][j]=3;
            }

            else{
                int first=dp[i][j-1];
                int second=dp[i-1][j];
                dp[i][j]=first>second?first:second;
                seq[i][j]=first>second?1:2;
            }
        }
    }

    int last=seq[m][n];
    string substri="";
    int i=m;int j=n;
    while(i!=0&&j!=0){
        if(last==3){
            substri.append(s1.substr(i-1,1));
            i--;j--;
        }
        else if(last==2){
            i--;
        }
        else if(last==1){
            j--;
        }
        last=seq[i][j];
    }

    cout<<substri;
    return 0;
}