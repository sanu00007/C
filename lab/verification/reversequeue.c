#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;

};


struct node *front=NULL;
struct node *rear=NULL;
struct node *top=NULL;

void enqueue(int item)
{
  struct node *newnode;
  newnode= (struct node*)malloc(sizeof(struct node));
  newnode->data=item;
  newnode->next=NULL;
  if(front==NULL)
  {
   
    front=newnode;
    rear=newnode;
    
  }
 else
 {
   rear->next=newnode;
 
 }
 
 rear=newnode; 

}

void dequeue()
{ struct node *temp,*new,*temp1;
 if(front==NULL)
 {
   printf("queue is empty");
 }
else
{ printf("dequeued is: %d\n",front->data);
  temp=front;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=temp->data;
  new->next=top;
  top=new;
  front=front->next;
  free(temp);
 
}
temp1=top;
printf("the stack is:");
while(temp1->next!=NULL)
{
 printf("%d--->",temp1->data);
 temp1=temp1->next;
}
printf("%d--->NULL\n",temp1->data);
}

void display()
{
  struct node *temp;
  temp=front;
  if(front==NULL)
  {
   printf("queue is empty");
  }
 else
 { printf("the queue is:");
  while(temp->next!=NULL)
  {
   printf("%d--->",temp->data);
   temp=temp->next;
  
  }
  printf("%d-->NULL\n",temp->data);
 }

}

void rev()
{
  struct node *temp;
  temp=top;
  while(temp!=NULL)
  {
   enqueue(temp->data);
   temp=temp->next;
  
  }
   display();

}

void main()
{
int choice,item;
while(1)
  {
     printf("MENU\n1)insert\n2)delete\n3)display\n4)reverse\nENTER YOU CHOICE(1-4)\nchoice:");
     scanf("%d",&choice);
    
     switch(choice)
     {
        case 1:
        {
           printf("enter the value to insert in queue:");
           scanf("%d",&item);
           enqueue(item);
           display();
           break;
        }
      case 2:
      {
        dequeue();
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
       rev();
       exit(0);
       break;
     } 
     
     
   }
   }} 
     
















