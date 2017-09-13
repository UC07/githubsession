#include <stdio.h>

#define size 5

void enqueue(int);
void display(void);
void dequeue(void);

int a[size];

int front,rear;

void main()
{
	int c,data;
	front = -1;
	rear = -1;
	do
	{
		printf("\t\t\t\tMAIN MENU \n");
		printf("1.Enqueue data \n");
		printf("2.Dequeue data \n");
		printf("3.Display queue \n");
		printf("4.Exit \n");
		printf("Enter your choice \n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the data value to be enqueued in the queue \n");
				scanf("%d",&data);
				enqueue(data);
				display();
				break;
			case 2: printf("Dequeueing data..... \n");
				dequeue();
				display();
				break;
			case 3: printf("displaying queue..... \n");
				display();
				break;
			case 4: return;
			default:return;
		}
	}
	while(c != 4);
}

void enqueue(int data)
{
	if(rear == -1 && front == -1)
	{
		front = 0;
		rear = 0;
		a[rear] = data;
	}
	else if(front == (rear + 1) % size)
	{
		printf("Error Overflow : queue is full ! \n");
		return;
	}
	else
	{
		rear = (rear + 1) % size;
		a[rear] = data;
	}
}

void display()
{
	if(rear == -1 && front == -1)
	{
		printf("Empty Queue ! \n");
		return;
	}
	int i;
	i = front;
	while(1)
	{
		if(i == rear)
		{
			printf("%d",a[i]);
			return;
		}
		printf("%d",a[i]);
		i = (i + 1) % size;
	}
}

void dequeue()
{
	if(rear == -1 && front == -1)
	{
		printf("Error Underflow : Can not enqueue more \n");
		return;
	}
	else if(front == rear)
	{
		front = -1;
		rear = -1;
		return;
	}
	else
	front = (front + 1) % size;
}
