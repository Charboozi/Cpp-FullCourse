#include <iostream>

/*
    recursion = a programming technique where a function
                invokes itself from withing
                break a complex concept into a repeatable singe step

    (iterative vs recursive)

    advantages = less code ads is cleaner
                 useful for sorting and searching algorithms

    disadvantages = use more memory
                    slower
*/

// ITERATIVE
// void walk(int steps){
//     for(int i = 0; i < steps; i++){
//         std::cout << "You take a step\n";
//     }
// }

// RECURSIVE
void walk(int steps){
    if(steps > 0){
        std::cout << "You take a step\n";
        walk(steps - 1);
    }
}
// if you end up in a recursive infinite loop it will result in stack overflow
// because when we call functions it gets added to a call stack, that has limited size

int main () {

    walk(100);
    return 0;
}