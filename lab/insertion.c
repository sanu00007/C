#include<stdio.h>
void main()
{
 int i,j,n,temp,a[10];
 printf("enter the number of elements");
 scanf("%d",&n);
 printf("elements in array is:");
 for(i=0;i<n;i++)
 {scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
  {
    temp=a[i];
    j=i-1;
     while(j>=0&&a[j]>temp)
      {
       a[j+1]=a[j];
       j--;
      
      }
     a[j+1]=temp;
  }
printf("sorted elements are:");
for(i=0;i<n;i++)
 { printf("%d\t",a[i]);
 }


}
