#include <iostream>

/*
    Abstraction = hiding unnecessary data from outside a class
    getter = function that makes a private attribute READABLE
    setter = function that makes a private attribute WRITEABLE
*/

class Stove{
    private: // hidden from outside the class 
        int temperature = 0;

    public: // accessible from outside the class
    Stove(int temperature){
        setTemperature(temperature);
    }
    int getTemperature(){
        return temperature;
    }
    int setTemperature(int temperature){
        if(temperature < 0){
             this->temperature = 0;
        }else if (temperature >= 10)
        {
            this->temperature = 10;
        }else{
            this->temperature = temperature;
        }
    }
};

int main(){

    Stove stove(0);

    //stove.setTemperature(100000);

    std::cout << stove.getTemperature() << '\n';

    return 0;
}