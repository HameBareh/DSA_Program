#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *insert(struct node *p, int x);
void create();
void inorder(struct node *p);
void degree(struct node *p,int x);
int height(struct node *p);

void create(){
    int n,i,x;
    root=NULL;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("\nEnter the value: ");
        scanf("%d",&x);
        root=insert(root,x);
    }
}
struct node *insert(struct node *p, int x){
    if(p==NULL){
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
    }
    else if(x<p->data)
    {
        p->left=insert(p->left,x);
    }
    else if(x>p->data){
        p->right=insert(p->right,x);
    }
    return p;
}
}
void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void degree(struct node *p,int x){
    if(p==NULL){
        return;
    }
    if(x<p->data)
        degree(p->left,x);
    else if(x>p->data)
        degree(p->right,x);
    else{
        if(p->left!=NULL && p->right!=NULL)
            printf("\nDegree=2");
        else if(p->left!=NULL || p->right!=NULL)
            printf("\nDegree=1");
        else
            printf("\nDegree=0");
    }
}
int height(struct node *p){
    int lt, rt;

    if(p!=NULL)
    return 0;

    lt=1+height(p->left);
    rt=1+height(p->right);
    if(lt>rt)
	return lt;
    else
	return rt;
}
void main(){
    int x,choice;
    int created=0;
    clrscr();
    do{
	printf("\n1.Create\n");
	printf("\n2.Insert\n");
	printf("\n3.Display\n");
	printf("\n4.Degree\n");
    printf("\n5.Height\n");
	printf("\n6.Exit");
	printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(created==0){
                    create();
                    created=1;
                }
                else{
                    printf("\nTree already created!");
                    printf("\nUse Insert to add more nodes.");
                }
                break;
            case 2:
                printf("\nEnter the value: ");
                scanf("%d",&x);
                root=insert(root,x);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                printf("\nEnter the value: ");
                scanf("%d",&x);
                degree(root,x);
                break;
            case 5:
		printf("\nHeight of Tree = %d",height(root));
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice");
        }
    }while(choice!=6);
    getch();
}