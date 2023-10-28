#ifndef GAME_H
#define GAME_H
#include <string>

class Game {
    public:
        std::string board[3][3] = {"_", "_", "_",
                                   "_", "_", "_",
                                   "_", "_", "_"};
        void drawBoard();
        void InputLoop();
        void ComputerSelection(std::string board[3][3]);
        bool didCPUWin();
        bool didPlayerWin();
        bool isDraw();
        void gameLoop();
        void resetBoard();
};

#endif