#include <iostream>

int main(){

    int month;
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    switch(month){
        case 1:
            std::cout << "It's January";
            break;
        case 2:
            std::cout << "It's February";
            break;
        default:
            std::cout << "Skitsamma";
    }

    return 0;
}