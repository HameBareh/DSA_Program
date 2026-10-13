#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct que{
    int item;
    struct que *next;
};

struct que *front=NULL;
struct que *rear=NULL;
void insert(int);
int delete(void);
void display(void);

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
    struct que *r;
    r=(struct que *)malloc(sizeof(struct que));
    r->item=x;
    r->next=NULL;
    if(front==NULL){
        rear=front=r;
    }
    else{
        rear->next=r;
        rear=r;
    }
    return;
}
int delete(void){
    int x;
    struct que *temp;
    if(rear==NULL){
	printf("\nEmpty Queue\n");
	return -1;
    }
    else{
	temp=front;
	x=front->item;

	front=front->next;
	free(temp);
	if(front==NULL){
	    rear=NULL;
	}
	return x;
    }
}
void display(void){
    struct que *t;
    t=front;
    if(rear==NULL){
	printf("\nEmpty Queue\n");
	exit(0);
    }
    if(
    while(front!=rear->next){
	printf("%d ,",front->item);
	front=front->next;
    }
    front=t;
}