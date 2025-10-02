#include <iostream>

int main(){

    std::string students[] = {"ahre", "bahre", "shahre", "Charbel"};

    for (int i = 0; i < sizeof(students)/sizeof(std::string); i++)
    {
        std::cout << students[i] << '\n';
    }
    

    return 0;
}