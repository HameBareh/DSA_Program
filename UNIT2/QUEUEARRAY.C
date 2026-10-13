#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

void insert(int);
int delete(void);
void display(void);

int queue[MAX];
int front=0;
int rear=0;
int full=0;
int empty=1;

void main(){
    int item, choice;
    clrscr();
    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the item to insert: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                item=delete();
                printf("\nThe Delete item is %d",item);
                break;
            case 3:
                display();
                break;
            case 4:
               exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }while(choice!=4);
    getch();
}
void insert(int x){
    if(full){
        printf("\nThe Queues is Full\n");
        return;
    }
    else{
    queue[rear]=x;
    rear++;
    empty=0;
    if(rear==MAX){
        full=1;
    }
    printf("\n%d is insert in Queue",x);
    return;
    }
}
int delete(void){
    int x;
    if(empty){
        printf("\nQueue is Empty");
        return -1;
    }
    else{
        x=queue[front];
        front++;
        full=0;
        if(front==rear){
            empty=1;
        }
    return(x);
    }
}
void display(void){
    int i;
    if(empty){
        printf("\nQueue is Empty");
        return;
    }
    for(i=front;i<rear;i++){
        printf("%d",queue[i]);
    }
}