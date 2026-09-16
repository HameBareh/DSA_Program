#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
	};
void main(){
	int i,n;
	struct node *p, *q, *r;
	clrscr();
	printf("Enter the number of note to construct:");
	scanf("%d",&n);

	r=(struct node *)malloc(sizeof(struct node));

	printf("Enter the first node: ");
	scanf("%d",&r->data);

	r->prev=NULL;
	r->next=NULL;
	p=q=r;

	for(i=0; i<n-1;i++){
	r=(struct node *)malloc(sizeof(struct node));

	printf("Enter next data: ");
	scanf("%d",&r->data);

	r->prev=q;
	r->next=NULL;

	q->next=r;
	q=r;
	}
	printf("Forward Traversing\n");
	q=p;
	while(q!=NULL){
	printf("%d",q->data);
	if(q->next!=NULL){
	printf("->");
	}
	q=q->next;
	}
	q=r;
	printf("\nBackward Traversing\n");
	while(q!=NULL){
	printf("%d",q->data);
	if(q->prev!=NULL){
	printf("<-");
	}
	q=q->prev;
	}
	getch();
}