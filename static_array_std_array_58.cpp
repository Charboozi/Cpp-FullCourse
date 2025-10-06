#include <iostream>

// std::array in C++
// ------------------
// - A container that wraps a fixed-size C-style array.
// - Size is known at compile time (e.g. std::array<int, 5>).
// - Provides member functions like .size(), .at(), .front(), .back().
// - Works with STL algorithms (e.g. std::sort(arr.begin(), arr.end())).
// - Cannot change size at runtime (use std::vector if you need resizing).
// - Safer and more feature-rich than raw C-style arrays.

#include <array>

#include <algorithm>
// works well with algorithms

// this is what you had to do with the old system, because we dont know size in compile time
// void PrintArray(int* array, unsigned int size){
//     for(int i = 0; i < size; i++){
//         array[i];
//     }
// }

template <std::size_t N> // this says to the program what the size of the array should be in compile time
// for each distinct size N you use (like for different size arrays), the compiler instantiates a separate version of PrintArray.

void PrintArray(std::array<int, N>& data){
    for(int i = 0; i < data.size(); i++){
        data[i];
    }
}

int main(){

    // old C-style as comparission
    int dataOld[5];
    dataOld[0] = 0;


    std::array<int, 5> data; // int array with 5 elements in size, zero-initialized
    std::array<int, 5> arr = {1, 2, 3, 4, 5}; // with initialized values

    data[0] = 2;
    data[4] = 1;

    // we can use STL algorithms with std::array because its a pre-built class, not a data structure
    data.begin(); // iterator of data, creates a pointer that points to first element. auto (in reality its: {std::array<int, 5>::iterator} but its long and ugly so we use auto)
    data.end(); // same but for end
    for(auto it = data.begin(); it != data.end(); it++){
        std::cout << *it << " "; // prints all values in array
    }
    std::cout << std::endl;
    // std::sort(data.begin(), data.end());

    data[6]; // direct access (no bounds check)
    //data.at(7); // bounds-checked access (throws exception if out of range)
    data.front();       // first element
    data.back();        // last element

    data.size(); // number of elements (always 5 here)
    data.empty(); // false if size > 0    

    for(int x : data){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::reverse(data.begin(), data.end()); // reverse array in place

    data.fill(7); // fills all elements with 7
    
    std::array<int, 5> arr2 = {9,9,9,9,9};
    data.swap(arr2);   // swaps contents with arr2

    // and more...
}