// Name:Masoom Khan Roll#24k-0001         LAB:7 Q:1
#include <stdio.h>
//main start
int main()
{
//assign array
int num[10]= {1,2,3,4,5,6,7,8,9};
//assign variable
int i,rev=0;
//for loop printing numbers
for ( i = 0; i < 10; i++)
{
   printf("Number[%d]=%d \n",i,num[i]);
}
//end for loop

 printf("\n Reverse:",num[i]);

//for loop for reverse number order
for ( i = 8; i < 10 && i!=-1; i--)
{
   printf(" %d",num[i]);
   rev=num[i]/10;
}
//end for loop

return 0;
}
//end main
