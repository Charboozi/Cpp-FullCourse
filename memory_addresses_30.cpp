#include <iostream>

/*
    memory address = a location in memory where data is stored
    a memory address can be accessed with & (address-of operator)
*/

int main(){

    std::string name = "Bro";
    int age = 21;
    bool student = true;

    std::cout << &name << '\n'; // 6422260
    std::cout << &age << '\n'; // 6422256 4 byte space ^
    std::cout << &student << '\n'; // 6422255 1 byte space ^

    return 0;
}