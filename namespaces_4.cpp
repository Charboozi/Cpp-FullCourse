/*
    Namespaces = provides a solution for preventing name conflicts
                 in large projects. Each identity needs a unique name.
                 A namespace allows for identically named entities
                 as long as the namespaces are different.
*/

#include <iostream>

namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}

int main() {
    //using namespace first; // we are explicitly saying use "first" namespace instead of local
    using namespace std; // we dont need to include std anywhere if we do this, ex: std::cout -> cout
    // but dont do this! std has alot of keywords, so it is a high probability of a naming conflict if you do this
    // instead you could do using std::cout which says the exact same thing but only for cout

    int x = 0;

    // if we dont explicitly say what namespace we are using, its going to choose the local version
    std::cout << x << '\n';
    std::cout << first::x << '\n';
    std::cout << second::x << '\n';

    return 0;
}