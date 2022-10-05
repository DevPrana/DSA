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
    return;
}

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height=1;
};

int maxElement(int a,int b){
    return (a>b)? a:b;
}

int getHeight(struct node * n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

void preOrderTransversal(struct node* root){
    if(root!=NULL){
        std::cout<<root->data<<" ";
        preOrderTransversal(root->left);
        preOrderTransversal(root->right);
    }
}

void postOrderTransversal(struct node* root){
    if(root!=NULL){
        postOrderTransversal(root->left);
        postOrderTransversal(root->right);
        std::cout<<root->data<<" ";
    }
}

void inOrderTransversal(struct node* root){
    if(root!=NULL){
        inOrderTransversal(root->left);
        std::cout<<root->data<<" ";
        inOrderTransversal(root->right);
    }
}

int getBalanceFactor(struct node* temp){
    if(temp==NULL){
        return 0;
    }
    return (getHeight(temp->left)-getHeight(temp->right));
}

struct node* createNode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}

struct node* leftRotate(struct node* x){
    node* y=x->right;
    node* b=y->left;
    y->left=x;
    x->right=b;
    //Now we have to update heights for both x and y
    y->height=maxElement(getHeight(y->right),getHeight(y->left))+1;
    x->height=maxElement(getHeight(x->right),getHeight(x->left))+1;
    return y;
}

struct node* rightRotate(struct node* y){
    node *x = y->left;
    node *a = x->right;
    x->right = y;
    y->left = a;
    y->height = maxElement(getHeight(y->left),getHeight(y->right)) +1;
    x->height = maxElement(getHeight(x->left),getHeight(x->right)) +1;
    return x; 
}

struct node* insertNewNode(node* temp,int data){
    //Check for empty tree
    if (temp==NULL){
        return createNode(data);
    }
    if(data<temp->data){
        temp->left=insertNewNode(temp->left,data);
    }
    else if(data>temp->data){
        temp->right=insertNewNode(temp->right,data);
    }
    else return temp;

    temp->height=maxElement(getHeight(temp->left),getHeight(temp->right))+1;
    int balanceFactor=getBalanceFactor(temp);

    if(balanceFactor>1){
        if (data < temp->left->data) {
            return rightRotate(temp);
        } 
        else if (data > temp->left->data) {
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }
    }
    if (balanceFactor < -1) {
        if (data > temp->right->data) {
            return leftRotate(temp);
        } 
        else if (data < temp->right->data) {
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }
    }
    return temp;
}

node *minVal(node *temp) {
  node *cur = temp;
  while (cur->left != NULL)
    cur = cur->left;
  return cur;
}

node *deleteNode(node *parent, int data) {
  // Find the node and delete it
  if (parent == NULL)
    return parent;
  if (data < parent->data)
    parent->left = deleteNode(parent->left, data);
  else if (data > parent->data)
    parent->right = deleteNode(parent->right, data);
  else {
    if ((parent->left == NULL) ||
      (parent->right == NULL)) {
      node *tempNode = parent->left ? parent->left : parent->right;
      if (tempNode == NULL) {
        tempNode = parent;
        parent = NULL;
      } else
        *parent = *tempNode;
      free(tempNode);
    } else {
      node *tempNode = minVal(parent->right);
      parent->data = tempNode->data;
      parent->right = deleteNode(parent->right,
                   tempNode->data);
    }
  }

  if (parent == NULL)
    return parent;

  // Update the balance factor of each node and
  // balance the tree
  parent->height = 1 + maxElement(getHeight(parent->left),
               getHeight(parent->right));
  int balanceFactor = getBalanceFactor(parent);
  if (balanceFactor > 1) {
    if (getBalanceFactor(parent->left) >= 0) {
      return rightRotate(parent);
    } else {
      parent->left = leftRotate(parent->left);
      return rightRotate(parent);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(parent->right) <= 0) {
      return leftRotate(parent);
    } else {
      parent->right = rightRotate(parent->right);
      return leftRotate(parent);
    }
  }
  return parent;
}

int main(){
    minHeap obj;

    obj.addElem(10);
    obj.addElem(9);
    obj.addElem(8);
    obj.addElem(7);
    obj.addElem(6);
    obj.addElem(5);

    std::cout<<"Our sorted heap becomes: ";
    sortHeap(obj);
    std::cout<<"\n";

        node* root=NULL;
        root=insertNewNode(root,65);
        root=insertNewNode(root,11);
        root=insertNewNode(root,56);
        root=insertNewNode(root,23);
        root=insertNewNode(root,90);
        root=insertNewNode(root,106);
        root=insertNewNode(root,24);
        root=insertNewNode(root,16);
        root=insertNewNode(root,63);
        root=insertNewNode(root,74);

        std::cout<<"We will now print our balanced binary tree in different orders of traversal "<<std::endl;
        std::cout<<"Our AVL tree during preOrder traversal looks like: ";
        preOrderTransversal(root);
        std::cout<<"\nOur AVL tree during postOrder traversal looks like: ";
        postOrderTransversal(root);
        std::cout<<"\nOur AVL tree during inOrder traversal looks like: ";
        inOrderTransversal(root);

}