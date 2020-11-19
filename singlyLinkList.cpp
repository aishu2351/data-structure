//singly link list Program
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *ptr,*temp,*cur,*start=NULL;
void insert_beg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		temp->link=start;
		start=temp;
	}
}
void insert_end()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
}
void insert_pos()
{
	int count=0,pos,i;
	printf("Enter the position to insert\n");
	scanf("%d",&pos);
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	if(pos==1)
		insert_beg();
	else if(pos==count+1)
		insert_end();
	else if(pos>1||pos<=count)
	 {
	 	temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&temp->data);
		temp->link=NULL;
		ptr=start;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	 }
	 else
	 printf("Invalid position");
}
void delete_beg()
{	
	ptr=start;
	if(start==NULL)
		printf("Empty\n");
	else if(start->link==NULL)
	{
		start=NULL;
		free(ptr);
	}
	else
	{
	    ptr->link=start;
		free(ptr);
	}
}
void delete_end()
{
	if(start==NULL)
		printf("Empty\n");
	else if(start->link==NULL)
	{
		start=NULL;
		free(ptr);
	}
	else
	{
		ptr=start;
	    while(ptr->link!=NULL)
	    {
	    	cur=ptr;
	    	ptr=ptr->link;
		}
		cur->link=NULL;
		free(ptr);
	}
}
void delete_pos()
{
	int count=0,i,pos;
	if(start==NULL)
	   printf("empty\n");
	else
	{
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("Enter pos to delete\n");
	scanf("%d",&pos);
	if(pos==1)
		delete_beg();
	else if(pos==count)
		delete_end();
	else if(pos>1||pos<count)
	{
		for(i=1;i<pos-1;i++)
		{
		  cur=ptr;
		  ptr=ptr->link;
	    }
		  cur->link=ptr->link;
		  free(ptr);
	}
	else 
		printf("invalid position\n");
	}
}
void display()
{
	if(start==NULL)
	{
		printf("list empty\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%d---->",ptr->data);
			ptr=ptr->link;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.insert_beg\n2.display\n3.insert end\n4.insert_pos\n5.delete_beg\n6.delete_end\n7.delete_pos\n");
		printf("\nEnter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_beg();
					break;
			case 2:display();
					break;
			case 3:insert_end();
					break;
			case 4:insert_pos();
					break;
			case 5:delete_beg();
					break;	
			case 6:delete_end();
					break;
			case 7:delete_pos();
		    		break;
			case 8:exit(0);
			default:printf("Invalid Entry");
		
		}
	}
}
