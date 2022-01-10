#include<stdio.h>
#define MAX 100

int st[100],top=-1,i,option,val;
void push();
void pop();
void peek();
void display();
void main(){
do{
printf("\nEnter the operation: \n1push \n2pop \n3peek \n4display\n");
scanf("%d",&option);
switch(option){
case 1:
    push();
    break;
case 2:
    pop();
    break;
case 3:
    peek();
    break;
case 4:
    display();
    break;
}
}while(option!=5);
}
void push()
{
if(top==MAX-1)
{
    printf("\nSTACK IS OVERFLOW");
}
else{
    top++;
    printf("Enter the value:");
    scanf("%d",&st[top]);


}
}
void pop()
{
    if(top==-1)
    {
        printf("the stack is underflow");
    }
    else
    {
    printf("Popped value %d\n",st[top]);
    top--;
    }
}
void peek()
{
    if (top==-1)
    {
        printf("the stack is underflow");

    }
    else{
      printf("the top of the stack is %d,",st[top]);
      }}

void display()
{
 if (top==-1)
    {
        printf("the stack is underflow");

    }else{
    for(i=top;i>=0;i--)
    {
    printf("%d\n",st[i]);
    }
}
}

