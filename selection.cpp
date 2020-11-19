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
	printf("Randomly Generated Array\n");
	for(i=0;i<n;i++)
	{
		r=rand();
		a[i]=r;
		printf("%d\t",a[i]);
	}
	start=clock();
	 for (i=0;i<n;i++)
	{
      for (j=i+1;j<n;j++) 
	  {
        if (a[i]>a[j])
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
    }
    end=clock();
    total_time=((double)end-start)/CLOCKS_PER_SEC;
    printf("\nSorted array is:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
	printf("\ntime taken to sort is:%lf",total_time);
  }

