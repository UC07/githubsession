#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
}node;
node * create(int);
void insert(node *);
int search(int);
node *root=NULL;
void main()
{
    int c,ele,n;
    node *h,*m;
    printf("Enter the size of the tree\n");
    scanf("%d",&n);
    h=create(n);
    printf("created...\n");
    do
    {
    printf("\t\t\tMAIN MENU\n");
    printf("1.insert\n");
    printf("2.search\n");
    printf("3.delete\n");
    printf("enter your choice\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:printf("enter the element to be inserted\n");
                scanf("%d",&m);
                insert(m);
                break;
        case 2:printf("enter element to be searched\n");
                scanf("%d",&ele);
                search(ele);
                break;
    }
    }
    while(c!=3);
}

node * create(int n)
{
    int ele,i;
    node *m;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ele);
        m=(node*)malloc(sizeof(node));
        m->info=ele;
        m->left=NULL;
        m->right=NULL;
        if(root==NULL)
            root=m;
        else
            insert(m);
    }
}
void insert(node *m)
{
    node *p,*q;
    int ele;
    p=q=root;
    while(q!=NULL)
    {
        p=q;
        if(ele<q->info)
            q=q->left;
        else
            q=q->right;
    }
    if(p->info>ele)
        p->left=m;
    else
        p->right=m;
}
int search(int ele)
{
    node *p;
    p=root;
    while(p!=NULL && p->info!=ele)
    {
        if(ele>p->info)
            p=p->right;
        else
            p=p->left;
        return p->info;
    }
}
