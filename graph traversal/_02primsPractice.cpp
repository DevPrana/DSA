#include<bits/stdc++.h>

int minKey(bool* visited,int* key,int vertexNum){
    int min=INT_MAX;
    int minIndex;
    for(int i=0;i<vertexNum;i++){
        if(visited[i]==false&&key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void primsMst(int** adjacencyMatrix,int vertexNum){
    int parent[vertexNum];
    int key[vertexNum];
    bool visited[vertexNum];

    for(int i=0;i<vertexNum;i++){
        key[i]=INT_MAX;
        visited[i]=false;
    }
    parent[0]=-1;
    key[0]=0;

    for(int i=0;i<vertexNum;i++){
        int u=minKey(visited,key,vertexNum);
        visited[u]=true;

        for(int j=0;j<vertexNum;j++){
            if(adjacencyMatrix[u][j]&&adjacencyMatrix[u][j]<key[j]&&!visited[j]){
                parent[j]=i;
                key[j]=adjacencyMatrix[u][j];
            }
        }
    }
}


int main(){
    int vertexNum;
    std::cout<<"Enter number of vertices: ";
    std::cin>>vertexNum;
    int** adjacencyMatrix=new int*[vertexNum];
    for(int i=0;i<vertexNum;i++){
        adjacencyMatrix[i]=new int[vertexNum];
    }

    int adjacencyMatrix1[5][5]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};

    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            // std::cout<<"Enter the weight if there exists an edge from vertex "<<x<<" to the vertex "<<y<<" or enter 0: ";
            // std::cin>>adjacencyMatrix[x][y];
            adjacencyMatrix[x][y]=adjacencyMatrix1[x][y];  
        }
    }

    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            std::cout<<adjacencyMatrix[x][y]<<" ";
        }
        std::cout<<"\n";
    }

    primsMst(adjacencyMatrix,vertexNum);
}