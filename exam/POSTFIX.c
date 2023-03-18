#include<stdio.h>
#include<ctype.h>
#include<string.h>

int ICP(char infix)
{
  if(infix=='+'||infix=='-')
  {
    return 1;
  }
  if(infix=='*'||infix=='/')
  {
    return 3;
  }
  if(infix=='^')
  {
    return 6;
  }
 

}

int ISP(char stack)
{
if(stack=='+'||stack=='-')
  {
    return 2;
  }
  if(stack=='*'||stack=='/')
  {
    return 4;
  }
  if(stack=='^')
  {
    return 5;
  }
  if(stack=='(')
  {
   return 0; 
  }
 
}

void main()
{
  char infix[100],output[100],stack[100];
  int a[100];
  int i=0,o=0,top=-1,j=0;
  int p1,p2;
  int item1,item2;
  printf("enter the infix expression:");
  scanf("%s",infix);

  while(infix[i]!='\0')
  {
    if(isalpha(infix[i]))
     {
       output[o]=infix[i];
       i++;
       o++;
     }
     else if(infix[i]==')')
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
     
     else if(infix[i]=='(')
     {
         top++;
      stack[top]=infix[i];
      i++;

     }
     else 
     {
       p1=ICP(infix[i]);
       p2=ISP(stack[top]);

       if(p1>p2)
       {
         top++;
         stack[top]=infix[i];
         i++;

       }
       else
       {
        output[o]=stack[top];
        o++;
        stack[top]=infix[i];
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
  printf("postfix expression is:");

  for(j=0;j<=o;j++)
  {
    printf("%c",output[j]);

  }

i=0;
top=-1;
while(output[i]!='\0')
{
  if(isalpha(output[i]))
   {
     printf("\nexpression is %c:",output[i]);
     printf("\nenter the value:");
     scanf("%d",&a[++top]);
     i++;
   }
  else
  { 
    item1=a[top];
    top--;
    item2=a[top];
    if(output[i]=='+')
    {
      a[top]=item2+item1;  
    }
     if(output[i]=='-')
    {
      a[top]=item2-item1;  
    }
     if(output[i]=='*')
    {
      a[top]=item2*item1;  
    }
     if(output[i]=='/')
    {
      a[top]=item2/item1;  
    }
     if(output[i]=='^')
    {
      a[top]=item2^item1;  
    }
   i++;

  }





}
printf("the evaluation is %d",a[0]);


}



