#include<iostream>

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    node(){
        std::cout<<"Enter the data you want to insert";
        int data;
        std::cin>>data;
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void preOrderTraversal(node* tempHead){
    if(tempHead!=NULL){
    std::cout<<tempHead->data<<" ";
    preOrderTraversal(tempHead->left);
    preOrderTraversal(tempHead->right);
    }
}

void insertNode(node* head,int data){
    node* tempParent=head;
    while(head!=NULL){
        tempParent=head;
        if(head->data>data){
            head=head->left;
        }
        else if(head->data<data){
            head=head->right;
        }
        else return;
    }
    if(tempParent->data>data){
        tempParent->left=new node(data);
    }
    else if(tempParent->data<data){
        tempParent->right=new node(data);
    }
}

node* deleteNode(node* head,int data){
    node* tempParent=head;
    if(head!=NULL){
        if(head->data>data){
            head->left=deleteNode(head->left,data);
            return head;
        }
        else if(head->data<data){
            head->right=deleteNode(head->right,data);
            return head;
        }
    }
    if(head->left==NULL){
        tempParent=head->right;
        delete(head);
        return tempParent;
    }
    else if(head->right==NULL){
        tempParent=head->left;
        delete(head);
        return tempParent;
    }
    else{
        tempParent=head;
        node* succ=head->right;
        while(succ->left!=NULL){
            tempParent=succ;
            succ=succ->right;
        }
        if(tempParent!=head){
            tempParent->left=succ->right;
        }
        else{
            tempParent->right=succ->right;
        }
        head->data=succ->data;
        delete(succ);
        return head;
    }
}

int main(){
    int nodeNum;
    std::cout<<"Enter the number of nodes you want to insert: ";
    std::cin>>nodeNum;
    int data;
    std::cout<<"Enter the value you want to insert: ";
    std::cin>>data;
    node* head=new node(data);
    insertNode(head,data);
    for(int i=0;i<nodeNum-1;i++){
        std::cout<<"Enter the value you want to insert: ";
        std::cin>>data;
        insertNode(head,data);
    }

    std::cout<<"The preorder traversal is: "<<std::endl;
    preOrderTraversal(head);
    std::cout<<"\n";
    deleteNode(head,54);
    preOrderTraversal(head);

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

    //kthMinimumElement(head,4);
    return 0;
}