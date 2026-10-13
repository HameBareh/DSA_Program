#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	};
void main(){
	int i,n;
	struct node *p, *q, *r;
	clrscr();

	printf("Enter the number of node to Create: ");
	scanf("%d",&n);

	r=(struct node *)malloc(sizeof(struct node));


	printf("Enter the first node: ");
	scanf("%d",&r->data);
	r->next=NULL;
	p=q=r;

	for(i=0; i<n-1;i++){
	r = (struct node *)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&r->data);
	r->next=NULL;
	q->next=r;
	q=r;
	}
	printf("Linked list:");
	q=p;
	while(q!=NULL){
	printf("%d->",q->data);
	q=q->next;
	}
	printf("NULL");
	getch();
}

