#include <iostream>

// foreach loop = loop that eases the traversal over an
//                   iterable data set (e.g. and array)

int main(){

    std::string students[] = {"ahre", "bahre", "shahre", "Charbel", "bitchen"};

    for(std::string student : students) // for each student in students
    {
        std::cout << student << '\n';
    }
    

    return 0;
}