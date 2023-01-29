#include<bits/stdc++.h>

#define n 5

int adj[n][n]={ {0,1,1,1,1},
                {1,0,1,0,1},
                {1,1,0,1,1},
                {0,0,1,0,1},
                {0,1,1,1,0}};

int color[n];
int m=3;

bool isSafe(int v,int c){
    for(int i=0;i<n;i++){
        if(adj[v][i]&& c==color[i]){
            return false;
        }
    }
    return true;
}

bool solve(int v){
    if(v==n){
        return true; //all the vertices have been checked
    }
    for(int i=1;i<=m;i++){
        if(isSafe(v,i)){
            color[v]=i;
            if(solve(v+1)==true){
                return true;
            }
            color[v]=0;
        }
    }
    return false;
}

void print(){
    std::cout<<"Assigned colors are\n";
    for(int i=0;i<n;i++){
        std::cout<<"Vertex "<<i<<"-> "<<color[i]<<"\n";
    }
}

int main(){
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    solve(0);
    print();
}