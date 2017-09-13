#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
	char data;
	struct node *next;
};

struct node* create_a_stack(void);
int isopp(char);
int pre(char,char);
char top(struct node*);
void push(char,struct node*);
int value(char);
void pop(struct node*);

void main()
{
	struct node *head;
	head = create_a_stack();
	char a[10000];
	printf("Enter an Expression.\n");
	scanf("%s",a);
	int n = strlen(a);
	int i;
	for(i = 0;i < n;i++)
	{
		if(a[i] == '(')
			push(a[i],head);
		else if(isalnum(a[i]))
			printf("%c ",a[i]);
		else if(isopp(a[i]))
		{
			if(head->next == NULL)
				push(a[i],head);
			else if(pre(a[i],top(head)) || top(head) == '(')
				push(a[i],head);
			else
			{
				while(head->next != NULL && pre(a[i],top(head)) == 0)
				{
					printf("%c ",top(head));
					pop(head);
				}
				push(a[i],head);
			}
		}
		else if(a[i] == ')')
		{
			while(top(head) != '(')
			{
				printf("%c ",top(head));
				pop(head);
			}
			pop(head);
		}
	}
	while(head->next != NULL)
	{
		if(isopp(((head->next)->data)))
		{
			printf("%c ",top(head));
			pop(head);
		}
		else if((head->next)->data == '(')
			pop(head);
	}
}

struct node* create_a_stack()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = 0;
	ptr->next = NULL;
	return ptr;
}

int isopp(char c)
{
	if(c == '+' ||c == '-' ||c == '/' ||c == '*')
		return 1;
	else
		return 0;
}

char top(struct node *ptr)
{
	return ((ptr->next)->data);
}

void push(char c,struct node *ptr)
{
	struct node *new_ptr;
	new_ptr = (struct node*)malloc(sizeof(struct node));
	new_ptr->data =  c;
	new_ptr->next = ptr->next;
	ptr->next = new_ptr;
}

int value(char c)
{
	if(c == '*' || c == '/')
		return 1;
	else if(c == '+' || c == '-')
		return 0;
}

int pre(char c,char s)
{
	if(value(c) > value(s))
		return 1;
	else
	return 0;
}

void pop(struct node* ptr)
{
	struct node *temp;
	temp = ptr->next;
	ptr->next = temp->next;
	free(temp);
}