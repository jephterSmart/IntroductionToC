/* * * * * * * * * * * * * * * * * * * ** * * * * * * * * ** * * * * * * * * * * * * * * * * * * * * * * * **
 * This a gaming application, that is also known as Othello-Type Game.                                      *
 * What this game basically is all about is that it will display a grid for us to select our numbered input *
 * , then after selecting, it will check if the color between our selection is not our type and converts    *
 * to our color type. The game end after all the box have been selected. The person with the maximum number *
 * of selection is the winner. The game can be played between two users or a user and the computer, and both*
 * are implemented here. 
 * We will use this to test our functions.
 * 
 * @author Uzezi Jephter Oghenekaro
 */

 #include <stdio.h>
 #include <stdbool.h>
 #include <ctype.h>
 #include <string.h>
 #include <time.h>
 #include <signal.h>
 #include <stdlib.h>

#define SIZE 6
#define DELAY 1
const char compSymbol = '@';
const char playerSymbol = 'O';

 //Function prototypes or declaration section

void displayGrid(char board[][SIZE]);
void resetBoard(char board[][SIZE]);
int validMoves(char board[][SIZE], bool moves[][SIZE], char player);
int playerCounters(char board[][SIZE], char player);
void makeMove(char board[][SIZE], size_t row, size_t col, char player);
void computerMove(char board[][SIZE], bool moves[][SIZE], char player);
void delay(void);

void signalHandler(int);

int main(void){
    char board[SIZE][SIZE] = {0};                  // The board  
    bool moves[SIZE][SIZE] = { false };            // Valid moves  
    int no_of_moves = 0;                           // Count of moves  
    int invalid_moves = 0;                         // Invalid move count  
    char again = 0;                                // Replay choice input 
    char y = 0;                                      // Column letter  
    size_t x = 0;                                    // Row number 
    // Player indicator: true for player and false for computer  
    bool next_player = true;
    unsigned int compWin = 0; // This is the how many times computer won for a particular game run
    unsigned int playerWin = 0; // This is the how many times player won for a particular game run
    unsigned int draws = 0;

    // Prompt for how to play  
    printf("\nREVERSI\n\n");  
    printf("You can go first on the first game, then we will take turns.\n");  
    printf("   You will be white - (%c)\n   I will be black   - (%c).\n", playerSymbol, compSymbol);  
    printf("Select a square for your move by typing a digit for the row\n "                  
            "and a letter for the column with no spaces between.\n");  
    printf("\nGood luck!  Press Enter to start.\n");  
    scanf("%1c", &again );  
    fflush(stdin);                                 // Clear the buffer

    //Before starting game initialize event.
    //This signalHandler function will be invoked when Ctrl C is pressed.
    signal(SIGINT, signalHandler);


    // The main game loop  
    do{     
        resetBoard(board);                         // Board in initial state    
        // On even games the player starts, on odd games the computer starts    
        next_player = !next_player;    
        no_of_moves = 4;                             // Starts with four symbols    
        // The game play loop    
        do{      
            displayGrid(board);                            // Display the board      
            if(true == (next_player = !next_player))   // Flip next player      
                { //   It is the player's turn
                    if(validMoves(board, moves, playerSymbol)){ 
                        // Read player moves until a valid move is entered          
                        for(;;){            
                            printf("Please enter your move (row column - no space): ");            
                            scanf(" %zd%1c", &x, &y);  // Read input            
                            fflush(stdin);                         // Clear the buffer            
                            y = tolower(y) - 'a';                  // Convert to column index            
                            --x;                                   // Convert to row index            
                            if(y < 0 || y >= SIZE || x >= SIZE || !moves[x][y]){              
                                printf("Not a valid move, try again.\n");              
                                continue;            
                            }            
                            makeMove(board, x, y, playerSymbol);            
                            ++no_of_moves;                         // Increment move count
                            break;          
                        } // End infinite loop.        
                    }// End Valid Moves.
                    else                                       // No valid moves        
                        {
                        if(++invalid_moves < 2) {            
                            printf("\nYou have to pass, press return");            
                            scanf("%c", &again);            
                            fflush(stdin);                         // Clear the buffer          
                        }          
                        else  
                            printf("\nNeither of us can go, so the game is over.\n");        
                        }// End when No valid moves are made.    
                }//End when player is playerSymbol

            else { // It is the computer's turn 
                
                //pause computer for 2 secs
                delay();

                if(validMoves(board, moves, compSymbol))      // Check for valid moves        
                {          
                    invalid_moves = 0;                       // Reset invalid count          
                    computerMove(board, moves, compSymbol);          
                    ++no_of_moves;                           // Increment move count        
                }        
                else  // if  no valid move for computer.
                {          
                    if(++invalid_moves < 2)
                        printf("\nI have to pass, your go\n"); // No valid move          
                    else            
                        printf("\nNeither of us can go, so the game is over.\n");        
                }   
            }// End when it is the computer turn to play.    
        }while(no_of_moves < SIZE*SIZE && invalid_moves < 2); // End game when the board is full and 
        //the two player wrong moves.

        // Game is over    
        displayGrid(board);             // Show final board 
        unsigned int compCount =    playerCounters(board, compSymbol);
        unsigned int playerCount =  playerCounters(board, playerSymbol);
        
        
        //This is to increase the amount by which either of them won for a particular game.
        if(playerCount > compCount) ++playerWin;
        else if(playerCount < compCount) ++compWin;
        else ++draws;

        printf("The final score is:\n");    
        printf("Computer %d\n    User %d\n\n",   compCount , playerCount );
        if(compCount > playerCount || playerCount > compCount)
        printf("Therefore %s won with %d points\nCongratulations!",compCount > playerCount ? "Computer" : "User",
        compCount > playerCount ? compCount : playerCount);  
        else{
            printf("The game was a fair play, Draw!");
        }  
        printf("Do you want to play again (y/n): ");    
        scanf(" %1c", &again);       // Get y or n 
        fflush(stdin);                               // Clear the buffer  
    }while(tolower(again) == 'y');                 // Go again on y or Y 
    
    //print who won and say good bye.
    bool whoWins = playerWin > compWin;
    char plural = (whoWins ? (playerWin > 1 ? 's' : ' '): compWin > 1 ? 's': ' ');
    if(playerWin > compWin || compWin > playerWin){
        printf("\nFor This game sitting %s won %u game%c out of %u game%c", whoWins ? "User" : "Computer",
    whoWins ? playerWin : compWin ,plural, playerWin + compWin + draws,plural  );
        if(draws> 0) printf("\nOf which %u was draw%c",draws,draws > 1 ? 's': ' ');
    }
    else 
        printf("\nIn total the game was a draw, fair play! We will see next time!");
    printf("\n\nGoodbye\n"); 
    return 0;
}

