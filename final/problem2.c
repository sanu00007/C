#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int ICP(char x)
{
  if(x=='+'||x=='-')
  return 1;
  if(x=='*'||x=='/')
  return 3;
  if(x=='^')
  return 6;


}

int ISP(char x)
{
  if(x=='+'||x=='-')
  return 2;
  if(x=='*'||x=='/')
  return 4;
  if(x=='^')
  return 5;
  if(x=='(')
  return 0;
}

void main()
{
  int i=0,j=0;
  int top=-1;
  int p1,p2;
  int len;
  char output[10],infix[10],stack[10];
  printf("enter the infix expression:");
  scanf("%s",infix);
  len=strlen(infix);
 
  while(infix[i]!='\0')
  {
    if(isalpha(infix[i]))
    {
      output[j]=infix[i];
      i++;
      j++;

    }
    else if(infix[i]=='(')
    {
      top++;
     stack[top]=infix[i];
     i++;

    }
    else if(infix[i]==')')
    {
      while(top!=-1)
      {
        if(stack[top]=='(')
        {break;
        }
        output[j]=stack[top];
        j++;
        top--;
      }
      if(stack[top]=='(')
      {
        top--;
        i++;
      }

    }
    else 
    {
      p1=ICP(infix[i]);
      p2=ISP(stack[top]);
      if(p1>p2)
      {
        stack[++top]=infix[i];
        i++;

      }
     else
     {
      output[j]=stack[top];
      j++;
      stack[top]=infix[i];
      i++;


     }
    }

    while(top!=-1)
    {
      if(stack[top]=='(')
      { 
        top--;
        
      }
      output[j]=stack[top];
      top--;
      j++;
    }

  }
 printf("the postfix expression is:");
 for(i=0;i<=j;i++)
 {  
    printf("%c",output[i]);
    
    
 }


}

