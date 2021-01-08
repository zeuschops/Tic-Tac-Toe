//
//  main.cpp
//  tic-tac-toe
//
//  Created by Austin on 1/8/21.
//

#include <iostream>
#include "string.h"
#include <vector>

int main(int argc, const char * argv[]) {
    //Tic-Tac-Toe single file work...
    std::vector<std::string> board;
    //default initialization of the board should be 1-9 inclusive, because we start counting at "1" or something..
    for(int i = 0; i < 9; i++) {
        board.push_back(std::to_string(i+1));
    }
    
    //Print out the board:
    for(int i = 0; i < board.size(); i++) {
        //Print data from vector/array
        std::cout << " " << board.at(i);
        if((i+1) % 3 == 0) { //Make it so we format the output lines during print
            std::cout << std::endl;
            if(i < 8) { //Make it so this line doesn't print on the last line of the application
                std::cout << "--- --- --- " << std::endl;
            }
        } else {
            std::cout << " |"; //Separate the numbers if this isn't the line we're outputting on :)
        }
        //std::cout << "Board at: " << i << " is " << board.at(i) << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    std::cout << "Do you want to be Xs or Os? (X or O)" << std::endl;
    std::cout << "> ";
    std::string xOrO;
    std::cin >> xOrO;
    std::string opponent;
    if(xOrO.compare("X") == 0 || xOrO.compare("x") == 0) {
        opponent = "O";
    } else if (xOrO.compare("O") == 0 || xOrO.compare("o") == 0){
        opponent = "X";
    }
    
    std::cout << "Where would you like to start? (1, 2, 3, ... ?)" <<std::endl;
    std::cout << "> ";
    std::string user_in;
    std::cin >> user_in;
    int user_position = std::stoi(user_in);
    std::string user_response_loc = board.at(user_position - 1);
    if(user_response_loc.compare("x") == 0 || user_response_loc.compare("X") == 0 || user_response_loc.compare("o") == 0 || user_response_loc.compare("O") == 0) {
        std::cout << "Space taken! Please choose another space to use:" << std::endl;
    } else {
        board.at(user_position - 1) = xOrO;
    }
    
    std::vector<int> remaining;
    std::string currentComparison;
    for(int i = 0; i < board.size(); i++) {
        currentComparison = board.at(i);
        if(!(currentComparison.compare("X") == 0 || currentComparison.compare("x") == 0 || currentComparison.compare("o") == 0 || currentComparison.compare("O") == 0)) { //should be flipped to board[i].compare(...) != 0 && board[i].compare(...) ...
            remaining.push_back(i);
        }
    }
    
    std::cout << "Board size: " << board.size() << std::endl;
    srand(time(0));
    std::cout << "Position to select: " << remaining.at(rand() % remaining.size()) << std::endl;
    
    //TODO: Build out game stuff and convert this code into methods.
    
    return 0;
}
