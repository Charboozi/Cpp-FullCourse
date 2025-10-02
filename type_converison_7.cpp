/*
    type conversion = convert a value of one data type to another
                      Implicit = automatic
                      Explicit = Precede value with new data type (int)
*/

#include <iostream>

int main(){

    double x = (int)3.14; // first converts 3.14 to an int (3) and then stores it in a double (still 3)

    char x = 100; // this will be letter 'd', it Implicitly casts int 100 to a ASCII value 100 = 'd'

    return 0;
}