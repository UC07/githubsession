#include <stdio.h>

void swap(int*,int*);

void main()
{
	int size;
	do
	{
		printf("Enter valid size of array . \n");
		scanf("%d",&size);
	}
	while(size <= 0);
	int a[size],i;
	printf("Enter %d elements of array . \n",size);
	for(i = 0;i < size;i++)
	{
		scanf("%d",&a[i]);
	}
	int j;
	for(i = 0;i < size;i++)
	{
		j = i;
		while(j > 0 && a[j] < a[j - 1])
		{
			int temp;
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
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