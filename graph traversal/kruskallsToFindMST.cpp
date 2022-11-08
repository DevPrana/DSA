#include <bits/stdc++.h>
using namespace std;

int searcher(int* parent,int i){
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void setUnion(int* parent,int i, int j){
	int a = searcher(parent,i);
	int b = searcher(parent,j);
	parent[a] = b;
}

void MSTusingKruskals(int** adjacencyMatrix,int vertexNum)
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
				if (searcher(parent,i) != searcher(parent,j) && adjacencyMatrix[i][j] < min) {
					min = adjacencyMatrix[i][j];
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
            // std::cout<<"Enter the weight if there exists an edge from vertex "<<x<<" to the vertex "<<y<<"or enter 0: ";
            // std::cin>>adjacencyMatrix[x][y]; 
			adjacencyMatrix[x][y]=adjacencyMatrix1[x][y]; 
        }
    }

    // std::cout<<"Your adjacency matrix is: "<<std::endl;


    // // std::cout<<"We will now print the formed MST by providing the edges joined (x to y) nad their corresponding weights:"<<std::endl;
    // for(int x=0;x<vertexNum;x++){
    //     for(int y=0;y<vertexNum;y++){
    //         std::cout<<adjacencyMatrix[x][y]<<" ";
    //     }
    //     std::cout<<"\n";
    // }
	std::cout<<"Your MST is: "<<std::endl;
    MSTusingKruskals(adjacencyMatrix,vertexNum);
    return 0;
}
