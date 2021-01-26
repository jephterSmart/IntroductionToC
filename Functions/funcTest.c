#include <stdio.h>

//Lets declare some function prototypes

int sum(int a, int b);
int product(int a, int);
int difference(int, int);

int main(void){

    //first lets define our  function pointers
    int (*ptrToFunc)(int,int); 

    // other variables
    int a = 10, b=5,
    result = 0;
    ptrToFunc = sum;
    result = ptrToFunc(a, b);                // Call sum() through pointer 
    printf("pfun = sum             result = %2d\n", result);

     ptrToFunc = product;                     // Points to function product()  
     result = ptrToFunc(a, b);                // Call product() through pointer 
     printf("pfun = product         result = %2d\n", result); 
     
     ptrToFunc = difference;                  // Points to function difference()  
     result = ptrToFunc(a, b);                // Call difference() through pointer  
     printf("pfun = difference      result = %2d\n", result);  
     return 0;

}

int sum(int x, int y){  return x + y;}
int product(int x, int y){  return x * y;}
int difference(int x, int y){  return x - y;}