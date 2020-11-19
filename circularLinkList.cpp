//Circular Link List Program
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *ptr,*last=NULL,*temp,*cur;
void insertbeg()
{
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nenter the element\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(last==NULL){
		last=temp;
		last->link=last;
	}	else{
		temp->link=last->link;
		last->link=temp;
	}
}
void insertend()
{
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nenter the element\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(last==NULL){
		last=temp;
		last->link=temp;
	}
	else{
		temp->link=last->link;
		last->link=temp;
		last=temp;
	}
}
void display()
{  
	if(last==NULL)
	{
		printf("empty");
	}
	else
	{
	       ptr=last->link;
		while(ptr!=last)
		{
			printf("%d-->",ptr->data);
			ptr=ptr->link;
		}
	}
	
}
void deletebeg(){
	if(last==NULL)
	{
		printf("empty");
	}
	else{
		ptr=last->link;
		last->link=ptr->link;
		free(ptr);
	}
}
void deletend()
{
	if(last==NULL)
	{
		printf("empty");
	}
	else
	{
		ptr=last->link;
		while(ptr->link!=last){
			ptr=ptr->link;
			
		}
		ptr->link=last->link;
		free(last);
		last=ptr;
		if(last->link==last)
		 last=NULL;
	}
}
void insertpos()
{
	int count=0,i,pos;   
    ptr=last->link;
	while(ptr!=last)
	{
	  	count++;
	    ptr=ptr->link;
	}
	count++;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos==1)
		{
		  	insertbeg();
		}
	else 
	if(pos==count+1)
	{
	  	insertend();
	}
	else
	if(pos>1&&pos<=count)
	{
	  	temp = (struct node*)malloc(sizeof(struct node));
       	printf("\nenter the element\n");
       	scanf("%d",&temp->data);
       	temp->link=NULL;
       	ptr=last->link;
       	for(i=1;i<pos-1;i++)
		{	
        	ptr=ptr->link;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
	else
	  	printf("invalid position\n");
}
void deletepos()
{
		int count=0,pos,i;
		printf("enter the postion to deleted");
		scanf("%d",&pos);
		ptr=last->link;
		while(ptr!=last){
			count++;
			ptr=ptr->link;
		}
		count++;
		if(pos==1){
		
		   deletebeg();
		   }
		else if(pos==count){
		
		    deletend();}
		else if(pos>1&&pos<=count)
		{
			ptr=last->link;
			for(i=1;i<pos;i++)
			{
				cur=ptr;
				ptr=ptr->link;
				
			}
		    cur->link=ptr->link;
		    free(ptr);
		}
		
	}

int main()
{
	int ch;
	while(1)
	{   
	    printf("\nCIRCULAR LINK LIST\nEnter Your Choice\n");
//		printf("Enter Your Choice\n");
		printf("\n1.insertbeg\n2.insertend\n3.insertpos\n4.deletebeg\n5.delete_end\n6.deletepos\n7.display\n8.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertbeg();
			        break;
	     	case 2: insertend();
			        break;
		    case 3: insertpos();
		    	    break;
		    case 4:deletebeg();
		    		break;
		    case 5: deletend();
			        break;
			case 6: deletepos();
			        break;
			case 7: display();
			        break;
            case 8:exit(0);
			        break;
		}
	}
}

