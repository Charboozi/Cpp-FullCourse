#include <iostream>

int main(){
    std::cout << "I like pizza!" << std::endl; // both lines are the same but endl will flush the output buffer
    std::cout << "It's really good!" << '\n';
    return 0;
}