#include<iostream>
class queue{
    public:
    int front;
    int back;
    int size;
    int* arr;

    queue(int size){
        this->size=size;
        arr=new int[size];
        front=back=-1;
    }

    queue(){
        this->size=10;
        arr=new int[this->size];
        front=back=-1;
    }

    int isEmpty(){
        if(this->front==this->back){
            return 1;
        }
        return 0;
    }

    int isFull(){
        if(this->back>=this->size-1){
            return 1;
        }
        return 0;
    }

    void enQueue(int data){
        if(isFull()){
            std::cout<<"Queue full error!"<<std::endl;
            return;
        }
        arr[++back]=data;
    }

    int deQueue(){
        if(isEmpty()){
            std::cout<<"Queue empty!"<<std::endl;
            return 404;
        }
        int temp=arr[++front];
        arr[front]=0;
        return temp;
    }
};

void BFS(int** adjacencyMatrix,bool* visited,int startVertex,int vertexNum){
    queue* obj=new queue[20];
    visited[startVertex]=true;
    obj->enQueue(startVertex);
    int dequeuedElement;
    while(!obj->isEmpty()){
        dequeuedElement=obj->deQueue();
        std::cout<<dequeuedElement<<" ";
        for(int i=0;i<vertexNum;i++){
            if(!visited[i]&&adjacencyMatrix[dequeuedElement][i]){
                obj->enQueue(i);
                visited[i]=true;
            }
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
    bool visited[vertexNum-1]={false};
    BFS(adjacencyMatrix,visited,1,4);   
}
