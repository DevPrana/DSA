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

void peek(struct container* temp,int index){
    if(isEmpty(temp)){
        std::cout<<"There are no elements in the stack to peek Error: ";
    }
    else{
        std::cout<<temp->arr[index]<<std::endl;
    }
}

int stackBottom(struct container* temp){
    if(isEmpty(temp)){
        std::cout<<"The Stack is Empty! "<<std::endl;
        return 0;
    }
    else{
        int val=temp->arr[0];
        return val;
    }
}

int stackTop(struct container* temp){
    if(isEmpty(temp)){
        std::cout<<"The stack is Empty/n Error: ";
        return 404;
    }
    else{
        int val=temp->arr[temp->top];
        return val;
    }
}

char * infixToPostfix(char * infix){
    struct container * sp=(struct container *)malloc(sizeof(struct container));
    
}