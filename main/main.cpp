#include <iostream>

int main() {
    int size;
    std:: cout << "Enter dimension of array: ";
    std:: cin >> size;
    int *array = new int [size];
    for (int i = 0; i < size; ++i) {
        printf("%s %d %s", "Enter", i, "element: ");
        std:: cin >> array[i];
    }
    //indexes
    int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > array[max]) max = i;
        if (array[i] < array[min]) min = i;
        //sleep
        std::this_thread::sleep_for(2000ms);
    }

    std::cout << "min: " << array[min] << " max: " << array[max];

    double average = 0;

    for (int i = 0; i < size; i++) {
        average += array[i];
        //sleep
    } average /= size;

    std::cout << " average: " << average << std::endl;

    array[max] = array[min] = average;
    std:: cout << "Changed array: ";
    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << ' ';
    }

    delete [] array;


    return 0;
}
