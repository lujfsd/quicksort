#include <stdio.h>

int partitions(int a[],int low,int high)
{
	int key = a[low];
	int i;
	while(low<high)
	{
		while(low<high && a[high]>=key)
			--high;
		a[low]=a[high];
		while(low<high && a[low]<=key)
			++low;
		a[high]=a[low];

		for(i=0;i<11;printf("%d* ",a[i]),i++);
		printf("\n");
	}
	a[low]=key;
	for(i=0;i<11;printf("*%d ",a[i]),i++);
	printf(" low=%d\n",low);
	return low;
}

void myqsort(int a[],int low,int high)
{
	int tag;
	if(low<high)
	{
		tag = partitions(a,low,high);
		myqsort(a,low,tag-1);
		myqsort(a,tag+1,high);
	}
}

void quicksort(int a[],int n)
{
	myqsort(a,0,n);
}

int main()
{
	//unsigned char *buf="ÄãºÃ";
	//printf("buf=%s\n",buf);
	//printf("buf0=%x\n",buf[0]);
	//test(buf);
	int i;
	int a[]={8,11,12,5,6,13,8,9,14,7,10};
	for(i=0;i<11;printf("%d ",a[i]),i++);
	printf("\n");
	quicksort(a,10);

	for(i=0;i<11;printf("%d ",a[i]),i++);

	printf("\n");
	return 1;
}