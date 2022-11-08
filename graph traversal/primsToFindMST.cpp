#include<bits/stdc++.h>

int minimumKeyValue(int* key,bool* mstValue,int vertexNum){
    int min=INT_MAX,min_index; 
    for (int v = 0; v < vertexNum; v++)
        if (mstValue[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primsMST(int** adjacencyMatrix,int vertexNum){
    int parent[vertexNum];
    int key[vertexNum];
    bool mstValues[vertexNum];

    for(int i=0;i<vertexNum;i++){
        key[i]=INT_MAX;
        mstValues[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<vertexNum;count++){
        int lower=minimumKeyValue(key,mstValues,vertexNum);
        mstValues[lower]=true; //marking visited

        for(int v=0;v<vertexNum;v++){
            if (adjacencyMatrix[lower][v] && mstValues[v] == false
                && adjacencyMatrix[lower][v] < key[v])
                parent[v] = lower, key[v] = adjacencyMatrix[lower][v];
        }
    }
    std::cout<<"Output using Prim's algorithm is: "<<std::endl;
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < vertexNum; i++)
        std::cout << parent[i] << " - " << i << " \t"
             << adjacencyMatrix[i][parent[i]] << " \n";
}


int main(){
    int vertexNum;
    std::cout<<"Enter the number of vertexes: ";
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

    std::cout<<"Your adjacency matrix is: "<<std::endl;


    // std::cout<<"We will now print the formed MST by providing the edges joined (x to y) nad their corresponding weights:"<<std::endl;
    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            std::cout<<adjacencyMatrix[x][y]<<" ";
        }
        std::cout<<"\n";
    }

    primsMST(adjacencyMatrix,vertexNum);
    return 0;
}