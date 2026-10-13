#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

void push(int);
void pop(void);
void peek(void);
void display(void);

int top=-1;
int full=0, empty=1;
int stack[MAX];

void main(void){
    int item, ch;
    clrscr();
    do
    {
        printf("\n1.Push item");
        printf("\n2.Pop item");
        printf("\n3.Peek item");
        printf("\n4.Display item");
        printf("\n5.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the item to push: ");
                scanf("%d",&item);
                push(item);
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
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }while(ch!=5);
    getch();
}
void push(int x){
    if(full==1){
        printf("\nThe Stack is Full\n");
    }
    else
    {
        top=top+1;
        stack[top]=x;
        empty=0;
        if(top==MAX-1){
            full=1;
        }
    }
}
void pop(void){
    int x;
    if(empty==1){
        printf("\nStack is Empty\n");
    }
    else{
        x=stack[top];
        top--;
        full=0;
        if(top==-1)
        empty=1;
        printf("Popped item is %d",x);
    }
}
void peek(void){
    if(empty==1){
        printf("\nStack is Empty\n");
    }
    else{
        printf("Peek item is %d",stack[top]);
    }
}
void display(void){
    int i;
    if(empty==1){
        printf("\nStack is Empty\n");
    }
    else{
        printf("\nStack Element are:\n");
        for(i=top;i>=0;i--){
            printf("\n%d",stack[i]);
        }
    }
}
