#include <iostream>

/*
    constuctor = special method that is automatically called when an object is instantiated
                 useful for assigning values to attributes as arguments
*/

class Student{
    public:
        std::string name;
        int age;
        double gpa;

    Student(std::string name, int age, double gpa){
        this->name = name; // this objects name equals the name parameter
        this->age = age; // {this} keyword is only used to explicitly say MY age because the parameter has the same name
        this->gpa = gpa;
    }
    /* same but another way   
    Student(std::string x, int y, double z){
        x = name;
        y = age;
        z = gpa;
    }
    */
};

int main(){

    Student student1("Spoongebob", 25, 3.2); 

    std::cout << student1.name << '\n';
    std::cout << student1.age << '\n';
    std::cout << student1.gpa << '\n';

    return 0;
}