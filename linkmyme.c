#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
 struct node *next;
};

struct node *head=NULL;

void createnode()
{
  struct node *newnode,*ptr;
  newnode= (struct node *)malloc(sizeof(struct node));
   if(newnode==NULL)
        {
                printf("Out of Memory Space:");
                exit(0);
        }
  printf("enter the data");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
    ptr=head;
    while(ptr->next!=NULL)
    {
       ptr=ptr->next; 
    }
   ptr->next=newnode;

  }
}
void display()
{
  struct node *ptr;
  printf("the link list is:");
  ptr=head;
  while(ptr->next!=NULL)
  {
    printf("%d--->",ptr->data);
    ptr=ptr->next;

  }
 printf("%d--->NULL",ptr->data);

}
void main()
{
  int choice;
  while(1)
  {
    printf("\n*******MENU********\n1:node_create\n2:display\n3:exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      {
       createnode();
       display();
       break; 
      }
     case 2:
     {
       display();
       break; 
     }
     case 3:
     {  display();
        exit(0);
        break;
     }
    }

  }


}

