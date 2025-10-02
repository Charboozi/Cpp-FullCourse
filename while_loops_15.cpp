#include <iostream>

int main(){

    std::string name;

    while(name.empty()){
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name << '\n';

////////////////////////////////////////////////////////////////////////////////////

    int number;

    do{
        std::cout << "Enter a positive #: ";
        std::cin >> number;
    }while(number < 0);

    std::cout << "The # is: " << number;

    return 0;
}