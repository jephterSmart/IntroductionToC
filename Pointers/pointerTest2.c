#include <stdio.h>
int main(void){  
    char board[3][3] = {
           {'1','2','3'},
           {'4','5','6'}, 
           {'7','8','9'}                 
               }; 
    char *look = "Hello There" ;
    char look2[] = "hello there";
    int love[] = {12,13,14,15,16};
    *(love + 1)= 18;

    // This reads what is the size in bytes of the value stored in address represented by love? 
    printf("size of int is %zd\n", sizeof(*look));


    printf("the element at index 1 is  %zd\n", *love);
    printf("value of board[0][0] : %c\n", board[0][0]);  
    printf("value of *board[0]   : %c\n", *board[0]);  
    printf("value of **board     : %c\n", **board); 
    printf("does this avaluate to 5 : %c", *(*(board + 1) + 1));
    printf("\nthe size of look is %zd", sizeof(*look));
    printf("\nthe size of look2 is %zd", sizeof(look2));
    printf("\nthe size of long is %zd", sizeof(long));
    printf("\nthe character at 2 using index notation on pointer is %c\n", look[10]);

    // let us test if a variable is const can it be changed through a non-constant pointer that point
    // to a non-constant data

    const int five = 5;
    // int *pfive = &five; // This work but throws us a warning at compile time
    // printf("The value of five is %d", five);
    // *pfive = 67; 
    // printf("Now the value of five is %d", five); 

    //but if pointer point to constant data, as in this

    const int *ptrfive = &five; // This does not throw any error at compile time
    printf("The value of five is %d", five);

    //Lets look at another scenerio of arrays and pointer

    int arr[10] = {0};
    int arr2[15] = {0};
    int *ptrArr = arr;
    ptrArr = arr2; // we can always change the address of a pointer to different 
    //address of pointer to that type(int in this case), irrespective of number of elements in the array.

    //The size of size_t type is
    printf("the size of size_t is %zu", sizeof(size_t));
    printf("\nthe character 1 is %d", '1');
 return 0;
 }