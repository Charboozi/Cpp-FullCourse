#include <iostream>

/*
    struct = A structure that groups related variables under one name
             structs can contain many different datatypes
             variables in a struct are known as "members"
             members can be accessed with . "Class Member Access Operator"

    an array can store multiple values of one datatype
    a struct can store multiple values of many datatypes 
*/

struct student{
    std::string name;
    double gpa;
    bool enrolled;
};


int main(){

    student student1;
    student1.name = "Charbel";
    student1.gpa = 3.2;
    student1.enrolled = true;

    std::cout << student1.name << '\n';
    std::cout << student1.gpa << '\n';
    std::cout << student1.enrolled << '\n';

    return 0;
}