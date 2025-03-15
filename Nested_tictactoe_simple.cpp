#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <tuple>
#include <set>
#include <string>

//Function declarations
void drawBoard(char *N);
void playerMove(char *N, char player);
void player1Move(char *N, char player1);
void player2Move(char *N, char player2);
void computerMove(char *N, char computer);
bool checkTie(char *N);
bool pcheckTie(char *N);
std::tuple<bool, int> checkWinOnLocalBoard(char *N, char marker);
std::tuple<bool, int> checkPWinnerloc(char *N, char player);
std::tuple<bool, int> checkCWinnerloc(char *N, char computer);
bool pcheckWinnerloc(char *N, char player1, char player2);
void drawboard(char *spaces);
void smileEmoji();
void updateChiefBoard(char *spaces, int position, char marker);

// Add a data structure to track which local boards have already been won
bool localBoardWon[9] = {false, false, false, false, false, false, false, false, false};

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
//The main board of the game i.e Chief Board
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
// A collection of LocalBoard
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

// Function to check if a player has won on a local board
std::tuple<bool, int> checkWinOnLocalBoard(char *N, char marker) {
    // For each of the 9 local boards
    for (int board = 0; board < 9; board++) {
        // Skip boards that have already been won
        if (localBoardWon[board]) {
            continue;
        }
        
        // Calculate starting index for this local board
        int startRow = (board / 3) * 3;
        int startCol = (board % 3) * 3;
        
        // Check rows in this local board
        for (int i = 0; i < 3; i++) {
            int row = startRow + i;
            // If all 3 cells in this row have the marker
            if (N[row*9 + startCol] == marker && 
                N[row*9 + startCol + 1] == marker && 
                N[row*9 + startCol + 2] == marker) {
                localBoardWon[board] = true;
                return {true, board + 1}; // +1 for 1-indexed board number
            }
        }
        
        // Check columns in this local board
        for (int i = 0; i < 3; i++) {
            int col = startCol + i;
            // If all 3 cells in this column have the marker
            if (N[startRow*9 + col] == marker && 
                N[(startRow+1)*9 + col] == marker && 
                N[(startRow+2)*9 + col] == marker) {
                localBoardWon[board] = true;
                return {true, board + 1};
            }
        }
        
        // Check diagonals in this local board
        // Top-left to bottom-right
        if (N[startRow*9 + startCol] == marker && 
            N[(startRow+1)*9 + startCol+1] == marker && 
            N[(startRow+2)*9 + startCol+2] == marker) {
            localBoardWon[board] = true;
            return {true, board + 1};
        }
        
        // Top-right to bottom-left
        if (N[startRow*9 + startCol+2] == marker && 
            N[(startRow+1)*9 + startCol+1] == marker && 
            N[(startRow+2)*9 + startCol] == marker) {
            localBoardWon[board] = true;
            return {true, board + 1};
        }
    }
    
    // No win found
    return {false, 0};
}

// bool checkLocalWin(char *N, int localBoard, char player) {
//     int startRow = (localBoard / 3) * 3;
//     int startCol = (localBoard % 3) * 3;
//     // Check rows.
//     for (int i = 0; i < 3; ++i) {
//         if (N[(startRow + i) * 9 + startCol] == player &&
//             N[(startRow + i) * 9 + startCol + 1] == player &&
//             N[(startRow + i) * 9 + startCol + 2] == player)
//             return true;
//     }
//     // Check columns.
//     for (int j = 0; j < 3; ++j) {
//         if (N[startRow * 9 + startCol + j] == player &&
//             N[(startRow + 1) * 9 + startCol + j] == player &&
//             N[(startRow + 2) * 9 + startCol + j] == player)
//             return true;
//     }
//     // Check diagonals.
//     if (N[startRow * 9 + startCol] == player &&
//         N[(startRow + 1) * 9 + startCol + 1] == player &&
//         N[(startRow + 2) * 9 + startCol + 2] == player)
//         return true;
//     if (N[startRow * 9 + startCol + 2] == player &&
//         N[(startRow + 1) * 9 + startCol + 1] == player &&
//         N[(startRow + 2) * 9 + startCol] == player)
//         return true;
//     return false;
// }

// Check for player win on any local board
std::tuple<bool, int> checkPWinnerloc(char *N, char player) {
    return checkWinOnLocalBoard(N, player);
}

// Check for computer win on any local board
std::tuple<bool, int> checkCWinnerloc(char *N, char computer) {
    return checkWinOnLocalBoard(N, computer);
} 



// Check for wins between two players
bool pcheckWinnerloc(char *N, char player1, char player2) {
    auto [p1Wins, p1Board] = checkWinOnLocalBoard(N, player1);
    auto [p2Wins, p2Board] = checkWinOnLocalBoard(N, player2);
    
    return p1Wins || p2Wins;
}

