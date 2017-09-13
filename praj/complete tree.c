#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

int max(int a, int b)
{
	return a>b?a:b;
}
int height(struct node *root)
{
	if(!root)
	return 0;
	else
	return 1+max(height(root->left), height(root->right));
}

int isComplete(struct node *root)
{

   if(!root)
       return 1;
   if(!root->left)
   {
       if(root->right)
       return 0;
       else
       return 1;
   }
  if(root->left)
  {
       if(!root->right)
        {
            if(!root->left->left && !root->left->right)
               return 1;
           else
              return 0;
        }
      else
         return isComplete(root->left)&&isComplete(root->right);
    }
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}


int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);
  root->right->left  = newNode(8);

 if(height(root->left)<height(root->right))
   printf ("NOT Complete Binary Tree");
 else
 {
  if ( isComplete(root) )
      printf ("Complete Binary Tree");
  else
       printf ("NOT Complete Binary Tree");
   }
}
