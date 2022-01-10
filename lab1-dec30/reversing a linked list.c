#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*newnode=NULL,*ptr;
void push(int data){
    newnode= (struct node*)(malloc(sizeof(struct node)));
    newnode->data = data;
    if(head==NULL){
                newnode->next=NULL;
                ptr=head=newnode;
    }else{
        newnode->next = ptr;
        ptr=head=newnode;
    }
}
int pop(){
        head=ptr->next;
        int popped = ptr->data;
        free(ptr);
        ptr=head;
        return popped;
}
void main(){
    push(3);
    push(4);
    push(5);
    ptr=head;
    printf("Reversed List\n");
    while(ptr!=NULL){
            printf("%d\n",pop());
    }
    }

