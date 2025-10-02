#include <iostream>

// sizeof() = determines the size in bytes of a:
//            variable, data type, class, object, etc.

int main(){

    std::string name = "Charbel Zeito"; // std::string in a object, so it will output the size of that object, NOT the size of the string
    // if you want length of string just do = name.length();

    int number = 5; // inte is 4 bytes

    double gpa = 2.5; // double is 8 bytes

    char grade = 'F'; // char is 1 byte

    bool student = true; // bool is 1 byte 

    char grades[] = {'A', 'B', 'C', 'D', 'F'}; // the size of THIS array is 5 bytes

    std::string students[] = {"ähre", "bähre", "shähre"}; // the size is the size of 3 std::string objects (24*3 = 72)

    int numbers[] = {3, 4, 5, 6, 7, 8, 9}; // (int * size of array = size of array in bytes (28)) EASY  

    std::cout << sizeof(grades)/sizeof(grades[0]) << '\n';
    // std::cout << sizeof(grades)/sizeof(char);
    // nice ways (both same) to get the size of an array

    return 0;
}