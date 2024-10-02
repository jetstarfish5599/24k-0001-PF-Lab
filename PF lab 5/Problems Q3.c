// Name:Masoom Khan Roll#24k0001 Problem Q3
#include <stdio.h>
//start main
int main() 
{
    char mes;
    char enc,dec;
    printf("Enter Message:");
    scanf("%c",&mes);
    //encryoption
    enc=mes>>1;
    printf("Encryption:%c \n",enc);
   //decryption
   dec=enc<<1;
      printf("Decryption:  %c",dec);
    return 0;
}
//end main