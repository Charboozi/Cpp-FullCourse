#include <iostream>

int main() {

    int students = 20;

    students = students + 1;
    students += 2;
    students++;

    students -= 2;
    students--;

    students = students * 2;
    students *= 2;

    students = students / 2;
    students /= 2; // remember if there is a decimal point it gets truncated, use double instead 

    int remainder = students % 2; // returns remainder after division of 2, if remainder is 0 its even, if its 1 its odd

    // ORDER
    // Parenthesis
    // multiplication & division
    // addition & subtraction

    return 0;
}