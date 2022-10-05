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
        postOrderTransversal(root->left);
        postOrderTransversal(root->right);
        std::cout<<root->data<<std::endl;
    }
}

void inOrderTransversal(struct node* root){
    if(root!=NULL){
        inOrderTransversal(root->left);
        std::cout<<root->data<<std::endl;
        inOrderTransversal(root->right);
    }
}

int recursiveSearchTree(struct node * root,int data){
    if(root!=NULL){
        if(root->data==data){
            return 1;
        }
        else if(root->data>data){
            return recursiveSearchTree(root->left,data);
        }
        else{
            return recursiveSearchTree(root->right,data);
        }
    }
    else{
        return 0;
    }
}

// int minElement(struct node* root){
//     while(root!=NULL){
//         root=root->left;
//     }
//     return root->data;
// }

void insertinTree(struct node* root, int data){
    struct node* prev=(struct node*)malloc(sizeof(struct node));
    while(root!=NULL){
        prev=root;
        if(root->data==data){
            return;
        }
        else if(root->data>data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    if(prev->data>data){
        prev->left=createNode(data);
    }
    else{
        prev->right=createNode(data);
    }
}

node *inOrder_Predecessor(node *root){
    root = root->left;
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *Delete(struct node* root,int val){
    struct node* prev=(struct node*)malloc(sizeof(struct node));
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    while(root->data!=val){
        if(root==NULL){
            std::cout<<"NOt found"<<std::endl;
            return NULL;
        }
        else if(root->data>val){
            prev=root;
            root=root->left;
        }
        else if(root->data<val){
            prev=root;
            root=root->right;
        }
    }
    
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    // std::cout<<(root->left)->data<<root->right;
    if(root->left != NULL && root->right != NULL){     ///This condition will true when the node have both left and right child node.
        temp = inOrder_Predecessor(root);
        root->data = temp->data;
        std::cout<<"helo";
        root->left = Delete(root->left , root->data);
    }
    else{
        temp = root;
        if(root->left == nullptr){
            root = root->right;
        }
        else if(root->right==nullptr){
            root  = root->left;
        }
        free(temp);
    }
    
}

node *delete_node(node *root , int val){
    node *temp;
    if(root == nullptr){
        std::cout<<"Element not found"<<std::endl;    }
    else if(root->data > val){
        root->left  = delete_node(root->left , val);
    }
    else if(root->data < val){
        root->right = delete_node(root->right , val);
    }
    else{
        if(root->left != nullptr && root->right != nullptr){     ///This condition will true when the node have both left and right child node.
            temp = inOrder_Predecessor(root);
            root->data = temp->data;
            root->left = delete_node(root->left , root->data);
        }
        else{     ///If the node have one child.
            temp = root;
            if(root->left == nullptr){
               root = root->right;
            }
            else{
                root  = root->left;
            }
        }
        delete(temp);
    }
    return root;
}

struct node* defaultTree(){
    struct node* p=createNode(76);
    struct node* p1=createNode(54);
    struct node* p2=createNode(94);
    struct node* p3=createNode(66);
    struct node* p4=createNode(60);
    struct node* p5=createNode(103);
    struct node* p6=createNode(40);

    p->left=p1;
    p->right=p2;
    p1->left=p6;
    p1->right=p4;
    p4->right=p3;
    p2->right=p5;

    /* Our default tree is
           76
         /    \
       54      94
       / \    /  \
     40  60  n   103
          \
           66
    */
   return p;
}

int main(){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    struct node* root1=(struct node*)malloc(sizeof(struct node));
    
    // root1=createNode(76);
    // insertinTree(root1,54);
    // insertinTree(root1,34);
    // insertinTree(root1,100);
    // preOrderTransversal(root1);

    int min,max;

    root=defaultTree();

    preOrderTransversal(root);
    std::cout<<"\n";

    Delete(root,60);
    // delete_node(root,60);
    // insertinTree(root,61);
    // insertinTree(root,62);
    // insertinTree(root,11);


    preOrderTransversal(root);
    // std::cout<<"\n";

}