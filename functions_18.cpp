#include <iostream>

void happyBirthday(std::string name, int age){
    std::cout << "Happy birthday to " << name << '\n';
    std::cout << "Happy birthday to " << name << '\n';
    std::cout << "Happy birthday dear " << name << '\n';
    std::cout << "Happy birthday to " << name << '\n';
    std::cout << "You are " << age << " years old!" << '\n';
}

int main(){

    std::string name = "Charbel";
    int age = 23;

    happyBirthday(name, age); // call (invoke) function
    happyBirthday(name, age);
    happyBirthday(name, age);

    return 0;
}

// if you declare the function here, the main function wont know what it is
// then add this on top to define it:
// void happyBirthday();