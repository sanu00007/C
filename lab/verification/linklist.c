#include<stdlib.h>
#include <stdio.h>
     

void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
 
 
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\n                MENU                             \n");
                printf("\n 1.Display    ");
                printf("\n 2.Insert at the beginning    ");
                printf("\n 3.Insert at the end  ");
                printf("\n 4.Insert at specified position       ");
                printf("\n 5.Delete from beginning      ");
                printf("\n 6.Delete from the end        ");
                printf("\n 7.Delete from specified position     ");
                printf("\n 8.Exit       ");
                printf("\n--------------------------------------");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        
                        case 1:
                                        display();
                                        break;
                        case 2: 
                                        insert_begin();
                                        display();
                                        break;
                        case 3:
                                        insert_end();
                                        display();
                                        break;
                        case 4:
                                        insert_pos();
                                        display();
                                        break;
                        case 5:
                                        delete_begin();
                                        display();
                                        break;
                        case 6:
                                        delete_end();
                                        display();
                                        break;
                        case 7:
                                        delete_pos();
                                        display();
                                        break;
                        
                        case 8:         
                                        display();  
                                        exit(0);
                                        break;
                             
                        default:
                                        printf(" Wrong Choice:");
                                        break;
                }
        }
        return 0;
}

void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=head;
                printf("The List elements are:");
                while(ptr->next!=NULL)
                {
                        printf("%d--->",ptr->data );
                        ptr=ptr->next ;
                }
                printf("%d--->NULL",ptr->data);
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the position for the new node to be inserted:");
        scanf("%d",&pos);
        printf("Enter the data value of the node:");
        scanf("%d",&temp->data) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=head;
                head=temp;
        }
        else
        {
                for(i=0,ptr=head;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("Position not found:");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("List is Empty:");
                return;
        }
        else
        {
                ptr=head;
                head=head->next ;
                printf("The deleted element is :%d\n",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("List is Empty:");
                exit(0);
        }
        else if(head->next ==NULL)
        {
                ptr=head;
                head=NULL;
                printf("The deleted element is:%d\n",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The deleted element is:%d\n",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("The List is Empty:");
                exit(0);
        }
        else
        {
                printf("Enter the position of the node to be deleted:");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        printf("The deleted element is:%d\n",ptr->data  );
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("Position not Found:");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("The deleted element is:%d\n",ptr->data );
                        free(ptr);
                }
        }
}


