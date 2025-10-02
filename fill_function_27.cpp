#include <iostream>

// fill() = Fills a range of elements with a specified value
 //          fill(begin, end, value)

int main(){

    const int SIZE = 100;
    std::string foods[SIZE];

    fill(foods, foods + (SIZE/2), "pizza");// begining adress is foods (it points to the begining of the array), end adress is foods + size
    fill(foods + (SIZE/2), foods + SIZE, "Burgers");

    for (std::string food : foods){
        std::cout << food << '\n';
    }

    return 0;
}