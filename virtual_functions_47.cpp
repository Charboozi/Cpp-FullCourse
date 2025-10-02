#include <iostream>

// virtual function cost memory because we have to create a table and go to the table everytime we need them
// but should be used, not that costly

class Entity{
    public:
        virtual std::string GetName(){ return "Entity"; }
        // virtual keyword tells the compiler to generate a vtable for this function so that if its overwritten you can point to the correct function 
};

class Player : public Entity{
    private:
        std::string m_Name;
    public:
        Player(const std::string& name) : m_Name(name) {}
        // tips: Pass string by const reference to avoid unnecessary copies and ensure it won't be modified

        std::string GetName() override { return m_Name; }
        // override keyword not necessary but should be done for readability and to prevent type errors, "this function has been overriden"
};

void PrintName(Entity* entity){
    // now you would think this point to the player object and would then pring "Charb" but it doesn't
    // it thinks its an entity object now so it will print "Entity"
    // this is because even if we are player we are calling the entities GetName function (player is also an entity)
    // we want c++ to know that it is a player calling and it should call players GetName() method
    // with virtual override of the GetName function, this will work
    std::cout << entity->GetName() << std::endl;
}

int main(){

    Entity* e = new Entity();

    PrintName(e); // e->GetName() same as (*e).GetName() shortcut for accessing a member with pointers
    // we dont have to manually dereference it first

    Player* p = new Player("Charb");
    PrintName(p);

    return 0;
}