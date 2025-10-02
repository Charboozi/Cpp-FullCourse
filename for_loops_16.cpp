#include <iostream>

int main(){

    for(int i = 1; i <= 3; i++){
        std::cout << "HAPPY NEW YEAR!\n";
    }// i increments after one loop cycle

/////////////////////////////////////////////////////////////////////////////

    // break = break out of a loop
    // continue = skip current iteration

    for(int i = 1; i <= 20; i++){
        if(i == 13){
            //break; // stop loop completely when i = 13
            continue; // skip number 13
        }
        std::cout << i << '\n';
    }

////////////////////////////////////////////////////////////////////////////////////

    int rows;
    int columns;
    char symbol;

    std::cout << "How many rows?";
    std::cin >> rows;

    std::cout << "How many columns?";
    std::cin >> columns;

    std::cout << "Enter a symbol:";
    std::cin >> symbol;

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            std::cout << symbol;
        }
         std::cout << '\n';
    }   

    return 0;
}