#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *p, *q, *r;

void create()
{
    int i,n;

    printf("Enter the Number of Nodes to Create: ");
    scanf("%d",&n);

    r=(struct node *)malloc(sizeof(struct node));

    printf("Enter the First node: ");
    scanf("%d",&r->data);

    r->next=NULL;
    p=q=r;

    for(i=0;i<n-1;i++)
    {
        r=(struct node *)malloc(sizeof(struct node));

        printf("Enter the next data: ");
        scanf("%d",&r->data);

        r->next=NULL;
        q->next=r;
        q=r;
    }
}

void display()
{
    printf("Traversing the Linklist:\n");

    q=p;

    while(q!=NULL)
    {
        printf("%d",q->data);

        if(q->next!=NULL)
        {
            printf("->");
        }

        q=q->next;
    }
}

void delete_begin()
{
    q=p;

    p=p->next;

    free(q);
}

void delete_middle()
{
    int pos,i;

    printf("Enter the position to Delete: ");
    scanf("%d",&pos);

    q=p;

    for(i=1;i<pos-1;i++)
    {
        q=q->next;
    }

    r=q->next;
    q->next=r->next;

    free(r);
}

void delete_end()
{
    q=p;

    while(q->next->next!=NULL)
    {
        q=q->next;
    }

    r=q->next;
    q->next=NULL;

    free(r);
}

void main()
{
    int choice;

    clrscr();

    create();

    do
    {
        printf("\n\nMenu\n");
        printf("1.Delete from Beginning\n");
        printf("2.Delete from Middle\n");
        printf("3.Delete from End\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                delete_begin();
                break;

            case 2:
                delete_middle();
                break;

            case 3:
                delete_end();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid Choice");
        }

    }while(choice!=5);

    getch();
}