#include<iostream>
struct node{
    int roll;
    struct node *next;
};

struct node *createlist(int elements){
    struct node *head;
    struct node *temp;


    for(int i=0;i<elements;i++){
        if(i==0){
            head=(struct node *) (malloc(sizeof(struct node)));
            temp = head;
        }
        else{
            temp ->next = (struct node *) malloc(sizeof(struct node)); 
            temp=temp->next;
        }
        temp->next=NULL;
        std::cin>>temp->roll;
    } 
    return head;
};

void display(node* head){
    int count=1;
    node *p;

    p=head;
    while(p!=NULL){
        std::cout<<p->roll<<std::endl;
        count++;
        p=p->next;
    }
}

void insert(int index){
    
}

int main(){
    node* head =createlist(7);
    display(head);
    return 0;
}
