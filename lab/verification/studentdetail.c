#include<stdio.h>
#include<stdlib.h>

struct node
{
  int number;
  char name[100];
  int mark;
  struct node *next;
};

struct node *head=NULL;
struct node *end=NULL;

void insert()
{ 
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("ENTER THE ROLL NUMBER OF STUDENT:");
  scanf("%d",&newnode->number);
  printf("ENTER THE NAME OF CHILD:");
  scanf("%s",newnode->name);
  printf("ENTER THE MARK OF STUDENT:");
  scanf("%d",&newnode->mark);
  newnode->next=NULL;
  if(head==NULL && end==NULL)
  {
    head=newnode;
    end=newnode;
  
  }
  else
  {
   end->next=newnode;
   end=newnode;
  }

}

void delete()
{
  struct node *temp,*ptr;
  int flag=0,x;
  temp=head;
  printf("ENTER THE ROLL NUMBER OF STUDENT TO BE DELETED: ");
  scanf("%d",&x);
  if(head->number==x)
  {
   head=head->next;
   free(temp);
   flag=1;
  }
 else
 {
  while(temp->next!=NULL)
   {
     if(temp->next->number==x)
     {
       ptr=temp->next;
       if(ptr->next==NULL)
        {
        end=temp;
        }
       temp->next=ptr->next;
       free(ptr);
       flag=1;
      
     }
     
    temp=temp->next;
     }
  }
 if(flag==0)
 {
  printf("ITEM NOT FOUND IN THE LIST %d",x);
 }

}
void search()
{
 struct node *temp;
 int flag=0,y;
 temp=head;
 printf("ENTER THE ROLL NUMBER OF STUDENT WHOSE MARK IS NEEDED TO SEARCH");
 scanf("%d",&y);
 while(temp!=NULL)
 { 
   if(temp->number==y)
   {
     printf("the student details:\n");
     printf("NAME:%s\nROLL NO:%d\nMARK:%d",temp->name,temp->number,temp->mark);
     flag=1;
     
   }
  temp=temp->next;
 }
 if(flag==0)
 {
  printf("ITEM IS NOT FOUND IN LIST %d",y);
 }
 
 
}

void sort()
{
 struct node *temp1,*temp2;
 int i,n,m;
 char a[100];
 temp1=head;
 temp2=head;
 for(temp1=head;temp1->next!=NULL;temp1=temp1->next)
 {
   for(temp2=head;temp2->next!=NULL;temp2=temp2->next)
    {
      if((temp2->number) > (temp2->next->number) )
       {
        n=temp2->number;
        m=temp2->mark;
        for(i=0;temp2->name[i]!='\0';i++)
        {
          a[i]=temp2->name[i];
        
        }
        a[i]='\0';
       
       temp2->number=temp2->next->number;
       temp2->mark=temp2->next->mark;
       temp2->next->number=n;
       temp2->next->mark=m;
       for(i=0;temp2->next->name[i]!='\0';i++)
       {
         temp2->name[i]=temp2->next->name[i];
       
       }   
       temp2->name[i]='\0';   
       for(i=0;a[i]!='\0';i++)
       {
        temp2->next->name[i]=a[i];
       }       
       }
    } 
 }
}

void display()
{
 struct node *temp;
 temp=head;
 if(head==NULL)
 {
  printf("LIST IN EMPTY");
 }
 else
 {
  while (temp!=NULL)
  {
   printf("\nthe student details:\n");
   printf("NAME:%s\nROLL NO:%d\nMARK:%d",temp->name,temp->number,temp->mark);
   temp=temp->next;
  }
 }
}
int main()
{
  int choice;
  
  while(1)
  {
    printf("\nMENU\n1:insert\n2:delete\n3:search\n4:sort\nSELECT 1/2/3/4");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
      {
        insert();
        display();
        break;
      }
      case 2:
      {
       delete();
       display();
       break;
      }
     case 3:
     {
      search();
      break;
     }
     case 4:
     {
      sort();
      display();
      break;
     
     }
     case 5:
     {
     display();
     exit(0);
     break;
     }
    }
  
  
  }
 


}
