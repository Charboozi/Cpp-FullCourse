#include <iostream>
#include <cstring>

// ===================================================================================
// Move Semantics in C++ (C++11 and later)
// -----------------------------------------------------------------------------------
// - Normally, objects are copied when assigned or passed around.
//   Example: std::string a = "Hello"; std::string b = a; // copy, expensive
//
// - Move semantics allow resources (like heap memory, file handles, buffers) 
//   to be transferred from one object to another *without copying*.
//
// - Uses rvalue references (T&&) to detect temporaries.
//   Example: 
//       std::string str = "Hello";
//       std::string moved = std::move(str); // move constructor
//       // 'moved' now owns the buffer, 'str' is left empty/valid but unspecified
//
// - Key parts:
//     * Move constructor:    T(T&& other) noexcept
//     * Move assignment:     T& operator=(T&& other) noexcept
//
// - Why? Efficiency!
//     * Copying large objects (e.g., vectors, strings) is expensive.
//     * Moving just steals pointers instead of duplicating data.
//
// - Rule of thumb:
//     * Use std::move() when you want to treat an lvalue as an rvalue 
//       (e.g., passing to a function that takes T&&).
//     * After moving from an object, it is still valid, but its content 
//       is unspecified (don’t rely on it).
//
// Example:
//   std::vector<int> v1 = {1,2,3,4};
//   std::vector<int> v2 = std::move(v1); // v2 takes ownership of data
//   // v1 is now empty (but still a valid vector)
//
// ===================================================================================

class String
{   
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    // move operator instead of copying
    String(String&& other) noexcept // cant be const!! we want to modify the old object
    {
        printf("Moved!\n");
        // point to the same string as the other
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        // rip everything from the old string
        // we created a hollow object
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    ~String()
    {
        printf("Destroyed\n");
        delete[] m_Data; // now this will delete nullptr instead of the object we moved to
    }

    void Print()
    {
        for(uint32_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }
private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    
    Entity(const String& name) : m_Name(name)
    {}

    Entity(String&& name) : m_Name((String&&)name) // cast name to a temporary so it moves instead of copies
    {} // actually we should write m_Name(std::move(name)) which does almost the same thing

    void PrintName()
    {
        m_Name.Print();
    }
private:
    String m_Name;
};

int main(){

    Entity entity(String("Cherno"));
    entity.PrintName(); 

    return 0;
}