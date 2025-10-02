#include <iostream>

/*
    object = A collection of attributes and methods
             They can have characteristics and could perform actions
             Can be used to mimic real world items (ex. Phone, Book, Dog)
             Created from a class wich acts as a "blue-print"
*/

class Human{
    public:
        std::string name = "Charbel";
        std::string occupation = "Scientist";
        int age = 23;

        void eat(){
            std::cout << "This person is eating\n";
        }
        void drink(){
            std::cout << "This person is drinking\n";
        }
        void sleep(){
            std::cout << "This person is sleeping\n";
        }
};

int main(){

    Human human1;
    Human human2;

    // human1.name = "Charbel";
    // human1.occupation = "Scientist";
    // human1.age = 23;

    // human2.name = "Zeito";
    // human2.occupation = "Bitch";
    // human2.age = 25;

    human1.name;
    human1.occupation;
    human1.age;

    human2.name;
    human2.occupation;
    human2.age;

    std::cout << human1.name << '\n';
    std::cout << human1.occupation << '\n';
    std::cout << human1.age << '\n';
    
    std::cout << human2.name << '\n';
    std::cout << human2.occupation << '\n';
    std::cout << human2.age << '\n';

    human1.eat();
    human1.drink();
    human1.sleep();

    return 0;
}