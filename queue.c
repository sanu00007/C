#include<stdio.h>
#include<stdlib.h>
int N,queue[100],front=-1,rear=-1;
void enqueue(int X)
 {
   if(rear==N-1)
    {
     printf("queue is full");    
    }
 else if(front==-1&&rear==-1)
 {front=0;
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
    if(front==-1&& rear==-1)
     {
       printf("queue is empty");
       
     }
    else if(front==rear)
    {
     return queue[0];
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
        printf("queue is full"); 
     }
    else
    {
      printf("the queue is:");    
      for(int i=front;i<=rear;i++)
        {
         printf("%d\t",queue[i]);        
        }      
        
    }
  }
  void main()
  { int X,choice;
    printf("total elements in queue");
    scanf("%d",&N);
   while(1)
    { printf("\n1:enqueue\n 2:dequeue \n 3:display\n4:exit(0)\n select choice from1-4\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
        {printf("element to add\n");
        scanf("%d",&X);
        enqueue(X);
        display();
        break;        
        }
        case 2:
        {
         printf("the element removed is:%d",dequeue());
         display();
         break;
        }
        case 3:
        {
          display();
          break;
        }
         case 4:
         {
            exit(0);
            break;
         }
         default :
         {printf("invalid");}
      }
    
    
    
    
        
        
    }
       
  }
  