#include <iostream>

/* 
    sort an array with Bubble Sort, the simplest sort method
    Not very efficient.

    Bubble Sort = for every element in an array, check if adjecent value
                  is smaller, if it is then set value to temp, put the adjecent value in the current values place,
                  and then set adjecent value to the temp value, which was the current value.
                  now we have swapped the two values
*/
void sort(int array[], int size);
int main(){

    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size);

    for(int element : array){
        std::cout << element << " ";
    }

    return 0;
}
void sort(int array[], int size){
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
}

