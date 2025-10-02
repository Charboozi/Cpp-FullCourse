#include <iostream>

/*
    Abstract classes define a common interface but cannot be instantiated directly.
    They contain at least one pure virtual function (= 0), which forces derived
    classes to provide their own implementation. This is how C++ supports runtime
    polymorphism (same interface, different behaviors in subclasses).
*/

// this is an abstract class, we CAN'T create an instance of an abstract class
// if a class has one or more pure functions, it's an abstract class
class Shape{
    public:
        virtual double area() = 0; // this is a pure firtual function, nothing in it becaue a shape cant have area, no shape is named shape, its a collective word
        // now children classes can take area and give their own definition
};

class Square : public Shape{
    public:
        double side;

        Square(double side) : side(side){}

        double area() override {
            return side * side;
        }
        // if we didnt override here this would also be an abstract class
};

class Triangle : public Shape{
    public:
        double base;
        double height;

        Triangle(double base, double height) : base(base), height(height){}

        double area() override {
            return 0.5 * base * height;
        }
};

int main() {

    //Shape shape; cant make an instance of an abstract class

    // we can have shape pointers to children classes of the shape that are not abstract
    Shape* shapes[] = 
    {
        new Square(5),
        new Triangle(8, 10),
        new Square(7),
        new Triangle(3, 4)
    };

    for (int i = 0; i < 4; i++){
        std::cout << "Shape " << i << ": " << shapes[i]->area() << std::endl;
    } // we want a area member function in shape that the different shapes can utilize
      // but we want the different shapes to give their own deffinition of the area function
      // we dont want to have a definition of the area function in Shape object
      // we solve this with abstract classes and pure virtual functions

    return 0;
}