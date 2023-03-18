#include<stdio.h>
#include<stdlib.h>

int N;
int front=-1,rear=-1;
int queue[100];

void enqueue(int X)
{
 if((rear+1)%N==front)
 {
   printf("the queue is full!");
 }
else if(front==-1&&rear==-1)
 {
   front=0;
   rear=0;
   queue[0]=X;
 }
 else
{ rear=(rear+1)%N;
  queue[rear]=X;
 }
}

int dequeue()
{
 if(front==-1&&rear==-1)
 {
  printf("queue is empty!");
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

void display()
{
  if(front==-1&&rear==-1)
   {
     printf("the queue is empty!");
   }
   else
   {printf("the queue is=");
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
  printf("enter the no.of elements in the queue= ");
  scanf("%d",&N);
  
  while(1)
  {
     printf("\n1:enqueue\n2:dequeue\n3:display\n4:exit \nother:invalid \n select from 1-4\n");
     scanf("%d",&choice);
    switch(choice)
    {
      case 1:
       {
         printf("enter the element to be added:");
         scanf("%d",&X);
         enqueue(X);
         display();
         break;
         
       }
      case 2:
      {
        printf("the element deleted is:%d\n",dequeue());
        display();
         break;
      } 
      case 3:
      {
       display();
       break;
      }
     case 4:
     {exit(0);
     }
     default:
     {
      printf("invalid choice");
     }
    } 
  
  } 
   
}