// Check for a tie on the nested board
bool checkTie(char *N) {
    for (int i = 0; i < 81; i++) {
        if (N[i] == ' ') {
            return false; // If any cell is empty, it's not a tie
        }
    }
    return true; // All cells are filled
}

// Simpler tie check for player vs player
bool pcheckTie(char *N) {
    return checkTie(N);
}


// Check for a winner on the chief board
bool checkWinner(char *spaces, char player, char computer) {
    const int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; ++i) {
        // Check for player win
        if (spaces[winConditions[i][0]] == player && 
            spaces[winConditions[i][1]] == player && 
            spaces[winConditions[i][2]] == player) {
            std::cout << "YOU have Won!!" << std::endl;
            // Fill the board with player's symbol
            for (int j = 0; j < 9; ++j) {
                spaces[j] = player;
            }
            drawboard(spaces);
            return true;
        }
        
        // Check for computer win
        if (spaces[winConditions[i][0]] == computer && 
            spaces[winConditions[i][1]] == computer && 
            spaces[winConditions[i][2]] == computer) {
            std::cout << "COMPUTER has Won!" << std::endl;
            // Fill the board with computer's symbol
            for (int j = 0; j < 9; ++j) {
                spaces[j] = computer;
            }
            drawboard(spaces);
            return true;
        }
    }
    return false;
}

// Update a local board when it's won
void updateLocalBoard(char *N, int localBoardIndex, char marker) {
    int localSize = 3;    // Each local board is 3x3
    // Determine the starting row and column in the overall board
    int startRow = (localBoardIndex / 3) * localSize;
    int startCol = (localBoardIndex % 3) * localSize;
    
    // Fill the entire local board with the marker
    for (int i = 0; i < localSize; ++i) {
        for (int j = 0; j < localSize; ++j) {
            // Calculate the index in the 1D array
            int index = (startRow + i) * 9 + (startCol + j);
            N[index] = marker;
        }
    }
}

// Update the chief board
void updateChiefBoard(char *spaces, int position, char marker) {
    if (position >= 0 && position < 9 && spaces[position] == ' ') {
        spaces[position] = marker;
    }
}

// Reset game state for a new game
void resetGame(char *spaces, char *N) {
    // Reset global board
    for (int i = 0; i < 9; i++) {
        spaces[i] = ' ';
    }
    
    // Reset nested board
    for (int i = 0; i < 81; i++) {
        N[i] = ' ';
    }
    
    // Reset local board win tracking
    for (int i = 0; i < 9; i++) {
        localBoardWon[i] = false;
    }
}

