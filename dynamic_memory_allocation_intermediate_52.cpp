#include <iostream>

// Memory management in C++ vs C:
//
// C-style (manual, no constructors/destructors):
//   void* malloc(size)   -> allocates raw memory (uninitialized).
//   void* calloc(n, size)-> allocates raw memory, zero-initialized.
//   free(ptr)            -> releases memory allocated by malloc/calloc.
//   - malloc/calloc do NOT call constructors.
//   - free does NOT call destructors.
//
// C++ style (type-safe, supports constructors/destructors):
//   new T                -> allocates memory and calls T's constructor.
//   new T[n]             -> allocates array and calls each element's constructor.
//   delete ptr           -> calls destructor, then frees memory.
//   delete[] ptr         -> calls destructor for each element, then frees memory.
//   - new/delete are type-aware and safer than malloc/free.
//   - Always match new ↔ delete, new[] ↔ delete[].
//
// General rule: In C++, prefer new/delete (or better: smart pointers & containers)
// instead of malloc/calloc/free, unless interfacing with legacy C libraries.

class Student{
public:
    std::string name;

    void print(){
        std::cout << name << std::endl;
    }

    Student(std::string name) : name(name){}
};

int main(){

    int x = 4; // on the stack, will be freed automatically when function ends

    int* ptr_to_int = new int(5); // allocates space for an int on heap, ptr points to that space, needs to be freed manually with delete
    //*ptr_to_int = 5; same as above

    std::cout << "ptr_to_int: " << ptr_to_int << std::endl;
    std::cout << "ptr_to_int: " << *ptr_to_int << std::endl;

    // ptr_to_int = new int(10); // problem: we didn't free the previous memory allocated, now we point to another space in memory, memory leak!

    delete ptr_to_int;

    double* array = new double[4]; // will allocate memory for 4 double values (a dynamic array)

    array[0] = 5;
    array[1] = 6;
    array[2] = 7;
    array[3] = 8;

    for (int i = 0; i < 4; i++)
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
    
    delete[] array; // free block of memory, free the entire arrays allocated memory

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // malloc() calloc() free() we can use these, the difference is the new operator will call the constructor for the object when memory is allocated for it
    // delete works the same way butr with the destructor instead
    Student* student = new Student("Mary");
    (*student).name = "John"; // we put the parentheses to ensure that the derefernece occurs before the dot operator is applied  
    (*student).print(); // where accessing the object on the heap

    student->name = "Mary"; // exact same as before but cleaner and more readable
    student->print(); // use this way instead of the (*student) way


    delete student;

// WAYS TOI HANDLE MEMORY ALLOCATION ERRORS
    try {
        size_t n = 1000000000000; // ~1 trillion (depends on your RAM/OS limits)
        double* big_array = new double[n]; // runtime request
        delete[] big_array;
    }
    catch (std::bad_alloc& exp) {
        std::cout << "bad_alloc caught: " << exp.what() << std::endl;
    }

    size_t m = 1000000000000; // another huge request
    double* big_again = new(std::nothrow) double[m]; // if its too big it will point to null
    if (big_again == nullptr) {
        std::cout << "Failed to allocate again" << std::endl;
    } else {
        delete[] big_again;
    }

    // here we are reusing the existing allocated memory, prevent memory leaks
    // its called "placement new"
    double* mydouble = new double(12.2);
    double* specific = new(mydouble double(20.5);)


    return 0;
}

    // ---- VISUALIZATION ----
    //
    // STACK (automatic storage, freed when function ends)
    // -----------------------------------------------------
    // | array (ptr)      | --> points to HEAP block [5,6,7,8]
    // | ptr_to_int (ptr) | --> (after delete, dangling: old heap freed)
    // | x                | 4
    // -----------------------------------------------------
    //
    // HEAP (manual allocation, must free with delete/delete[])
    // -----------------------------------------------------
    // | [5]              | (allocated by new int(5), freed by delete)
    // | [5][6][7][8]     | (allocated by new double[4], freed by delete[])
    // -----------------------------------------------------
    
    // NOTES:
    // - Stack memory is automatically freed when function ends.
    // - Heap memory must be manually freed using delete/delete[].
    // - Pointers live on the stack, but what they point to lives on the heap.