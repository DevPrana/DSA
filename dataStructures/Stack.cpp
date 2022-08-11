#include <iostream>

struct container{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct container* temp){
    if(temp->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct container* temp){
    if( (temp->top) == (temp->size)-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct container* temp){
    if(isFull(temp)){
        std::cout<<"Stack Overflow! "<<std::endl;
    }
    else{
        temp->top++;
        int data;
        std::cout<<"Enter the element you want to push: ";
        std::cin>>data;
        temp->arr[temp->top]=data;
    }
}

int pop(struct container* temp){
    if(isEmpty(temp)){
        std::cout<<"Stack Underflow!"<<std::endl;
    }
    else{
        int val = temp->arr[temp->top];
        temp->arr[temp->top]=0;
        temp->top--;
        return val;
    }
    return -1;
}

int peek(struct container* temp,int index){
    if(isEmpty(temp)){
        std::cout<<"There are no elements in the stack to peek Error: ";
        return -101;
    }
    else{
        int val=temp->arr[index];
        return val;
    }
}

int main(){

    struct container* stack=(struct container*)malloc(sizeof(container));
    stack->top=-1;
    int size;
    std::cout<<"Enter size of your stack: ";
    std::cin>>size;
    stack->size=size;
    
    stack->arr=(int *)malloc( stack->size * sizeof(int) );

    //?Code to push elements into stack
    push(stack);
    push(stack);
    push(stack);
    push(stack);
    push(stack);
    int index;
    std::cin>>index;
    std::cout<<"The element at index "<<index<<" is "<<peek(stack,index)<<std::endl;

    return 0;
}