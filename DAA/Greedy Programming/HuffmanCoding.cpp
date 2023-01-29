//First we create the minheap (not the usual minheap with arrays but minheap with nodes)

#include<iostream>
#include<limits.h>

struct minNode{
    int frequency;
    char item;
    struct minNode* left,*right;
};

struct minHeap{
    int size;
    int capacity;

    struct minNode** heapArray;
};

struct minNode* newNode(char item,int freq){
    struct minNode* temp=(minNode*)malloc(sizeof(minNode));
    temp->right=temp->left=NULL;
    temp->item=item;
    temp->frequency=freq;
    return temp;
};

struct minHeap* createHeap(int capacity){
    struct minHeap* newHeap=(minHeap*)malloc(sizeof(minHeap));
    newHeap->capacity=capacity;
    newHeap->size=0;
    newHeap->heapArray=(minNode**)malloc(capacity*sizeof(minNode));
    return newHeap;
}; 

