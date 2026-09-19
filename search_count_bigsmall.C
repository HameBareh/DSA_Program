#include<stdio.h>
#include<conio.h>
#include<alloc.h>
void input();
void traver();
void reverse();
void search();
void countEvenOdd();
void bigsmall();
struct node {
	long int data;
	struct node *next;
	};
struct node *p, *q, *r;
void main(){
	clrscr();
	input();
	traver();
	reverse();
	search();
	countEvenOdd();
	bigsmall();
	getch();
	}
void input(){
	int n, i;
	printf("Enter the number of node: ");
	scanf("%d",&n);
	r=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the First node: ");
	scanf("%ld",&r->data);
	r->next=NULL;
	p=q=r;
	for(i=0;i<n-1;i++){
	r=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the next data: ");
	scanf("%ld",&r->data);
	r->next=NULL;
	q->next=r;
	q=r;
	}
}
void traver(){
	printf("Traversing the linklist\n");
	q=p;
	while(q!=NULL){
	printf("%ld",q->data);
	if(q->next!=NULL){
	printf("->");
	}
	q=q->next;
	}
}
void reverse(){
	printf("\nReverse the linklist\n");
	q=p;
	p=NULL;
	while(q!=NULL)
	{
	 r=q->next;
	 q->next=p;
	 p=q;
	 q=r;
	 }
	q=p;
	while(q!=NULL)
	{
	printf("%ld",q->data);
	if(q->next!=NULL)
	{
	 printf("<-");
	 }
	 q=q->next;
	}
}
void search(){
	long int item, found=0;
	printf("\nEnter the item to search: ");
	scanf("%ld",&item);
	q=p;
	while(q!=NULL){
	if(item==q->data){
		found=1;
		break;
		}
	q=q->next;
	}
	if(found==1){
	printf("The item search is %ld ",item);
	}else{
	printf("The item is not found");
	}
}
void countEvenOdd(){
	long int even=0, odd=0;
	q=p;
	while(q!=NULL){
	if(q->data%2==0){
	even++;
	}else{
	odd++;
	}
	q=q->next;
	}
	printf("\nThe number of even number is %ld",even);
	printf("\nThe number of odd number is %ld",odd);
}
void bigsmall(){
	long int big, small;
	q=p;
	big=q->data;
	small=q->data;
	q=q->next;
	while(q!=NULL){
	if(q->data>big){
	 big=q->data;
	 }
	if(q->data<small){
	 small=q->data;
	 }
	 q=q->next;
	}
	printf("\nThe Biggest number is %ld",big);
	printf("\nThe Smallest number is %ld",small);
}
