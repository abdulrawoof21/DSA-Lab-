#include <stdio.h>
#include <string.h>
char n[10][20],st[10][20],temp[10][20],c[20];
int h,t=-1,t1=-1;
char* peek(){
    return st[t];
}
void push(char x[]){

    t++;
    strcpy(st[t],x);
}
void push1(char y[]){

    t1++;
    strcpy(temp[t1],y);
}
char* pop(){
    strcpy(c,(st[t]));
    t--;
    return c;
}
char* pop1(){
    strcpy(c,(temp[t1]));
    t1--;
    return c;
}
void display(){
    for(int i=0;i<=t;i++){
        printf("\n%s",st[i]);
    }

}
int main() {
    printf("Enter the number of names ");
    scanf("%d",&h);
    for(int i=0;i<h;i++){
        scanf("%s",n[i]);
    }
    push(n[0]);
     //display()
    for(int i=1;i<h;i++){
        while(strcmp(peek(),n[i])>0){
            push1(pop());
        }
        push(n[i]);
        while(t1>-1){
            push(pop1());
        }



    }
        display();


    }
