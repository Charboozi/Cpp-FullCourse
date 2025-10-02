#include <iostream>

int main(){

    std::string cars[] = {"Corvette", "Mustang", "Camry"}; // valid, we essentially set size to 3 implicitly

    std::cout << cars << '\n'; // you will get the memory address of the begining of the array

    std::cout << cars[1] << '\n';

    cars[0] = "Camaro"; // change first element of array to Camaro

    std::cout << cars[0] << '\n'; 

/////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::string cars_[3]; // array is a static datatype that we need to set size of on initialization
    // now we have 0, 1, 2 slots open in cars_

    cars_[0] = "Camaro";
    cars_[1] = "Ferrari";
    cars_[2] = "Volvo";

    std::cout << cars_[2];

    //std::cout << cars_[5]; // out of bounds!
    // C++ raw arrays don't do bounds checking so be careful

    return 0;
}