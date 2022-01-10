#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *newnode,*prev,*temp,*start,*end;
int isempty(){
    return start==NULL;
}
void createNode(int data){
    newnode = (struct node *)(malloc(sizeof(struct node)));
    newnode->data = data;
    newnode->left =NULL;
    newnode->right=NULL;
}
void insertBegin(int data){
    createNode(data);
    if(isempty()){
        end=start=newnode;

    }else{
        start->left =newnode;
        newnode->right=start;
        start=newnode;
    }
    printf("Inserted Successfully");
}
void insertEnd(int data){
    createNode(data);
  if(isempty()){
        end=start=newnode;

    }else{
        end->right =newnode;
        newnode->left=end;
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
        while(temp->right != NULL && i<pos-1){
        temp = temp->right;
        i++;
        };
        if(temp->right == NULL && i<pos-1){
            end->right = newnode;
            newnode->left = end;
            end = newnode;
        }else if(pos ==1){
            newnode->right = start;
            start->left =newnode;
            start = newnode;
        }else{
            newnode->right = temp->right;
            temp->right->left = newnode;
            temp->right = newnode;
            newnode->left = temp;
        }

    }
    printf("Inserted Successfully");
}
void delete(int data){
    if(isempty()){
                printf("\n List is empty");
    }else{
        temp = start;
        while(temp->right != NULL && temp->data != data){
            prev = temp;
            temp= temp->right;
        }
        if(temp->right == NULL && temp->data!=data){
            printf("\n Data not found");
            return;
        }else if(start->data == data){
            start = start->right;
            start->left = NULL;
        }else if(end->data == data)
        {
            prev->right = NULL;
            end = prev;
        }else{
                prev->right = temp->right;
                temp->right->left = prev;
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
        while(temp->right != NULL && temp->data !=data){
            temp=temp->right;
            i++;
        }
        if(temp->right==NULL && temp->data!=data){
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
        while(temp->right != NULL){
                    printf("\n Left :%p \t Address : %p \t Data : %d \t Right: %p\n",temp->left,temp,temp->data,temp->right);
                    temp=temp->right;
        }
        printf("\n Left :%p \t Address : %p \t Data : %d \t Right: %p\n",temp->left,temp,temp->data,temp->right);
    }
}
void main(){

int option,c=1,element,position;
do{
    printf("\n  Doubly Linked List \n 1.Insert Begin \n 2.Insert End \n 3.Insert in Position \n 4.Delete \n 5.Search \n 6.Display \n Enter Your Option\n");
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

