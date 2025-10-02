#include <iostream>

int main(){

    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    // std::istream& getline(std::istream& is, std::string& str, char delim);
    // Reads characters into str until delimiter {delim} is found
    // is -> the input stream (usually std::cin)
    // str -> the string that will recieve the characters
    // delim (optional) -> character t ostop at (default = '\n')

    std::cout << "Your name is " << name.length() << " characters long\n"; // returns amount of characters in string, including whitespace
    name.empty() ? std::cout << "You didn't enter your name" : std::cout << "Hello " << name << '\n'; // returns true if string is empty
    name.clear(); std::cout << "Hello " << name << "no? ok :(\n"; // clears string
    name.append("@gmail.com"); std::cout << "Your username is now " << name << '\n'; // add string to end of string
    std::cout << name.at(0) << '\n'; // display char in a index of the string
    name.insert(2, "!!"); std::cout << name << '\n'; // insert something to the n:th idex of the string, before the current n:th index
    std::cout << name.find('.') << '\n'; // returns the first index where a char is found
    name.erase(0, 3); std::cout << name << '\n'; // delete all chars between two indicies from string, end string is EXCLUSIVE(dont count with it)

    return 0;
}