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
    solve(0); // start filling from the 0th column
    if(!found)
        cout<<"No Solution \n";
    return 0;
}
void solve(int col){
    if(col == n){  // if col==n , it means that all n queens are placed
        found = true;
        print();
        return;
    }
    
    //loop through the row so as to try to place the queen right from 0th row onwards
    for(int i=0; i<n; i++){
        //checking if the current cell is safe to place a queen
        if(issafe(i,col)){
            //set current value to 1 to mean that u have placed a queen
            chess[i][col] = 1;
            //trying to place the next queen in the next column
            solve(col+1);
            //backtrack - reset to 0 to mean that the queen is removed
            chess[i][col] = 0;
        }
    }
}
 
//to check whether the current position is safe or not
bool issafe(int row, int col){
    //Check the same row but only upto the current cell as the subsequent columns
	// would not have been filled so far
	//if the current cell =row, col, then the cells in the same row will have 
	//indexes as (row,0),(row,1),(row,2) ....etc Hence (i--) in the loop
    for(int i=col; i>=0; i--){
        if(chess[row][i] == 1)
            return false;
    }
    //check the top diagonal 
    // if the current cell=row,col, then the cells in the top diagonals will have
    //indexes as (row-1,col-1),(row-2,col-2) etc.... Hence,(i--,j--) in the loop
    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(chess[i][j] == 1)
            return false;
    }
 
    //check the bottom diagonal
     // if the current cell=row,col, then the cells in the bottom diagonals will have
    //indexes as (row+1,col-1),(row+2,col-2) etc.... Hence,(i++,j--) in the loop
    for(int i=row, j=col; i<n && j>=0; i++,j--){
        if(chess[i][j] == 1)
            return false;
    }
    
    //return true because it is safe
    return true;
}
 
//funtion to display the board
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