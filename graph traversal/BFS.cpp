#include <iostream>

struct container{
    int front;
    int back;
    int size;
    int *arr;
};

int isFull(struct container* temp){
    if(temp->back==(temp->size)-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enQueue(struct container* temp,int data){
    if(isFull(temp)){
        std::cout<<"The queue is already full"<<std::endl;
    }
    else{
        temp->back++;
        temp->arr[temp->back]=data;
    }
}

int deQueue(struct container* temp){
    if(temp->front==temp->back){
        std::cout<<"There are no more elements to deQueue! Error: ";
        return 404;
    }
    else{
        temp->front++;
        return temp->arr[temp->front];
    }
}

int isEmpty(struct container* temp){
    if(temp->back==temp->front){
        return 1;
    }
    return 0;
}

void breadthFirstSearch(int sourceVertex, int noOfVertices, int** adjacencyMatrix){
    struct container* queue=(struct container*)malloc(sizeof(struct container));
    queue->back=queue->front=-1;
    std::cout<<"Enter the size of the queue: ";
    std::cin>>queue->size;
    queue->arr=(int*)malloc((queue->size)*sizeof(int));
    int dequeuedElement;

    bool visited[noOfVertices - 1];
    for(int index = 0; index < noOfVertices; index++) {
        visited[index] = false;
    }

    enQueue(queue,sourceVertex);
    visited[sourceVertex]=true;

    while(!isEmpty(queue)){
        dequeuedElement = deQueue(queue); 
        printf("%d, ", dequeuedElement);

        for(int i=0;i<noOfVertices;i++){
            if(adjacencyMatrix[dequeuedElement][i]!=0 && visited[i]==false){
                enQueue(queue,i);
                visited[i]=true;
            }
        }
    }
}

int main(){
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

    int startVertex;
    std::cout<<"Enter the starting vertex: ";
    std::cin>>startVertex;
    breadthFirstSearch(startVertex,noOfVertex,adjacencyMatrix);
    return 0;
}