#include <iostream>

/*
    multiple functions with the same name can exist if they have different parameter lists
    They are not the same function, C++ chooses the correct function based on the parameter used 
*/

void bakePizza(){
    std::cout << "Here is your pizza\n";
}
void bakePizza(std::string topping1){
    std::cout << "Here is your " << topping1 << " Pizza!\n";
}
void bakePizza(std::string topping1, std::string topping2){
    std::cout << "Here is your " << topping1 << " and " << topping2 << " Pizza!\n";
}

int main(){

    bakePizza();
    bakePizza("pepperoni");
    bakePizza("pepperoni", "mushroom");

    return 0;
}
