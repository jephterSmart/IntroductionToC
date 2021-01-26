/* This is a game application that allow us to play the Simon game - 
* this game test our cognitive power by displaying number for us and
* and then after a delay wipe the screen and ask us to enter the number
* that was entered.
*/

#include <stdio.h>
#include <stdbool.h> // this enables us to use true and false and bool datatype
#include <stdlib.h> // enable us to generate random numbers
#include <ctype.h> // this function contains the toUpperCase function
#include <time.h> // contains the clock() and time function and also hv some constant

int main(void){
    char anotherGame = 'Y';
    clock_t startTime = 0;
    time_t seed = 0;
    const unsigned char DELAY = 5; // This is number of seconds our display is going to last
    time_t waitStart = 0;// use to track delays
    unsigned int tries = 0; // This should be long since we can really have a good player.
    unsigned char number = 0; // tempory variable for reading our input from the input buffer
    const unsigned char numOfTriesPerSeqLength  = 3;
    unsigned int seqLength = 2;
    bool correct = true; // use to ensure that our input match with what was displayed.
    
    // This 3 variable are used calculating the score of player after he failed.

    unsigned int totalDigitCount = 0;
    unsigned int gameTime = 0;
    unsigned int score = 0;



    printf("To play Simple Simon, watch the screen for a sequence of digits.\n"
    "Watch carefully, as the digits are only displayed for %u second%s ", DELAY, DELAY > 1 ? "s!" :"!");
    printf("\nThe computer will remove them, and then prompt you to enter the same sequence.\n"
    "When you do, you must put spaces between the digits.");
    printf("\nGood Luck!\nPress Enter to play\n");  
    scanf("%c", &anotherGame);
    
    do{
        //This section initializes the game, so that everything work appropriately.

        seqLength = 2;
        number = 0;
        startTime = clock();
        waitStart = 0;
        tries =0;
        correct = true;
        while(correct){
            tries++;
            srand(time(&seed));
            //loop for displaying our digit to the output

            for(unsigned int i =1; i <= seqLength; i++){
                printf("%d ", rand() % 10);
            }
            // code to wait for one second

            waitStart = clock();
            for(;clock() - waitStart < DELAY * CLOCKS_PER_SEC; );

            // after waiting, then clean the screen.
            printf("\r"); // return cursor to be beginning of line
            for(unsigned int i =1; i <= seqLength; i++){
                printf("  "); // overwrite original sequence with empty space.
            }
            if(tries == 1)
            printf("Enter the digits you just saw and don't forget to add space between digits :\n");
            else printf("\r");
            //read the input we just type from the keyboard buffer,
            // first we need to seed our random function, so that the rand function can start
            // with the same sequence as before. 
            
            srand(seed);
            for(unsigned int i =1; i <= seqLength; i++){
                scanf("%u", &number);
                
                if(number != rand() % 10 ){
                    correct = false;
                    break;
                }   

            }
            if(correct && ((tries % numOfTriesPerSeqLength) == 0))
                seqLength++;
            printf("%s\n", correct ? "Correct!":"Wrong!");

        }
        // This section is used for calculating score for player.
         totalDigitCount = 0;
        
         score = 10 * (seqLength - 
                ((tries % numOfTriesPerSeqLength ) == 1));// we award 10pts for every seqLength
         totalDigitCount = seqLength * //This return the number of digits entered for this particular sequence.
          (((tries % numOfTriesPerSeqLength ) == 0) ? 3 : tries % numOfTriesPerSeqLength ); 
          if(seqLength > 2){
              totalDigitCount += numOfTriesPerSeqLength * (seqLength * (seqLength - 1) / 2 - 1);
          }
           gameTime = (clock() - startTime)/CLOCKS_PER_SEC - tries*DELAY;

           if(totalDigitCount > gameTime)     
            score += 10*(gameTime - totalDigitCount);         // Add points for speed    
           printf("\n\nGame time was %u seconds. Your score is %u", gameTime, score); 

            fflush(stdin);  // do these so that answer the next question will be answer well.      

        //If players fail, then ask would you like to play again?
        printf("\nwould you like to play again (y/n): ");
        scanf("%c",&anotherGame);
        fflush(stdin);
       
    }while(toupper(anotherGame) == 'Y');
    return 0;
}