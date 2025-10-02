#include <iostream>

/*
    enums = a user-defined data type that consists
            of paired named-integer constants.
            GREAT if you have a set of potential options

    its a integer but they are named, great for readability
*/

enum Day {sunday = 0, monday = 1, tuesday = 2};

int main(){

    Day today = sunday;

    switch(today){
        case sunday:
            std::cout << "It is Sunday!\n";
            break;
        case monday:
            std::cout << "It is Monday!\n";
            break;
        case tuesday:
            std::cout << "It is Tuesday!\n";
            break;
        default:
            std::cout << "WTF!\n";
    }

    return 0;
}