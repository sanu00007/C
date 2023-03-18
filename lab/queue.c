#include<stdio.h>
#include<stdlib.h>

int N,front=-1,rear=-1,queue[100];

void enqueue(int X)
 {
  if(rear==(N-1))
   {
    printf("queue is full");
   }
 
  else if(front==-1&&rear==-1)
  { front=0;
    rear=0;
    queue[0]=X;
  } 
 else
   {rear++;
    queue[rear]=X; 
   }
 }
int dequeue()
{
 if(front==-1&&rear==-1)
  {
    printf("queue is empty");
   } 
 else if(front==rear)
  {
    return queue[front];
    front=-1;
    rear=-1;
  }
 else
  {
   front++;
   return queue[front-1];
  }
 
 
} 
void display()
 { 
   if(front==-1&&rear==-1)
     { 
       printf("queue is empty");
     }
   else
    { printf("the elements in queue is");
      for(int i=front;i<=rear;i++)
         {printf("%d\t",queue[i]);
          }
    }
 }
 
 
 void main()
 { 
   int choice,X;
   printf("the number of elements in queue:");
   scanf("%d",&N);

   while(1)
   {
     printf("\n1:enqueue\n2:dequeue\n3:display\n4:exit \nother:invalid \n select from 1-4\n");
     scanf("%d",&choice);
     
     switch(choice)
      {
       case 1:
        { printf("enter the element to add:");
          scanf("%d",&X);
          enqueue(X); 
          display();
          break; 
         }
       case 2:
       {
         printf("the removed element is %d",dequeue());
         display();
         break;       
       }
       case 3:
       {display();
        break;
       }       
       case 4:
        {exit(0);
        }
       default:
       {printf("invalid choice");
       }
      }
   
   
   
   
   }


 }


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
