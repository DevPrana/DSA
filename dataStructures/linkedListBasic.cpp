#include <iostream>

struct Node{
    int data;
    struct Node * next;
};

void transversal(struct Node* ptr){
    while(ptr!=NULL){
        std::cout<<ptr->data<<std::endl;
        ptr=ptr->next;
    }
}

struct Node * creation(int elements){
    struct Node * head=(struct Node*)malloc(sizeof(struct Node));
    struct Node * tempptr=head;
    // tempptr=head;
    int datta;
    for(int index=0;index<elements;index++){
        std::cin>>datta;
        tempptr->data=datta;
        if(index == (elements-1) ){
            tempptr->next=NULL;
            // tempptr=NULL; This does nt work as when we assign temptr to null it assigns the variable itself to NULL but when we do tempptr->next to NULL it dereferences the tempptr to the next variable of where it is currently pointing to
            //Use python tutor visualize to get more info
            break;
        }
        tempptr->next = (struct Node*)malloc(sizeof(struct Node));
        tempptr=tempptr->next;
    }
    return head;
}

struct Node * insertFirst(struct Node *head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

void insertAt(struct Node* head,int data,int index){
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node* temp=head;
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;  
}

void insertEnd(struct Node* head,int data){
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    ptr->next=NULL;
    temp->next=ptr;
}

struct Node* deleteFirst (struct Node* head){
    head=head->next;
    return head;
}

void deleteIndex(struct Node* head,int index){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    temp=head;
    // struct Node* pop=(struct Node*)malloc(sizeof(struct Node));
    for(int i = 0 ; i < (index-1); i++){
        temp=temp->next;
    }
    p=temp->next;
    temp->next=p->next;
    free(p);
}

void deleteLast(struct Node* head){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=head;
    while((temp->next)->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
}
int main(){
    struct Node* head= new Node;

    int size;
    std::cout<<"Enter size of your linked list"<<std::endl;
    std::cin>>size;
    
    head=creation(size);
    std::cout<<"\nYour linked list is: "<<std::endl;
    
    transversal(head);
    
    //? Code to insert element in beginning
    // std::cout<<"\nEnter element at first"<<std::endl;
    // int first;
    // std::cin>>first;

    // head=insertFirst(head,first);
    // transversal(head);

    //? Code to insert element at an index
    // std::cout<<"\nEnter index where we insert element"<<std::endl;
    // int index;
    // std::cin>>index;
    
    // std::cout<<"\nEnter what element do you want to insert"<<std::endl;
    // int datas;
    // std::cin>>datas;

    // insertAt(head,datas,index);
    // transversal(head);

    //? Code to delete first element
    // head = deleteFirst(head);
    // std::cout<<"\nAfter deletion the linked list: "<<std::endl;
    // transversal(head);

    //?Code to delete index element
    // int index;
    // std::cout<<"Enter index which you want to delete: ";
    // std::cin>>index;
    // deleteIndex(head,index);
    // std::cout<<std::endl;
    // transversal(head);    
    
    //?Code to delete last element in a linked list
    // deleteLast(head);
    // std::cout<<std::endl;
    // transversal(head);
    
    return 0;
}