#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* create_a_queue();
void enqueue(int,struct node*);
void print(struct node*);
void dequeue(struct node*);

struct node *front,*rear;

void main()
{
	struct node *head; 
	head = create_a_queue();
	int c,new_data;
	do
	{
		printf("\t\t\t\t MAIN MENU \n");
		printf("1.Enqueue a data.\n");
		printf("2.Dequeue a data.\n");
		printf("3.Front data value.\n");
		printf("4.Print all data values.\n");
		printf("5.Exit.\n");
		printf("Enter your choice.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter data value to be enqued.\n");
				scanf("%d",&new_data);
				enqueue(new_data,head);
				print(head);
				break;
			case 2: printf("Dequeueing data.....\n");
				dequeue(head);
				print(head);
				break;
			case 3: if(head->next == NULL)
				{
					printf("Queue empty\n");
				}
				else
				printf("Front data value = %d \n",front->data);
				break;
			case 4: print(head);
				break;
			case 5: return;
				break;
			default: printf("Invalid Entry....!\n");
		}
	}
	while(c != 5);
}

struct node* create_a_queue()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = 0;
	ptr->next = NULL;
	return ptr;
}

void enqueue(int new_data,struct node *ptr)
{
	ptr->data = ptr->data + 1;
	struct node *new_ptr;
	new_ptr = (struct node*)malloc(sizeof(struct node));
	new_ptr->data = new_data;
	if(ptr->next == NULL)
	{
		new_ptr->next = ptr->next;
		ptr->next = new_ptr;
		front = ptr->next;
		rear = ptr->next;
	}
	else
	{
		new_ptr->next = rear->next;
		rear->next = new_ptr;
		rear = rear->next;
	}
}

void print(struct node *ptr)
{
	if(ptr->next == NULL)
	{
		printf("Queue empty\n");
		return;
	}
	printf("loading Queue......\n");
	struct node *temp;
	temp = ptr;
	while(temp->next != NULL)
	{
		temp = temp->next;
		printf("%d",temp->data);
	}
	printf("\n");
}

void dequeue(struct node *ptr)
{
	if(ptr->next == NULL)
	{
		printf("Queue empty\n");
		return;
	}
	struct node *temp;
	temp = front;
	front = front->next;
	ptr->next = temp->next;
	free(temp);
}