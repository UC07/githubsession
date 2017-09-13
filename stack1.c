//stack using linked list.
#include <stdio.h>
#include <stdlib.h>

struct node* create_a_stack(void);
void push(int,struct node*);
void print(struct node*);
void pop(struct node*);

struct node
{
	int data;
	struct node *next;
};

void main()
{
	int c,n;
	struct node *head;
	printf("creating stack......\n");
	head = create_a_stack();
	printf("Stack created!\n");
	do
	{
		printf("\t\t\t\tMAIN MENU\n");
		printf("1.Push into stack\n");
		printf("2.Pop out to stack\n");
		printf("3.Display all elements of stack\n");
		printf("4.Exit\n");
		printf("Enter your choice....!\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the number to be pushed into stack\n");
				scanf("%d",&n);
				push(n,head);
				print(head);
				break;
			case 2: printf("Popping out an element from stack....\n");
				pop(head);
				print(head);
				break;
			case 3: print(head);
				break;
			case 4: return;
				break;
		}
	}
	while(c != 4);
}

struct node* create_a_stack()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = 0;
	ptr->next = NULL;
	return ptr;
}

void push(int n,struct node *ptr)
{
	struct node *new_ptr;
	ptr->data = ptr->data + 1;
	new_ptr = (struct node*)malloc(sizeof(struct node));
	new_ptr->data = n;
	new_ptr->next = ptr->next;
	ptr->next = new_ptr;
}

void print(struct node *ptr)
{
	struct node *temp;
	temp = ptr;
	if(temp->next == NULL)
	{
		printf("Stack is empty !\n");
		return;
	}
	printf("Loading stack....\n");
	while(temp->next != NULL)
	{
		temp = temp->next;
		printf("%d\n",temp->data);
	}

}

void pop(struct node *ptr)
{
	struct node *temp;
	if(ptr->next == NULL)
	{
		printf("Error : Can not pop stack is empty...!\n");
		return;
	}
	else
	{
		ptr->data = ptr->data - 1;
		temp = ptr->next;
		ptr->next = (ptr->next)->next;
		free(temp);
	}
}