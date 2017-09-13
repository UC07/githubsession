#include <stdio.h>

void swap(int*,int*);

void main()
{
	int size;
	do
	{
		printf("Enter the valid size of array . \n");
		scanf("%d",&size);
	}
	while(size <= 0);
	int a[size],i,j;
	printf("Enter %d elements of array . \n",size);
	for(i = 0;i < size ;i++)
	{
		scanf("%d",&a[i]);
	}
	int s;
	s = 1;
	i = 0;
	while(s != 0)
	{
		s = 0;
		for(j = 0;j < size - i - 1;j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(&a[j],&a[j + 1]);
				s++;
			}
		}
		i++;
	}
	for(i = 0;i < size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int* a,int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}