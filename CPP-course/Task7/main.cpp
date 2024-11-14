#include <iostream>
#include <array>
#include <list>
#include <random>
#include "TicTacToe.h"
namespace draw{
    void drawBoard(char brd[3][3]){
        std::cout << "   | a | b | c" << std::endl;
        std::cout << "---+---+---+---" << std::endl;
        std::cout << "1  | " << brd[0][0] << " | " << brd[0][1] << " | " << brd[0][2] << std::endl;
        std::cout << "---+---+---+---" << std::endl;
        std::cout << "2  | " << brd[1][0] << " | " << brd[1][1] << " | " << brd[1][2] << std::endl;
        std::cout << "---+---+---+---" << std::endl;
        std::cout << "3  | " << brd[2][0] << " | " << brd[2][1] << " | " << brd[2][2] << std::endl;
    }
}

namespace computer {
    std::string computerChoice(char brd[3][3]) {
        std::list<std::pair<int, int>> emptyIndx;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (brd[i][j] == ' ') {
                    emptyIndx.emplace_back(j, i);
                }
            }
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, emptyIndx.size() - 1);

        auto it = emptyIndx.begin();
        std::advance(it, dis(gen));

        std::string pairStr = std::to_string(it->first) + std::to_string(it->second);

        return pairStr;
    }

    std::string printChoice(std::string pairStr){
        std::string x, y, a;
        int b;
        x = pairStr[0];
        y = pairStr[1];
        b = std::stoi(y) + 1;
        if (x == "0") {
            a = "a";
        } else if (x == "1") {
            a = "b";
        } else if (x == "2") {
            a = "c";
        }
        return a + std::to_string(b);
    }
}


int main() {
    GameState::TicTacToe ticTacToe;

    draw::drawBoard(ticTacToe.board);

    bool playerWin = false;
    bool computerWin = false;
    std::string chosenField;

    while (true) {
        std::cout << " Podaj numer pola: ";
        std::cin >> chosenField;

        while (!ticTacToe.correctField(chosenField)) {
            std::cout << "Bledny numer pola, podaj inny: ";
            std::cin >> chosenField;
        }

        ticTacToe.move(chosenField, 'X');

        playerWin = ticTacToe.someoneWin('X');
        if (playerWin || ticTacToe.isFull()){
            draw::drawBoard(ticTacToe.board);
            break;
        }

        std::string chosenFieldc = computer::computerChoice(ticTacToe.board);
        std::cout << "Komputer wybral: " << computer::printChoice(chosenFieldc) << std::endl;

        ticTacToe.move(chosenFieldc, 'O');

        draw::drawBoard(ticTacToe.board);

        computerWin = ticTacToe.someoneWin('O');
        if (computerWin || ticTacToe.isFull()){
            break;
        }

    }

    if (playerWin) std::cout << "Gracz wygral!" << std::endl;
    else if (computerWin) std::cout << "Komputer wygral!" << std::endl;
    else std::cout << "Remis!" << std::endl;
    return 0;
}
