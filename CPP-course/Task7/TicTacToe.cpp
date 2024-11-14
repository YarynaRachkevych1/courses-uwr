#include "TicTacToe.h"

void GameState::TicTacToe::move(std::string chosenField, char sign) {
    std::string a, b;
    int x, y;

    a = chosenField[0];
    b = chosenField[1];

    if (sign == 'X') {
        x = std::stoi(b) - 1;
        if (a == "a") {
            y = 0;
        } else if (a == "b") {
            y = 1;
        } else if (a == "c") {
            y = 2;
        }
    } else if (sign == 'O'){
        x = std::stoi(b);
        y = std::stoi(a);
    }

    emptyIndx[x][y] = "";
    board[x][y] = sign;
}

bool GameState::TicTacToe::someoneWin(char sign) {

    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == sign && board[i][1] == sign && board[i][2] == sign) {
            return true;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == sign && board[1][j] == sign && board[2][j] == sign) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign) {
        return true;
    }
    if (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign) {
        return true;
    }

    return false;
}


bool GameState::TicTacToe::isFull(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool GameState::TicTacToe::correctField(std::string chosenField) {
    bool found = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (emptyIndx[i][j] == chosenField) {
                found = true;
            }
        }
    }
    return found;
}