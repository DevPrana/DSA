#include <bits/stdc++.h>

int find(int* parent,int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void union1(int* parent,int i, int j)
{
	int a = find(parent,i);
	int b = find(parent,j);
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
				if (find(parent,i) != find(parent,j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(parent,a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}
int main()
{
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
            std::cout<<"Enter the weight if there exists an edge from vertex "<<x<<" to the vertex "<<y<<"or enter 0: ";
            adjacencyMatrix[x][y]=adjacencyMatrix1[x][y];  
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
	kruskalMST(adjacencyMatrix,vertexNum);

	return 0;
}
