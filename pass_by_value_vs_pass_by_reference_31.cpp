#include <iostream>

void swap(std::string &x, std::string &y);

int main(){

    std::string x = "Kool-Aid";
    std::string y = "Water";

    swap(x, y);

    std::cout << "X: " << x << '\n';
    std::cout << "Y: " << y << '\n';

    return 0;
}

void swap(std::string &x, std::string &y){
    // if we pass by value, meaning we dont access the memory addresses
    // of the actuall variables, we just make copies of them in the function
    // that wont affect the actuall variables in main
    // copies have different memory addresses, completely different variables
    // pass by value only gets a copy of the value to the function
    // pass by reference instead!! (&)
    std::string temp;

    temp = x;
    x = y;
    y = temp;

    // with pass by refernece (&) we store the acuall addresses
    // of the variables in main and them manipulate them.
}