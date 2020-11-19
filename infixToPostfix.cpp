//Infix to Postfix Expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char infix[30],postfix[30],s[30],ch,temp;
int i=0,j=0,t=-1;

void push(char c)
{
 	s[++t]=c;
}

char pop()
{
 	return(s[t--]);
}

int precedence(char c)
{
 	switch(c)
	 {
 		case '^':
 				return 4;
 		case '*':
 		case '/':
				return 3;
 		case '+':
 		case '-':
 				return 2;
 		default:
 				return 1;
 }
}	

int main()
{
 printf("\nEnter the infix\n");
 gets(infix);
 while(infix[i]!='\0')
 	{
 		ch=infix[i];
 		if(isalpha(ch))
 			postfix[j++]=ch;
 		else if(ch=='(')
 				push(ch);
 			else if(ch=='^'||ch=='/'||ch=='*'||ch=='-'||ch=='+')
 				{
 					if(ch!='^')
 						while(t!=-1&&precedence(s[t])>=precedence(ch))
 							postfix[j++]=pop();
 							push(ch);
				}
	 			else	
					if(ch==')')
 					{
 						while(s[t]!='(')
 						postfix[j++]=pop();
 						temp=pop();
 					}
 					else
					printf("\nInvalid expression\n");	
					 ++i;
	}
 	for(;t>-1;postfix[j++]=pop());
 	postfix[j]='\0';
 	printf("\nThe postfix expression is:\n");
 	puts(postfix);

}
