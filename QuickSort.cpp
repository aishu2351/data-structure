#include<stdio.h>
#include<time.h>

int partition(int [],int,int);

void quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

int partition(int a[],int low,int high)
{
	int p,i,j,temp;
	p=a[low];
	i=low;
	j=high+1;
	do
	{
		do
			i++;
		while((a[i]<p) && (i<=p));
		do
			j--;
		while(p<a[j]);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
 	}
	while(i<j);
	a[low]=a[j];
	a[j]=p;
	return j;
}

int main()
{
	int a[10],n,i,time_count;
	clock_t start_clk,end_clk;
	double time_used;
	start_clk=clock();
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	printf("Array elements after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	end_clk=clock();
	time_used=((double)(end_clk-start_clk)/CLOCKS_PER_SEC);
	printf("\nTime required is%d",time_used);
}

