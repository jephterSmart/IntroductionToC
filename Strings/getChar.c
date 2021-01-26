#include <stdio.h>
int main( void ){
     char c; /* variable to hold character input by user */
     char sentence[ 80 ]; /* create char array */
     int i = 0; /* initialize counter i */
     puts( "Enter a line of text:" );/* prompt user to enter line of text */
     while ( ( c = getchar() ) != '\n') {   
             sentence[ i++ ] = c;             
                 }
    sentence[ i ] = '\0'; /* terminate string */
     /* use puts to display sentence */
    puts( "\nThe line entered was:" );
    puts( sentence );
    // scanf(" %s", sentence);
    // printf("%d",sentence[5]);
    puts("type in something");
    c = getchar();
    printf("%c",c);
     return 0; /* indicates successful termination */
} /* end main */