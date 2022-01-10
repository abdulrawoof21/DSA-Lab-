#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head,*temp,*temp1,*prev,*ptr,*newnode;
void display()
{
    temp1=head;
    while(temp1!=NULL)
    {
        printf("%d  ",temp1->data);
        temp1=temp1->next;
    }
}
void push(int data){
    newnode= (struct Node*)(malloc(sizeof(struct Node)));
    newnode->data = data;
    if(head==NULL){
                newnode->next=NULL;
                ptr=head=newnode;
    }else{
        newnode->next = NULL;
        ptr->next=newnode;
        ptr=newnode;
    }
}
void main()
{

    push(-1);
    push(2);
    push(-3);
    push(4);
    push(-5);
    push(6);
    printf("\n\nGiven values are\n");
    display();
    temp1=head->next;
    prev=head;
    while(temp1!=NULL)
    {
        if(temp1->data<0)
        {
            prev->next=temp1->next;
            free(temp1);
            temp1=prev->next;
        }
        else
        {
            prev=temp1;
            temp1=temp1->next;
        }
    }
    if(head->data<0)
        head=head->next;
    printf("\nAfter deleting negative values\n");
    display();
}
