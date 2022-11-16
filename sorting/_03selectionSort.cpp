#include<iostream>

int maxIndexFunc(int* arr,int last){
    int maxnum=INT_MIN;
    int maxIndex;
    for(int i=0;i<last;i++){
        if(arr[i]>maxnum){
            maxnum=arr[i];
            maxIndex=i;
        }
    }
    // std::cout<<"The current max index is: "<<maxIndex<<std::endl; Debugging purposes only
    return maxIndex;
}

void selectionSort(int* arr,int size){
    int maxIndex;
    int last;
    for(int i=0;i<size;i++){
        last=size-i-1;
        maxIndex=maxIndexFunc(arr,last+1);
        int temp=arr[maxIndex];
        arr[maxIndex]=arr[last];
        arr[last]=temp;
    }
}

void printArray(int* arr,int size){
    for(int i=0;i<size-1;i++){
        std::cout<<arr[i]<<", ";
    }
    std::cout<<arr[size-1];
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
    selectionSort(arr,size);
    std::cout<<"\nThe new array is: [";
    printArray(arr,size);
    std::cout<<"]";
}