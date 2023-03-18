#include<stdio.h>
#include<ctype.h>
#include<string.h>

int ICP(char infix)
{
  if(infix=='+'||infix=='-')
  {
    return 2;
  }
  if(infix=='*'||infix=='/')
  {
    return 4;
  }
  if(infix=='^')
  {
    return 5;
  }
 

}

int ISP(char stack)
{
if(stack=='+'||stack=='-')
  {
    return 1;
  }
  if(stack=='*'||stack=='/')
  {
    return 3;
  }
  if(stack=='^')
  {
    return 6;
  }
  if(stack=='(')
  {
   return 0; 
  }
 
}

void main()
{
  char infix[100],output[100],stack[100],reverse[100];
  int i=0,o=0,top=-1,j=0;
  int p1,p2;
  printf("enter the infix expression:");
  scanf("%s",infix);
 
  for(i=0;i<strlen(infix);i++)
  {
    if(infix[strlen(infix)-i-1]=='(')
    {
      reverse[i]=')';
    }
    else if(infix[strlen(infix)-i-1]==')')
    {
      reverse[i]='(';
    }
    else
    reverse[i]=infix[strlen(infix)-i-1];

  }
   i=0;
  while(reverse[i]!='\0')
  {
    if(isalpha(reverse[i]))
     {
       output[o]=reverse[i];
       i++;
       o++;
     }
     else if(reverse[i]==')')
     {
         while(top!=-1)

        {   if (stack[top]=='(')

                break;

            output[o]=stack[top];

            o++;top--;

        }

         if (stack[top]=='(')

            top--;

         i++;

    }
     
     else if(reverse[i]=='(')
     {
         top++;
      stack[top]=reverse[i];
      i++;

     }
     else 
     {
       p1=ICP(reverse[i]);
       p2=ISP(stack[top]);

       if(p1>p2)
       {
         top++;
         stack[top]=reverse[i];
         i++;

       }
       else
       {
        output[o]=stack[top];
        o++;
        stack[top]=reverse[i];
        i++;
       }

     }

  }

  while(top!=-1)
  { if(stack[top]=='(')
    {
       top--;
    }
    output[o]=stack[top];
    top--;
    o++;

  }
  printf("prefix expression is:");

  for(j=0;j<o;j++)
  {
    printf("%c",output[o-j-1]);

  }

}



