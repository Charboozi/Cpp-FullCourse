/*
    typedef = reserved keyword used to create an additional name
              (alias) for another data type.
              New identifier for an existing type
              Helps with readability and reduces typos
              Use when there is a clean benefit only
              Replaced with 'using' (work better w/ templates)
*/ 

#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
// this just shows that we can simplify complex datatypes with typedef

typedef std::string text_t; // we basiclly rename a datatype to whatever we want, giving it an alias
using text_t = std::string; // this is better than typedef, its the same but works better with templates

int main() {

    //std::vector<std::pair<std::string, int>> pairlist; this would be unreadable
    pairlist_t pairlist; // exact same but, much more readable and clean

    //std::string firstName;
    text_t firstName = "Bro";

    std::cout << firstName << '\n';

    return 0;
}