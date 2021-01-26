/*
 * This string test is use to test the different memory string functions that consider every block of memory
 * as a character array.
 * 
 * @author Uzezi Jephter Oghenekaro
 */

#include <stdio.h>
#include <string.h>

int main(void){
    unsigned int num = 0x35323130;
    unsigned int num2 = 0x45535254;
    unsigned char letSee[5] = {0};

    memcpy(letSee,&num,sizeof(int)); // THis copy 4 byte into letSee
    letSee[4] = '\0';
    for(int j = 0; j<strlen(letSee) ; j++){
        printf("\nByte%d value is: %u",j+1, letSee[j]);
        printf("\nThen if it converts to character is: %c\n",letSee[j]);
    }
     memcpy(letSee,&num2,sizeof(int)); // THis copy 4 byte into letSee
    letSee[4] = '\0';
    for(int j = 0; j<strlen(letSee) ; j++){
        printf("\nByte%d value is: %u",j+1, letSee[j]);
        printf("\nThen if it converts to character is: %c\n",letSee[j]);
    }
    char *restByte = memchr(letSee,'S',sizeof(int));
    printf("\nWhere 'S' is found is : %s\n",restByte);
    int numValueRead = scanf("%s",restByte);
    printf("\n\nNow restByte is %s\nAnd number of value read is: %d",restByte, numValueRead);
    printf("\n why is it not working");
    // memset(letSee,97,sizeof(int));
    // letSee[4] = '\0';
    // for(int j = 0; j<strlen(letSee) ; j++){
    //     printf("\nByte%d value is: %u",j+1, letSee[j]);
    //     printf("\nThen if it converts to character is: %c\n",letSee[j]);
    // }
    
    return 0;
}