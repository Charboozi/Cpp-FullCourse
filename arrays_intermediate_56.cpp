#include <iostream>

int main(){

    int example[5]; // allocated memory for 5 integers on the stack
    int* ptr = example; // example is the same as &example[0]
    
    int* another = new int[5]; // allocated memory for 5 integers on the heap
    // exact same as int example[5]; except for the lifetime, it wont get destoyed untill you destrow it with delete[]
    delete[] another; // free the memory allocated on the heap, avoid memory leak

    example[0] = 2; // first element
    example[4] = 4; // last element

    example[2] = 6;
    *(ptr + 2) = 6; // exact same as example[2] = 6;
    // moves the pointer 2 integers forward in memory since its an int pointer, then dereferences it to assign the value 6 
    *(int*)((char*)ptr + 8) = 6; // moves the pointer 8 bytes forward in memory since its a char pointer, then dereferences it to assign the value 6
    // this is the same as example[2] = 6; because each int is 4 bytes, so moving 8 bytes is the same as moving 2 integers
    // now we can be more specific with the bytes we want to manipulate if we wanted to (dont do this)

    //example[5] = 6; // oops, we only allocated memory for 5 integers
                    // this is undefined behavior, could be anything
                    // program might crash, might work fine, might overwrite
                    // other important data in memory

    for (int i = 0; i < 5; i++)// < 5 is the conventional way of doing it because arrays are 0 indexed and <= 4 is a bit confusing 
    {
        example[i] = 2;
    }
    // example is an int pointer to the first element in the array
    // in memory, int* example ->: 02 00 00 00 | 02 00 00 00 | 02 00 00 00 | 02 00 00 00 | 02 00 00 00
    // index:        0            1            2            3            4

    return 0;
}