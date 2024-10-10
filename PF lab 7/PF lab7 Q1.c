// Name:Masoom Khan Roll#24k-0001         LAB:7 Q:1
#include <stdio.h>
//main start
int main()
{
//assign array
int num[10]= {1,2,3,4,5,6,7,8,9};
//assign variable
int i,sum=0;
//for loop printing numbers
for ( i = 0; i < 10; i++)
{
   printf("Number[%d]=%d \n",i,num[i]);
}
//end for loop
//for loop to sum number
for ( i = 0; i < 10; i++)
{
   printf("%d \n",num[i]);
   sum+=num[i];
}
//end for loop
//output
   printf(" \nSum:%d",sum);
return 0;
}
//end main
