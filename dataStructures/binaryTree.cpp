#include<iostream>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* createNode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp-> data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preOrderTransversal(struct node* root){
    if(root!=NULL){
        std::cout<<root->data<<std::endl;
        preOrderTransversal(root->left);
        preOrderTransversal(root->right);
    }
}

void postOrderTransversal(struct node* root){
    if(root!=NULL){
        preOrderTransversal(root->left);
        preOrderTransversal(root->right);
        std::cout<<root->data<<std::endl;
    }
}

struct node* defaultTree(){
    struct node* p=createNode(7);
    struct node* p1=createNode(2);
    struct node* p2=createNode(3);
    struct node* p3=createNode(4);
    struct node* p4=createNode(6);
    struct node* p5=createNode(76);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;

    /* Our default tree is
           7
         /   \
        2     3
       / \   / \
      4   6 n   76
    */
   return p;
}


int main(){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    
    root=defaultTree();
    
    std::cout<<"The preorder transversal is as follows: "<<std::endl;
    preOrderTransversal(root);
    std::cout<<"\n";
    
    std::cout<<"The postorder transversal is as follows: "<<std::endl;
    postOrderTransversal(root);
    std::cout<<"\n";
    

}