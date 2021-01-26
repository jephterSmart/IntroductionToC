#include <stdio.h>
#define __STDC_WANT_LIB_EXT1__ 1     // Make optional versions of functions available
#include <string.h>                  // Header for string functions

int main(void){
#if defined __STDC_LIB_EXT1__ 
 printf("Optional functions are defined.\n");
#else  
printf("Optional functions are not defined.\n");
#endif 
    char see = 'k';
    char arr[16] = "i love this.";
     
    printf("\nThe address of arr is %p", &arr[15]);
    printf("\nWhile the address of see is %p",&see);
     arr[12] = ' ';
     arr[13] = 'd';
     arr[14] = 'o';
     arr[15] = ' '; 
     arr[16] = 'a';
     
     printf("The string:\n    \"%s\"\n contains %zu characters.\n",                                     
     arr, strnlen(arr, sizeof(arr)));
     printf("\nthe string length using strlen function is: %zu",strlen(arr));
     printf("\n what is see now? %c",see);
     char source[] = "Only the mediocre are always at their best.";
     char destination[50];
     strncpy(destination, source,18);
     destination[18] = '\0';
     printf("destination is \"%s\" ", destination) ;
      
return 0;
}