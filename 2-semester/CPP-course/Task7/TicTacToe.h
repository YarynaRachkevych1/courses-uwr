#ifndef ZADANIE7_TICTACTOE_H
#define ZADANIE7_TICTACTOE_H

#include <string>
#include <list>

namespace GameState{
    class TicTacToe{
    public:
        std::string emptyIndx[3][3] = {"a1", "b1", "c1",
                                    "a2", "b2", "c2",
                                    "a3", "b3", "c3"};
        char board[3][3] = {' ', ' ', ' ',
                        ' ', ' ', ' ',
                        ' ', ' ', ' '};
        void move(std::string chosenField, char sign);
        bool someoneWin(char sign);
        bool isFull();
        bool correctField(std::string chosenField);
    };
}
#endif //ZADANIE7_TICTACTOE_H
