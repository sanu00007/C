#include<stdio.h>
#include<stdlib.h>

int N,stack[5],queue[5],top=-1,rear=-1,front=-1,N;

void enqueue(int x)
{ 
  if(rear==N-1)
  {
    printf("queue is full");
  }
 else if(front==-1 && rear==-1)
 {
   front=0;
   rear=0;
   queue[0]=x;
 }
 else
 {
  rear++;
  queue[rear]=x;
 }
}

int dequeue()
{
  if(front==-1 && rear==-1)
  {
    printf("queue is empty");
  }
  else if(front==0 && rear==0)
  {
    front=-1;
    rear=-1;
    return queue[0];
  }
  else
  {
  front++;
  return queue[front-1];
  }
}

void push(int x)
{
 if(top==N-1)
 {
  printf("stack is full");
 }
 else
 {
  top++;
  stack[top]=x;
 }
}

int pop()
{
 if(top==-1)
 {
  printf("stack is empty");
 }
 else
 {
  top--;
  return stack[top+1];
 }
}

void display()
{
 if(front==-1)
 {
  printf("queue is empty");
 }
else
{ printf("queue is:");
  for(int i=front;i<=rear;i++)
  {
    printf("%d",queue[i]);
  }
}

}

void main()
{
 int x,choice,item1,item2;
 printf("enter the elements in the queue:");
 scanf("%d",&N);
 while(1)
 {
   printf("\n1.enqueue\n2.dequeue to stack\n3.pop to queue\n4.exit\nselect your choice:");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    {
      printf("enter the value to be added in queue:");
      scanf("%d",&x);
      enqueue(x);
      break;
    }
   case 2:
   {
    item1=dequeue();
    push(item1);
    break;
   }
   case 3:
   {
    item2=pop();
    enqueue(item2);
   break;
   }
   case 4:
   {
    display();
    exit(0);
   }
   case 5:
   {
    display();
    break;
   }
   }


 }



}