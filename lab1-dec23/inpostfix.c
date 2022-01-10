#include <stdio.h>
#include<ctype.h>
void push(char c);
char pop();
void display();
char a[3],st[10],temp;
int top=-1;
void push(char c)
{
    if(top==9)
        {
        printf("Stack overflow\n");
        }
    else
        {
        st[++top]=c;
        }
}
char pop()
{
    if(top==-1)
        {
        printf("Stack underflow\n");
        return ;
        }
    else
        {
        temp=st[top];
        top--;
        return temp;
        }
}
void display()
{
    if(top==-1)
        {
        printf("\nStack underflow");
        }
    else
        {
        for(int i=0;i<=top;i++)
            {
            printf("%c",st[i]);
            }
        }
}
int main()
 {
    printf("Enter expression\n");
    scanf("%s",a);
    push(a[0]);
    push(a[1]);
    if(isalpha(st[top])<=0 && isalpha(a[2])>0)
        {
        temp=pop();
        st[++top]=a[2];
        st[++top]=temp;
        }
    else
        {
        push(a[2]);
        }
    display();
    return 0;
}

