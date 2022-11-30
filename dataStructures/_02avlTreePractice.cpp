#include<iostream>
class node{
    public:
    int data;
    int height;
    node* right;
    node* left;

    node(){
        std::cout<<"Please enter your data element";
        std::cin>>data;
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int maxElement(int a,int b){
    return a>b?a:b;
}

int getHeight(node* temp){
    if(temp!=NULL){
        return temp->height;
    }
    return 0;
}

int getBalanceFactor(node* temp){
    if(temp!=NULL){
        return getHeight(temp->left)-getHeight(temp->right);
    }
    return 0;
}

void preOrderTraversal(node* temp){
    if(temp!=NULL){
        std::cout<<temp->data<<" ";
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
}

node* leftRotate(node* y){
    node*x=y->right;
    node*b=x->left;
    x->left=y;
    y->right=b;
    //Update the heights of our rotated tree
    x->height=maxElement(getHeight(x->left),getHeight(x->right))+1;
    y->height=maxElement(getHeight(y->left),getHeight(y->right))+1;
    return x;
}

node* rightRotate(node* y){
    node*x=y->left;
    node*b=x->right;
    x->right=y;
    y->left=b;
    //Update the heights of our rotated tree
    x->height=maxElement(getHeight(x->left),getHeight(x->right))+1;
    y->height=maxElement(getHeight(y->left),getHeight(y->right))+1;
    return x;
}
