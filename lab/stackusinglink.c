#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
struct node *top=NULL;



void push(int value)
{
  struct node *newnode;
  newnode= (struct node *)malloc(sizeof(struct node));
  newnode->data=value;
  if(top==NULL)
  {
    newnode->next=NULL;
  }
  else
  {
    newnode->next=top;
  
  }
  top=newnode;
}

int pop()
{
  struct node *temp;
  temp=top;
  if(top==NULL)
  {printf("stack is empty");
  }
  
  else 
  {
    top=top->next;
    return(temp->data);
    free(temp);
  
  }
  
}

void display()
{
  struct node *ptr;
  printf("stack is:");
 if(top==NULL)
 {
   printf("\nstack is empty");
 }
 else
 {
  ptr=top;
  while(ptr->next!=NULL)
  {
  
   printf("%d--->",ptr->data);
   ptr=ptr->next;
  
  }
  printf("%d--->NULL",ptr->data);
 
 }



}


void main()
{
  int choice,value;
  
  while(1)
  {
     printf("\nMENU\n1).push\n2).pop\n3).display\n4).exit\nselect your choice\nchoice:");  
     scanf("%d",&choice);
     
     switch(choice)
     {
       case 1:
       {
         printf("\nenter the data needed to add in front of stack:");
         scanf("%d",&value);
         push(value);
         display();
         break;
       }
       
      case 2:
       {
         printf("\n the data deleted from front is %d\n",pop());
         display();
         break;      
      }
    
      case 3:     
       {
         display();
         break;
       }
      case 4:
       {display();
        exit(0);
        
        break;
       }
      
      default:
       {
        printf("invalid choice");
        break;
       }
   } 
 }
}




































