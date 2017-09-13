#include <stdio.h>
#include <stdlib.h>

struct node* create_a_node();
void insert_a_node(int,int,struct node*);
void display_list(struct node*);
void modify_all(int,int,struct node*);
void delete_all(int,struct node*);
int search_first_data(int,struct node*);

struct node
{
	struct node *next;
	int data;
	struct node *prev;
};

void main()
{
	int c,new_data,index,old_data;
	struct node *head;
	head = create_a_node();
	do
	{
		printf("\t\t\t\t MAIN MENU \n");
		printf("1. Insert a node \n");
		printf("2. Delete a node \n");
		printf("3. Modify Data \n");
		printf("4. Search data \n");
		printf("5. Display data\n");
		printf("6. Exit \n");
		printf("Enter your choice \n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter data to be inserted \n");
				scanf("%d",&new_data);
				printf("Enter the position to which this data to be insered \n");
				scanf("%d",&index);
				insert_a_node(new_data,index,head);
				display_list(head);
				break;
			case 2: printf("Enter the data to be deleted \n");
				scanf("%d",&new_data);
				delete_all(new_data,head);
				display_list(head);
				break;
			case 3: printf("Enter the data to be modified in the list \n");
				scanf("%d",&old_data);
				printf("Enter new data \n");
				scanf("%d",&new_data);
				modify_all(old_data,new_data,head);
				display_list(head);
				break;
			case 4: printf("Enter data to be searched \n");
				scanf("%d",&new_data);
				index = search_first_data(new_data,head);
				if(index == -1)
				printf("Data not found....! \n");
				else
				printf("Your givin data is on %d position \n",index);
				break;
			case 5: display_list(head);
				break;
			default : return;
		}
	}
	while(c != 6);
}

struct node* create_a_node()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data = 0;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}

void insert_a_node(int new_data,int index,struct node* ptr)
{
	int i = 0;
	if(index < 0 || index > ptr->data)
	{
		printf("Invalid Index....! \n");
		return;
	}
	struct node *new_ptr;
	new_ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data = ptr->data + 1;
	while(i < index)
	{
		ptr = ptr->next;
		i++;
	}
	new_ptr->data = new_data;
	new_ptr->next = ptr->next;
	ptr->next = new_ptr;
	if((ptr->next)->next != NULL)
	(new_ptr->next)->prev = new_ptr;
	new_ptr->prev = ptr;
}

void delete_all(int new_data,struct node *ptr)
{
	int i = 0;
	struct node *root_ptr,*temp;
	root_ptr = ptr;
	while(ptr->next != NULL)
	{
		if((ptr->next)->data == new_data)
		{
			temp = ptr->next;
			ptr->next = (ptr->next)->next;
			if(temp->next != NULL)
			(temp->next)->prev = ptr;
			free(temp);
			i++;
		}
		else
		ptr = ptr->next;
		root_ptr->data = root_ptr->data - i;
	}
}


void display_list(struct node *ptr)
{
	printf("Displaying List..... \n");
	while(ptr->next != NULL)
	{
		printf("%d ->",(ptr->next)->data);
		ptr = ptr->next;
	}
	printf("\n");
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

int search_first_data(int new_data,struct node *ptr)
{
	int i,k;
	i = 0;
	k = 0;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		i++;
		if(ptr->data == new_data)
		{
			return i;
			k++;
		}
	}
	if(k == 0)
	return -1;
}
