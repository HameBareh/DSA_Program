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
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
struct node *delete(struct node *p, int x);
struct node *search(struct node *p, int x);

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
struct node *smallest(struct node *p){
    while(p->left!=NULL)
    p=p->left;
return p;
}
void preorder(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
struct node *delete(struct node *p, int x)
{
    struct node *q;
    if(p==NULL)
    {
        printf("\nvalue not found");
    }
    else if(x<p->data)
    {
        p->left=delete(p->left,x);
    }
    else if(x>p->data)
    {
        p->right=delete(p->right,x);
    }
    else
    {
        //NO CHILD
       if(p->left==NULL && p->right==NULL)
        {
            free(p);
            return NULL;
        }
        //ONLY RIGHT CHILD
        else if(p->left==NULL){
            q=p->right;
            free(p);
            return q;
        }
        //ONLY LEFT CHILD
        else if(p->right==NULL){
            q=p->left;
            free(p);
            return q;
        }
       else{
            q=p->right;
            while(q->left!=NULL)
            {
                q=q->left;
            }
            p->data=q->data;
            p->right=delete(p->right,q->data);
       } 
    }
    return p;
}
struct node *search(struct node *p, int x){
    if(p==NULL){
        return NULL;
    }
    else if(x==p->data){
        return p;
    }
    else if(x<p->data){
        return search(p->left,x);
    }
    else
    {
        return search(p->right,x);
    }
}

void main(){
    int x,choice;
    int created=0;
    clrscr();
    do{
	printf("\n1.Create\n");
	printf("\n2.Insert\n");
	printf("\n3.Preorder\n");
	printf("\n4.Inorder\n");
	printf("\n5.Postorder\n");
    printf("\n6.Delete\n");
    printf("\n7.Searching\n");
	printf("\n8.Exit");
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
                preorder(root);
		break;
            case 4:
                inorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                printf("\nEnter the value to delete: ");
                scanf("%d",&x);
                root=delete(root,x);
                break;
            case 7:
                printf("\nEnter the value to search: ");
                scanf("%d",&x);
                if(search(root,x)!=NULL)
                {
                    printf("\nValue %d is found!",x);
                }
                else{
                    printf("\nValue %d is not found!",x);
                }
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid Choice");
        }
    }while(choice!=8);
    getch();
}