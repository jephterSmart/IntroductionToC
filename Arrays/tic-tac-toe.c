/* This is another game application written in C.
* This game was most played when we were kids.
*/

#include <stdio.h>


int main(void){
   
    unsigned char player = 0; // this store who the current player is
    unsigned char winner = 0; // this store who won the game
    unsigned int choice = 0; // the box which the player choose.
    unsigned char row = 0;
    unsigned char column = 0;

    printf("\nIn this game you will be asked to select a number between"
    " 1 and 9 inclusively, \nwhich will specify the location in the box"
    "where you want to place your symbol.");
    char grid[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    printf("\n");
    printf("\t\t|---+---+---|");
    for(unsigned char i = 0; i < 3; i++){
         printf("\n\t\t| %c | %c | %c |",grid[i][0],grid[i][1],grid[i][2]);
         printf("\n\t\t|---+---+---|");
    }
    //This is the loop to start game

    for(unsigned char i = 0; i<9 && winner == 0; i++){
        player = (i % 2) + 1;
        
        
        // This allows the user to specify his number for his symbol once or more.

        do{
           
            printf("\nPlayer %d specify the box number ( 1-9 ) you want to place your %s Symbol: ",
            player, (player == 1 ) ? "X" : "O" );
           
            scanf("%u", &choice);
           
            row = --choice /3;
            column = choice % 3;
            // player = (i  % 2) + 1;
          //printf("\nplayer is %d", player);
        }while(choice<0 || choice > 8 || grid[row][column] > '9');
           
        
         grid[row][column] = (player == 1) ? 'X' : 'O';
         
        //This is done to check if there is a winner

        if((grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) //for checking main diagonal
         ||(grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2]) // for checking minor diagonal
         ){
             winner = player;
         }
         else{
             //check for horizontals and verticals
             for(unsigned char line = 0; line< 3; line++){
                 //check for horizontals
                 if((grid[line][0] == grid[line][1] && grid[line][0] == grid[line][2])){
                     winner = player;
                     break;
                 }
                 // check for verticals
                 if(grid[0][line] == grid[1][line] && grid[0][line] == grid[2][line]){
                     winner = player;
                     break;
                 }
             }
         }
          

         printf("\n");
         printf("\t\t|---+---+---|");
         for(unsigned char j = 0; j < 3; j++){
         printf("\n\t\t| %c | %c | %c |",grid[j][0],grid[j][1],grid[j][2]);
         printf("\n\t\t|---+---+---|");
         }
            
    }
    // code to determine if there is a winner.

    if(winner){
        printf("\nPlayer %d won the game. Congratulations!", winner);
    }
    else printf("\nYou guys are good! It was a draw");
   return 0;
}