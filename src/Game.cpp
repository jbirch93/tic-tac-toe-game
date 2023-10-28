#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Game.h"

void Game::drawBoard()
{
    //Loops through each element of board array and prints to user
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void Game::InputLoop() {
    int location; //variable for input choice location on board
    bool over = false; //holds whether user or CPU has won
    drawBoard();
    while (!over) { //loops through user input until user or computer has won
        std::cout << "Input: " << std::endl;
        while (true) {
            std::cin >> location;
            // Validate the input
            if (1 <= location && location <= 9) {
                break; // Valid input, exit the loop
            } else {
                std::cout << "Invalid input. Please enter a number from 1 to 9: ";
            }
        }
        //Switch statement to determine where to place the O on the board based on user input
        switch (location) {
            case 1:
                if (board[0][0] == "_") {
                    board[0][0] = "O";
                }
                break;
            case 2:
                if (board[0][1] == "_") {
                    board[0][1] = "O";
                }
                break;
            case 3:
                if (board[0][2] == "_") {
                    board[0][2] = "O";
                }
                break;
            case 4:
                if (board[1][0] == "_") {
                    board[1][0] = "O";
                }
                break;
            case 5:
                if (board[1][1] == "_") {
                    board[1][1] = "O";
                }
                break;
            case 6:
                if (board[1][2] == "_") {
                    board[1][2] = "O";
                }
                break;
            case 7:
                if (board[2][0] == "_") {
                    board[2][0] = "O";
                }
                break;
            case 8:
                if (board[2][1] == "_") {

                board[2][1] = "O";
                }
                break;
            case 9:
                if (board[2][2] == "_") {
                    board[2][2] = "O";
                }
                break;
            default: {
                std::cout << "Must enter a number 1-9";
                break;
            }
        }
        //If player win returns true, print message and exit loop
        if (didPlayerWin()) {
            over = true;
            std::cout << "Congratulations! You won the game!" << std::endl;
            drawBoard();
            break;
        }
        else if (isDraw()) {
            over = true;
            std::cout << "Game is a draw." << std::endl;
            drawBoard();
            break;
        }
        //Runs the computer selection function which just generates a random position and draws an X
        ComputerSelection(board);
        //If computer wins returns true print message and exit loop
        if (didCPUWin()) {
            over = true;
            std::cout << "Sorry! Computer wins!" << std::endl;
            drawBoard();
            break;
        }
        drawBoard(); //draws updated board on each iteration of loop
    }
}
//Function to allow computer to pick a spot on the board
void Game::ComputerSelection(std::string board[3][3])
{
    bool selected = false;
    srand(static_cast<unsigned int>(time(nullptr))); //seed
    while (selected == false) {
        int i = rand() % 3; //random value 0-2
        int j = rand() % 3; //random value 0-2
        //If board slot is empty, fill in an X
        if (board[i][j] == "_") {
            board[i][j] = "X";
            selected = true;
        }
    }
}
//function to check if player won
bool Game::didPlayerWin()
{
    //checks all combinations of 3 in a row and returns true if so
    if (board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O" ||  // Checks if 
        board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O" ||  // rows have
        board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "O" ||  // 3 in a row
        board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O" ||  // Checks if
        board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O" ||  // columns have
        board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O" ||  // 3 in a row
        board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O" ||  // Checks if diagonal
        board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O") {  // have 3 in a row
        return true;
    }
    else {
        return false;
    }
}
//Checks if game is a tie
bool Game::isDraw()
{
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != "_") {
                count++;
            }
        }
    }
    if (count == 9 && !didPlayerWin() && !didCPUWin()) {
        return true;
    }
    return false;
}
//function to offer menu, then play game, and play again if user chooses so
void Game::gameLoop()
{
    std::string play;
    std::cout << "===== TicTacToe =====" << std::endl;
    std::cout << "        Play?" << std::endl;
    std::cout << "         Yes" << std::endl;
    std::cout << "         No" << std::endl;
    std::cin >> play;
    while (play == "Yes") {
        resetBoard();
        std::cout << "Enter 1, 2, or 3 for the top row, 4, 5, 6 for the middle row, and 7, 8, 9 for the bottom row." << std::endl;
        InputLoop();
        std::cout << "Play again?" << std::endl;
        std::cin >> play;

    }
}
//function to check if computer won
bool Game::didCPUWin()
{
    //checks all combinations of 3 in a row and returns true if so
    if (board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X" ||  // Checks if 
        board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X" ||  // rows have
        board[0][2] == "X" && board[1][2] == "X" && board[2][2] == "X" ||  // 3 in a row
        board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X" ||  // Checks if
        board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X" ||  // columns have
        board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X" ||  // 3 in a row
        board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X" ||  // Checks if diagonal
        board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X") {  // have 3 in a row
        return true;
    }
    else {
        return false;
    }
}
//Sets board back to empty
void Game::resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = "_"; 
        }
    }
}
