#include<stdio.h>
#include<stdlib.h>

int N,front=-1,rear=-1,queue[100];

void enqueueRear(int X)
{
  if((rear+1)%N==front)
    {
      printf("the queue is full");
    }
   else if(front==-1&&rear==-1)
    { front=0;
      rear=0;
      queue[rear]=X;
    }
   else 
   {
     rear=(rear+1)%N;
     queue[rear]=X;
   } 
}
void enqueueFront(int X)
{
 if((front-1)%N==rear)
   {
    printf("the queue is full");
   
   }
 else if(front==-1&&rear==-1)
    { front=0;
      rear=0;
      queue[front]=X;
    }
 else if(front==0)
 {front=N-1;
   queue[front]=X;
 }
 else
 {
  front=(front-1)%N;
  queue[front]=X;
 }
}
int dequeueFront()
{
  if(front==-1&&rear==-1)
   {
     printf("queue is empty");
   
   }
 else if(front==rear)
 {
   front=-1;
   rear=-1;
   return queue[front+1];
 }
 else
 {
  front=(front+1)%N;
  return queue[front-1];
 
 }
 }
 int dequeueRear()
{ 
  if(front==-1&&rear==-1)
   {
     printf("queue is empty");
   }
  else if(front==rear)
  {
    front=-1;
    rear=-1;
    return queue[rear+1];
  } 
  else if(rear==0) 
  {
    rear=N-1;
    return queue[0];
  }
  else
  {
    rear=(rear-1)%N;
    return queue[rear+1];
  }
}

void display()
{
  if(front==-1&&rear==-1)
   {
     printf("the queue is empty!");
   }
   else
   {printf("the queue is:");
    int i=front;
    while(i!=rear)
    {
     printf("%d(%d)\t",queue[i],i);
     i=(i+1)%N;
    }
   printf("%d(%d)\t",queue[rear],i);
   
   }



}


void main()
{

  int choice,X;
  printf("enter the number of elements in double ended queue:");
  scanf("%d",&N);
  
 while(1)
 
 {
 
  printf("enter the below choice\n 1:enter from rear\n2:enter from front\n 3:remove from front\n4:remove from rear\n5:display\n6:exit\nyour choice:");
  
  scanf("%d",&choice);
 
  switch(choice)
  {
    case 1:
    {
      printf("enter the element to add in rear:");
      scanf("%d",&X);
      enqueueRear(X);
      display();
      break;
    }
    case 2:
    
   {
      printf("enter the element to add in front:");
      scanf("%d",&X);
      enqueueFront(X);
      display();
      break;
    }
    
    case 3:
    {
      printf("enter the element removed from front: %d",dequeueFront());
      display();
     break;
    }
    
   case 4:
   {
     
    printf("enter the element removed from rear: %d",dequeueRear());
      display();
     break;
   
   
   }
   case 5:
   {
     display();
     break;
   }
   case 6:
   {
     exit(0);
   }
  default:
  {
    printf("INVALID");
  }
  
  
  
  
  
  
  
  }
 
 
 
 
 
 
 
 }
 





}




























