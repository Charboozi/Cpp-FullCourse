#include <iostream>

/*
    A normal destructor cleans up resources when an object goes out of scope or is
    explicitly deleted. It works fine when deleting objects directly, but if the
    class is intended for polymorphic use (deleted via a base pointer), the
    destructor should be declared virtual instead.

    base class = a class from which other classes are derived.
*/

class Number{
    private:
        double* number;
    
    public:
        Number(double num){
            number = (double *) malloc(sizeof(double)); // this allocates memory with size of a double and it returns a double pointer pointing to that memory, then we have a number variable pointing to that pointer (pointing to the same location)
            *number = num;
            std::cout << "Constructor executing!" << std::endl;
            std::cout << "Number: " << *number << std::endl << std::endl;
        }
        ~Number(){// destructor often times handle cleanup
            std::cout << "Destructor executing!" << std::endl;
            std::cout << "Number: " << *number << std::endl << std::endl;
            free(number);// give back memory when this object is destroyed, to avoid memory leak
        }
};

void test(){
    Number six(6);
}// six object destroyed when reaching end of scope

int main(){

    Number *five = new Number(5); // dynamically allocate memory for five object
    delete five; // delete five object to prevent memory leak

    test();

    Number seven(7);// calls constructor explicitly

    return 0;
} // when program is done, the destructor is called implicitly automatically, if its not destroyed/deleted yet