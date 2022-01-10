#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
};
void push();
void pop();
void display();
struct node *head;
void main(){
    int choice =0;
    while(choice !=4){
                printf("Enter your choice \n 1.Push\n 2.Pop\n 3.Show\n 4.Exit\n");
                scanf("%d",&choice);
                switch(choice){
                    case 1: push();
                            break;
                    case 2 : pop();
                            break;
                    case 3: display();
                            break;
                    case 4:printf("Exiting...\n");
                            break;
                    default: printf("Enter valid choice\n");
                }
    };
}
void push(){
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
                printf("Unable to push\n");
    }else{
            printf("Enter the value \n");
            scanf("%d",&val);
            if(head==NULL){
                ptr->val=val;
                ptr->next=NULL;
                head=ptr;
            }else{
                    ptr->val = val;
                    ptr->next = head;
                    head=ptr;
            }
    }
    printf("Item pushed");
}
void pop(){
int item;
struct node *ptr;
if(head==NULL){
 printf("Underflow");
}else{
        item=head->val;
        ptr=head;
        head=head->next;
        free(ptr);
        printf("Item Popped %d\n",item);
}

}
void display(){
 int i;
 struct node *ptr;
 ptr=head;
 if(ptr==NULL){
 printf("Stack is empty");
 }else{
        printf("Stack\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->val);
            ptr=ptr->next;
        }
 }
}