void resetBoard(char board[][SIZE]){  
    // Blank all the board squares  
    for(size_t row = 0 ; row < SIZE ; ++row)    
        for(size_t col = 0; col < SIZE; ++col)      
        board[row][col] = ' ';  
        // Place the initial four symbols in the center  
    size_t mid = SIZE/2;  
    board[mid - 1][mid - 1] = board[mid][mid] = playerSymbol;  
    board[mid - 1][mid] = board[mid][mid - 1] = compSymbol;
}
// Function to display the board in its current state
void displayGrid(char board[][SIZE]){  // Display the column labels  
    char col_label = 'a';                          // Column label  
    printf("\n ");                                 // Start top line  
    for(size_t col = 0 ; col < SIZE ; ++col)    
        printf("   %c", (char)(col_label + col));    // Display the top line 
    printf("\n");                                  // End the top line

    // Display the rows...  
    for(size_t row = 0 ; row < SIZE ; ++row)  {    
        // Display the top line for the current row    
        printf("  +");    
            for(size_t col = 0 ; col < SIZE ; ++col)      
                printf("---+");    
        printf("\n%2zd|",row + 1);    // Display the counters in current row  
          for(size_t col = 0 ; col < SIZE; ++col)      
                printf(" %c |", board[row][col]);          // Display counters in row    
            printf("\n");  
    }  
    // Finally display the bottom line of the board  
    printf("  +");                                 // Start the bottom line  
    for(size_t col = 0 ; col < SIZE ; ++col)    
        printf("---+"); // Display the bottom line  
    printf("\n");                                  // End the bottom  line
}
    

