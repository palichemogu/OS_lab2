#include <iostream>
#include "windows.h"

DWORD WINAPI ThreadFun(LPVOID lpParam) {
    const char* str = (const char*) lpParam;
    std::cout << str << std::endl;
    return 1;
}

int main() {
    /*int size;
    std:: cout << "Enter dimension of array: ";
    std:: cin >> size;
    int *array = new int [size];
    for (int i = 0; i < size; ++i) {
        printf("%s %d %s", "Enter", i, "element: ");
        std:: cin >> array[i];
    }*/
    const char* str = "Hello Thread !!!";
    HANDLE  hThread;
    DWORD ThreadID;
    hThread = CreateThread(
            NULL,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(ThreadFun),
            (LPVOID)str,
            0,
            &ThreadID
            );
    if (hThread == NULL) {
        std::cout << "Thread creation failed" << std::endl;
    }
    std::cout << "Thread creation success" << std::endl;
    DWORD iRetVal;
    if(GetExitCodeThread(hThread, &iRetVal)) {
        std::cout << iRetVal << std::endl;
    }
    CloseHandle(hThread);
    //indexes
    /*int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > array[max]) max = i;
        if (array[i] < array[min]) min = i;
        //sleep
        Sleep(7);
    }

    std::cout << "min: " << array[min] << " max: " << array[max];

    double average = 0;

    for (int i = 0; i < size; i++) {
        average += array[i];
        //sleep
        Sleep(12);
    } average /= size;

    std::cout << " average: " << average << std::endl;

    array[max] = array[min] = average;
    std:: cout << "Changed array: ";
    for (int i = 0; i < size; ++i) {
        std:: cout << array[i] << ' ';
    }

    delete [] array;
    return 0;
    //CreateThread()*/
}
