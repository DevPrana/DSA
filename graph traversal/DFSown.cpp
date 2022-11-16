#include<bits/stdc++.h>
#include<vector>

class graph{
    public:
    std::map<int, bool> visited;
    std::map<int, std::list<int>> adj;

    void addEdge(int v,int w){
        adj[v].push_back(w);
    }

    void DFS(int startVertex){
        visited[startVertex]=true;
        std::cout<<startVertex<<" ";

        std::list<int>::iterator i;
        for(i=adj[startVertex].begin();i!=adj[startVertex].end();i++){
            if (!visited[*i]){
                DFS(*i);
            }
        }
    }
};

void addEdge(int** adjacencyMatrix,int x,int y){
    adjacencyMatrix[x][y]=1;
    adjacencyMatrix[y][x]=1;
}

void dfs(int** adjacencyMatrix,bool* visited,int start,int vertexNum){
    std::cout<<start<<" ";
    visited[start]=true;
    for(int i=0;i<vertexNum;i++){
        if(adjacencyMatrix[start][i]==1&&(!visited[i])){
            dfs(adjacencyMatrix,visited,i,vertexNum);
        }
    }
}

// class graph

int main(){
    // graph g;
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    // g.DFS(2);
    int noOfVertex;
    std::cout<<"Enter the number of Vertexes: ";
    std::cin>>noOfVertex;

    int** adjacencyMatrix=new int*[noOfVertex];
    for(int i=0;i<noOfVertex;i++){
        adjacencyMatrix[i]=new int[noOfVertex];
    }

    int adjacencyMatrix1[4][4] = {{0,1,1,0},{0,0,1,0},{1,0,0,1},{0,0,0,1}};

    for(int x=0;x<noOfVertex;x++){
        for(int y=0;y<noOfVertex;y++){
            // std::cout<<"Enter 1 if there exists an edge from vertex "<<x<<" to the vertex "<<y<<": ";
            adjacencyMatrix[x][y]=adjacencyMatrix1[x][y];  
            //Replace with cin command to actually take input
        }
    }

    std::cout<<"Your adjacency matrix is: "<<std::endl;

    for(int x=0;x<noOfVertex;x++){
        for(int y=0;y<noOfVertex;y++){
            std::cout<<adjacencyMatrix[x][y]<<" ";
        }
        std::cout<<"\n";
    }
    bool visited[noOfVertex];
    for(int index = 0; index < noOfVertex; index++) {
        visited[index] = false;
    }
    int startVertex;
    std::cout<<"Enter the starting vertex: ";
    std::cin>>startVertex;
    dfs(adjacencyMatrix,visited,startVertex,noOfVertex);

    return 0;
}