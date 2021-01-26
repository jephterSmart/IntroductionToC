#include <ctype.h>
#include <stdio.h>


double strtod( char arr[], size_t length,char **ptrToEndOfNumber){
    
    double result = 0;
    unsigned char tempCh= 0;
    unsigned long long multiplier = 1ULL; // This is used to keep the amount of decimal places
    size_t ch;
    for( ch= 0; ch < length; ch++){
        if(isdigit(arr[ch]) || arr[ch] == '.' ){
            // 48 is the ascii character for zero
            if(arr[ch] != '.'){
                printf("\n The digit is %c", arr[ch]);
            tempCh = arr[ch] - 48; // This is done to convert ASCII to normal number;
             printf("\n The digit after conversion is %d", tempCh);
            result =result * 10 + tempCh; 
            }
            
      
             //if a dot is encountered a decimal is added.  
         if(ch > 0 && arr[ch] == '.'){
               tempCh = ch;
               multiplier = 10ULL;
            }
            if(tempCh < ch){
                multiplier *= 10ULL;
            }
        }
       
        else break;
    }
    result = result / (double)multiplier; // add the decimal numbers

    *ptrToEndOfNumber = &arr[ch];
    return result;
}
int main(void){
    char arr[] = "99.3 is a solid number";
    char *remainingString = NULL;
    double num = strtod(arr,sizeof(arr),&remainingString);
    printf("\n Lets check if our function worked well");
    printf("\n\n The number that is part of the string is :%f"
    "\n and the remaining string in the String arr is : %s", num,remainingString);
    return 0;
}