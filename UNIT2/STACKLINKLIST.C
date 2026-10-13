#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<malloc.h>
void push(int);
void pop(void);
void peek(void);
void display(void);

struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
void main(){
    int item, choice;
    clrscr();
    do{
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
    struct node *r;
    r=(struct node *)malloc(sizeof(struct node));

    r->data=x;//new node
    r->next=top;//old node
    top=r;//make new node to top
    printf("\n%d is Push in the stack\n",x);
}
void pop(void){
    struct node *r;
    int x;
    if(top==NULL){
        printf("\nStack is Empty\n");
        return;
    }
    r=top;//set them equal
    x=top->data;//set value to x
    top=top->next;//move the top to next
    free(r);//then delete r
    printf("\nThe Popped element is: %d",x);
}
void peek(void){
    int x;
    if(top==NULL){
        printf("\nStack is Empty\n");
        return;
    }
    x=top->data;
    printf("\nThe Peek element is: %d",x);
}
void display(void){
    struct node *r;
    if(top==NULL){
        printf("\nStack is Empty");
        return;
    }
    r=top;
    printf("\nStack is:\n");
    while(r!=NULL){
        printf("\n%d",r->data);
        r=r->next;
    }
}
