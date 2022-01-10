#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *newnode,*prev,*temp,*start,*end;
int isempty(){
    return start==NULL;
}
void createNode(int data){
    newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = data;
    newnode->next =NULL;
}
void insertBegin(int data){
    createNode(data);
    if(isempty()){
        end=start=newnode;

    }else{
        newnode->next=start;
        start=newnode;
    }
    printf("Inserted Successfully");
}
void insertEnd(int data){
    createNode(data);
  if(isempty()){
        end=start=newnode;

    }else{
        end->next =newnode;
        end=newnode;
    }
    printf("Inserted Successfully");
}
void insertPos(int data, int pos){
    int i=1;
    createNode(data);
  if(isempty()){
        end=start=newnode;

    }else{
        temp =start;
        while(temp->next != NULL && i<pos-1){
        temp = temp->next;
        i++;
        };
        if(temp->next == NULL && i<pos-1){
            end->next = newnode;
            end = newnode;
        }else if(pos ==1){
            newnode->next = start;
            start = newnode;
        }else{
            newnode->next = temp->next;
            temp->next = newnode;
        }

    }
    printf("Inserted Successfully");
}
void delete(int data){
    if(isempty()){
                printf("\n List is empty");
    }else{
        temp = start;
        while(temp->next != NULL && temp->data != data){
            prev = temp;
            temp= temp->next;
        }
        if(temp->next == NULL && temp->data!=data){
            printf("\n Data not found");
            return;
        }else if(start->data == data){
            start = start->next;
        }else if(end->data == data)
        {
            prev->next = NULL;
            end = prev;
        }else{
                prev->next = temp->next;
                printf("\n %d is deleted",temp->data);
        }

    }
}
void search(int data){
    int choice,i=1;
    if(isempty()){
        printf("\n List is empty");
    }else{
        temp= start;
        while(temp->next != NULL && temp->data !=data){
            temp=temp->next;
            i++;
        }
        if(temp->next ==NULL && temp->data!=data){
            printf("\n %d is not found",data);
        }else{
            printf("\n %d is found in %d position",temp->data,i);
        }
    }
}
void display(){
    temp=start;
    if(isempty()){
        printf("\n List is empty");
    }else{
        while(temp->next != NULL){
                    printf("\n Address : %p \t Data : %d \t Next: %p\n",temp,temp->data,temp->next);
                    temp=temp->next;
        }
        printf("\n Address: %p \t Data:%d \t Next: %p",temp,temp->data,temp->next);
    }
}
void main(){

int option,c=1,element,position;
do{
    printf("\n  Singly Linked List \n 1.Insert Begin \n 2.Insert End \n 3.Insert in Position \n 4.Delete \n 5.Search \n 6.Display \n Enter Your Option\n");
    scanf("%d",&option);
    switch(option){
        case 1: printf("Enter element");
                scanf("%d",&element);
                insertBegin(element);
                break;
        case 2: printf("Enter element");
                scanf("%d",&element);
                insertEnd(element);
                break;
        case 3:printf("Enter element");
                scanf("%d",&element);
                printf("Enter position");
                scanf("%d",&position);
                insertPos(element,position);
                break;
        case 4:printf("Enter element");
                scanf("%d",&element);
                delete(element);
                break;
        case 5: printf("Enter element");
                scanf("%d",&element);
                search(element);
                break;
        case 6: display();
                break;
        default: printf("\n Invalid input");
                break;
    }
    printf("\n Press 1 to continue:");
    scanf("%d",&c);
}while(c==1);
}
