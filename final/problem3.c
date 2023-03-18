#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *left;
 struct node *right;
}*root;

char hc;
struct node *create()
{
 int x;
 struct node *newnode= (struct node *)malloc(sizeof(struct node));
 newnode->left=NULL;
 newnode->right=NULL;

 printf("enter the value to be inserted (-1 if NULL)");
 scanf("%d",&x);

 if(x==-1)
 {   
    return NULL;
 }
 
 else
 {
  newnode->data=x;
  printf("if there is any left child for %d",x);
  newnode->left=create();
  printf("if there is any right child for %d",x);
  newnode->right=create();
  return newnode;
 }


}

void preorder(struct node *ptr)
{
 if(ptr==NULL)
 {
    return;
 }
 else
 {
    printf(" %d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
 }

}
struct node *search(struct node *ptr,int key)
{
 struct node *ptr1;
 ptr1=ptr;
 if(ptr1->data!=key)
  {
   if(ptr1->left!=NULL)
   ptr1= search(ptr1->left,key); 
   if(ptr1->right!=NULL)
   ptr1= search(ptr1->right,key);


 }
 else
 {
    return ptr1;
 }

}

void insert()
{
  int key,value;
  char hc;
  struct node *newnode;
  printf("enter the key where we needed to insert");
  scanf("%d",&key);  
  struct node *ptr=search(root,key);
  if(ptr==NULL)
  {printf("cannot insert");
  exit;
  }
  else
  {
   if(ptr->left==NULL||ptr->right==NULL)
   {
     printf("left or right");
     hc=getchar();
     scanf("%c",&hc);
     printf("enter the value:");
     scanf("%d",&value);
     if(hc=='l')
     {
      if(ptr->left==NULL)
      {
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=value;
       newnode->left==NULL;
       newnode->right==NULL;
       ptr->left=newnode;

      }
      else
      exit;

     }
     if(hc=='r')
     {
      if(ptr->right==NULL)
      {
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->data=value;
       newnode->left==NULL;
       newnode->right==NULL;
       ptr->right=newnode;

      }
      else
      exit;

     }
     



   }


  }
  


}

void main()
{  
   int ch=3;
   while(ch!=4)
   {printf("enter 1-3");
    scanf("%d",&ch);
    if(ch==1)
    root=create();
    printf("enter 1-3");
    scanf("%d",&ch);
    if(ch==2)
    insert();
    ch=4;

   } 
   printf("preorder traversal is:");
   preorder(root);
}