#include <iostream>

/*
    Member initializer lists provide a clean and efficient way to initialize class members.
    - For objects (like std::string, std::vector, or custom classes), they avoid the
      extra step of default construction followed by assignment, by constructing the
      member directly with the desired value.
    - For primitive types (like int or double), there is no real efficiency difference,
      but using initializer lists keeps the style consistent and avoids mistakes.
*/

class Entity{
    private:
        int m_Score;
        std::string m_Name;
    public:
        // initialize them in order, good practice
        Entity() : m_Score(0), m_Name("Unknown"){
            //m_Name = "Unknown"; not needed we already initialized member
        }

        Entity(const std::string& name) : m_Name(name){
            //m_Name = name; dont need this anymore
        }
        std::string GetName(){ return m_Name; }
};

int main(){

    Entity e0;
    Entity e1("Charb");

    std::cout << e0.GetName() << '\n';
    std::cout << e1.GetName() << '\n';

    return 0;
}