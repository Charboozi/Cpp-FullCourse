#include <iostream>
#include <string>

/* all about strings

   array of characters
*/

// always do const and & because otherwise we do copyinmg unecessary, and also it should be read-only
void PrintString(const std::string& string){
    std::cout << string << std::endl;
}

int main(){

    //C-STYLE STRING
    const char* name = "Charboozi"; // the reason we use const is that strings are immutable, we dont want to change the string, its a fixed alocated block of memory
    // if you want a new string you need to delete the old string and allocate memory for a new one
    // but this isnt allocated in the heap, even tho there is a pointer, so you dont free the memory
    // rule of thumb: only free memory when using {new} keyword, (when allocating memory on the heap)
    // name[2] = 'b'; change the 3rd letter of name, use this only if string is NOT const
    // In memory: charptr -> 43 68 61 72 62 6F 6F 7A 69 00
    //       ASCII rep: 'C' 'H' 'A' 'R' 'B' 'O' 'O' 'Z' 'I' '/0'
    // /0 is a null terminator: determines the end of the string   
    // The string is stored in a read-only data segment(static/global memory)(the .rodata segment)
    // it exists there for the entire lifetime of the program
    // the pointer lives on the stack because its a local variable
    // the string literal lives in read-only static memory
    // that literal stays in memory until the program exits, no dangling pointer issue

    char name2[7] = {'C', 'h', 'e', 'r', 'n', 'o', '\0'};
    // this shows us that we need the \0 null terminator, if we printed the string without it
    // there would be random letters after the string, that we dont want.
    // the pointer doesn't know where the string should end
    
    //C++-STYLE STRING (what we should be using)
    // you should include header <string> for this (not always necessary tho)
    std::string namecpp = "Charboozi";
    // this is all we need to de because std::string class takes a const char* as argument, so it does it for us automatically
    namecpp.size(); // because its a class we can use builtin methods like size() instead of strlen(name)
    namecpp.length();// exactly the same as size()

    //std::string namecpp2 = "charb" + " hello!";
    //this doesn't work because they are 2 const char pointers, you cant add two pointers
    // do this instead:
    namecpp += " hello!";
    // std::string has a overload of hte += operator meant to append strings
    // looks something like this std::string& operator+=(const std::string&); or std::string& operator+=(const char* s); or std::string& operator+=(char c);
    // namecpp += " hello!"; this appends a C-style string
    // namecpp += std::string("something"); this appends a std::string
    // namecpp += '!'; this appends a char
    
    namecpp.find("booz"); // returns first index of substring booz, in this case 4
    bool contains = namecpp.find("booz") != std::string::npos; // this looks if we can find the substring in the main string
    // std::string::npos = means not found, so this says if NOT not found then return true, basically if we found something return true
    // quick OBS in c++ if we print a bool it returns the numerical 0 and 1 instead of alphabetical true and false

    std::cout << contains << std::endl;
    PrintString(namecpp);

    return 0;
}