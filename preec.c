#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define size 20
char pop();

int priority(char);
void push(char);
int eval(int,int,char);
int answer(char []);

char stack[size];

int top=-1;




int main()

{

char exp[20],x,temp,pre[20];
int i=0,j,l,k=0;
long int r;



printf("\nenter expression");
scanf("%s",exp);

l=strlen(exp)-1;

for(j=0;j<l/2;j++)
{
	temp=exp[j];
	exp[j]=exp[l-j];
	exp[l-j]=temp;
}

while(exp[i]!='\0')
{


	if(isalnum(exp[i]))
	{
		/*printf("%c",exp[i]);*/
		pre[k]=exp[i];
		k++;
	}
	

	else if(exp[i]==')')
	{
		push(exp[i]);

	}
	else if(exp[i]=='(')
	{	

		while((x=pop())!=')')
		{
		/*printf("%c",x);*/
		pre[k]=x;
		k++;
		}
	}

	else
	{
		while(priority(stack[top])>priority(exp[i]))
		{
		x=pop();
		/*printf("%c",x);*/

		pre[k]=x;
		k++;
		}
	push(exp[i]);

	}

i++;
}

while(top!=-1)
{
	x=pop();
	/*printf("%c",x);*/
	pre[k]=x;
	k++;
}
pre[k]='\0';

l=strlen(pre)-1;
for(i=0;i<l/2;i++)
{
	temp=pre[i];
	pre[i]=pre[l-i];
	pre[l-i]=temp;
}

printf("\n prefix expresion is %s",pre);

l=strlen(pre)-1;

for(i=0;i<l/2;i++)
{
	temp=pre[i];
	pre[i]=pre[l-i];
	pre[l-i]=temp;
}

x=answer(pre);
printf("\n final answer is %d",x);

return 0;
}


void push(char x)
{

if(top==size-1)
	{
		printf("overflow");
	}

	else
	{
	top++;
	stack[top]=x;
	}

}
char pop()

{

	if(top==-1)

	{
	printf("under flow");

	}

	else
	{
	return(stack[top--]);
	}

}

int priority(char a)
{


if(a==')')

	return 0;

if(a=='+'||a=='-')
	return 1;

if(a=='*'||a=='/')
	return 2;
if(a=='^')
	return 3;
	
}

int answer(char a[])
{

int i=0,op1,op2,r;

while(a[i]!='\0')
{
	if(a[i]>='0'&&a[i]<='9')
	{
	push(a[i]-'0');
	}
	
	else
	{
	op1=pop();
	op2=pop();
	r=eval(op1,op2,a[i]);
	push(r);
	}
i++;

}

return(pop());
}

int eval(int a,int b,char ch)
{	
	switch(ch)
	{
	case '+':return(a+b);

	case '-':return(a-b);

	case '*':return(a*b);

	case '/':return(a/b);
	
	case '^':return(pow(a,b));
	}

}

