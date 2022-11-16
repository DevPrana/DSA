#include<bits/stdc++.h>

int ultimateParent(int* parent,int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

int setunion(int* parent,int i,int j){
    int a=ultimateParent(parent,i);
    int b=ultimateParent(parent,j);
    parent[a]=b;
}

void kruskallsMST(int** adjacencyMatrix,int vertexNum){
    int parent[vertexNum];
    for(int i=0;i<vertexNum;i++){
        parent[i]=i;
    }
    int edgeCount=0;
    while(edgeCount!=vertexNum-1){
        int min=INT_MAX;
        int a=-1;
        int b=-1;
        for(int i=0;i<vertexNum;i++){
            for(int j=0;j<vertexNum;j++){
                if(ultimateParent(parent,i)!=ultimateParent(parent,j)&&adjacencyMatrix[i][j]<min){
                    min=adjacencyMatrix[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        setunion(parent,a,b);
        edgeCount++;
        std::cout<<a<<"->"<<b<<" cost: "<<min<<std::endl;
    }
}