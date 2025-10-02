#include <iostream>

int main(){

    // string is a static data type, we can't change the size of it
    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);
    std::string temp;

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter a food you like or 'q' to quit #" << i << ": ";
        std::getline(std::cin, temp);
        if(temp == "q"){
            break;
        }else{
            foods[i] = temp;
        }
    }

    std::cout << "You like the following food:\n";


    // remember that the string is static, say we only add 3 foods to array
    // then there will be 5 - 3 = 2 spaces empty left, here we say:
    // if element is not empty, print the element, no empty string space
    for(int i = 0; !foods[i].empty(); i++){
        std::cout << foods[i] << '\n';
    }

    return 0;
}