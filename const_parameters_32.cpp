#include <iostream>

/*
    const parameter = parameter that is effectively read-only
                      code is more secure & conveys intent
                      useful for references and pointers
*/

void printInfo(const std::string name, const int &age);

int main(){

    std::string name = "Charbel";
    int age = 21;

    printInfo(name, age);

    return 0;
}

void printInfo(const std::string name, const int &age){
    // some idiot trying to change the values (as an example)
    //name = " "; // we would get error because we shouldn't be able to change it
    //age = 0; 
    // even more important with pass by reference, we dont want anyone to change the original variables.

    std::cout << name << '\n';
    std::cout << age << '\n';
}