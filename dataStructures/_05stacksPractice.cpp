#include<iostream>

class structure{
    public:
        int top;
        int size;
        int* arr;

        structure(int size=10){
            this->size=size;
            arr=new int[size];
            top=-1;
        }

        structure(){
            this->size=10;
            arr=new int[10];
            top=-1;
        }
};

int isEmpty(structure* temp){
    if(temp->top==-1){
        return 1;
    }
    return 0;
}

int isFull(structure* temp){
    if(temp->top>=temp->size-1){
        return 1;
    }
    return 0;
}

void push(structure* temp){
    if(isFull(temp)){
        std::cout<<"Stack Overflow error!"<<std::endl;
    }
    else{
        int data;
        std::cout<<"Enter the data you wnat to push: ";
        std::cin>>data;
        temp->arr[++temp->top]=data;
    }
}

int pop(structure* temp){
    if(isEmpty(temp)){
        std::cout<<"Stack underflow error!. Err: ";
        return 404;
    }
    int val;
    val=temp->arr[temp->top];
    temp->arr[temp->top--]=0;
    return val ;
}

int main(){
    structure* stack=new structure(10);
}