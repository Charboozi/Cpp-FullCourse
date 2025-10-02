#include <iostream>

/*
    Null value = a special value that means something has no value.
                 When a pointer is holding a null value,
                 that pointer is not pointing at anything (null pointer)

    nullptr = keyword represents a null pointer literal

    nullptrs are helful when determining if an address
    was successfully assigned to a pointer

    when using pointers, be careful that your code isn't
    dereferencing nullptr or pointing to free memory
    this will cause undefined behaviour
*/

int main(){

    int *pointer = nullptr; // good practice to say, this pointer is not pointing to anything, if we dont set it right away
    // we dont want it to point to a random value, that can cause issues

    int x = 123;

    // *pointer; // dereferencing a null pointer can lead to undefined behaviour, so checkbefore doing anything
    // also dereferencing a pointer that is not assigned any value can also lead to undefined behaviour

    pointer = &x;

    if(pointer == nullptr){
        std::cout << "Did not successfully assign addres\n";
    }else{
        std::cout << "Address was assigned\n";
        std::cout << *pointer; // safe to access now
    }

    return 0;
}