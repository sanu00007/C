#include<stdio.h>
#include<ctype.h>
int i,j;
struct sparse
{
  int row,col;
  int a[100][100];
  int tuple[100][3];
};

void readarray(struct sparse *sp)
{
 printf("enter the number of rows and column:");
 scanf("%d\t%d",&sp->row,&sp->col);
 for(i=0;i<sp->row;i++)
   {
     for(j=0;j<sp->col;j++)
     {
       scanf("%d",&sp->a[i][j]);
         }
    
   }

}

void displayarray( struct sparse *sp)
{
  printf("the matrix is: \n");
  for(i=0;i<sp->row;i++)
   {
     for(j=0;j<sp->col;j++)
     {
       printf("%d ",sp->a[i][j]);
         }
     printf("\n");
   }
}

void maketuple(struct sparse *sp)
{
  sp->tuple[0][0]=sp->row;
  sp->tuple[0][1]=sp->col;
  int k=0;
   for( i=0;i<sp->row;i++)
   {
     for( j=0;j<sp->col;j++)
     {
        if(sp->a[i][j]!=0)
        {k++;
         sp->tuple[k][0]=i;
         sp->tuple[k][1]=j;
         sp->tuple[k][2]=sp->a[i][j];
         
        }
      
     }
      sp->tuple[0][2]=k;
   }

}
void displaytuple(struct sparse *sp)
{
  for(i=0;i<sp->tuple[0][2]+1;i++)
  {
    for(j=0;j<3;j++)
    {
        printf("%d ",sp->tuple[i][j]);
    }
    printf("\n");
  }

}

void addtuple(struct sparse *sp1,struct sparse *sp2,struct sparse *sp3)
{
 if(sp1->row!=sp2->row || sp1->col!=sp2->col)
 {
  printf("addition not possible");
  return;
 }
int i=1,j=1,k=1;
while(i<=sp1->tuple[0][2]||j<=sp2->tuple[0][2])
 {
   if(i>sp1->tuple[0][2])
   {
    sp3->tuple[k][0]=sp2->tuple[j][0];
    sp3->tuple[k][1]=sp2->tuple[j][1];
    sp3->tuple[k][2]=sp2->tuple[j][2];
    k++;
    j++;
   }
   else if(j>sp2->tuple[0][2])
    {
    sp3->tuple[k][0]=sp1->tuple[i][0];
    sp3->tuple[k][1]=sp1->tuple[i][1];
    sp3->tuple[k][2]=sp1->tuple[i][2];
    k++;
    i++;
   }
   else if(sp1->tuple[i][0]==sp2->tuple[j][0]) 
     {
       
        
          if(sp1->tuple[i][1]==sp2->tuple[j][1])
            {
                sp3->tuple[k][0]=sp2->tuple[j][0];
                sp3->tuple[k][1]=sp2->tuple[j][1];
                sp3->tuple[k][2]=sp2->tuple[j][2]+sp1->tuple[i][2];
                k++;
                j++;
                i++;
            }
           else if(sp1->tuple[i][1]<sp2->tuple[j][1])
             {   
            sp3->tuple[k][0]=sp1->tuple[i][0];
            sp3->tuple[k][1]=sp1->tuple[i][1];
            sp3->tuple[k][2]=sp1->tuple[i][2];
            k++;
            i++;

             }
            else
            {
               sp3->tuple[k][0]=sp2->tuple[j][0];
               sp3->tuple[k][1]=sp2->tuple[j][1];
               sp3->tuple[k][2]=sp2->tuple[j][2];
               k++;
               j++;

            }
         }
          
        else if (sp1->tuple[i][0]<sp2->tuple[j][0])
          { 
            sp3->tuple[k][0]=sp1->tuple[i][0];
            sp3->tuple[k][1]=sp1->tuple[i][1];
            sp3->tuple[k][2]=sp1->tuple[i][2];
            k++;
            i++;


          }  

        else
         {
           sp3->tuple[k][0]=sp2->tuple[j][0];
               sp3->tuple[k][1]=sp2->tuple[j][1];
               sp3->tuple[k][2]=sp2->tuple[j][2];
               k++;
               j++;
         }
       }
    

    sp3->tuple[0][0]=sp1->tuple[0][0];
    sp3->tuple[0][1]=sp1->tuple[0][1];
    sp3->tuple[0][2]=k-1;

   }


  
 





void main()
{ struct sparse sp1,sp2,sp3;
  printf("read matrix 1\n");
  readarray(&sp1);
  printf("display matrix 1\n");
  displayarray(&sp1);
  printf("tuple form of 1\n");
  maketuple(&sp1);
  displaytuple(&sp1);
  printf("read matrix 2\n");
  readarray(&sp2);
  printf("display matrix 2\n");
  displayarray(&sp2);
  printf("tuple form of 2\n");
  maketuple(&sp2);
  displaytuple(&sp2);
  printf("matrix addition is \n");
  addtuple(&sp1,&sp2,&sp3);
  displaytuple(&sp3);
}