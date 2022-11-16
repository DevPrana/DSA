#include<iostream>

int binarySearch(int* arr,int target,int size){
    int start=0;
    int end=size-1;
    if(start>end){
        return -1;
    }
    while(start<=end){
        int middle=start +(end-start)/2;
        if(arr[middle]>target){         //Checks if if middle element is greater than target
            end=middle;               //is middle is greater makes our end to middle-1 index to now check in that index range
        }
        else if(arr[middle]<target){
            start=middle+1;
        }
        else{
            return middle;
        }
    }
    return -1;
}

int binarySearchRecursive(int* arr,int start,int end,int target){
    int middle=start+(end-start)/2;
    if(arr[middle]>target){
        return  binarySearchRecursive(arr,start,middle,target);
    }
    else if(arr[middle]<target){
        return binarySearchRecursive(arr,middle+1,end,target);
    }
    else if(arr[middle]==target){
        return middle;
    }
    return -1;
}

int main(){
    int size;
    std::cout<<"Enter the size of your array: ";
    std::cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        std::cout<<"Enter element "<<i+1<<": ";
        std::cin>>arr[i];
    }
    
    std::cout<<"Your element is present at index: "<<binarySearchRecursive(arr,0,size-1,4);
}