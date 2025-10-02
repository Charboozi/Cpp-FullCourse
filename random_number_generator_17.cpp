#include <iostream>
#include <ctime>

// pseudo-random = NOT truly random (but close)

int main(){

    srand(time(NULL)); // sets a starting point for the random sequences
    // without this each run of rand() would be the same
    // our startingpoint is the current time, that way its always differents

    int num = (rand() % 6) + 1; // number between 1 - 6

    std::cout << num;

    return 0;
}