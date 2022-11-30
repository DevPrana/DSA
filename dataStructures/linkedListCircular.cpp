#include <iostream>

struct Node{
    int data;
    struct Node * next;
};

void transversal(struct Node* ptr){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));    //Creation first then initialization later (for clarity only)
    temp=ptr;
    do{
        std::cout<<ptr->data<<std::endl;
        ptr=ptr->next;
    }
    while(ptr!=temp);     
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
            tempptr->next=head;
            // tempptr=NULL; This does nt work as when we assign temptr to null it assigns the variable itself to NULL but when we do tempptr->next to NULL it dereferences the tempptr to the next variable of where it is currently pointing to
            //Use python tutor visualize to get more info
            break;
        }
        tempptr->next = (struct Node*)malloc(sizeof(struct Node));
        tempptr=tempptr->next;
    }
    return head;
}

struct Node* insertFirst(struct Node* head){
    struct Node* temp=head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    int data;
    std::cout<<"Enter data in new node: ";
    std::cin>>data;
    newNode->data=data;
    do{
        temp=temp->next;
    }
    while(temp->next!=head);
    temp->next=newNode;
    newNode->next=head;
    return newNode;
}

void insertIndex(struct Node* head,int index,int size){
    // index=(index+1)%size;
    // index-=1;
    if(index==0){
        insertFirst(head);
    }
    else{
        int data;
        std::cout<<"Enter the data you want to insert: ";
        std::cin>>data;
        struct Node* temp=head;
        struct Node* p=(struct Node*)malloc(sizeof(struct Node));
        p->data=data;
        for(int i = 0; i < (index-1); i++ ){
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
}

void insertLast(struct Node* head){
    struct Node* temp=head;
    int data;
    std::cout<<"Enter the data you want to insert: ";
    std::cin>>data;
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    do{
        temp=temp->next;
    }
    while(temp->next!=head);
    temp->next=p;
    p->next=head;
}

int main(){
    struct Node* head= new Node;

    int size;
    std::cout<<"Enter size of your linked list"<<std::endl;
    std::cin>>size;
    
    head=creation(size);
    std::cout<<"\nYour linked list is: "<<std::endl;
    transversal(head);
    std::cout<<std::endl;  
    

    //? Code to insert in the beggining of the circular linked list
    // head=insertFirst(head);
    // std::cout<<"Your new list is: "<<std::endl;
    // transversal(head);

    //? Code to insert in the middle with given index
    // int index;
    // std::cout<<"Enter index of th element where you want to insert element: ";
    // std::cin>>index;
    // insertIndex(head,index,size);
    // std::cout<<"Your new list is: "<<std::endl;
    // transversal(head);

    //? Code to insert element before head pointer
    // insertLast(head);
    // std::cout<<"Your new list is: "<<std::endl;
    // transversal(head);

    

    return 0;
}