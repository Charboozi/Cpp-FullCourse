#include <iostream>

// Multiple Inheritance in C++:
// A class can inherit from more than one base class, e.g. `class C : public A, public B`.
// This allows C to use members of both A and B, but introduces complexity:
//  - Ambiguity: If both A and B define the same function or variable, the compiler won't
//    know which one to use unless you qualify it explicitly (e.g. A::foo vs B::foo).
//  - Diamond Problem: If A and B both inherit from the same base class, and C inherits
//    from both A and B, then C may contain two copies of that base class. This can cause
//    duplication, ambiguity, and bugs.
//  - To solve the diamond problem, use "virtual inheritance" when inheriting from
//    the common base (e.g. `class B : virtual public A`). This ensures only one copy
//    of A exists in the final derived class.
// Multiple inheritance should be used carefully; often interfaces (pure abstract classes)
// are a safer and cleaner alternative.

class CommonBaseClass{
public:
    int common_value;

    CommonBaseClass() : common_value(-99){}
    CommonBaseClass(int common_value) : common_value(common_value){}
};
class BaseClass1: virtual public CommonBaseClass{ // this (virtual inheritance) solves the diamond problem (see above)
    public:

        int value;

        BaseClass1() : CommonBaseClass(100) {}

        void function1(){
            std::cout << "Function1 BaseClass1" << std::endl;
        }
};
class BaseClass2: virtual public CommonBaseClass{
    public:

        int value;

        BaseClass2() : CommonBaseClass(200) {}

        void function1(){
            std::cout << "Function1 BaseClass2" << std::endl;
        }
};
class DerivedClass: public BaseClass1, public BaseClass2{ // problem: if derived class want to access the commonbaseclass, which way to go? baseclass 1 -or 2?
    // the problem is that it will call both base classes
    public:
        void function1(){
            BaseClass1::function1();
            //std::cout << "Function1 DerivedClass" << std::endl;
        }

        DerivedClass() : CommonBaseClass(999) {} // the derived class has to call the CommonBaseClass itself
};

int main() {

    DerivedClass derived;

    std::cout << "Common value: " << derived.common_value << std::endl; // this will output the default constructor of commonBaseClass (-99) nopt any of the base classes

    //derived.common_value = 10;

    // derrived.BaseClass1::value = 20;
    // derrived.BaseClass1::function1(); // now we know what BaseClass to call function1 on

    derived.function1();

    return 0;
}