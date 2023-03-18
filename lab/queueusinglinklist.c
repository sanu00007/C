#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;


void enqueue(int value)
{
  struct node *newnode;
  newnode= (struct node*)malloc(sizeof(struct node));
  newnode->data=value;
  newnode->next=NULL;
  if(front==NULL && rear==NULL)
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

int dequeue()
{
  struct node *temp;
  
  if(front==NULL)
  {
    printf("queue is empty\n");
  }
  else
  {
    temp=front;
    front=front->next;
    return temp->data;
    free(temp);
  
  }

}
void display()
{
  struct node *ptr;
  if(front==NULL)
  {
    printf("queue is empty\n");
  }
  else
  {
    ptr=front;
    printf("the queue is:");
    while(ptr->next!=NULL)
    {
      printf("%d--->",ptr->data);
      ptr=ptr->next;
    }
    printf("%d--->NULL\n",ptr->data);
  }


}



void main()
{
  int choice,value;
  
  while(1)
  {
     printf("MENU\n1)insert\n2)delete\n3)display\n4)exit\nENTER YOU CHOICE(1-4)\nchoice:");
     scanf("%d",&choice);
    
     switch(choice)
     {
        case 1:
        {
           printf("enter the value to insert in queue:");
           scanf("%d",&value);
           enqueue(value);
           display();
           break;
        }
      case 2:
      {
        printf("the deleted element is:%d\n",dequeue());
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
       display();
       exit(0);
     } 
     
   } 
     
     
     
     
  
  
  
  }


}


