#include <iostream>

    // condition ? expression1 : expression2;

int main(){
    
    int grade = 75;

    grade >= 50 ? std::cout << "You Passed!" : std::cout << "You failed!";

    return 0;
}