#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int heap_size,capacity,*heap;
void swap(int*a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void min_heap(int n)
{
    heap_size=0;
    capacity=n;
    heap=(int*)malloc(capacity*sizeof(int));
}
void min_heapify(int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int min=i;
    if(left<heap_size&&heap[left]<heap[i])
        min=left;
    if(right<heap_size&&heap[right]<heap[min])
        min=right;
    if(min!=i)
    {
        swap(&heap[i],&heap[min]);
        min_heapify(min);
    }
}
void make_min_heap()
{
    int i;
    for(i=heap_size/2;i>=0;i--)
    {
        min_heapify(i);
    }
}
void insert(int v)
{
    if(heap_size==capacity)
        return;
    heap_size++;
    int i=heap_size-1;
    heap[i]=v;
    while(i!=0&&heap[(i-1)>>1]>heap[i])
    {
        swap(&heap[i],&heap[(i-1)>>1]);
        i=(i-1)>>1;
    }
}
int extract_min(int i)
{
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1)
    {
        return heap[--heap_size];
    }
    int ans=heap[0];
    heap[0]=heap[--heap_size];
    min_heapify(0);
    return ans;
}
int main()
{
    min_heap(5);
    int i,d;
    for(i=0;i<5;i++)
    {
        scanf("%d",&d);
        insert(d);
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%d ",extract_min(0));
    }
    printf("\n");
    return 0;
}
