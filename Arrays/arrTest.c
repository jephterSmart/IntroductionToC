#include <stdio.h>

int main(void){
    int numbers[5];
    printf("%zu",sizeof(numbers[0]));
    #ifdef   __STDC_NO_VLA__ // This is use to test if variable or dynamic array are supported by this compiler
     printf("Variable length arrays are not supported.\n"); 
     exit(1);
     #endif
     size_t size = 0;
     printf("enter the size of the array:");
     scanf("%zu",&size);
     int num[size];
     for(unsigned int j = 0; j< size; j++){
         printf("\nEnter the %u value: ",j+1);
         scanf("%d",&num[j]);
     }
     printf("\nThese are the value you entered: ");
     for(unsigned int j = 0; j< size; j++){
         printf("\nYour %u value is %d",j+1, num[j]);
     }
     return 0;
}