#include<iostream>

class node{
    public: 
        int data;
        node* right;
        node* left;

        node(){
            int tempData;
            std::cout<<"Please enter the node data: ";
            std::cin>>tempData;
            this->data=tempData;
            this->left=NULL;
            this->right=NULL;
        }

        node(int datta){
            this->data=datta;
            this->left=NULL;
            this->right=NULL;
        }
};

node* insertInTree(node* root,int data){
    if(root==NULL){
        return (new node(data));
    }
    node* prev=root;
    while(root!=NULL){
        prev=root;
        if(root->data>data){
            root=root->left;
        }
        else if(root->data<data){
            root=root->right;
        }
        else{
            std::cout<<"This value already exists in tree!"<<std::endl;
            return root;
        }
    }
    if(prev->data>data){
        prev->left=new node(data);
        return prev->left;
    }
    else{
        prev->right=new node(data);
        return prev->right;
    }
}

node* deleteNode(node* root,int target){
    if(root==NULL){
        return root;
    }
    if((root->data)>target){
        root->left=deleteNode(root->left,target);
        return root;
    }
    else if(root->data<target){
        root->right=deleteNode(root->right,target);
        return root;
    }

    if(root->left==NULL){
        node* temp=root->right;
        delete root;
        return temp;
    }

    else if(root->right==NULL){
        node* temp=root->left;
        delete root;
        return temp;
    }

    else{   //Case for 2 nodes
        node* parent=root;
        node* succ=root->right;
        while(succ->left!=NULL){
            parent=succ;
            succ=succ->left;
        }

        if(parent!=root){
            parent->left=succ->right;
        }
        else{
            parent->right=succ->right;
        }
        root->data=succ->data;
        delete succ;
        return root;
    }
}

void preOrderTraversal(node* root){
    if(root!=NULL){
        std::cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(node* root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        std::cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(node* root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout<<root->data<<" ";
    }
}

void kthMinimumElement(node* root,int k){
    static int count=0;
    if(root!=NULL){
        kthMinimumElement(root->left,k);
        count++;
        if(count==k){
            std::cout<<"The kth minimum element is: "<<root->data<<std::endl;
        }
        kthMinimumElement(root->right,k);
    }
}

int main(){
    int nodeNum;
    std::cout<<"Enter the number of nodes you want to insert: ";
    std::cin>>nodeNum;
    int data;
    std::cout<<"Enter the value you want to insert: ";
    std::cin>>data;
    node* root=insertInTree(NULL,data);
    for(int i=0;i<nodeNum-1;i++){
        std::cout<<"Enter the value you want to insert: ";
        std::cin>>data;
        insertInTree(root,data);
    }

    std::cout<<"The preorder traversal is: "<<std::endl;
    inOrderTraversal(root);
    std::cout<<"\n";
    deleteNode(root,54);
    inOrderTraversal(root);

    /*
    Enter the value you want to insert: 76
    Enter the value you want to insert: 54
    Enter the value you want to insert: 40
    Enter the value you want to insert: 60
    Enter the value you want to insert: 66
    Enter the value you want to insert: 94
    Enter the value you want to insert: 103

    Our default tree is
           76
         /    \
       54      94
       / \       \
     40  60      103
          \
           66
    */

    //kthMinimumElement(root,4);
    return 0;
}