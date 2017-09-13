// balancing Factor of binary tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int lDepth=0;
int rDepth=0;

int maxDepth(struct node* node)
{

   if (node==NULL)
      {

       return 0;
       }
   else
   {
       /* compute the depth of each subtree */
       lDepth = maxDepth(node->left);
       rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
          {

           return(lDepth+1);
           }
       else
       {

       return(rDepth+1);

       }
   }
}
 /*int bal(struct node* node)
 {
 	int lh=maxDepth(node->left);
 	int rh=maxDepth(node->right);
 	int b=lh-rh;
 	if(b<0)
 	{
 		b=-1*b;

 	}
 	return b;
 }
*/
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left= newNode(8);
    root->right->left->right= newNode(6);
    root->left->right= newNode(7);

//	int k=bal(root);
 	int i=maxDepth(root->left);
 	int j=maxDepth(root->right);
    printf("Height of tree is %d\n", maxDepth(root));
//	printf("balfac %d",k);
	printf("balfac=%d",j-i);
    getchar();
    return 0;
}