// This function check to tell us if we have a valid move.
// for each blank square, search the squares around that square for an opponent’s symbol. 
//If you find an opponent’s symbol, 
//follow a line of opponent symbols (horizontal, vertical, or diagonal) until you find a player symbol.

int validMoves(char board[][SIZE],
    bool moves[][SIZE],//This array will store true for position where there is a valid move andfalse otherwise
    char player // The identity of the player.
    ){
        int rowdelta = 0;                     // Row increment around a square  
        int coldelta = 0;                     // Column increment around a square  
        int x = 0;                            // Row index when searching  
        int y = 0;                            // Column index when searching  
        int no_of_moves = 0;                  // Number of valid moves  
        
        // Set the opponent  
        char opponent = (player == playerSymbol) ? compSymbol : playerSymbol;

        // Initialize moves array to false  
        for(size_t row = 0 ; row < SIZE ; ++row)    
            for(size_t col = 0 ; col < SIZE ; ++col)      
                moves[row][col] = false;
        // Find squares for valid moves.  
        // A valid move must be on a blank square and must enclose  
        // at least one opponent square between two player squares  
        for(size_t row = 0 ; row < SIZE ; ++row)  {    
            for(size_t col = 0 ; col < SIZE ; ++col)    {      
                if(board[row][col] != ' ')        // If it's not a blank square...       
                    continue;                       // ...go to the next
                // Check all the squares around the blank square for opponents symbol      
                for(rowdelta = -1 ; rowdelta <= 1 ; ++rowdelta)      {        
                    for(coldelta = -1 ; coldelta <= 1 ; ++coldelta)        {   
                        // Don't check outside the array, or the current square          
                        if((row == 0 && rowdelta == -1) || row + rowdelta >= SIZE ||             
                            (col == 0 && coldelta == -1) || col + coldelta >= SIZE ||                                      
                            (rowdelta == 0 && coldelta == 0))            
                            continue;
                         // Now check the square          
                         if(board[row + rowdelta][col + coldelta] == opponent){            
                            // If we find the opponent, move in the delta direction            
                            // over opponent symbols searching for a player symbol            
                            x = row + rowdelta;         // Move to            
                            y = col + coldelta;         // opponent square

                            // Look for a player square in the delta direction            
                                for(;;){              
                                    x += rowdelta;            // Go to next square              
                                    y += coldelta;            // in delta direction              
                                    
                                    // If we move outside the array or it's a blank square, give up              
                                    if(x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] == ' ')                
                                        break;              
                                    //  If square has a player counter then we have a valid move              
                                    if(board[x][y] == player) {                
                                        moves[row][col] = true; // Mark as valid                
                                        no_of_moves++;          // Increase valid moves count                
                                        break;                  // Go check another square             
                                    }            
                                }
                         } // End opponent checking
                    }// End coldelta braces
                } // End rowdelta braces
            }// End col braces
        }// End row braces
        return no_of_moves;
            
}
// Count how many symbols for each player in the board, the highest is the winner.
int playerCounters(char board[][SIZE],char playerSymbol){
    int count = 0;  
    for(size_t row = 0 ; row < SIZE ; ++row)    
        for(size_t col = 0 ; col < SIZE ; ++col)      
            if(board[row][col] == playerSymbol) ++count;  
    return count;
}

//To make a move, we must place the appropriate symbol on the selected square 
//and flip any adjacent rows, columns, or diagonals of opponent symbols
// that are bounded at the opposite end by a player symbol.

