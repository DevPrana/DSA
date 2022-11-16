#include<iostream>

class data{
  public:
    std::string name;

    void getData(){
        std::cout<<"The name is: "<<name<<std::endl;
    }

    void setData(std::string name){
        this->name=name;
    }
};

class node{
  public:
    data* info;
    node* next;
    node* prev;
};

void traversal(node* head){
    node* temp=head;
    do{
        temp->info->getData();
        temp=temp->next;
    }
    while(temp!=head);
}

class node* linkedListCreation(int size){
    node* head=new node;
    head->info=new data;
    node* tempPtr=head;
    node* prevTempPtr=tempPtr;

    std::string name;
    std::cout<<"Enter your name: ";
    std::cin>>name;
    // name="prerit";
    tempPtr->info->setData(name);

    for(int i=0;i<size-1;i++){
        tempPtr->next=new node;
        tempPtr->next->info=new data;

        prevTempPtr=tempPtr->next;
        prevTempPtr->prev=tempPtr;
        
        tempPtr=tempPtr->next;
        
        std::cout<<"Enter your name: ";
        std::cin>>name;
        // name="prerit";
        tempPtr->info->setData(name);
    }

    tempPtr->next=head;
    head->prev=tempPtr;
    return head;
}

node* insertAtFirst(node* head){
    node* newHead=new node;
    node* temp=head;
    newHead->info=new data;
    
    std::string name;
    std::cout<<"Please enter new name to insert at beginning: ";
    std::cin>>name;
    // name="rohan";
    newHead->info->setData(name);

    head->prev->next=newHead;
    newHead->prev=head->prev;
    newHead->next=head;
    head->prev=newHead;
    
    return newHead;
}

int main(){
    node* head=new node;
    node* temp=head;
    int size;
    std::cout<<"Enter the size of your linked list: ";
    std::cin>>size;
    // size=2;
    head=linkedListCreation(size);
    traversal(head);
    head=insertAtFirst(head);
    traversal(head);
}