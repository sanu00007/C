#include<stdio.h>
int main()
{int i,j,temp,n;
 int left,right,mid;
 int flag=0,key,a[10];
 printf("enter the number of elements\n");
 scanf("%d",&n);
 left=0;right=n-1;mid=0;
 printf("elements in the array \n");
 for(i=0;i<n;i++)
 {scanf("%d",&a[i]);
 }
 for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {if(a[j]>a[j+1])
      { temp=a[j];
      a[j]=a[j+1];
      a[j+1]=temp; 
      }
     }
 }
 printf("enter the element which is needed to find\n");
 scanf("%d",&key);
 while(left<=right)
  {
   mid=(left+right)/2;
   if(a[mid]==key)
    {flag=1;
     break;}
    else if(a[mid]<key)
     {left=mid+1;
      } 
    else
     {right=mid-1;
     }
    }
  
 if(flag==1)
  {
    printf("the element is found at a position %d",mid+1);
   }
 else
  {printf("element is not found");
   }
return 0;
}



