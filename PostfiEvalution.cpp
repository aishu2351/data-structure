//Postfix Evalution
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int s[30],op1,op2,top=-1,i=0;
char postfix[30],ch;

void push(int num)
{
 	s[++top]=num;
}

int pop()
{
	 return(s[top--]);
}

int main()
{
 	printf("\nEnter the postfix\n");
 	gets(postfix);
 	while(postfix[i]!='\0')
 	{
 		ch=postfix[i];
 		if(isalpha(ch))
 		{
 			int num;
 			printf("\n Enter the value of %c\n",ch);
 			scanf("%d",&num);
 			push(num);
 		}
 		else
 		{
 			op1=pop();
 			op2=pop();
 			int res=0;
 			switch(ch)
 			{
 				case '+':
 						res = op2+op1;
 						push(res);
 						break;
 				case '-':
 						res = op2-op1;
 						push(res);
 						break;
 				case '*':
 						res = op2*op1;
 						push(res);
 						break;
 				case '/':
 						if(op1==0)
 							printf("\nDivide by 0 error\n");
 						else
 					    	{
								 res = op2/op1;
 								push(res);
 							}
 						break;
 				case '^':
 						res = op2^op1;
 						push(res);
 						break;
 				default:
 						printf("\n Invalid expression\n");
 			}
 		}
 		++i;
	}
	printf("\nThe output of expression is:\n%d",s[top]);
	
}
