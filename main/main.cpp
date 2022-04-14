#include <iostream>
#include "windows.h"

struct arrayAndSize {
    int* array;
    int size;
    int minIndex = 0;
    int maxIndex = 0;
    double average = 0;
};

DWORD WINAPI min_max(void *v) {
    arrayAndSize *data = static_cast<arrayAndSize*>(v);

    int min = 0;
    int max = 0;
    for (int i = 0; i < data->size; i++) {
        if (data->array[i] > data->array[max]) max = i;
        if (data->array[i] < data->array[min]) min = i;
        //sleep
        Sleep(7);
    }
    std::cout << "min: " << data->array[min] << " max: " << data->array[max] << std::endl;
    data->minIndex = min; data->maxIndex = max;
}

DWORD WINAPI average(void *v) {
    arrayAndSize *data = static_cast<arrayAndSize*>(v);
    double average = 0;
    for (int i = 0; i < data->size; i++) {
        average += data->array[i];
        //sleep
        Sleep(12);
    } average /= data->size;
    std::cout << " average: " << average << std::endl;
    data->average = average;
}

int main() {
    int size;
    std:: cout << "Enter dimension of array: ";
    std:: cin >> size;
    int *array = new int [size];
    for (int i = 0; i < size; ++i) {
        printf("%s %d %s", "Enter", i, "element: ");
        std:: cin >> array[i];
    }

    arrayAndSize *data = new arrayAndSize();
    data->array = array;
    data->size = size;

    HANDLE hMinMax;
    DWORD ThreadMinMaxID;
    hMinMax = CreateThread(
            NULL,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(min_max),
            (LPVOID*)data,
            0,
            &ThreadMinMaxID
            );
    if (hMinMax == NULL) {
        std::cout << "Thread min_max creation failed" << std::endl;
    }
    std::cout << "Thread min_max creation success" << std::endl;
    WaitForSingleObject(hMinMax, INFINITE);
    CloseHandle(hMinMax);

    HANDLE hAverage;
    DWORD ThreadAverageID;
    hAverage = CreateThread(
            NULL,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(average),
            (LPVOID*)data,
            0,
            &ThreadMinMaxID
    );
    if (hAverage == NULL) {
        std::cout << "Thread average creation failed" << std::endl;
    }
    std::cout << "Thread average creation success" << std::endl;
    WaitForSingleObject(hAverage, INFINITE);
    CloseHandle(hAverage);

    data->array[data->minIndex] = data->array[data->maxIndex] = data->average;
    std:: cout << "Changed array: ";
    for (int i = 0; i < data->size; ++i) {
        std:: cout << data->array[i] << ' ';
    }
    delete [] array;
    return 0;
}
