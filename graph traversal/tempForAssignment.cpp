#include<bits/stdc++.h>

int minimumKeyValue(int* key,bool* mstValue,int vertexNum){
    int min=INT_MAX,min_index; // Yeh line samajhni hai baadmein
    for (int v = 0; v < vertexNum; v++)
        if (mstValue[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int searcher(int* parent,int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void setUnion(int* parent,int i, int j)
{
	int a = searcher(parent,i);
	int b = searcher(parent,j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int** cost,int vertexNum)
{   
    int parent[vertexNum];

	int mincost = 0;
	for (int i = 0; i < vertexNum; i++)
		parent[i] = i;
	int edge_count = 0;
	while (edge_count < vertexNum - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < vertexNum; i++) {
			for (int j = 0; j < vertexNum; j++) {
				if (searcher(parent,i) != searcher(parent,j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		setUnion(parent,a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

//Find MST using prims algorithm
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
    std::cout<<"The Output using Prims algorithm is: "<<std::endl;
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

    int adjacencyMatrix1[5][5]={{INT_MAX,2,INT_MAX,6,INT_MAX},{2,INT_MAX,3,8,5},{INT_MAX,3,INT_MAX,INT_MAX,7},{6,8,INT_MAX,INT_MAX,9},{INT_MAX,5,7,9,INT_MAX}};

    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            std::cout<<"Enter the weight if there exists an edge from vertex "<<x<<" to the vertex "<<y<<"or enter 0: ";
            std::cin>>adjacencyMatrix[x][y];  
        }
    }

    std::cout<<"Your adjacency matrix is: "<<std::endl;


    std::cout<<"We will now print the formed MST by providing the edges joined (x to y) nad their corresponding weights:"<<std::endl;
    for(int x=0;x<vertexNum;x++){
        for(int y=0;y<vertexNum;y++){
            std::cout<<adjacencyMatrix[x][y]<<" ";
        }
        std::cout<<"\n";
    }

    primsMST(adjacencyMatrix,vertexNum);
    kruskalMST(adjacencyMatrix,vertexNum);
    return 0;
}