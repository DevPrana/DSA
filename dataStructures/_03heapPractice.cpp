#include<iostream>
#include<limits.h>

class minHeap{
    public:
    int size;
    int last=-1;
    int* heap;

    minHeap(int size=10){
        this->size=size;
        heap= new int[size];

        for(int i=0;i<size;i++){
            heap[i]=INT_MAX;
        }
    }

    void increaseSize(){
        int curCap=this->size;
        if(this->last+1==curCap){
            int* temp=new int[2*curCap];
            for(int i=0;i<curCap;i++){
                temp[i]=this->heap[i];
            }
            for(int i=curCap;i<2*curCap;i++){
                temp[i]=INT_MAX;
            }

            this->size=2*curCap;
            this->heap=temp;
        }
    }

    int leftChildIndex(int parent){
        return 2*parent+1;
    }

    int rightChildIndex(int parent){
        return 2*parent+2;
    }

    int parentIndex(int child){
        return (child-1)/2;
    }

    int hasParent(int index){
        if(parentIndex(index)>=0){
            return 1;
        }
        return 0;
    }

    int hasLeftChild(int parent){
        if(leftChildIndex(parent)<=last){
            return 1;
        }
        else{
            return 0;
        }
    }

    int hasRightChild(int parent){
        if(rightChildIndex(parent)<=last){
            return 1;
        }
        else{
            return 0;
        }
    }

    void exchangeElem(int elementIndex1,int elementIndex2){
        if(elementIndex1!=elementIndex2){
            int temp=heap[elementIndex1];
            heap[elementIndex1]=heap[elementIndex2];
            heap[elementIndex2]=temp;
        }
    }

    void heapify(int i){
        int smallest=i;
        int rightChild=rightChildIndex(i);
        int leftChild=leftChildIndex(i);

        if(hasRightChild(i)&&heap[rightChild]<heap[smallest]){
            smallest=rightChild;
        }

        if(hasLeftChild(i)&&heap[leftChild]<heap[smallest]){
            smallest=leftChild;
        }

        if(smallest!=i){
            exchangeElem(smallest,i);
            heapify(smallest);
        }
    }

    void addElem(int data){
        increaseSize();
        heap[++(this->last)]=data;

        for(int i=size/2-1;i>=0;i--){
            heapify(i);
        }
    }

    void printArray(){
        for(int i=0;i<=last;i++){
            std::cout<<this->heap[i]<<" ";
        }
        std::cout<<"\n";
    }

    void deleteElem(){
        if(last==-1){
            std::cout<<"heap is empty";
            return;
        }
        int index=0;
        int leastIndex;
        exchangeElem(index,last--);
        if(last==-1){
            index=0;
            while(heap[index]!=INT_MAX){
                std::cout<<heap[index]<<" ";
                index++;
            }
            std::cout<<"\n";
            return;
        }
        for(int i=last/2;i>=0;i--){
            heapify(i);
        }
    }
};

int main(){
    minHeap obj;

    obj.addElem(10);
    obj.addElem(9);
    obj.addElem(8);
    obj.addElem(7);
    obj.addElem(6);
    obj.addElem(5);

    // obj.printArray();

    obj.deleteElem();
    obj.printArray();
    obj.deleteElem();
    obj.printArray();
    obj.deleteElem();
    obj.printArray();
    obj.deleteElem();
    obj.printArray();
    obj.deleteElem();
    obj.printArray();
    obj.deleteElem();
    obj.printArray();
    }