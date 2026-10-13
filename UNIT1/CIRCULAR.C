#include<stdio.h>
#include<conio.h>
#include<alloc.h>
//create node
struct node{
	int data;
	struct node *next;
	};

void main(){
	struct node *start, *p, *q, *r;
	clrscr();

	//create memory for three nodes
	p=(struct node*)malloc(sizeof(struct node));
	q=(struct node*)malloc(sizeof(struct node));
	r=(struct node*)malloc(sizeof(struct node));
	start=p;

	//WITH USER INPUT
	printf("Enter the first node: ");
	scanf("%d",&p->data);
	printf("Enter the Second node: ");
	scanf("%d",&q->data);
	printf("Enter the third node: ");
	scanf("%d",&r->data);

	//link the nodes
	p->next=q;
	q->next=r;
	r->next=start;

	printf("Circular Link list:\n");

	printf("%d ->",start->data);
	printf("%d ->",q->data);
	printf("%d->",r->data);
	getch();
