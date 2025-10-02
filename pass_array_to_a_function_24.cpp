#include <iostream>

double getTotal(double prices[], int size);

int main(){

    double prices[] = {49.99, 15.67, 32.45, 56};
    int size = sizeof(prices) / sizeof(prices[0]);
    double total = getTotal(prices, size);

    std::cout << total << "$";

    return 0;
}
double getTotal(double prices[], int size){// the parameter prices[] is a pointer to the first element of an array, so we cant calculate the size of it, it doesent know the size because its just a pointer
    // even foreach loops needs to know the size the iterable data structure
    // THIS IS A SIZE AND POINTER ISSUE
    // when a array is in a function parameter it decays into a pointer to the first element of an array
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        total += prices[i];
    }

    return total;
}