int main(){
    int ch;
    std::srand(static_cast<unsigned int>(std::time(0))); 
    //Global Board
    char spaces[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    //Nested Board (9x9)
    char N[81];
    for(int i = 0; i < 81; i++) {
        N[i] = ' ';
    }

    char player = 'X';
    char computer = 'O';
    char player1 = 'x';
    char player2 = 'o';
    bool running = true;

     // Reset local board win tracking at the start
     for (int i = 0; i < 9; i++) {
        localBoardWon[i] = false;
    }

    std::cout << "\n**********Which Game Mode***********\n"
              << "\n**********1. Player vs Player********\n"
              << "\n**********2. Player vs Computer******\n"
              << "\n**********3. Exit the game***********\n";
    std::cin >> ch;
    
    drawBoard(N);
    
    if (ch == 1) {
        // Player vs Player mode
        while (running) {
            // Player 1's turn
            std::cout << "Player " << player1 << "'s turn\n";
            player1Move(N, player1);
            drawBoard(N);
            
            // Check if Player 1 won a local board
            auto [p1Wins, p1WinningBoard] = checkPWinnerloc(N, player1);
            if (p1Wins) {
                std::cout << "Player " << player1 << " wins local board " << p1WinningBoard << "!\n";
                updateLocalBoard(N, p1WinningBoard-1, player1);
                updateChiefBoard(spaces, p1WinningBoard-1, player1);
                drawboard(spaces);
                
                // Check if Player 1 won the global game
                if (checkWinner(spaces, player1, player2)) {
                    std::cout << "Player " << player1 << " wins the game!\n";
                    running = false;
                    break;
                }
            }
            
            // Check for a global tie
            if (pcheckTie(N)) {
                std::cout << "The game is a tie!\n";
                running = false;
                break;
            }
            
            // Player 2's turn
            std::cout << "Player " << player2 << "'s turn\n";
            player2Move(N, player2);
            drawBoard(N);
            
            // Check if Player 2 won a local board
            auto [p2Wins, p2WinningBoard] = checkPWinnerloc(N, player2);
            if (p2Wins) {
                std::cout << "Player " << player2 << " wins local board " << p2WinningBoard << "!\n";
                updateLocalBoard(N, p2WinningBoard-1, player2);
                updateChiefBoard(spaces, p2WinningBoard-1, player2);
                drawboard(spaces);
                
                // Check if Player 2 won the global game
                if (checkWinner(spaces, player1, player2)) {
                    std::cout << "Player " << player2 << " wins the game!\n";
                    running = false;
                    break;
                }
            }
            
            // Check for a global tie
            if (pcheckTie(N)) {
                std::cout << "The game is a tie!\n";
                running = false;
                break;
            }
        }
    } else if (ch == 2) {
        // Player vs Computer mode
        while (running) {
            // Player's turn
            std::cout << "Your turn (Player " << player << ")\n";
            playerMove(N, player);
            drawBoard(N);
            
            // Check if Player won a local board
            auto [playerWins, playerWinningBoard] = checkPWinnerloc(N, player);
            if (playerWins) {
                std::cout << "You win local board " << playerWinningBoard << "!\n";
                updateLocalBoard(N, playerWinningBoard-1, player);
                updateChiefBoard(spaces, playerWinningBoard-1, player);
                drawboard(spaces);
                
                // Check if Player won the global game
                if (checkWinner(spaces, player, computer)) {
                    std::cout << "Congratulations! You win the game!\n";
                    running = false;
                    break;
                }
            }
            
            // Check for a tie
            if (checkTie(N)) {
                std::cout << "The game is a tie!\n";
                running = false;
                break;
            }
            
            // Computer's turn
            computerMove(N, computer);
            drawBoard(N);
            
            // Check if Computer won a local board
            auto [computerWins, computerWinningBoard] = checkCWinnerloc(N, computer);
            if (computerWins) {
                std::cout << "Computer wins local board " << computerWinningBoard << "!\n";
                updateLocalBoard(N, computerWinningBoard-1, computer);
                updateChiefBoard(spaces, computerWinningBoard-1, computer);
                drawboard(spaces);
                
                // Check if Computer won the global game
                if (checkWinner(spaces, player, computer)) {
                    std::cout << "Computer wins the game!\n";
                    running = false;
                    break;
                }
            }
            
            // Check for a tie
            if (checkTie(N)) {
                std::cout << "The game is a tie!\n";
                running = false;
                break;
            }
        }
    } else if (ch == 3) {
        smileEmoji();
        std::cout << "THANKS FOR PLAYING!!\n";
    }
    
    return 0;
}

void playerMove(char *N, char player) {
    int localBoard, position;
    bool validMove = false;
    
    while (!validMove) {
        std::cout << "Choose a local board (1-9): ";
        std::cin >> localBoard;
        
        if (localBoard < 1 || localBoard > 9) {
            std::cout << "Invalid board selection. Please choose a board between 1 and 9.\n";
            continue;
        }
        
        // Convert to 0-indexed
        localBoard--;
        
        // Check if this local board has already been won
        if (localBoardWon[localBoard]) {
            std::cout << "This board has already been won. Please choose a different board.\n";
            continue;
        }
        
        // Calculate the starting index for this local board
        int startRow = (localBoard / 3) * 3;
        int startCol = (localBoard % 3) * 3;
        
        std::cout << "Choose a position within this local board (1-9): ";
        std::cin >> position;
        
        if (position < 1 || position > 9) {
            std::cout << "Invalid position. Please choose a position between 1 and 9.\n";
            continue;
        }
        
        // Convert to 0-indexed
        position--;
        
        // Calculate row and column within the local board
        int row = position / 3;
        int col = position % 3;
        
        // Calculate absolute position in the nested board
        int index = (startRow + row) * 9 + (startCol + col);
        
        if (N[index] == ' ') {
            N[index] = player;
            validMove = true;
        } else {
            std::cout << "Position already taken. Choose another position.\n";
        }
    }
}

// Player 1 move function (for PvP mode)
void player1Move(char *N, char player1) {
    playerMove(N, player1);
}

// Player 2 move function (for PvP mode)
void player2Move(char *N, char player2) {
    playerMove(N, player2);
}

// Computer move function
void computerMove(char *N, char computer) {
    std::cout << "Computer's turn...\n";
    
    // Simple AI: just choose a random valid move
    bool validMove = false;
    
    while (!validMove) {
        // Choose a random local board
        int localBoard = std::rand() % 9;
        
        // Skip boards that have already been won
        if (localBoardWon[localBoard]) {
            continue;
        }
        
        // Calculate the starting index for this local board
        int startRow = (localBoard / 3) * 3;
        int startCol = (localBoard % 3) * 3;
        
        // Choose a random position within the local board
        int position = std::rand() % 9;
        
        // Calculate row and column within the local board
        int row = position / 3;
        int col = position % 3;
        
        // Calculate absolute position in the nested board
        int index = (startRow + row) * 9 + (startCol + col);
        
        if (N[index] == ' ') {
            N[index] = computer;
            validMove = true;
            std::cout << "Computer chose local board " << localBoard + 1 << ", position " << position + 1 << ".\n";
        }
    }
}
