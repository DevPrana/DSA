#include<iostream>

class node{
    public:
        int data;
        node* left;
        node* right;
        int height;
        node(){
            std::cout<<"Enter the value you want to insert in this node: ";
            std::cin>>this->data;
            this->left=NULL;
            this->right=NULL;
            this->height=1;
        }

        node(int datta){
            this->data=datta;
            this->left=NULL;
            this->right=NULL;
            this->height=1;
        }
};

int maxElement(int a,int b){
    return (a>b)? a:b;
}

int getHeight(node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
void preOrderTransversal(node* root){
    if(root!=NULL){
        std::cout<<root->data<<" ";
        preOrderTransversal(root->left);
        preOrderTransversal(root->right);
    }
}
int getBalanceFactor(node* temp){
    if(temp==NULL){
        return 0;
    }
    return (getHeight(temp->left)-getHeight(temp->right));
}

node* leftRotate(node* x){
    node* y=x->right;
    node* b=y->left;
    y->left=x;
    x->right=b;
    //Now we have to update heights for both x and y
    x->height=maxElement(getHeight(x->right),getHeight(x->left))+1;
    y->height=maxElement(getHeight(y->right),getHeight(y->left))+1;
    return y;
}

node* rightRotate(node* y){
    node *x = y->left;
    node *a = x->right;
    x->right = y;
    y->left = a;
    y->height = maxElement(getHeight(y->left),getHeight(y->right)) +1;
    x->height = maxElement(getHeight(x->left),getHeight(x->right)) +1;
    return x; 
}

node* insertNewNode(node* temp,int data){
    //Check for empty tree
    if (temp==NULL){
        node* a=new node(data);
        return a;
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

int main(){
    int nodeNum;
    std::cout<<"Enter the number of nodes you want to insert: ";
    std::cin>>nodeNum;
    int data;
    std::cout<<"Enter the value you want to insert: ";
    std::cin>>data;
    node* root=insertNewNode(NULL,data);
    for(int i=0;i<nodeNum-1;i++){
        std::cout<<"Enter the value you want to insert: ";
        std::cin>>data;
        root=insertNewNode(root,data);
    }

    std::cout<<"The preorder traversal is: "<<std::endl;
    preOrderTransversal(root);

    /*
    Enter the value you want to insert: 76
    Enter the value you want to insert: 54
    Enter the value y
    
    
    
    ou want to insert: 40
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
