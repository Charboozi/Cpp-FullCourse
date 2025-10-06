#include <iostream>
#include <cstring>

// ===================================================================================
// std::move and the Move Assignment Operator
// -----------------------------------------------------------------------------------
//
// std::move
// ----------
// - std::move(x) does NOT actually move anything.
// - It performs a static_cast<T&&>(x), turning an lvalue 'x' into an rvalue (xvalue).
// - This allows functions/constructors with T&& parameters (move-enabled overloads) 
//   to be selected instead of the copy versions.
// - After std::move, the object 'x' is considered an "expiring" value, and you should
//   not use its contents except to assign to it or destroy it.
// - Example:
//       String a("Hello");
//       String b = std::move(a);   // calls move constructor
//       // 'a' is now valid but unspecified (likely empty).
//
// Move Assignment Operator
// -------------------------
// - Signature: T& operator=(T&& other) noexcept
// - Purpose: Reuse an existing object by *stealing* resources from another rvalue.
// - Steps (typical implementation):
//     1. Guard against self-move (if (this == &other) return *this;).
//     2. Release any current resources of *this (delete[] etc).
//     3. Transfer ownership of other's resources (pointer, size, etc).
//     4. Nullify 'other' so its destructor won’t free memory twice.
// - Efficiency: Unlike copy assignment (which duplicates memory), 
//   move assignment is O(1) because it just swaps pointers.
// - Example:
//       String a("Hello");
//       String b("World");
//       b = std::move(a);   // 'b' takes over 'a's memory
//       // 'a' is left in a valid but unspecified state.
//
// Rule of Thumb
// -------------
// - Use std::move() when you want to treat a named object as a temporary, so the 
//   move assignment (or move constructor) will be called instead of copy.
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
    {// takes in a temporary object
        printf("Moved!\n");
        // point to the same string as the other
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        // rip everything from the old string
        // we created a hollow object
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    // move assignment operator
    String& operator=(String&& other) noexcept 
    {
        printf("Moved!\n");

        if(this != &other) // prevent us from accedentaly moving to ourselves, which would lead to deleting the data
        {
            delete[] m_Data; // delete the current data of the object to recieve the new data from another object

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;
        // {this} is a pointer to the current object
        // *this return a reference to the current object
        // The function returns a reference to the current object (*this),
        // so that you can chain assignments like:
        // a = b = c;
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

    Entity(String&& name) : m_Name(std::move(name)) // cast name to a temporary so it moves instead of copies, use std::move!
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

    String string = "Hello";
    string.Print();
    //String dest((String&&)string); // this "string" needs to become a temporary to be able to be called by the move constructor
    String dest(std::move(string)); // better way to cast something to a rvalue (temporary value, &&value)
    // its a pre-built method that helps us cast it in a nice way what works for all types
    // this uses move constructor String(String&& other)
    // when creating a new object from an rvlaue

    String apple = "Apple";
    String newDest = "Orange";
    apple.Print();
    newDest.Print();
    apple = std::move(newDest);
    newDest.Print();
    apple.Print();
    // assigning into an existing object from an rvalue
    // this uses move assignment operator String& operator=(String&& other)
    
    //OBS: important destinction
    // dest = std::move(string);
    // this is not calling the = operator so no move assignment is being called
    // the move constuctor is being called here

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // String dest(string); // sidenote named variables are always lvalues, therefore this is &string and not conts char*
    // String(const char* string) only gets called when we pass in a C-style string literal

    return 0;
}