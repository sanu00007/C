#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL,*queue[100],*node_to_delete;

int front=-1;
int rear=-1;

struct node *create()
{
  int x;
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  
  newnode->left=NULL;
  newnode->right=NULL;

  printf("enter the data(-1 is NULL)");
  scanf("%d",&x);
  
  if(x==-1)
  {
    return NULL;

  }
  else
  {
   newnode->data=x;
   printf("for the left child of the node %d\n",newnode->data);
   newnode->left=create();
   printf("for the right child of the node %d\n",newnode->data);
   newnode->right=create();
   return newnode;

  }

}

void preorder(struct node *root)
{
   if(root==NULL)
   {
     return;

   }
  else
  {
   printf("%d\t",root->data);
   preorder(root->left);
   preorder(root->right);
 

}
}

void postorder(struct node *root)
{
 if(root==NULL)
   {
     return;

   }
  else
  {
   
   postorder(root->left);
   postorder(root->right);
   printf("%d\t",root->data);

}
}

void inorder(struct node *root)
{
if(root==NULL)
   {
     return;

   }
  else
  {
   
   inorder(root->left);
   printf("%d\t",root->data);
   inorder(root->right);
  

}


}

void enqueue(struct node*temp)
{
  if(front==-1&&rear==-1)
  {
    front=0;
    rear=0;
    queue[front]=temp;
  }
  else
  {
    queue[++rear]=temp;
  }

}
struct node *dequeue()
{
 if((front==-1&&rear==-1)||front>rear)
 {
    printf("queue is empty");
    return NULL;
 }
 else
 {
    return queue[front++];
 }

}

void insert()
{
  struct node *temp=root;
  front=rear=-1;
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter the data:\n");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;

if(root==NULL)
{
    root=newnode;
}
else
{
   while(front<=rear)
    {
      if(temp->left==NULL)
      {
        temp->left=newnode;
        return;
      }
      if(temp->right==NULL)
      {
        temp->right==NULL;
        return;
      }
      if(temp->left!=NULL)
      {
        enqueue(temp->left);
      }
     if(temp->right!=NULL)
     {
        enqueue(temp->right);
     }
     temp=dequeue();
    }

}


}

void deleteLastNode(struct node *last)
{
  struct node *temp=root;
  front=rear=-1;
  if(root!=NULL)
  { if(last==root)
    {root=NULL;
    return;
     }
  
   while(front<=rear)
    {
      if(temp->left==last)
      {
        temp->left=NULL;
        break;
      }
      if(temp->right==last)
      {
        temp->right==NULL;
        break;
      }
      if(temp->left!=NULL)
      {
        enqueue(temp->left);
      }
     if(temp->right!=NULL)
     {
        enqueue(temp->right);
     }
     temp=dequeue();
    }

  }
}


void deletion(int value)
{
  struct node *temp=root,*ptr=root,*node_to_delete=NULL;
  front=-1;
  rear=-1;
  if(root==NULL)
  {
    printf("\ntree is empty\n");
    return;
  }
  else
  {
  while(front<=rear)
    { temp=dequeue();
      if(temp->data==value)
      {
        node_to_delete=temp;
      
      }
     
      if(temp->left!=NULL)
      {
        enqueue(temp->left);
      }
     if(temp->right!=NULL)
     {
        enqueue(temp->right);
     }
     
    }

  }
  if(node_to_delete==temp)
  {
    deleteLastNode(temp);
  }
else if(node_to_delete==NULL)
{
  printf("element doesn't exist");
  
}
else
{
    node_to_delete->data=temp->data;
    deleteLastNode(temp);

}
}


void main()
{
  
  int ch,x;
  while(1)
  {
    printf("\n1.create\n2.insertion\n3.delete\n4.inorder\n.5.preorder\n6.postorder\n6.exit\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      root=create();
      break;
      case 2:
      insert();
      break;
      case 3:
      printf("enter the element to be deleted:");
      scanf("%d",&x);
      deletion(x);
      break;
      case 4:
      printf("inorder traversal:");
      inorder(root);
      break;
      case 5:
      printf("pre order traversal:");
      preorder(root);
      break;
      case 6:
      printf("post order traversal:");
      postorder(root);
      break;
      case 7:
      exit(0);
    }
  


  }


}









