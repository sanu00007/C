#include<stdio.h>
#include<stdlib.h>
int N,top=-1,stack[100];

void push(int X)
{ 
 if(top==(N-1))
   {
    printf("stack is full \n"); 
   
   } 
 else
  {
    top++;
    stack[top]=X; 
   }
}

int pop()
{
 if(top==-1)
  {printf("stack is empty");
   }
 else
  {    top--;
    return stack[top+1];
 
    
   }
}

void display()
{
  if(top==-1)
    {
      printf("stack is empty");
     }  
  else
   { printf("the stacK is:");
     for(int i=0;i<=top;i++)
      {
        printf("%d\t",stack[i]);
       }
    }
}

void main()
 { 
   int choice,X;
   printf("the number of elements in stack:");
   scanf("%d",&N);

   while(1)
   {
     printf("\n1:push\n2:pop\n3:display\n4:exit \nother:invalid \n select from 1-4\n");
     scanf("%d",&choice);
     
     switch(choice)
      {
       case 1:
        { printf("enter the element to add:");
          scanf("%d",&X);
          push(X); 
          display();
          break; 
         }
       case 2:
       { printf("the removed element is %d",pop());
         
         display();
         break;       
       }
       case 3:
       {display();
        break;
       }       
       case 4:
        {exit(0);
         break;
        }
       default:
       {printf("invalid choice");
        break;
       }
      }
   
   
   
   
   }


 }

























