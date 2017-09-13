#include <stdio.h>

void swap(int*,int*);


void main()
{
	int size;
	do
	{
		printf("Enter size of array . \n");
		scanf("%d",&size);
	}
	while(size <= 0);
	int a[size],minimum,i;
	printf("Enter %d elements of array . \n",size);
	for(i = 0;i < size ;i++)
	{
		scanf("%d",&a[i]);
	}
	int j;
	for(i = 0;i < size - 1;i++)
	{
		minimum = i;
		for(j = i + 1;j < size;j++)
		{
			if(a[j] < a[minimum])
				minimum = j;
		}
		swap(&a[i],&a[minimum]);
	}
	for(i = 0;i < size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int *p1,int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
