#include <stdio.h>

int main (void){
    char chr[] = "i love this.";
    char ch = 'q';
    int c = 10;
    int number = 0;                 // A variable of type int initialized to 0 
    char can = 'a'; 
    int *pnumber = NULL;            // A pointer that can point to type 
    number = 10;
    int *const p = &number; 

    printf("the address of p is %p\n", &p);
    printf("The address of array chr is %p (chr)\n", chr);             // Output the address 
    printf("Does the variable chr has a different address %p (&chr)", &chr); 
    printf("ch's address: %p\n", &ch);
    printf("c's address: %p\n", &c);                 // Output the address  
    printf("number's address: %p\n", &number);               // Output the address  
    printf("number's value: %d\n\n", number);                // Output the value  
    printf("can's address : %p\n",&can);
    pnumber = &number;              // Store the address of number in pnumber  
    printf("pnumber's address: %p\n", (void*)&pnumber);      // Output the address  
    printf("pnumber's size: %zd bytes\n", sizeof(pnumber));  // Output the size  
    printf("pnumber's value: %p\n", (void*)pnumber);                // Output the value (an address)  
    printf("value pointed to: %d\n", *pnumber);              // Value at the address  
    
    return 0;
}