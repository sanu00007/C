#include<stdio.h>
#include<stdlib.h>

struct poly
{
  int exp;
  int coef;

}p[100];

void main()
{
  int i,j,n1,n2;
  printf("number of terms in polynomial 1");
  scanf("%d",&n1);
  printf("number of terms in polynomial 2");
  scanf("%d",&n2);
  for(i=0;i<n1;i++)
  {
   scanf("%d%d",&p[i].exp,&p[i].coef);

  }


}