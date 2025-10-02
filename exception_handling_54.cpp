#include <iostream>

// Exception Handling in C++
// --------------------------
// - Used to handle runtime errors without crashing the program.
// - Syntax: try { ... } catch(Type& e) { ... }
// - "throw" is used to signal an error, "catch" handles it.
// - Common exception: std::bad_alloc (thrown by new on memory failure).
// - Always catch exceptions by reference (e.g. catch(const std::exception& e)).
// - Example:
//     try {
//         riskyFunction();
//     } catch(const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

class custom_exception : public std::exception{
    // our own exception
    const char* what() const noexcept override{ 
        return "Custom Exception";
    }
    // The stuff after what() are function specifiers(like laws of the functions):
    // - const   → this function cannot modify member variables
    // - noexcept → this function will not throw exceptions
    // - override → this function overrides a virtual function in the base class
};

// the exception is going to go uppwards until it hits a catch block
// so we can nest like this
void myfunction2(){
    throw 5.6;
}
void myfunction1(){
    myfunction2();
}

int main(){

    std::string word = "four";

    // if an error occurs outside a try catch block, it will be an uncaught exception, BAD
    
    try
    {// code that might throw an exception, we want to check this code for errors
        //std::cout << word.at(4) << std::endl;
        
        //size_t n = 1000000000000; // 1 trillion ints (~8 TB on 64-bit)
        //int* big_array = new int[n]; // valid type, but impossible allocation

        // throw std::runtime_error("Some problem encountered!"); // calling our own exception(error)
        // throw custom_exception();
        //throw 20; // we can throw any value, but we need a cathc block that is looking for a inte type expression
        
        //throw 5.6;
        myfunction1(); // exact same
    }
    catch(const std::out_of_range& e)
    {// what to do if we catch an error
        std::cout << "Exception thrown!" << std::endl;
        std::cout << "First Catch: " << e.what() << std::endl; // e.what() method that tells us what happened
    }// program doesn't crash if we get an error
    catch(const std::bad_alloc& e)
    {
        std::cout << "Exception thrown!" << std::endl;
        std::cout << "Second Catch: " << e.what() << std::endl;
    }
    catch(const std::exception& e) // match for any type that is derived from it.(see below)
    {
        std::cout << "Exception thrown!" << std::endl;
        std::cout << "Default Exception Catch: " << e.what() << std::endl;
    }
    catch(const int& code)
    {
        std::cout << "Error Code: " << code << std::endl;
    }
    catch(...) // ... is a catch-all handler, catches ALL cases
    {// we should try to avoid these because we want to know exactly what the problem in the code is
        // can be used but be careful
        std::cout << "Default catch case!: " << std::endl;
    }

    return 0;
}

/*
Error classes:(exception is base class)

                    exception
            ------------------------------
            |            |               |
       logic_error   bad_alloc     runtime_error
            |
       out_of_range

if you write exception it will try to catch any of the derived class exception types
*/