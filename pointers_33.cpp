#include <iostream>

/*
    pointers = variable that stores a memory address of another variable
               sometimes it's easier to work with an address

    & address-of operator
    * derefernece operator
*/

int main(){

    std::string name = "Charbel";
    int age = 21;
    std::string freePizzas[5] = {"pizza1", "pizza2","pizza3","pizza4","pizza5"};

    std::string *pName = &name;
    int *pAge = &age;
    //std::string *pFreePizzas = &freePizzas; // an array is already an address to the first element of an array, no need to refernece the address with &
    std::string *pFreePizzas = freePizzas;

    std::cout << pName << '\n'; // returns address of name, pName stores the address of name
    std::cout << *pName << '\n'; // returns value of name, dereferences address, meaning it takes the value instead of the addess
    std::cout << *pAge << '\n';
    
    std::cout << freePizzas << '\n'; // address of freePizzas array
    std::cout << *freePizzas << '\n'; // value of first element of array
    std::cout << freePizzas[0] << '\n'; // exact same

    return 0;
}