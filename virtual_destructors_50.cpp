#include <iostream>

/*
    Virtual destructor ensures that when deleting an object through a base class
    pointer, the derived class's destructor is called too. Without it, only the
    base destructor would run, potentially causing resource leaks.
*/

class BaseData{
public:
    int *data;

    BaseData(int size){
        data = new int[size];
        std::cout << "BaseData constructor is running" << std::endl;
    }

    virtual ~BaseData(){
        std::cout << "BaseData destructor is running" << std::endl;
        delete data; // to avoid memory leak
    }
};

class DerivedData : public BaseData{
public:
    int *extra_data;

    DerivedData(int size, int extra_size) : BaseData(size){ // BaseData(size) = When constructing a DerivedData object, call the constructor of BaseData with size as argument, we must do this if base class doesn't have any default constuctors, it needs to set a parameter somehow
        extra_data = new int[extra_size];
        std::cout << "DerivedData constructor is running" << std::endl;
    }

    ~DerivedData() override {
        std::cout << "DerivedData destructor is running" << std::endl;
        delete extra_data;
    }
};

int main(){

    BaseData *array[] = 
    {
        new BaseData(5),
        new DerivedData(4, 4)
    }; // if the destructors aren't virtual, only the base class destructor will be running for both objects when they are deleted
    // remember from firtual functions: "// virtual keyword tells the compiler to generate a vtable for this function so that if its overwritten you can point to the correct function"
    // if we use virtual things its called dynamic binding, if not we use static binding
    // so make the destructor virtual so it knows to override and what destructor should be called  

    for (int i = 0; i < 2; i++)
    {
        delete array[i];
    }
    

    return 0;
}