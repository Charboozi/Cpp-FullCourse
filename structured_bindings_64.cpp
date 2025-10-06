#include <iostream>
#include <vector>
#include <algorithm> // for std::sort, std::find, std::minmax, etc.
#include <tuple>     // for tuple bindings
#include <utility> // for std::pair
#include <string>

// -----------------------------------------------------------------------------
// STRUCTURED BINDINGS (C++17 feature)
// -----------------------------------------------------------------------------
//
// Structured bindings let you **unpack** multiple values from
// tuples, pairs, arrays, or structs *directly into variables*.
//
// Instead of writing:
//     auto p = std::make_pair(1, 2);
//     int a = p.first;
//     int b = p.second;
// You can write:
//     auto [a, b] = p;
//
// -----------------------------------------------------------------------------

// A simple struct for demonstration
struct Point {
    int x;
    int y;
};

// A more complex struct with private members and a getter tuple
struct Person {
    std::string name;
    int age;
};

int main(){

    // BASIC USAGE WITH std::pair
    std::pair<int, std::string> data = {1, "Hello"};

    // Unpack both elements:
    auto [id, text] = data;
    std::cout << id << " " << text << "\n"; // 1 Hello

    return 0;
}