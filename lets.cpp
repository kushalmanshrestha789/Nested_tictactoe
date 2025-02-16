#include<iostream>
#include<vector>
#include<ctime>
#include <cstdlib>
#include <tuple>
#include <set>
#include<string>
#include <limits> 



void drawBoard(char *N);
void playerMove(char *N, char player,char computer);
void player1Move(char *N,char player1);
void player2Move(char *N,char player2);
void Cheif_Board(char *spaces,char *N,char player,char computer);
bool pcheckWinnerloc(char *N,char player1,char player2);
void computerMove(char *N,char computer);
std::tuple<bool, int> checkPWinnerloc(char *N, char player);
std::tuple<bool, int> checkCWinnerloc(char *N,char computer);
bool checkTie(char *N);
bool checkSubBoardWin(const std::vector<char>& N, int subBoard, char marker);
void updateBoard(char *N, const int *box, char symbol);
bool pcheckTie(char *N);
bool checkChiefWinner(const char* spaces, char player, char computer);  
// A simple function to clear the local board.
void resetLocalBoard(char* N) {
    for (int i = 0; i < 81; ++i)
        N[i] = ' ';
}


const char* getSuffix(int num) {
    int lastDigit = num % 10;
    switch (lastDigit) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

void smileEmoji(){
     std::cout << "       ******       " << std::endl;
    std::cout << "    ************    " << std::endl;
    std::cout << "  ****************  " << std::endl;
    std::cout << " ****************** " << std::endl;
    std::cout << "****   o    o   ****" << std::endl;
    std::cout << "****      ^      ****" << std::endl;
    std::cout << "****    \\___/    ****" << std::endl;
    std::cout << " ****************** " << std::endl;
    std::cout << "  ****************  " << std::endl;
    std::cout << "    ************    " << std::endl;
    std::cout << "       ******       " << std::endl;
   
}

void drawboard(char *spaces){
    std::cout << '\n' << "*****************Chief Board**********************"<< '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  "<< spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

 bool checkWinner(char *spaces, char player, char computer) {
   
    const int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

     for (int i = 0; i < 8; ++i) {

        bool isPlayerWin = (spaces[winConditions[i][0]] == player && 
                            spaces[winConditions[i][1]] == player && 
                            spaces[winConditions[i][2]] == player);
        bool isComputerWin = (spaces[winConditions[i][0]] == computer && 
                              spaces[winConditions[i][1]] == computer && 
                              spaces[winConditions[i][2]] == computer);

       
    if (isPlayerWin) {
    std::cout << "YOU have Won!!" << std::endl;

    int winningBox[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        spaces[winningBox[i]] = 'X';
    }

    drawBoard(spaces);
    break;
    return 0;


        } else{
            std::cout << "COMPUTER has Won!" << std::endl;
           
           int losingBox[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 spaces[losingBox[i]] = 'O';
             }
           break;
           return 0;
        }
    }
   

    return false;
}


void Cheif_Board(char *spaces,char *N,char player,char computer){
   auto [isWinner,winningBox] = checkPWinnerloc(N, player);
   auto [iscWinner1,winningcBox1] = checkCWinnerloc(N,computer);
   
   
  
      
   //you were trying to pass bool and box data to the chief board and problem is assumed to be bool not booling of isWinner.
   
    
if(isWinner){
    for(int i = 0;i <= winningBox - 1;++i){
        if(spaces[i] == ' '){
           if(i == winningBox-1){
            
               spaces[i] = 'X';
              
           }
           
        }
  }
}else if(iscWinner1){

    for(int i = 0; i < winningBox;++i){
        if(spaces[i] == ' '){
            if(i == winningBox - 1){
                spaces[i] = 'O';
            }
            
        }
    }



}else{
    playerMove(N,player,computer);
}
       

}

int main(){
    /*
    You are going to define the condition when the chief is winner
    
    
    */
    int ch = 0;
    std::srand(static_cast<unsigned int>(std::time(0))); 

    // Chief board (each cell represents a local board's win)
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    // Local board (9x9 cells in a single array of 81 chars)
    char N[81] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    
    // Symbols for the two game modes (adjust as needed)
    char player = 'X';
    char computer = 'O';
    char player1 = 'x';
    char player2 = 'o';

    // Input validation loop for game mode selection.
    while (true) {
        std::cout << "\n********** Which Game Mode ***********\n";
        std::cout << "1. Player vs Player\n";
        std::cout << "2. Player vs Computer\n";
        std::cout << "3. Exit the game\n";
        std::cout << "Enter your choice (1-3): ";
        if (std::cin >> ch && (ch == 1 || ch == 2 || ch == 3)) {
            break;  // valid input
        } else {
            std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Initially display the local board
    drawBoard(N);
    
    // Outer loop: keep playing local boards until a chief board winner is found.
    bool chiefWinnerFound = false;
    while (!chiefWinnerFound) {
        // Reset the local board for each new game.
        resetLocalBoard(N);
        bool localBoardDecided = false;
        
        // Play the local board until someone wins it or it ties.
        while (!localBoardDecided) {
            if (ch == 1) {  // Player vs Player mode
                // Player 1 move
                playerMove(N, player1, player2);  // assuming playerMove works for PvP here
                drawBoard(N);
                if (pcheckWinnerloc(N, player1, player2)) {
                    std::cout << "Player " << player1 << " wins the local board!\n";
                    localBoardDecided = true;
                } else if(checkTie(N)){
                    std::cout << "The local board is a tie!\n";
                    localBoardDecided = true;
                } else {
                    // Player 2 move
                    playerMove(N, player2, player1);
                    drawBoard(N);
                    if (pcheckWinnerloc(N, player2, player1)) {
                        std::cout << "Player " << player2 << " wins the local board!\n";
                        localBoardDecided = true;
                    } else if(checkTie(N)){
                        std::cout << "The local board is a tie!\n";
                        localBoardDecided = true;
                    }
                }
            } else if (ch == 2) {  // Player vs Computer mode
                // Human move
                playerMove(N, player, computer);
                drawBoard(N);
                auto [isWinner,winningBox] = checkPWinnerloc(N, player);
                auto [iscWinner1,winningcBox1] = checkCWinnerloc(N,computer);
                if (isWinner) {
                    std::cout << "Player wins the local board!\n";
                    localBoardDecided = true;
                } else if(checkTie(N)){
                    std::cout << "The local board is a tie!\n";
                    localBoardDecided = true;
                    break; // In a tie, you might choose not to update the chief board.
                } else {
                    // Computer move
                    computerMove(N, computer);
                    drawBoard(N);
                    if (iscWinner1) {
                        std::cout << "Computer wins the local board!\n";
                        localBoardDecided = true;
                    } else if(checkTie(N)){
                        std::cout << "The local board is a tie!\n";
                        localBoardDecided = true;
                    }
                }
            }
        } // end of local board play

        // Update the chief board using the result of the local board.
        Cheif_Board(spaces, N, player, computer);
        drawboard(spaces);

        // Check if there is a winner in the chief board.
        if (checkChiefWinner(spaces, player, computer)) {
            std::cout << "A winner has been determined on the Chief Board!\n";
            chiefWinnerFound = true;
        } else {
            std::cout << "No chief board winner yet. Proceeding to the next local board...\n";
        }
    }
    
    return 0;
}  /*
        idea that i have came up of are very simple first make a seperate function which tracks the winner and passes to the cheif board according to the winner 
        */
void drawBoard(char *N){

std::cout << '\n';
    std::cout << "               ||                 ||                 " << '\n';
    std::cout << "               ||                 ||                 " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[0] << "|" << " "<< N[1]<< " |" << " "<< N[2] << " ||" << "    "<< N[3] << "|" << " "<< N[4]<< " |" << " "<< N[5] << "     ||" << "  "<< N[6] << "|" << " "<< N[7]<< " |" << " "<< N[8]  <<std::endl;
    std::cout << "    ___|___|___||  ___|___|____   ||___|___|___      " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[9] << "|" << " "<< N[10]<< " |" << " "<< N[11] << " ||" << "    "<< N[12] << "|" << " "<< N[13]<< " |" << " "<< N[14] << "     ||" << "  "<< N[15] << "|" << " "<< N[16]<< " |" << " "<< N[17]  <<std::endl;
    std::cout << "    ___|___|___||  ___|___|____   ||___|___|___      " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[18] << "|" << " "<< N[19]<< " |" << " "<< N[20] << " ||" << "    "<< N[21] << "|" << " "<< N[22]<< " |" << " "<< N[23] << "     ||" << "  "<< N[24] << "|" << " "<< N[25]<< " |" << " "<< N[26]  <<std::endl;
    std::cout << "       |   |   ||     |   |       ||   |   |         " << '\n';
    std::cout << "===============||=================||=============== " << '\n';
         std::cout << "               ||                 ||                 " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[27] << "|" << " "<< N[28]<< " |" << " "<< N[29] << " ||" << "    "<< N[30] << "|" << " "<< N[31]<< " |" << " "<< N[32] << "     ||" << "  "<< N[33] << "|" << " "<< N[34]<< " |" << " "<< N[35]  <<std::endl;
    std::cout << "    ___|___|___||  ___|___|____   ||___|___|___      " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[36] << "|" << " "<< N[37]<< " |" << " "<< N[38] << " ||" << "    "<< N[39] << "|" << " "<< N[40]<< " |" << " "<< N[41] << "     ||" << "  "<< N[42] << "|" << " "<< N[43]<< " |" << " "<< N[44]  <<std::endl;
    std::cout << "    ___|___|___||  ___|___|____   ||___|___|___      " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[45] << "|" << " "<< N[46]<< " |" << " "<< N[47] << " ||" << "    "<< N[48] << "|" << " "<< N[49]<< " |" << " "<< N[50] << "     ||" << "  "<< N[51] << "|" << " "<< N[52]<< " |" << " "<< N[53]  <<std::endl;
    std::cout << "       |   |   ||     |   |       ||   |   |         " << '\n';
    std::cout << "===============||=================||=============== " << '\n';
          std::cout << "               ||                 ||                 " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[54] << "|" << " "<< N[55]<< " |" << " "<< N[56] << " ||" << "    "<< N[57] << "|" << " "<< N[58]<< " |" << " "<< N[59] << "     ||" << "  "<< N[60] << "|" << " "<< N[61]<< " |" << " "<< N[62]  <<std::endl;
    std::cout << "    ___|___|___||  ___|___|____   ||___|___|___      " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[63] << "|" << " "<< N[64]<< " |" << " "<< N[65] << " ||" << "    "<< N[66] << "|" << " "<< N[67]<< " |" << " "<< N[68] << "     ||" << "  "<< N[69] << "|" << " "<< N[70]<< " |" << " "<< N[71]  <<std::endl;
    std::cout << "    ___|___|___||  ___|___|____   ||___|___|___      " << '\n';
    std::cout << "       |   |   ||     |   |       ||   |   |         " <<'\n';
    std::cout << "      "<< N[72] << "|" << " "<< N[73]<< " |" << " "<< N[74] << " ||" << "    "<< N[75] << "|" << " "<< N[76]<< " |" << " "<< N[77] << "     ||" << "  "<< N[78] << "|" << " "<< N[79]<< " |" << " "<< N[80]  <<std::endl;
    std::cout << "       |   |   ||     |   |       ||   |   |         " << '\n';
}
void playerMove(char *N, char player, char computer) {
    int place, number;
    auto [isWinner, winningBox] = checkPWinnerloc(N, player);

    const int mappings[9][9] = {
        {1, 2, 3, 10, 11, 12, 19, 20, 21}, 
        {4, 5, 6, 13, 14, 15, 22, 23, 24}, 
        {7, 8, 9, 16, 17, 18, 25, 26, 27}, 
        {28, 29, 30, 37, 38, 39, 46, 47, 48}, 
        {31, 32, 33, 40, 41, 42, 49, 50, 51}, 
        {34, 35, 36, 43, 44, 45, 52, 53, 54}, 
        {55, 56, 57, 64, 65, 66, 73, 74, 75}, 
        {58, 59, 60, 67, 68, 69, 76, 77, 78}, 
        {61, 62, 63, 70, 71, 72, 79, 80, 81}  
    };

    while (true) {
        std::cout << "Enter a place (1-9) or 0 to exit: ";
        std::cin >> place;

        if (place == 0) {
            std::cout << "THANKS FOR PLAYING!!" << "\n";
            smileEmoji();
            exit(0);
        }

        if (place < 1 || place > 9) {
            std::cout << "Invalid place. Try again.\n";
            continue;
        }

        if (place == winningBox) {
            std::cout << "The box is already used!! Try again.\n";
            continue;
        }

        break;
    }

    while (true) {
        std::cout << "Enter a spot within place " << place << " (1-9) or 0 to exit: ";
        std::cin >> number;

        if (number == 0) {
            std::cout << "THANKS FOR PLAYING!!" << "\n";
            smileEmoji();
            exit(0);
        }

        if (number == 10) {
            playerMove(N,player,computer);
        }

        if (number < 1 || number > 9) {
            std::cout << "Invalid spot. Try again.\n";
            continue;
        }

        int index = mappings[place - 1][number - 1] - 1; 
        if (N[index] == ' ') {
            N[index] = player;
            drawBoard(N);
            break;
        } else {
            std::cout << "Spot already taken. Try again.\n";
        }
    }
}

void player1Move(char *N, char player1) {
    int place, number;


 const int mappings[9][9] = {
        {1, 2, 3, 10, 11, 12, 19, 20, 21}, 
        {4, 5, 6, 13, 14, 15, 22, 23, 24}, 
        {7, 8, 9, 16, 17, 18, 25, 26, 27}, 
        {28, 29, 30, 37, 38, 39, 46, 47, 48}, 
        {31, 32, 33, 40, 41, 42, 49, 50, 51}, 
        {34, 35, 36, 43, 44, 45, 52, 53, 54}, 
        {55, 56, 57, 64, 65, 66, 73, 74, 75}, 
        {58, 59, 60, 67, 68, 69, 76, 77, 78}, 
        {61, 62, 63, 70, 71, 72, 79, 80, 81}  
    };

   
    do {
        std::cout << "\nPlayer_1((x)):";
        std::cout << "Enter a place (1-9): ";
        std::cin >> place;

        if(place == 0){
            std::cout << "THANKS FOR PLAYING!!" << "\n";
            smileEmoji();
            exit(0);
            
        }

        if (place < 1 || place > 9) {
            std::cout << "Invalid place. Try again.\n";
        }
    } while (place < 1 || place > 9);

    
    do {
        std::cout << "Enter a spot within place " << place << " (1-9): ";
        std::cin >> number;

            if(number == 0){
            std::cout << "THANKS FOR PLAYING!!" << "\n";
            smileEmoji();
            exit(0);
            
        }else if(number == 10){

            player1Move(N,player1); 

        }

        if (number < 1 || number > 9) {
            std::cout << "Invalid spot. Try again.\n";
            continue;
        }

        
        int index = mappings[place - 1][number - 1] - 1;

        if (N[index] == ' ') {
            N[index] = player1; 
            drawBoard(N);
            break;
        } else {
            std::cout << "Spot already taken. Try again.\n";
        }
    } while (true);
}

void player2Move(char *N, char player2) {
    int place, number;


    const int mappings[9][9] = {
        {1, 2, 3, 10, 11, 12, 19, 20, 21}, 
        {4, 5, 6, 13, 14, 15, 22, 23, 24}, 
        {7, 8, 9, 16, 17, 18, 25, 26, 27}, 
        {28, 29, 30, 37, 38, 39, 46, 47, 48}, 
        {31, 32, 33, 40, 41, 42, 49, 50, 51}, 
        {34, 35, 36, 43, 44, 45, 52, 53, 54}, 
        {55, 56, 57, 64, 65, 66, 73, 74, 75}, 
        {58, 59, 60, 67, 68, 69, 76, 77, 78}, 
        {61, 62, 63, 70, 71, 72, 79, 80, 81}  
    };

   
    do {
        std::cout << "\nPlayer_2((o)):";
        std::cout << "Enter a place (1-9): ";
        std::cin >> place;

            if(place == 0){
            std::cout << "THANKS FOR PLAYING!!" << "\n";
            smileEmoji();
            exit(0);
            
        }

        if (place < 1 || place > 9) {
            std::cout << "Invalid place. Try again.\n";
        }
    } while (place < 1 || place > 9);

    
    do {
        std::cout << "Enter a spot within place " << place << " (1-9): ";
        std::cin >> number;

            if(number == 0){
            std::cout << "THANKS FOR PLAYING!!" << "\n";
            smileEmoji();
            exit(0);
            
        }

        if (number < 1 || number > 9) {
            std::cout << "Invalid spot. Try again.\n";
            continue;
        }

        
        int index = mappings[place - 1][number - 1] - 1;

        if (N[index] == ' ') {
            N[index] = player2; 
            drawBoard(N);
            break;
        } else {
            std::cout << "Spot already taken. Try again.\n";
        }
    } while (true);
}

bool checkSubBoardWin(char *N, int subBoard, char marker) {
    const int mappings[9][9] = {
        {1, 2, 3, 10, 11, 12, 19, 20, 21},
        {4, 5, 6, 13, 14, 15, 22, 23, 24},
        {7, 8, 9, 16, 17, 18, 25, 26, 27},
        {28, 29, 30, 37, 38, 39, 46, 47, 48},
        {31, 32, 33, 40, 41, 42, 49, 50, 51},
        {34, 35, 36, 43, 44, 45, 52, 53, 54},
        {55, 56, 57, 64, 65, 66, 73, 74, 75},
        {58, 59, 60, 67, 68, 69, 76, 77, 78},
        {61, 62, 63, 70, 71, 72, 79, 80, 81}
    };

    int indices[9];
    for (int i = 0; i < 9; i++) {
        indices[i] = mappings[subBoard][i] - 1;
    }

    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (N[indices[wins[i][0]]] == marker &&
            N[indices[wins[i][1]]] == marker &&
            N[indices[wins[i][2]]] == marker) {
            return true;
        }
    }
    return false;
}


void computerMove(char *N, char computer) {
    const int mappings[9][9] = {
        {1, 2, 3, 10, 11, 12, 19, 20, 21},
        {4, 5, 6, 13, 14, 15, 22, 23, 24},
        {7, 8, 9, 16, 17, 18, 25, 26, 27},
        {28, 29, 30, 37, 38, 39, 46, 47, 48},
        {31, 32, 33, 40, 41, 42, 49, 50, 51},
        {34, 35, 36, 43, 44, 45, 52, 53, 54},
        {55, 56, 57, 64, 65, 66, 73, 74, 75},
        {58, 59, 60, 67, 68, 69, 76, 77, 78},
        {61, 62, 63, 70, 71, 72, 79, 80, 81}
    };

    char opponent = (computer == 'X') ? 'O' : 'X';
    int bestMove = -1;

    // Check for a winning move for the computer.
    for (int p = 0; p < 9; p++) {
        for (int s = 0; s < 9; s++) {
            int idx = mappings[p][s] - 1;
            if (N[idx] == ' ') {
                N[idx] = computer;
                if (checkSubBoardWin(N, p, computer)) {
                    bestMove = idx;
                    N[idx] = ' ';
                    N[bestMove] = computer;
                    return;
                }
                N[idx] = ' ';
            }
        }
    }

    // Check to block the opponent's winning move.
    for (int p = 0; p < 9; p++) {
        for (int s = 0; s < 9; s++) {
            int idx = mappings[p][s] - 1;
            if (N[idx] == ' ') {
                N[idx] = opponent;
                if (checkSubBoardWin(N, p, opponent)) {
                    bestMove = idx;
                    N[idx] = ' ';
                    N[bestMove] = computer;
                    return;
                }
                N[idx] = ' ';
            }
        }
    }

    // Take center if available.
    if (N[40] == ' ') {
        N[40] = computer;
        return;
    }

    // Otherwise, choose a random available spot.
    int available[81];
    int count = 0;
    for (int i = 0; i < 81; i++) {
        if (N[i] == ' ') {
            available[count++] = i;
        }
    }
    if (count > 0) {
        bestMove = available[std::rand() % count];
        N[bestMove] = computer;
    }
}

bool checkTie(char *N){

for(int i = 0; i<9;i++){
    if(N[i] == ' '){
        return false;
    }
    }
    std::cout << "ITS a tie!\n";
    return true;

   
}

bool pcheckTie(char *N){
   
   for(int i = 0; i<9;i++){
    if(N[i] == ' '){
        return false;
    }
    }
    std::cout << "ITS a tie!\n";
    return true;

   
} 



bool pcheckWinnerloc(char *N, char player1, char player2) {
    const int winConditions1[8][3] = {
        {0, 1, 2},  // First row
        {9, 10, 11}, // Second row
        {18, 19, 20}, // Third row
        {0, 9, 18},  // First column
        {1, 10, 19}, // Second column
        {2, 11, 20}, // Third column
        {0, 10, 20}, // Diagonal top-left to bottom-right
        {2, 10, 18}  // Diagonal top-right to bottom-left
    };
    const int winConditions2[8][3] = {
    {3, 4, 5},
    {12, 13, 14},
    {21, 22, 23},
    {3, 12, 21},
    {4, 13, 22},
    {5, 14, 23},
    {3, 13, 23},
    {5, 13, 21}
};
    const int winConditions3[8][3] = {
    {6, 7, 8},
    {15, 16, 17},
    {24, 25, 26},
    {6, 15, 24},
    {7, 16, 25},
    {8, 17, 26},
    {6, 16, 26},
    {8, 16, 24}
};

    const int winConditions4[8][3] = {
    {27, 28, 29},
    {36, 37, 38},
    {45, 46, 47},
    {27, 36, 45},
    {28, 37, 46},
    {29, 38, 47},
    {27, 37, 47},
    {29, 37, 45}
};

    const int winConditions5[8][3] = {
    {30, 31, 32},
    {39, 40, 41},
    {48, 49, 50},
    {30, 39, 48},
    {31, 40, 49},
    {32, 41, 50},
    {30, 40, 50},
    {32, 40, 48}
};
    const int winConditions6[8][3] = {
    {33, 34, 35},
    {42, 43, 44},
    {51, 52, 53},
    {33, 42, 51},
    {34, 43, 52},
    {35, 44, 53},
    {33, 43, 53},
    {35, 43, 51}
};
    const int winConditions7[8][3] = {
    {54, 55, 56},
    {63, 64, 65},
    {72, 73, 74},
    {54, 63, 72},
    {55, 64, 73},
    {56, 65, 74},
    {54, 64, 74},
    {56, 64, 72}
};
    const int winConditions8[8][3] = {
    {57, 58, 59},
    {66, 67, 68},
    {75, 76, 77},
    {57, 66, 75},
    {58, 67, 76},
    {59, 68, 77},
    {57, 67, 77},
    {59, 67, 75}
};
    const int winConditions9[8][3] = {
    {60, 61, 62},
    {69, 70, 71},
    {78, 79, 80},
    {60, 69, 78},
    {61, 70, 79},
    {62, 71, 80},
    {60, 70, 80},
    {62, 70, 78}
};
    
    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win1 = (N[winConditions1[i][0]] == player1 && 
                            N[winConditions1[i][1]] == player1 && 
                            N[winConditions1[i][2]] == player1);
        bool isComputerWin = (N[winConditions1[i][0]] == player2 && 
                              N[winConditions1[i][1]] == player2 && 
                              N[winConditions1[i][2]] == player2);

    if (isPlayer1Win1) {
    std::cout << "Player1 has Obtained 1st Box!" << std::endl;

    int winningBox[] = {0, 1, 2, 9, 10, 11, 18, 19, 20};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;

        } else if (isComputerWin) {
            std::cout << "Player2 Has Obtained 1st Box" << std::endl;
           
             int losingBox[] = {0, 1, 2, 9, 10, 11, 18, 19, 20};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 N[losingBox[i]] = 'O';
             }
            drawBoard(N);
            return true;
        }
    }

    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win2 = (N[winConditions2[i][0]] == player1 && 
                            N[winConditions2[i][1]] == player1 && 
                            N[winConditions2[i][2]] == player1);
        bool isComputerWin = (N[winConditions2[i][0]] == player2 && 
                              N[winConditions2[i][1]] == player2 && 
                              N[winConditions2[i][2]] == player2);

       
    if (isPlayer1Win2) {
    std::cout << "Player1 has Obtained 2nd Box!" << std::endl;

    int winningBox[] = {3, 4, 5, 12, 13, 14, 21, 22, 23};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;


        } else if (isComputerWin) {
            std::cout << "Player2 has obtained 2nd Box !" << std::endl;
           
           int losingBox[] = {3, 4, 5, 12, 13, 14, 21, 22, 23};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 N[losingBox[i]] = 'O';
             }
            drawBoard(N);
            return true;
        }
    }
   
   for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win3 = (N[winConditions3[i][0]] == player1 && 
                            N[winConditions3[i][1]] == player1 && 
                            N[winConditions3[i][2]] == player1);
        bool isComputerWin = (N[winConditions3[i][0]] == player2 && 
                              N[winConditions3[i][1]] == player2 && 
                              N[winConditions3[i][2]] == player2);

    if (isPlayer1Win3) {
            std::cout << "Player1 has Obtained 3rd Box !" << std::endl;
 

    int winningBox[] = {6, 7, 8, 15, 16, 17, 24, 25, 26};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;


        } else if (isComputerWin) {
            std::cout << "Player2 has obtained 3rd Box !" << std::endl;
           
           int losingBox[] = {6, 7, 8, 15, 16, 17, 24, 25, 26};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 N[losingBox[i]] = 'O';
             }
            drawBoard(N);
            return true;
        }
    }


    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win4 = (N[winConditions4[i][0]] == player1 && 
                            N[winConditions4[i][1]] == player1 && 
                            N[winConditions4[i][2]] == player1);
        bool isComputerWin = (N[winConditions4[i][0]] == player2 && 
                              N[winConditions4[i][1]] == player2 && 
                              N[winConditions4[i][2]] == player2);

     if (isPlayer1Win4) {
    std::cout << "Player1 has Obtained 4th Box!" << std::endl;

    int winningBox[] = {27, 28, 29, 36, 37, 38, 45, 46, 47};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;
}
    
