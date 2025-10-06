#include <iostream>

// ===================================================================================
// Lvalues vs Rvalues in C++
// -----------------------------------------------------------------------------------
// - An **lvalue** ("locator value") has an address in memory, you can take & of it.
//   Example: 
//      int x = 5;     // x is an lvalue (you can do &x)
//      std::string s; // s is an lvalue
//
// - An **rvalue** ("right-hand value") is a temporary object or literal with no 
//   persistent memory address (you cannot take & of it).
//   Example:
//      5            // literal, rvalue
//      x + 2        // result of expression, temporary, rvalue
//      std::string("hi") // temporary object, rvalue
//
// Assignment rule:
//   lvalue = rvalue;
//   (left side must be an lvalue, right side can be lvalue or rvalue)
//
// Special references:
//   - lvalue reference:    int& ref = x;         // binds to lvalues only
//   - const lvalue ref:    const int& ref = 5;   // can bind to rvalues too
//   - rvalue reference:    int&& ref = 5;        // can bind to rvalues (C++11)
// 
// Why care?
//   * Needed for efficient code (move semantics, perfect forwarding).
//   * Distinguishing between "named objects" (lvalues) and "temporaries" (rvalues).
//
// Quick examples:
//   int a = 10;     // a is lvalue, 10 is rvalue
//   int b = a;      // b is lvalue, a is lvalue (but used as rvalue here)
//   int&& c = 20;   // c binds to rvalue 20
// ===================================================================================

int GetValue(){
    return 10;
}
int& GetAnotherValue(){
    static int value = 10;
    return value;
}

// works for both lvalue and rvalue
void PrintNameb(const std::string& name){
    std::cout << name << std::endl;
}

// lvalue refernece
void PrintNamel(std::string& name){
    std::cout << name << std::endl;
}

// rvalue reference
// this accepts only temporary objects
void PrintNamer(std::string&& name){
    std::cout << name << std::endl;
}
// this is useful for move semantic, we dont need to worry about
// maintaining the refernece, we just steal everything from it
// then we can throw it away, because its temporary

int main(){

    int i = 10; // i = lvalue, 10, rvalue
    // i has a place in memory
    // 10 is just a temporary value

    int a = i; // a and i is an lvalue

    int b = GetValue(); // GetValue() is an rvalue, temporarily returns value 10
    //GetValue() = 5; we cannot add anything to a rvalue, it has no place to store values
    GetAnotherValue() = 5; // now this works because GetAnotherValue() returns a reference to a real place in memory (an lvalue)

    std::string firstName = "Yan";
    std::string lastName = "Chernikov";

    std::string fullName = firstName + lastName; // lvalue = rvalue

    PrintNamel(fullName); // this obviously works
    PrintNamer(firstName + lastName); // here we give an rvalue as parameters, it works because we set PrintName to const
    // const refernece is a neat way of being able to take as refernece a rvalue
    // without the const, rvalues would not be able to be passed as a reference
    // if we really want to know if a value is an lvalue, we just do a non const refernece in a function
    // if its still possible to reference it, the its an lvalue else, its an rvalue

    return 0;
}

