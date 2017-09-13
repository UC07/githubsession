#include <stdio.h>
#include <stdlib.h>

struct node* create_a_node();
void insert_a_node(int,int,struct node*);
void display_list(struct node*);
int search(int,struct node*);
void delete_a_node(int,struct node*);
void modify_all(int,int,struct node*);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *head;
	int c,new_data,index,old_data;
	head = create_a_node();
	do
	{
		printf("\t\t\t\tMAIN MENU\n");
		printf("1. Insert a node. \n");
		printf("2. Search a data value. \n");
		printf("3. Delete a node. \n");
		printf("4. Display all elements in the list. \n");
		printf("5. Exit. \n");
		printf("Enter your choice.....! \n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter data value \n");
				scanf("%d",&new_data);
				printf("Enter index to which it is to be inserted \n");
				scanf("%d",&index);
				insert_a_node(new_data,index,head);
				display_list(head);
				break;
			case 2: printf("Enter data value to be searched \n");
				scanf("%d",&new_data);
				index = search(new_data,head);
				if(index == -1)
					printf("Entered data is not found in the list....! \n");
				else
					printf("your data is on %d position \n",index);
				break;
			case 3: printf("Enter the data value to be deleted \n");
				scanf("%d",&new_data);
				index = search(new_data,head);
				if(index == -1)
					{
						printf("Entered data is not found in the list....! \n");
						continue;
					}
				else
					printf("your data is on %d position \n",index);
				delete_a_node(index,head);
				display_list(head);
				break;
			case 4: display_list(head);
				break;
			case 5: printf("Enter the data to be modified \n");
				scanf("%d",&old_data);
				printf("Enter the new data \n");
				scanf("%d",&new_data);
				modify_all(old_data,new_data,head);
				display_list(head);
				break;
			default: return 0;
		}
	}
	while(c != 6);
	return 0;
}

struct node* create_a_node()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data = 0;
	ptr->next = NULL;
	return ptr;
}

void insert_a_node(int new_data,int index,struct node* ptr)
{
	if(index < 0 || index > ptr->data)
	{
		printf("INVALID INDEX...! \n");
		return;
	}
	struct node *new_ptr;
	ptr->data = ptr->data + 1;
	new_ptr = (struct node*)malloc(sizeof(struct node*));
	new_ptr->data = new_data;
	int i = 0;
	while(i < index)
	{
		ptr = ptr->next;
		i++;
	}
	new_ptr->next = ptr->next;
	ptr->next = new_ptr;
}

void display_list(struct node *ptr)
{
	printf("List loading.... \n");
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		printf("%d ",ptr->data);
	}
}

int search(int new_data,struct node *ptr)
{
	int i = 1;
	int k = -1;
	while(ptr->next != NULL)
	{
		if(ptr->next->data == new_data)
		{
			k = 1;
			return i;
		}
		else
		ptr = ptr->next;
		i++;
	}
	if(k == -1)
	return -1;
}

void delete_a_node(int index,struct node* ptr)
{
	struct node *temp;
	ptr->data = ptr->data - 1;
	int i = 1;
	while(i < index)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next = (ptr->next)->next;
	free(temp);
}

void modify_all(int old_data,int new_data,struct node *ptr)
{
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		if(ptr->data == old_data)
		ptr->data = new_data;
	}
}
