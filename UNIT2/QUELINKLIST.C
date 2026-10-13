
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct que
{
    int item;
    struct que *next;
};

struct que *front=NULL;
struct que *rear=NULL;

void insert(int);
int delete(void);
void display(void);

void main()
{
    int item, choice;

    clrscr();

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the item to insert: ");
                scanf("%d",&item);
                insert(item);
                break;

            case 2:
                item=delete();

                if(item!=-1)
                    printf("\nThe deleted item is %d",item);

                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice");
        }

    }while(choice!=4);

    getch();
}

void insert(int x)
{
    struct que *r;

    r=(struct que *)malloc(sizeof(struct que));

    if(r==NULL)
    {
        printf("\nMemory Allocation Failed");
        return;
    }

    r->item=x;
    r->next=NULL;

    if(front==NULL)
    {
        front=rear=r;
    }
    else
    {
        rear->next=r;
        rear=r;
    }

    printf("\n%d is inserted in Queue",x);
}

int delete(void)
{
    int x;
    struct que *temp;

    if(front==NULL)
    {
        printf("\nQueue is Empty");
        return -1;
    }

    temp=front;
    x=front->item;

    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(temp);

    return x;
}

void display(void)
{
    struct que *t;

    if(front==NULL)
    {
        printf("\nQueue is Empty");
        return;
    }

    t=front;

    printf("\nQueue elements are:\n");

    while(t!=NULL)
    {
        printf("%d ",t->item);
        t=t->next;
    }
}
