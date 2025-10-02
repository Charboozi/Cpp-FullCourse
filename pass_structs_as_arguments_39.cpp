#include <iostream>

struct Car{
    std::string model;
    int year;
    std::string color;
};

void paintCar(Car &car, std::string color);
void printCar(Car car);

int main(){

    Car car1;
    Car car2;

    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "red";

    car2.model = "Corvette";
    car2.year = 2021;
    car2.color = "blue";

    paintCar(car1, "silver");
    paintCar(car2, "gold");

    printCar(car1);
    printCar(car2);

    return 0;
}
void printCar(Car car){
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
}
// structs are passed by value by default, so you create a copy of struct car here
// its exactly as a normal variable, use & to pass by refernece

void paintCar(Car &car, std::string color){
    car.color = color;
}