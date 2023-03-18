#include <stdio.h>

 

struct sparse

{   int row,col;

    int a[10][10];

    int tuple[100][3];

};

 

void readarray(struct sparse *sp,int i)

{printf("Enter no of rows and columns of matrix %d\n",i);

scanf("%d%d",&sp->row,&sp->col);

printf("Enter the elements\n");

for (int i=0;i<sp->row;i++)

for (int j=0;j<sp->col;j++)

scanf("%d",&sp->a[i][j]);

}

 

void disparray(struct sparse *sp,int i)

{printf("The matrix %d\n",i);

  for (int i=0;i<sp->row;i++)

 { for (int j=0;j<sp->col;j++)

    {printf("%d  ",sp->a[i][j]);}

  printf("\n");

  }

}

 

void disptuple(struct sparse *sp,int i)

{printf("The tuple representation of sparse matrix %d\n",i);

  for (int i=0;i<=sp->tuple[0][2];i++)

  { for (int j=0;j<3;j++)

    {printf("%d  ",sp->tuple[i][j]);}

  printf("\n");

  }

}

 

void maketuple(struct sparse *sp)

{int k=0;

sp->tuple[0][0]=sp->row;

sp->tuple[0][1]=sp->col;

for (int i=0;i<sp->row;i++)

for (int j=0;j<sp->col;j++)

{if(sp->a[i][j]!=0)

  {k++;

   sp->tuple[k][0]=i;

   sp->tuple[k][1]=j;

   sp->tuple[k][2]=sp->a[i][j];

  }

  sp->tuple[0][2]=k;

}

}

 

void transtuple(struct sparse *sp1,struct sparse *sp2,int a)

{

if (sp1->tuple[0][2]==0)

printf("Matrix %d cannot be transposed",a);

else

{

sp2->tuple[0][1]=sp1->tuple[0][0];

sp2->tuple[0][0]=sp1->tuple[0][1];

sp2->tuple[0][2]=sp1->tuple[0][2];

int k=1;

for(int i=0;i<sp1->tuple[0][1];i++)

for(int j=1;j<=sp1->tuple[0][2];j++)

if(i==sp1->tuple[j][1])

{

sp2->tuple[k][0]=sp1->tuple[j][1];

sp2->tuple[k][1]=sp1->tuple[j][0];

sp2->tuple[k][2]=sp1->tuple[j][2];

k++;

}

printf("Transpose is\n");

disptuple(sp2,a);

}}

 

void addtuple(struct sparse *sp1,struct sparse *sp2,struct sparse *sp3,int a,int b)

{

int i=1,j=1,k=1;

if(sp1->tuple[0][0]!=sp2->tuple[0][0]||sp1->tuple[0][1]!=sp2->tuple[0][1])

printf("Matrix %d and Matrix %d cannot be added\n",a,b);

else

{

while (i<=sp1->tuple[0][2]||j<=sp2->tuple[0][2])

{

if(i>sp1->tuple[0][2])

{

sp3->tuple[k][0]=sp2->tuple[j][0];

sp3->tuple[k][1]=sp2->tuple[j][1];

sp3->tuple[k][2]=sp2->tuple[j][2];

k++;j++;

}

else if(j>sp2->tuple[0][2])

{

sp3->tuple[k][0]=sp1->tuple[i][0];

sp3->tuple[k][1]=sp1->tuple[i][1];

sp3->tuple[k][2]=sp1->tuple[i][2];

k++;i++;

}

 

else if(sp1->tuple[i][0]==sp2->tuple[j][0])

{

if(sp1->tuple[i][1]==sp2->tuple[j][1])

{

sp3->tuple[k][0]=sp2->tuple[j][0];

sp3->tuple[k][1]=sp2->tuple[j][1];

sp3->tuple[k][2]=sp2->tuple[j][2]+sp1->tuple[i][2];

k++;i++;j++;

}

else if(sp1->tuple[i][1]<sp2->tuple[j][1])

{

sp3->tuple[k][0]=sp1->tuple[i][0];

sp3->tuple[k][1]=sp1->tuple[i][1];

sp3->tuple[k][2]=sp1->tuple[i][2];

k++;i++;

}

else

{

sp3->tuple[k][0]=sp2->tuple[j][0];

sp3->tuple[k][1]=sp2->tuple[j][1];

sp3->tuple[k][2]=sp2->tuple[j][2];

k++;j++;

}

}

else if(sp1->tuple[i][0]<sp2->tuple[j][0])

{

sp3->tuple[k][0]=sp1->tuple[i][0];

sp3->tuple[k][1]=sp1->tuple[i][1];

sp3->tuple[k][2]=sp1->tuple[i][2];

k++;i++;

}

else

{

sp3->tuple[k][0]=sp2->tuple[j][0];

sp3->tuple[k][1]=sp2->tuple[j][1];

sp3->tuple[k][2]=sp2->tuple[j][2];

k++;j++;

}

}

sp3->tuple[0][0]=sp1->tuple[0][0];

sp3->tuple[0][1]=sp1->tuple[0][1];

sp3->tuple[0][2]=k-1;

printf("Sum of Matrices %d and %d\n",a,b);

disptuple(sp3,3);

}

}

 

void main()

{

struct sparse sp1,sp2,trans1,trans2,sumsp3;

readarray(&sp1,1);

readarray(&sp2,2);

maketuple(&sp1);

maketuple(&sp2);

disptuple(&sp1,1);

disptuple(&sp2,2);

transtuple(&sp1,&trans1,1);

transtuple(&sp2,&trans2,2);

addtuple(&sp1,&sp2,&sumsp3,1,2);

}
