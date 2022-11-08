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

int isEmpty(struct container* temp){
    if(temp->back==temp->front){
        return 1;
    }
    return 0;
}

void enQueue(struct container* temp){
    if(isFull(temp)){
        std::cout<<"The queue is already full"<<std::endl;
    }
    else{
        temp->back++;
        int data;
        std::cout<<"Enter the element you want to queue up: ";
        std::cin>>data;
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

int main(){
    struct container* queue=(struct container*)malloc(sizeof(struct container));
    queue->back=queue->front=-1;
    
    int size;
    std::cout<<"Enter the size of your queue: ";
    std::cin>>size;
    queue->size=size;

    queue->arr=(int*)malloc(size*sizeof(int));

    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    enQueue(queue);
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
    std::cout<<deQueue(queue)<<std::endl;
}