else if (isComputerWin) {
    std::cout << "Player2 has obtained 4th Box !" << std::endl;
    
    int losingBox[] = {27, 28, 29, 36, 37, 38, 45, 46, 47}; 
    int size = sizeof(losingBox) / sizeof(losingBox[0]);

    for (int i = 0; i < size; ++i) {
        N[losingBox[i]] = 'O';
   }
   drawBoard(N);
    return true;
    }
}

    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win5 = (N[winConditions5[i][0]] == player1 && 
                            N[winConditions5[i][1]] == player1 && 
                            N[winConditions5[i][2]] == player1);
        bool isComputerWin = (N[winConditions5[i][0]] == player2 && 
                              N[winConditions5[i][1]] == player2 && 
                              N[winConditions5[i][2]] == player2);

        if (isPlayer1Win5) {
    std::cout << "Player1 has Obtained 5th Box!" << std::endl;

    int winningBox[] = {30, 31, 32, 39, 40, 41, 48, 49, 50};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;
}
else if (isComputerWin) {
    std::cout << "Player2 has obtained 5th Box !" << std::endl;
    
    int losingBox[] = {30, 31, 32, 39, 40, 41, 48, 49, 50};
    int size = sizeof(losingBox) / sizeof(losingBox[0]);

    for (int i = 0; i < size; ++i) { 
        N[losingBox[i]] = 'O';
            
        }
        drawBoard(N);
        return true;
    }
    }


    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win6 = (N[winConditions6[i][0]] == player1 && 
                            N[winConditions6[i][1]] == player1 && 
                            N[winConditions6[i][2]] == player1);
        bool isComputerWin = (N[winConditions6[i][0]] == player2 && 
                              N[winConditions6[i][1]] == player2 && 
                              N[winConditions6[i][2]] == player2);

      if (isPlayer1Win6) {
    std::cout << "Player1 has Obtained 6th Box!" << std::endl;

    int winningBox[] = {33, 34, 35, 42, 43, 44, 51, 52, 53};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;
}
 else if (isComputerWin) {
            std::cout << "Player2 Has Obtained 6th box!" << std::endl;
            
            int lossingBox[] = {33, 34, 35, 42, 43, 44, 51, 52, 53};
            int size = sizeof(lossingBox)/sizeof(lossingBox[0]);
            
            for(int i = 0;i < size; ++i){
                N[lossingBox[i]] = 'X';
            }
            drawBoard(N);
            return true;
        }
    }

    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win7 = (N[winConditions7[i][0]] == player1 && 
                            N[winConditions7[i][1]] == player1 && 
                            N[winConditions7[i][2]] == player1);
        bool isComputerWin = (N[winConditions7[i][0]] == player2 && 
                              N[winConditions7[i][1]] == player2 && 
                              N[winConditions7[i][2]] == player2);

       if (isPlayer1Win7) {
    std::cout << "Player1 has Obtained 7th Box!" << std::endl;

    int winningBox[] = {54, 55, 56, 63, 64, 65, 72, 73, 74};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;
}
 else if (isComputerWin) {
           std::cout << "Player2 has obtained 7th Box !" << std::endl; 

           int losingBox[] = {54, 55, 56, 63, 64, 65, 72, 73, 74};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 N[losingBox[i]] = 'O';
             }
             drawBoard(N);
            return true;



        }
    }

    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win8 = (N[winConditions8[i][0]] == player1 && 
                            N[winConditions8[i][1]] == player1 && 
                            N[winConditions8[i][2]] == player1);
        bool isComputerWin = (N[winConditions8[i][0]] == player2 && 
                              N[winConditions8[i][1]] == player2 && 
                              N[winConditions8[i][2]] == player2);

     if (isPlayer1Win8) {
    std::cout << "Player1 has Obtained 8th Box!" << std::endl;

    int winningBox[] = {57, 58, 59, 66, 67, 68, 75, 76, 77};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;
}
 else if (isComputerWin) {
            
            std::cout << "Player2 has obtained 8th Box !" << std::endl;
            
            int losingBox[] = {57, 58, 59, 66, 67, 68, 75, 76, 77};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 N[losingBox[i]] = 'O';
             }
             drawBoard(N);
            return true;


        }
    }

    for (int i = 0; i < 8; ++i) {

        bool isPlayer1Win9 = (N[winConditions9[i][0]] == player1 && 
                            N[winConditions9[i][1]] == player1 && 
                            N[winConditions9[i][2]] == player1);
        bool isComputerWin = (N[winConditions9[i][0]] == player2 && 
                              N[winConditions9[i][1]] == player2 && 
                              N[winConditions9[i][2]] == player2);

      if (isPlayer1Win9) {
    std::cout << "Player1 has Obtained 9th Box!" << std::endl;

    int winningBox[] = {60, 61, 62, 69, 70, 71, 78, 79, 80};
    int size = sizeof(winningBox) / sizeof(winningBox[0]);

    for (int i = 0; i < size; ++i) {
        N[winningBox[i]] = 'X';
    }

    drawBoard(N);
    return true;
}
else if (isComputerWin) {

            std::cout << "Player2 has obtained 9th Box !" << std::endl;
            
            int losingBox[] = {60, 61, 62, 69, 70, 71, 78, 79, 80};
             int size = sizeof(losingBox) / sizeof(losingBox[0]);

             for(int i = 0; i < size; ++i){
                 N[losingBox[i]] = 'O';
             }
            drawBoard(N);
            return true; 



        }
    }

    return false;
}

