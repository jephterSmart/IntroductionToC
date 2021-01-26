/* This is progame that allows one to guess a particular number
* the program selected
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
   // srand(time(NULL));
    int chosen = rand();
    int count = 3;
    int guess =0;
    printf("This program enable you guess a number betwen 1 and 20 inclusively,"
    "\nthat matches the program selected number %d", chosen);
    for(short iterator = 0; iterator < count; ++iterator){
        printf("\nYou have %d tr%s left", count-iterator, count==1 ? "y":"ies");
        printf("\nenter your guess: ");
        scanf(" %d", &guess);
        if(guess == chosen){
            printf("Congratulations! You guessed the number right %d");

            return 0;
        }
        else if(guess < 1 || guess > 20){
            printf(" i said the number is between 1 and 20 inclusively");
        }
        else {
            printf(" your guess, %d is %s than the chosen number", guess, guess> chosen ? "greater" : "lesser");
        }

    }
    printf("\n Thanks for playing, the lucky number is %d", chosen);
    return 0;
}