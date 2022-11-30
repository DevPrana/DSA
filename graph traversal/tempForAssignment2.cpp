#include<bits/stdc++.h>

void dfs(int** adjacencyMatix,bool* visited,int curVertex,int vertexNum){
    std::cout<<curVertex<<" ";
    visited[curVertex]=true;
    for(int i=0;i<vertexNum;i++){
        if(adjacencyMatix[curVertex][i]==1&&visited[i]==false){
            dfs(adjacencyMatix,visited,i,vertexNum);
        }
    }
}

int main(){
    int vertexNum;
    std::cout<<"Enter the number of vertexes: ";
    std::cin>>vertexNum;

    int** adjacencyMatrix=new int*[vertexNum];
    for(int i=0;i<vertexNum;i++){
        adjacencyMatrix[i]=new int[vertexNum];
    }

    int adjacencyMatrix1[4][4] = {{0,1,1,0},{0,0,1,0},{1,0,0,1},{0,0,0,1}};

    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            // std::cout<<"Enter 1 if there exists an edge from vertex "<<x<<" to the vertex "<<y<<": ";
            adjacencyMatrix[x][y]=adjacencyMatrix1[x][y];  
            //Replace with cin command to actually take input
        }
    }

    std::cout<<"Your adjacency matrix is: "<<std::endl;

    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            std::cout<<adjacencyMatrix[x][y]<<" ";
        }
        std::cout<<"\n";
    }

    bool visited[vertexNum];
    for(int i=0;i<vertexNum;i++){
        visited[i]=false;
    }


}