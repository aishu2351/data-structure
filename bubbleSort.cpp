#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,r,a[10000],i,j,temp;
	clock_t start,end;
	double total_time;
	printf("Enter array size\n");
	scanf("%d",&n);
	printf("Randomly Generated %d Number\n",n);
	for(i=0;i<n;i++)
	{
		r=rand();
		a[i]=r;
		printf("%d\t",a[i]);
	}
	start=clock();
	 for (i=0;i<n-1;i++)
	{
      for (j=0;j<n-i-1;j++) 
	  {
        if (a[j]>a[j+1])
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
        }
      }
    }
    end=clock();
    total_time=((double)end-start)/CLOCKS_PER_SEC;
    printf("\nSorted array is:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
	printf("\ntime taken to sort is:%lf",total_time);
  }

