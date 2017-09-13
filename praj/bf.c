#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct tree//to shorten name
        {
            int info;
            struct tree *left;
	    	struct tree *right;
        }node;
node * create(int n);
node * search(node *root,int ele);
void insert(node *root,int ele,int *num);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void del(node *root,int ele,int *num);
int height(node *pos);
int balfac(node *pos);
void complete(node *root);
int main()
{
    int i,n,ele,b,num;
    node *root,*p;
    node *pos=NULL;
    char ch;
    root=NULL;
    p=NULL;
	int *a;//to store address of no. of elements
	printf("\n\nCreate your Binary Search Tree (^_^)\n");
	printf("\nEnter number of elements in the tree --> ");
    scanf("%d",&num);
    root=create(num);
    a=&num;
    printf("\nTree successfully created...\n");
    while(1)//so that programme runs any no. of times
    {
        printf("\n\n      **MAIN MENU:**\n");
        printf("Press 1 to create your Tree\n");//menu
        printf("Press 2 to search an element\n");
        printf("Press 3 to insert an element\n");
        printf("Press 4 to delete an entry\n");
        printf("Press 5 for Pre-Order traversal\n");
		printf("Press 6 for In-Order traversal\n");
		printf("Press 7 for Post-Order traversal\n");
		printf("Press h to find height of a node\n");
		printf("Press 8 to find balance factor of a node\n");
		printf("Press 9 to check tree is complete or not\n");
        printf("Press 0 to exit from the programme\n");
        printf("\nEnter your choice --> ");
        scanf("%s",&ch);
        switch(ch)
        {
            case '1':printf("\n   Enter the size of the Tree --> ");
                     scanf("%d",&num);
                     root=create(num);
		   		     a=&num;
		   		     printf("Tree successfully created...\n");
                     break;
            case '2':printf("\nEnter the value to be searched --> ");
                     scanf("%d",&ele);
                     pos=search(root,ele);
                     if(pos==NULL)
                         printf("%d Not Found in this tree!!\n",ele);
                     else
                         printf("%d Found...",ele);
                     break;
            case '3':printf("\nEnter the value to be inserted --> ");
                     scanf("%d",&ele);
                     insert(root,ele,a);
                     printf("Value inserted in the Tree...\n");
                     break;
            case '4':printf("\nEnter the value to be deleted --> ");
                     scanf("%d",&ele);
                     del(root,ele,a);
                     printf("Value Successfully Deleted..\n");
                     break;
            case '5':printf("  Tree -->\n");
                     preorder(root);
                     break;
			case '6':printf("  Tree -->\n");
                     inorder(root);
                     break;
			case '7':printf("  Tree -->\n");
                     postorder(root);
                     break;
			case 'h':printf("Enter info whose height is to be found --> ");
                     scanf("%d",&ele);
                     pos=search(root,ele);
                     if(pos==NULL)
                     {
                         printf("%d Not Found in this tree!!\n",ele);
                         break;
                     }
                     else
                     {
                        b=height(pos);
                        printf("height of node containing %d is %d",ele,b);
                        break;
                     }
            case '8':printf("Enter info whose balance factor is to be found --> ");
                     scanf("%d",&ele);
                     pos=search(root,ele);
                     if(pos==NULL)
                     {
                         printf("%d Not Found in this tree!!\n",ele);
                         break;
                     }
                     else
                     {
                        b=balfac(pos);
                        printf("Balance Factor of node containing %d is %d",ele,b);
                        break;
                     }
            case '9':complete(root);
                     break;
            case '0':exit(0);
            default :printf("Invalid Choice (-_-)\n");
        }
        printf("\n\nPress a key to continue --> ");
        getchar();
        printf("\n");
    }
    return 0;
}
node * create(int n)
{
    int i,ele;
    node *root,*p,*q,*m;
    root=NULL;
    for(i=1;i<=n;i++)
    {
        q=root;
        m=(node *)malloc(sizeof(node));
        printf("Enter Data [%d] --> ",i);
        scanf("%d",&ele);
        m->info=ele;
        m->left=NULL;
        m->right=NULL;
        if(root==NULL)
        {
            root=m;
            p=root;
            q=root;
        }
        else
        {
            while(q!=NULL)
            {
                p=q;//To store address of last node
                if(q->info>ele)
                    q=q->left;
                else
                    q=q->right;
            }
            if(p->info<ele)
                p->right=m;
            else if(p->info>ele)
                p->left=m;
            else
            {
                printf(" **This value already exits (-_-)\n");
                i--;
            }
        }
    }
    return root;
}
node * search(node *root,int ele)
{
    node *p,*q;
    q=root;
    p=NULL;
    while(q!=NULL && q->info!=ele)
    {
        if(ele<q->info)
            q=q->left;
        else
            q=q->right;
    }
    return q;
}
void insert(node *root,int ele,int *num)
{
    node *p,*q,*m;
    p=q=root;
    m=(node *)malloc(sizeof(node));
    m->info=ele;
    while(p!=NULL)
    {
        q=p;
        if(p->info>ele)
            p=p->left;
        else if(ele>p->info)
            p=p->right;
        else
        {
            printf("This value already exists (-_-)\n");
            break;
        }
    }
    if(p==NULL)
    {
        if(ele<q->info)
        {
            q->left=m;
        }
        else if(ele>q->info)
        {
            q->right=m;
        }
        *num=*num+1;
    }
}
void del(node *root,int ele,int *num)
{
    node *p,*q,*s,*r;
    p=root;
    while((p!=NULL) && (p->info!=ele))
    {
        q=p;
        if(p->info>ele)
            p=p->left;
        else
            p=p->right;
    }
    if(p==NULL)
        printf("Information not Found (-_-)\n");
    else if(p->info==ele)
    {
        if((p->left==NULL) && (p->right==NULL))
        {
            if(q->info>ele)
                q->left=NULL;
            else
                q->right=NULL;
        }
        if((p->left==NULL) && (p->right!=NULL))
        {
            if(q->info>ele)
                q->left=p->right;
            else
                q->right=p->right;
        }
        if((p->left!=NULL) && (p->right==NULL))
        {
            if(q->info>ele)
                q->left=p->left;
            else
            q->right=p->left;
        }
        if((p->left!=NULL) && (p->right!=NULL))
        {
            r=p->left;
            while(r->right!=NULL)
            {
                s=r;
                r=r->right;
            }
            if(r->left==NULL)
                p->info=r->info;
            else if(r->left!=NULL)
            {
                p->info=r->info;
                s->right=r->left;
            }
        }
        *num=*num-1;
    }
}
void preorder(node *p)
{
    if(p!=NULL)
    {
        printf("%d  ",p->info);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
		printf("%d  ",p->info);
        inorder(p->right);
    }
}
void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
		printf("%d  ",p->info);
    }
}
int balfac(node *pos)
{
	int lh,rh;
	lh=height(pos->left);
	rh=height(pos->right);
	return (lh-rh);
}
void complete(node *root)
{

}
int height(node *pos)
{
	int lh,rh;
	if(pos == NULL || (pos->left==NULL && pos->right==NULL))
		return 0;
	else
	{
		lh=height(pos->left);
		rh=height(pos->right);
		if (lh > rh)
        	return(lh+1);
        else
			return(rh+1);
	}
}