void makeMove(char board[][SIZE], size_t row, size_t col, char player){
    int rowdelta = 0;                                       // Row increment  
    int coldelta = 0;                                       // Column increment  
    size_t x = 0;                                           // Row index for searching  
    size_t y = 0;                                           // Column index for searching  
    // Identify opponent  
    char opponent = (player == playerSymbol) ? compSymbol : playerSymbol;  
    board[row][col] = player;                               // Place the player counter  
    // Check all squares around this square for opponents symbol  
    for(rowdelta = -1 ; rowdelta <= 1 ; ++rowdelta)  {    
        for(coldelta = -1; coldelta <= 1; ++coldelta)    {      
            // Don't check off the board, or the current square      
            if((row == 0 && rowdelta == -1) || row + rowdelta >= SIZE ||        
                 (col == 0 && coldelta == -1) || col + coldelta >= SIZE ||                              
                 (rowdelta == 0 && coldelta == 0))        
                    continue;
            // Now check the square      
            if(board[row + rowdelta][col + coldelta] == opponent){ 
                // Found opponent so search in same direction for player counter        
                x = row + rowdelta;                               // Move to opponent        
                y = col + coldelta;                               // square        
                for(;;){          
                    x += rowdelta;                                  // Move to the          
                    y += coldelta;                                  // next square          
                    if(x >= SIZE || y >= SIZE || board[x][y] == ' ')// If blank square or off board...            
                    break;                                        // ...give up          
                    
                    // If we find the player counter, go backward from here  
                    // changing all the opponents counters to player
                     if(board[x][y] == player){ 
                                    
                         while(board[x -= rowdelta][y -= coldelta] == opponent) // Opponent?  
                         {
                             if(player == compSymbol) delay();
                             board[x][y] = player; // Yes, change it
                         }             
                                                            
                        break;                                                 // We are done          
                      }// Break out of indefinite loop        
                }// End indefinite loop      
            } // End if opponent is found   
        }// ENd coldelta braces
    }// End rowdelta braces.
}

// The function below(before we get to the computerMove) are helper function to the computerMove function

//This returns by how far the winner is playing.
int getScore(char board[][SIZE], char player){
      return playerCounters(board, player) -                      
        playerCounters(board, (player == playerSymbol) ? compSymbol : playerSymbol);
}
//This is another helper function.
//This help us to return the highest move score for a particular movement.
int bestMove(char board[][SIZE], bool moves[][SIZE], char player){
    char new_board[SIZE][SIZE] = {0};     // Local copy of board  
    int score = 0;                        // Best score  
    int new_score = 0;                    // Score for current move  
    // Check all valid moves to find the best  
    for(size_t row = 0 ; row < SIZE ; ++row)  {    
        for(size_t col = 0 ; col < SIZE ; ++col)    {      
            if(!moves[row][col])              // if not a valid move...        
                continue;                       // ...go to the next      
            // Copy the board      
            memcpy(new_board, board, sizeof(new_board));      
            // Make move on the board copy      
            makeMove(new_board, row, col, player);      // Get score for move      
            new_score = getScore(new_board, player);      
                if(score < new_score)             // If it's better...        
                    score = new_score;              // ...save it as best score.   
        }
    }  
    return score;                         // Return best score
}

//This is the computer move
void computerMove(char board[][SIZE], bool moves[][SIZE], char player){
    size_t best_row = 0;                  // Best row index  
    size_t best_col = 0;                  // Best column index  
    int new_score = 0;                    // Score for current move  
    int score = SIZE*SIZE;                // Minimum opponent score  
    char temp_board[SIZE][SIZE];          // Local copy of board  
    bool temp_moves[SIZE][SIZE];          // Local valid moves array 

    // Identify opponent  
    char opponent = (player == playerSymbol) ? compSymbol : playerSymbol;  // Go through all valid moves  
    for(size_t row = 0 ; row < SIZE ; ++row)  {    
        for(size_t col = 0 ; col < SIZE ; ++col)    {
              if(!moves[row][col])        
                continue;
              
              // First make a copy of the board array      
              memcpy(temp_board, board, SIZE*SIZE);      // Now make this move on the temporary board      
              makeMove(temp_board, row, col, player);      // find valid moves for the opponent after this move      
              validMoves(temp_board, temp_moves, opponent);      // Now find the score for the opponent's best move     
              new_score = bestMove(temp_board, temp_moves, opponent);      
              if(new_score < score)             // If it's worse...      
              {                                 // ...save this move       
               score = new_score;              // Record new lowest opponent score        
               best_row = row;                 // Record best move row        
               best_col = col;                 // and column      
              }
            }  
        }
        delay();
        makeMove(board, best_row, best_col, player);   // Make the best move
    
}

void delay(void){
    int waitStart = clock();
    for(;clock() - waitStart < DELAY * CLOCKS_PER_SEC; );
}

void signalHandler(int signalNumber){
    unsigned char response = 'n';
    printf("\nAre you sure you want to quit? (Press y or n): ");
    scanf(" %c",response);

    if(tolower(response) == 'y') exit(EXIT_SUCCESS);
    else signal(SIGINT, signalHandler );
}