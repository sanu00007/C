#include<stdio.h>
#include<stdlib.h>
int queue[100],front=-1,rear=-1;
int N;


void enqueueRear(int X)
{if((rear+1)%N==front)
   {
    printf("queue is full");
   }
  else if(front==-1&&rear==-1)
   {
    front=0;
    rear=0;
    queue[front]=X;

   }
else
 {
  rear=(rear+1)%N;
  queue[rear]=X;

 }

}
void enqueueFront(int X)
{
  if((rear+1)%N==front)
   {
    printf("queue is full");
   }
  else if(front==-1&&rear==-1)
   {
    front=0;
    rear=0;
    queue[front]=X;

   }
else if(front==0)
 {
  front=N-1;
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
    printf("queue is empty");
  }
 else 
 {int i;
  i=front;
while(i!=rear)
 {
   printf("%d(%d)",queue[i],i);
   i=(i+1)%N; 
 }
 printf("%d(%d)",queue[rear],i);
 }



}

void main()
{
  int X,choice;
  printf("the number of elements in queue");
  scanf("%d",&N);

while(1)
{
  printf("\n1:add from reart\n2:remove from front \n 3:display\n 4:add from front\n5:remove from rear \n 6:exit ");

  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    {
      printf("enter the element to add:");
      scanf("%d",&X);
      enqueueRear(X);
      display();
      break;
    }
  case 2:
  {
   printf("the elements removed is%d\n",dequeueFront());
   display();
   break;
  }
  case 3:
  {
   display();
   break;

  }
  case 4:
  { printf("enter the element to add:");
      scanf("%d",&X);
      enqueueFront(X);
      display();
      break;

  }
  case 5:
  {
     printf("the elements removed is%d\n",dequeueRear());
   display();
   break;
  }
  
  case 6:
  {
    exit(0);
  }
  default:
  {
    printf("invalid!");
  }





  }
}

}