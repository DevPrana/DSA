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
        std::cout<<"Enter the node element "<<index+1<<" : ";
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

struct Node* concatLists(Node** arr,int n){
    int j=1;
    for(int i=0;i<n-1;i++){
        struct Node* tempPtr=(struct Node*)malloc(sizeof(Node));
        tempPtr=arr[i];
        while(tempPtr->next!=NULL){
            tempPtr=tempPtr->next;
        }
        tempPtr->next=arr[j];
        j++;
    }
    return arr[0];
}
int main(){
    struct Node* head= new Node;
    int sizeOfList;
    int n;
    int j;
    std::cout<<"Enter the number of linked list you want to concatenate: "<<std::endl;
    std::cin>>n;
    Node** arr= new Node*[n];

    for(int i=0;i<n;i++){
        arr[i]=(struct Node*)malloc(sizeof(struct Node));
        std::cout<<"\nEnter the size of your list: ";
        std::cin>>sizeOfList;
        arr[i]=creation(sizeOfList);
    }
    
    head=concatLists(arr,n);
    
    transversal(head);
    
    return 0;
}