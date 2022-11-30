#include<iostream>


void printArray(int* arr,int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
}

void bubbleSort(int* arr,int size){ //Passing a pointer to array to make changes in orignal
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int size;
    std::cout<<"Enter the size of your array: ";
    std::cin>>size;
    int* arr=new int[size];

    for(int i=0;i<size;i++){
        std::cout<<"Enter element number "<<i+1<<": ";
        std::cin>>arr[i];
    }
    std::cout<<"\nThe old array was: [";
    printArray(arr,size);
    std::cout<<"]"<<std::endl;
    bubbleSort(arr,size);
    std::cout<<"\nThe new array is: [";
    printArray(arr,size);
    std::cout<<"]";
    
}