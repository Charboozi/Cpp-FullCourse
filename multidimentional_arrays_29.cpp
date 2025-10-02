#include <iostream>

int main(){

    // array[rows][columns] (you dont need to set row size but you need to set column size)
    // because we omit the size of the first array(rows) so it knows the rows
    // but then it only sees rows of rows, it doesn't know where the columns start, thats why we must say how many columns there are
    std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
                            {"Corvette", "Equinox", "Silverado"},
                            {"Challanger", "Durango", "Ram 1500"}};

    std::cout << cars[1][2] << "\n";

    int rows = sizeof(cars)/sizeof(cars[0]);
    int cols = sizeof(cars[0])/sizeof(cars[0][0]);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << cars[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}