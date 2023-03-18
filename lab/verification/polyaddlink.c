#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int coef;
  int exp;
  struct node *next;
} ;
struct node *head1=NULL;
struct node *head2=NULL;


void insert1()
{
  struct node *newnode, *ptr;
  newnode= (struct node *)malloc(sizeof(struct node));
  printf("enter the coefficient and exponenial(increasing order) of 1st polynomial");
  scanf("%d\t%d",&newnode->coef,&newnode->exp);
  newnode->next=NULL;
  if(head1==NULL)
  {
    head1=newnode;
  
  }
  else
  { 
    ptr=head1;
     
     while(ptr->next!=NULL)
     {ptr=ptr->next;
     
     }
     ptr->next=newnode;

  }
}

void insert2()
{
  struct node *newnode, *ptr;
  newnode= (struct node *)malloc(sizeof(struct node));
  printf("enter the coefficient and exponenial(increasing order) of 1st polynomial");
  scanf("%d\t%d",&newnode->coef,&newnode->exp);
  newnode->next=NULL;
  if(head2==NULL)
  {
    head2=newnode;
  
  }
  else
  { 
    ptr=head2;
     
     while(ptr->next!=NULL)
     {ptr=ptr->next;
     
     }
     ptr->next=newnode;

  }
}
void display1()
{
  struct node *ptr;
  if(head1==NULL)
  {
    printf("linklist is empty");
  }
  else
  {
    ptr=head1;
    while(ptr->next!=NULL)
    {
      printf("%d^(%d)--->",ptr->coef,ptr->exp);
      ptr=ptr->next;
    }
   printf("%d^(%d)--->NULL\n",ptr->coef,ptr->exp);
  
  }



}

void display2()
{
  struct node *ptr;
  if(head2==NULL)
  {
    printf("linklist is empty");
  }
  else
  {
    ptr=head2;
    while(ptr->next!=NULL)
    {
      printf("%d^(%d)--->",ptr->coef,ptr->exp);
      ptr=ptr->next;
    }
   printf("%d^(%d)--->NULL\n",ptr->coef,ptr->exp);
  
  }



}

void addition()
{
  struct node *ptr1,*ptr2;
  ptr1=head1;
  ptr2=head2;
 
   
  while(ptr1!=NULL && ptr2!=NULL)
  {
    if((ptr1->exp)>(ptr2->exp))
     {
       printf("%dX^(%d)+",ptr1->coef,ptr1->exp);
       ptr1=ptr1->next;
     }
    else if((ptr2->exp)>(ptr1->exp)) 
     {
       printf("%dX^(%d)+",ptr2->coef,ptr2->exp);
       ptr2=ptr2->next;
     }
     else
     {
       printf("%dX^(%d)+",(ptr1->coef+ptr2->coef),ptr1->exp);
       ptr2=ptr2->next;
       ptr1=ptr1->next;
     }
  }
  while(ptr1!=NULL)
  {
       printf("%dX^(%d)+",ptr1->coef,ptr1->exp);
       ptr1=ptr1->next;
  }
 while(ptr2!=NULL)
 {
       printf("%dX^(%d)+",ptr2->coef,ptr2->exp);
       ptr2=ptr2->next;
 
 }

}




void main()
{int choice;
        while(1){
               
                printf("\n                MENU                             \n");
                printf("\n 1.insert first polynomial ");
                printf("\n 2.Insert second polynomial   ");
                printf("\n 3.display both polynomial  ");
                printf("\n 4.addition of two polynomial      ");
                printf("\n 5.Exit       ");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        
                        case 1:
                                        insert1();
                                        display1();
                                        break;
                        case 2: 
                                        insert2();
                                        display2();
                                        break;
                        case 3:
                                        
                                        display1();
                                        display2();
                                        break;
                        case 4:
                                        addition();
                                        break;
                   
                      
                        case 5:         
                                        display1();
                                        display2();  
                                        exit(0);
                                        break;
                             
                        default:
                                        printf(" Wrong Choice:");
                                        break;
                }
        }
        
}











