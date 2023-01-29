#include<iostream>


void quicksort(int* arr,int low,int high){
    if(low>=high){
        return;
    }
    int start=low;
    int end=high;
    int mid=start +(end-start)/2;
    int pivot=arr[mid];
    int temp;

    while(start<=end){
        while(arr[start]<pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<=end){
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
    quicksort(arr,low,end);
    quicksort(arr,start,high);
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
    quicksort(arr,0,size-1);
    std::cout<<"\nThe new array is: [";
    printArray(arr,size);
    std::cout<<"]";
}