#include<iostream>
#include<limits.h>

class minHeap{
    public:
        int size;
        int last=-1;
        int *heap;

    public:
        minHeap(int size=10){
            this->size=size;
            heap=new int[size];

            for(int i=0;i<size;i++){
                heap[i]=INT_MAX;
            }
        }

        void increaseSize(){
            int curCap=this->size;
            if(this->last+1==curCap){
                int* tempArr=new int[2*curCap];

                for(int i=0;i<curCap;i++){
                    tempArr[i]=this->heap[i];
                }

                for(int i=curCap;i<2*curCap;i++){
                    tempArr[i]=INT_MAX;
                }

                this->size*=2;
                this->heap=tempArr;
            }
            return;
        }

        int leftChildIndex(int parent){
            return ((2*parent)+1);
        }

        int rightChildIndex(int parent){
            return ((2*parent)+2);
        }

        int parentIndex(int child){
            return ((child-1)/2);
        }

        int hasParent(int index) {
            if( parentIndex(index) >= 0 ) {
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

        int getLeftChild(int parent){
            return heap[leftChildIndex(parent)];
        }

        int getRightChild(int parent){
            return heap[rightChildIndex(parent)];
        }

        int getParent(int child){
            return heap[parentIndex(child)];
        }

        void exchangeElem(int elemIndex1,int elemIndex2){
            if(elemIndex1!=elemIndex2){
                int temp=heap[elemIndex1];
                heap[elemIndex1]=heap[elemIndex2];
                heap[elemIndex2]=temp;
            }
        }

        void addElem(int element){
            increaseSize();

            int index=++last;
            heap[index]=element;

            while(hasParent(index)&&(getParent(index)>heap[index])){
                exchangeElem(index,parentIndex(index));
                index=parentIndex(index);
            }
        }

        void deleteElem(){
            if(last==-1){
                printf("Heap is Empty!!");
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

            leastIndex=index;

            while(true){
                if (hasLeftChild(index)&&(getLeftChild(index))<heap[leastIndex]){
                    leastIndex=leftChildIndex(index);
                }

                if (hasRightChild(index)&& (getRightChild(index))<heap[leastIndex]){
                    leastIndex=rightChildIndex(index);
                }

                if(leastIndex==index){
                    break;
                }
                exchangeElem(index,leastIndex);
                index=leastIndex;
            }
        }

};

void sortHeap(minHeap obj){
    int a=obj.last+1;
    for(int i=0;i<a;i++){
        obj.deleteElem();
    }
}

int main(){
    minHeap obj;

    obj.addElem(10);
    obj.addElem(9);
    obj.addElem(8);
    obj.addElem(7);
    obj.addElem(6);
    obj.addElem(5);

    sortHeap(obj);

    // obj.deleteElem();
    // obj.deleteElem();
    // obj.deleteElem();
    // obj.deleteElem();
    // obj.deleteElem();
    // obj.deleteElem();
    return 0;
}