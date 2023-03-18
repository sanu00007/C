#include<stdio.h>

void main()

{

 int n=10,f=-1,r=-1,ch=0,i;

 int v=0,p=0; 

 struct queue

 {

  int val[n];

  int prio[n];

  }q;

  

  while(ch!=4)

  {

   printf("\nMENU\n\n1.Enque\n2.Deque\n3.Display\n4.Exit");

   printf("\nEnter your choice\t");

   scanf("%d",&ch);


   

   if(ch==1)

   {

	if(r==n-1)

	{

		printf("QUEUE IS FULL\n");

	}

	

        else if(f==-1&&r==-1)

	{

                printf("\nEnter the value \t");

	        scanf("%d",&v);

	        printf("\nEnter the priority\t");

	        scanf("%d",&p);

	        f=r=0;

		q.val[r]=v;

		q.prio[r]=p;

	}

	else

	{

	    	printf("\nEnter the value \t");

	        scanf("%d",&v);

	        printf("\nEnter the priority\t");

	        scanf("%d",&p);

	

		r++;

		q.val[r]=v;

		q.prio[r]=p;

	}

    }

    if(ch==2)

    {

     	int temp,t;

	for(int i=f;i<r;i++)

	{

          for(int j=0;j<r;j++)

	    {

             if(q.prio[j]>q.prio[j+1])

		{

		 temp=q.prio[j];

		 q.prio[j]=q.prio[j+1];

		 q.prio[j+1]=temp;

                 t=q.val[j];

		 q.val[j]=q.val[j+1];

    		 q.val[j+1]=t;

		}

	    }

	 }

      	if(f==-1&&r==-1)

	{

	   printf("QUEUE IS EMPTY\n");

	}

	else if(f==r)

	{

          printf("\nThe Dequeued element is %d\n",q.val[f]);

	  f=r=-1;

	}

	else

	{

	  printf("\nThe Dequeued element is %d\n",q.val[f]);

	  f++;

		

	}	 

      }

      if(ch==3)

      {

       	if(f==-1&&r==-1)

	   printf("QUEUE IS EMPTY\n");

	else

	{ 

	   

	   printf("\nTHE CURRENT QUEUE IS:\n");

	   printf("Value\tPriority\n");

	   for(int i=f;i<r+1;i++)

	        printf("%d\t%d\n",q.val[i],q.prio[i]);

	}	

       }

       

       if(ch==4)

       break;

       

       if(ch>4)

        printf("\nInvalid choice\n");

   }

 }