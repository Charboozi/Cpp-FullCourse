#include <iostream>

int main(){

    int x; // decleration
    int y = 6;
    x = 5; // assignment 

    std::cout << x << '\n';
    std::cout << y << '\n';

/////////////////////////////////////////////////////////////////////

    // INTEGER (whole number)
    int age = 21;
    int days = 7.5; // this will output 7 because inte cant store decimals, so it truncates the decimal
    // int is 4 bytes in size

    // DOUBLE (number including decimal)
    double price = 10.99;

    // CHAR (single character)
    char grade = 'A'; // important use single quotes ''
    char initial = 'CZ'; // this will return only Z, overflow warning because char can only store one character (1 byte)
    // a char gets treated as an int with ASCII values, 'C' = 67, 'Z' = 90
    // computer sees it in hexadecimal, 'C' > 0x43, 'Z' > 0x5A, 'CZ' -> 0x435A
    // 0x435A is in decimal 17242, a char can only hold one byte (0 - 255) so this is to much
    // so the compiler truncates the integer, keeping the lowest byte, 0x435A -> remove lowest byte = 0x5A
    // byte goes from big->lower->lower...

    // BOOLEAN (true or false)
    bool isStudent = true;
    // represented as int 0 or 1

    // STRING (objectthat represents a sequence of chars)
    std::string name = "Charbel"; // important to use double-quotes ""

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << '\n';

    return 0;
}