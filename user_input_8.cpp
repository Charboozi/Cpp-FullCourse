#include <iostream>

// cout << (insertion operator)
// cin >> (extraction operator)

// cin skips spaces, tabs, and newlines, input stops at first space
// remember, when we click enter in terminal we actually add \n to the input buffer
// when we store anything from cin, it only takes the datatype
// EX: std::cin >> age; input buffer: 23\n -> cin stores 23 in age and in the inputbuffer the \n is still there



int main(){

    std::string name;
    int age;

    std::cout << "What's your age?: ";
    std::cin >> age; // after we do this, the inputbuffer still contains \n (see comment above)
    // we need to clear the buffer before using getline because getline gets the whole line untill \n and i \n is the first token, getline will return nothing

    std::cout << "What's your full name?: "; // the cin stops when encountering whitespace, this is bad for when typing a full name with spaces for example
    std::getline(std::cin >> std::ws, name); // use this to get the whole line, until \n
    // std::ws tells cin to skip any whitespaces or newlines, essentially clearing any unvalid token from the input buffer

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << " years old";

    return 0;
}