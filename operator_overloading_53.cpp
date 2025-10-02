#include <iostream>

// Operator Overloading in C++:
// -----------------------------
// - Lets you define how operators (+, -, ==, <<, etc.) work for your own classes.
// - Makes objects behave more like built-in types, improving readability.
//
// Example: Overloading + for a Vector class
//   Vector a(1,2), b(3,4);
//   Vector c = a + b;  // calls operator+ we define
//
// Rules / Notes:
// - You can only overload existing operators (not invent new symbols).
// - At least one operand must be a user-defined type (class/struct).
// - Keep the meaning intuitive (e.g. + should feel like addition).
// - Syntax:
//     ReturnType operatorOP(const Type& rhs) { ... }
//   e.g. Vector operator+(const Vector& rhs);
//
// - Common overloads: +, -, ==, <, [], (), <<, >>
// - Avoid overusing it – use when it makes code more natural.

class Number{
public:
    int n;

    Number(int set_n){
        n = set_n;
    }

    Number operator+(const Number& numA){
        // std::cout << "this->n: " << this->n << std::endl; // 5 in this case
        // std::cout << "numA.n: " << numA.n << std::endl; // 10
        return Number(this->n + numA.n); // 15
        // return Number(0); we could do this, everytime we use + with this object it would then give us 0 which is stupid
    }

    bool operator==(const Number& numA){
        if(this->n == numA.n){
            return true;
        }else{
            return false;
        }
    }

    // this lets us use the + operator with our object
    // it wants a refernece to another object with type Number
    // then we add this n with numA.n to get sum
};

int main(){

    Number a(5);
    Number b(10);
    Number c = a + b;

    std::cout << "c.n: " << c.n << std::endl;

    if(a == c) std::cout << "a == c" << std::endl;
    else std::cout << "a != c" << std::endl;

    return 0;
}