std::tuple<bool, int> checkPWinnerloc(char *N, char player) {
    static bool occupied[9] = { false, false, false, false, false, false, false, false, false };
    static const char* ordinals[9] = { "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th" };
    static const int boxCells[9][9] = {
        {0, 1, 2, 9, 10, 11, 18, 19, 20},
        {3, 4, 5, 12, 13, 14, 21, 22, 23},
        {6, 7, 8, 15, 16, 17, 24, 25, 26},
        {27, 28, 29, 36, 37, 38, 45, 46, 47},
        {30, 31, 32, 39, 40, 41, 48, 49, 50},
        {33, 34, 35, 42, 43, 44, 51, 52, 53},
        {54, 55, 56, 63, 64, 65, 72, 73, 74},
        {57, 58, 59, 66, 67, 68, 75, 76, 77},
        {60, 61, 62, 69, 70, 71, 78, 79, 80}
    };
    static const int winCon1[8][3] = {
        {0,1,2}, {9,10,11}, {18,19,20}, {0,9,18},
        {1,10,19}, {2,11,20}, {0,10,20}, {2,10,18}
    };
    static const int winCon2[8][3] = {
        {3,4,5}, {12,13,14}, {21,22,23}, {3,12,21},
        {4,13,22}, {5,14,23}, {3,13,23}, {5,13,21}
    };
    static const int winCon3[8][3] = {
        {6,7,8}, {15,16,17}, {24,25,26}, {6,15,24},
        {7,16,25}, {8,17,26}, {6,16,26}, {8,16,24}
    };
    static const int winCon4[8][3] = {
        {27,28,29}, {36,37,38}, {45,46,47}, {27,36,45},
        {28,37,46}, {29,38,47}, {27,37,47}, {29,37,45}
    };
    static const int winCon5[8][3] = {
        {30,31,32}, {39,40,41}, {48,49,50}, {30,39,48},
        {31,40,49}, {32,41,50}, {30,40,50}, {32,40,48}
    };
    static const int winCon6[8][3] = {
        {33,34,35}, {42,43,44}, {51,52,53}, {33,42,51},
        {34,43,52}, {35,44,53}, {33,43,53}, {35,43,51}
    };
    static const int winCon7[8][3] = {
        {54,55,56}, {63,64,65}, {72,73,74}, {54,63,72},
        {55,64,73}, {56,65,74}, {54,64,74}, {56,64,72}
    };
    static const int winCon8[8][3] = {
        {57,58,59}, {66,67,68}, {75,76,77}, {57,66,75},
        {58,67,76}, {59,68,77}, {57,67,77}, {59,67,75}
    };
    static const int winCon9[8][3] = {
        {60,61,62}, {69,70,71}, {78,79,80}, {60,69,78},
        {61,70,79}, {62,71,80}, {60,70,80}, {62,70,78}
    };

    struct BoxData {
        int boxNumber;
        const int (*cells)[9];
        const int (*winCon)[3];
    };

    const BoxData boxes[9] = {
        {1, &boxCells[0], winCon1},
        {2, &boxCells[1], winCon2},
        {3, &boxCells[2], winCon3},
        {4, &boxCells[3], winCon4},
        {5, &boxCells[4], winCon5},
        {6, &boxCells[5], winCon6},
        {7, &boxCells[6], winCon7},
        {8, &boxCells[7], winCon8},
        {9, &boxCells[8], winCon9}
    };

    for (int b = 0; b < 9; ++b) {
        const BoxData& box = boxes[b];
        for (int w = 0; w < 8; ++w) {
            const int* cond = box.winCon[w];
            if (N[cond[0]] == player && N[cond[1]] == player && N[cond[2]] == player) {
                if (occupied[box.boxNumber - 1]) {
                    std::cout << "\nThis box is occupied!!\n";
                    return std::make_tuple(false, box.boxNumber);
                }
                char symbol = 'X';  // Player's symbol
                std::string message = "YOU have Obtained " + std::string(ordinals[box.boxNumber - 1]) + " Box!";
                std::cout << message << std::endl;
                occupied[box.boxNumber - 1] = true;
                for (int i = 0; i < 9; ++i) {
                    int cellIndex = (*box.cells)[i];
                    N[cellIndex] = symbol;
                }
                drawBoard(N);
                return std::make_tuple(true, box.boxNumber);
            }
        }
    }
    return std::make_tuple(false, 0);
}

