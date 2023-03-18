#include<stdio.h>
struct poly
{int coef;
 int exp;
}p[100];
void main()
{
 int i,j,k,m,n;
 printf("the number of elements in first polynomial:");
 scanf("%d",&m);
 printf("exponentials and coeficiant in ascending order is\n");
 for(i=0;i<m;i++)
  { printf("coefficiant\texponential\n");
    scanf("%d",&p[i].coef);
    
    scanf("%d",&p[i].exp);
  }
   printf("the number of elements in second polynomial:");
 scanf("%d",&n);
 printf("exponentials and coefficient in ascending order is\n");
 for(i=m;i<m+n;i++)
  { printf("coefficiant\texponential\n");
    scanf("%d",&p[i].coef);
   
    scanf("%d",&p[i].exp);
  
  }
 i=0;
 k=m+n;
 j=m;
 while(i<m&&j<m+n)
   {
    if(p[i].exp<p[j].exp)
      {
       p[k].exp=p[i].exp;
       p[k].coef=p[i].coef;
       k++;
       i++;
      }
     else if(p[j].exp<p[i].exp)
       {
         p[k].exp=p[j].exp;
         p[k].coef=p[j].coef;
         k++;
         j++;
       
       }
     else
     {
       p[k].exp=p[j].exp;
       p[k].coef=p[i].coef+p[j].coef;
       k++;
       i++;
       j++;
     }
  
   }
   while(i<m)

      {
       p[k].exp=p[i].exp;
       p[k].coef=p[i].coef;
       k++;
       i++;
      }
   
   while(j<m+n)
   
    { p[k].exp=p[j].exp;
         p[k].coef=p[j].coef;
         k++;
         j++;
   }
   
 
   printf("addition of polynomial is:");
   for(i=k-1;i>=m+n;i--)
    {
     printf("%dX^(%d)+",p[i].coef,p[i].exp);
    }
    
  
 
 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
