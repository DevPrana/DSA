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
        
    } ;
};