std::tuple<bool, int> checkCWinnerloc(char *N,char computer){
    static bool occupied[9] = { false, false, false, false, false, false, false, false, false };
    static const char* ordinals[9] = { "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th" };
    static const int boxCells[9][9] = {
        {0, 1, 2, 9, 10, 11, 18, 19, 20},
        {3, 4, 5, 12, 13, 14, 21, 22, 23},
        {6, 7, 8, 15, 16, 17, 24, 25, 26},
        {27, 28, 29, 36, 37, 38, 45, 46, 47},
        {30, 31, 32, 39, 40, 41, 48, 49, 50},
        {33, 34, 35, 42, 43, 44, 51, 52, 53},
        {54, 55, 56, 63, 64, 65, 72, 73, 74},
        {57, 58, 59, 66, 67, 68, 75, 76, 77},
        {60, 61, 62, 69, 70, 71, 78, 79, 80}
    };
    static const int winCon1[8][3] = {
        {0,1,2}, {9,10,11}, {18,19,20}, {0,9,18},
        {1,10,19}, {2,11,20}, {0,10,20}, {2,10,18}
    };
    static const int winCon2[8][3] = {
        {3,4,5}, {12,13,14}, {21,22,23}, {3,12,21},
        {4,13,22}, {5,14,23}, {3,13,23}, {5,13,21}
    };
    static const int winCon3[8][3] = {
        {6,7,8}, {15,16,17}, {24,25,26}, {6,15,24},
        {7,16,25}, {8,17,26}, {6,16,26}, {8,16,24}
    };
    static const int winCon4[8][3] = {
        {27,28,29}, {36,37,38}, {45,46,47}, {27,36,45},
        {28,37,46}, {29,38,47}, {27,37,47}, {29,37,45}
    };
    static const int winCon5[8][3] = {
        {30,31,32}, {39,40,41}, {48,49,50}, {30,39,48},
        {31,40,49}, {32,41,50}, {30,40,50}, {32,40,48}
    };
    static const int winCon6[8][3] = {
        {33,34,35}, {42,43,44}, {51,52,53}, {33,42,51},
        {34,43,52}, {35,44,53}, {33,43,53}, {35,43,51}
    };
    static const int winCon7[8][3] = {
        {54,55,56}, {63,64,65}, {72,73,74}, {54,63,72},
        {55,64,73}, {56,65,74}, {54,64,74}, {56,64,72}
    };
    static const int winCon8[8][3] = {
        {57,58,59}, {66,67,68}, {75,76,77}, {57,66,75},
        {58,67,76}, {59,68,77}, {57,67,77}, {59,67,75}
    };
    static const int winCon9[8][3] = {
        {60,61,62}, {69,70,71}, {78,79,80}, {60,69,78},
        {61,70,79}, {62,71,80}, {60,70,80}, {62,70,78}
    };

    struct BoxData {
        int boxNumber;
        const int (*cells)[9];
        const int (*winCon)[3];
    };

    const BoxData boxes[9] = {
        {1, &boxCells[0], winCon1},
        {2, &boxCells[1], winCon2},
        {3, &boxCells[2], winCon3},
        {4, &boxCells[3], winCon4},
        {5, &boxCells[4], winCon5},
        {6, &boxCells[5], winCon6},
        {7, &boxCells[6], winCon7},
        {8, &boxCells[7], winCon8},
        {9, &boxCells[8], winCon9}
    };
    for (int b = 0; b < 9; ++b) {
        const BoxData& box = boxes[b];
        for (int w = 0; w < 8; ++w) {
            const int* cond = box.winCon[w];
            if (N[cond[0]] == computer && N[cond[1]] == computer && N[cond[2]] == computer) {
                if (occupied[box.boxNumber - 1]) {
                    std::cout << "\nThis box is occupied!!\n";
                    return std::make_tuple(false, box.boxNumber);
                }
                char symbol = 'O';  // Computer's symbol
                std::string message = "COMPUTER has obtained " + std::string(ordinals[box.boxNumber - 1]) + " Box!";
                std::cout << message << std::endl;
                occupied[box.boxNumber - 1] = true;
                for (int i = 0; i < 9; ++i) {
                    int cellIndex = (*box.cells)[i];
                    N[cellIndex] = symbol;
                }
                drawBoard(N);
                return std::make_tuple(true, box.boxNumber);
            }
        }
    }
    return std::make_tuple(false, 0);
}

