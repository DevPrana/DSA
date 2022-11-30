#include<iostream>

int main(){
    int size;
    std::cout<<"Enter size of array: ";
    std::cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        std::cin>>arr[i];
    }

    int elem;
    std::cout<<"Enter the element you want to search: ";
    std::cin>>elem;
    for(int i=0;i<size;i++){
        if(elem==arr[i]){
            std::cout<<"Found element at position: "<<i+1<<std::endl;
        }
    }
}