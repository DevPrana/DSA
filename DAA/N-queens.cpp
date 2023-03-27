#include <iostream>
#include <stdlib.h>
using namespace std;
void solve(int);
bool issafe(int , int);
void print();
int n;
int chess[20][20];
bool found = false;
 
int main(){
    cout<<"Enter number of Queens: ";
    cin>>n;
    solve(0);
    if(!found)
        cout<<"No Solution \n";
    return 0;
}
void solve(int col){
    if(col == n){  
        found = true;
        print();
        return;
    }
    
    for(int i=0; i<n; i++){
        if(issafe(i,col)){
            chess[i][col] = 1;
            solve(col+1);
            chess[i][col] = 0;
        }
    }
}
 
bool issafe(int row, int col){
    for(int i=col; i>=0; i--){
        if(chess[row][i] == 1)
            return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(chess[i][j] == 1)
            return false;
    }
 
    for(int i=row, j=col; i<n && j>=0; i++,j--){
        if(chess[i][j] == 1)
            return false;
    }
    
    return true;
}
 
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chess[i][j] == 1)
                cout<<" Q ";
            else
                cout<<" - ";
        }
        cout<<"\n";
    }
     cout<<"\n";
}