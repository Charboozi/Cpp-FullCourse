#include <iostream>
template <typename T, typename U> // important 
/*
    function template = describes what a function looks like.
    
                        Can be used to generate as many overloaded functions

                        as needed, each using different data types

                        similar to overloaded functions but more efficient
*/

// you can think of T as "Thing" becuase we dont know what data type its going to be yet
auto max(T x, U y){
    return (x > y) ? x : y;
}
// auto makes sure we can return any datatype (T or U)
// compiler will deduce what the return type should be

int main(){

    std::cout << max(1, 2.1) << '\n'; // we can add any value we want and the function will know what data type it is
    // but right now we can only pass in one kind of data type (only ints, only doubles etc.)
    // so lets add another template to fix this, (see above)

    return 0;
}