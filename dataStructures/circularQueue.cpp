#include<iostream>
struct container{
    int front;
    int rear;
    int size;
    int* arr;
};

int isEmpty(struct container* temp){
    if(temp->front==temp->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct container* temp){
    if((temp->rear+1)%temp->size==temp->front){
        return 1;
    }
    else{
        return 0;
    }
}

void enQueue(struct container* temp){
    if(isFull(temp)){
        std::cout<<"Queue is full"<<std::endl;
    }
    else{
        temp->rear=(temp->rear+1)%temp->size;
        int data;
        std::cout<<"Enter element you want to enqueue: ";
        std::cin>>data;
        temp->arr[temp->rear]=data;
    }
}

int deQueue(struct container* temp){
    if(isEmpty(temp)){
        std::cout<<"There are no elements present in the queue Error: ";
        return 404;
    }
    else{
        int val;
        temp->front=(temp->front+1)%temp->size;
        val=temp->arr[temp->front];
        return val;
    }
}

int main(){
    struct container* queue=(struct container*)malloc(sizeof(struct container));
    queue->rear=queue->front=0;
    
    int size;
    std::cout<<"Enter the size of your queue: ";
    std::cin>>size;
    queue->size=size+1;

    queue->arr=(int*)malloc(size*sizeof(int));

    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    enQueue(queue);
    enQueue(queue);
    
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    // std::cout<<deQueue(queue)<<std::endl;
    // std::cout<<deQueue(queue)<<std::endl;
    // std::cout<<deQueue(queue)<<std::endl;
    // std::cout<<deQueue(queue)<<std::endl;
}