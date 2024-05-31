#include "Puzzle.h"

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> predefined_puzzles = {
    "!#!&%*&@&!@&!!@#!@$$**%!&!&&!##&#*@$&@$%%$$*&*@$##$#@$%@#$&#%$@#",
    "#!%%@%!&@*%!&@&!#*$$%%%&#*$#@$@!$%$@%@&!%$&%&@*%*$&&*&#!$$&*$#*!",
    "*@&*@#%%&%%&!$!*%#%*!*##*$$###*$$!#&&@*$$@#&#$&$$#!!!**@##@@@!!!",
    "$#@!%@$#$&$&!!*@@!$$@$!&*@**&$&@$!#*@&*@&###!@@%&@&!%&&%##$#@@&$",
};

int getInput() {
    int user_input;
    std::cout << "<<< BEJEWELED >>>\n" << std::endl;
    std::cout << "[1] Start a new random puzzle\n" << std::endl;
    std::cout << "[2] Start a pre-defined puzzle\n" << std::endl;
    std::cout << "[3] Exit\n" << std::endl;
    std::cout << ">Choose a menu option (1~3): ";
    std::cin >> user_input;
    return user_input;
}

int getIndex() {
    int static_index;
    std::cout << ">Choose a puzzle number (0~3): ";
    std::cin >> static_index;
    return static_index;
}

int checkGetInput(int userInput) {
    if (userInput == 1) {
        return 1;
    } else if (userInput == 2) {
        return 2;
    } else if (userInput == 3) {
        exit(0);
    } else {
        return checkGetInput(getInput());
    }
}

int checkStaticIndex(int userInput) {
    if (userInput >= 0 && userInput <= 3) {
        return userInput;
    } else {
        return checkStaticIndex(getIndex());
    }
}

void printPuzzle(const Puzzle& puzzle) {
    int numRows = puzzle.getNumRows();
    int numCols = puzzle.getNumColumns();

    std::cout << "   0 1 2 3 4 5 6 7\n";
    std::cout << "  +---------------\n";
    for (int i = 0; i < numRows; ++i) {
        std::cout << i << " |";
        for (int j = 0; j < numCols; ++j) {
            Jewel jewel = puzzle.getJewel({i, j});
            char jewelChar = puzzle.getJewelLetter(jewel);
            std::cout << jewelChar << ' ';
        }
        std::cout << std::endl;
    }
}

Puzzle initialize() {
    Puzzle puzzle(8, 8);
    int userInput = checkGetInput(getInput());
    if (userInput == 1) {
        puzzle.randomize();
    } else {
        puzzle.initialize(predefined_puzzles[checkStaticIndex(getIndex())]);
    }

    return puzzle;
}

void randomize(Puzzle& puzzle) {
    puzzle.randomize();
}

void update(Puzzle& puzzle) {
    puzzle.update();
}

bool swap(Puzzle& puzzle, int x1, int y1, int x2, int y2) {
    return puzzle.swapJewels({x1, y1}, {x2, y2});
}

int main() {
    Puzzle puzzle = initialize();

    while (true) {
        printPuzzle(puzzle);

        int x1, y1, x2, y2;
        std::cout << "Input the first swap position (row, col): ";
        std::cin >> x1 >> y1;
        std::cout << "Input the second swap position (row, col): ";
        std::cin >> x2 >> y2;
        std::cout << "\n\n\n";

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
            puzzle = initialize();
        } else {
            if (swap(puzzle, x1, y1, x2, y2)) {
                std::cout << "Swap successful!" << std::endl;
            } else {
                std::cout << "Swap failed!" << std::endl;
            }
            update(puzzle);
        }
    }
}
