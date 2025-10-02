#include <iostream>
#include <cmath>

int main(){

    double x = 3.14;
    double y = 3.99;
    double z;

    z = std::max(x, y); // return max of two values
    z = std::min(x, y); // return min of two values

    //REQUIRES #include <cmath>
    z = pow(2, 3); // 2³
    z = sqrt(9); // √9
    z = abs(-3) // how far away are we from 0, returns 3
    z = round(x) // x rounded is 3
    z = ceil(x) // x rounded up is 4
    z = floor(y) // y rounded down is 3

    std::cout << z;

    return 0;
}