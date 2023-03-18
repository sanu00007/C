#include<stdio.h>
#include<ctype.h>
struct Employee
{
  char name[10];
  int age;
  float salary;
  char address[100];

}E1,E2;

int main()
{
  struct Employee E1={"sanin",20,10000000,"nakkottil"};
  struct Employee E2={"aparna",18,2500000,"kottayam"};
  printf("NAME:%s(AGE:%d(SALARY:%f(ADDRESS:%s)))",E1.name,E1.age,E1.salary,E1.address);
  printf("\n");
 printf("NAME:%s(AGE:%d(SALARY:%f(ADDRESS:%s)))",E2.name,E2.age,E2.salary,E2.address);
 return 0;
}