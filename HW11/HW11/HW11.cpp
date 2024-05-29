#include <iostream>

const int ROWS = 4;
const int COLUMNS = 4;

enum SortingDirection {
    ascending,
    descending
};

bool find(int arr_2d[ROWS][COLUMNS], int toFind) {
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (arr_2d[i][j] == toFind) {
                return true;
            }
        }
    }
    return false;
}

bool isSorted(const int* arr, int size, SortingDirection direction) {
    for (int i = 1; i < size; i++) {
        int previos = i - 1;
        if (direction == SortingDirection::ascending) {
            if (arr[previos] >= arr[i]) {
                return false;
            }
        }
        else {
            if (arr[previos] <= arr[i]) {
                return false;
            }
        }
    }
    return true;
}

void inputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void outPut2dArray(int arr_2d[COLUMNS][ROWS], int ROWS, int COLUMNS) {
    std::cout << "V1:" << std::endl;
    for (int j = ROWS - 1; j >= 0; j--) {
        for (int i = 0; i < COLUMNS ; i++) {
            std::cout << arr_2d[i][j] << " ";
        }
    }

    std::cout << "\nV2:" << std::endl;
    bool revers = false;
    int j = 0;
    for (int i = COLUMNS - 1; i >= 0; i--) {
        if (!revers) {
            for (; j < ROWS; j++) {
                std::cout << arr_2d[i][j] << " ";
            }
            j -= 1;
        }
        else {
            for (; j >= 0; j--) {
                std::cout << arr_2d[i][j] << " ";
            }
            j++;
        }
        revers = !revers;
    }
    
}

int main()
{
    //1
    int elemToFind;
    std::cout << "Enter number you want to find in array: " << std::endl;
    std::cin >> elemToFind;
    int arr_2d[COLUMNS][ROWS] = {
    1, 2, 3, 4,
    15, 21, 6, 8,
    91, 0, 12, 16,
    17, 19, 24, 32
    };
    std::cout << std::boolalpha << "Is elem in array - " << find(arr_2d, elemToFind) << std::endl;

    //2
    const int size = 8;
    int arr[size];
    int order;
    std::cout << "Enter 8 elements into array, to check their order" << std::endl;
    inputArray(arr, size);
    std::cout << "Choose order: ascending(0), descending(1)" << std::endl;
    std::cin >> order;
    std::cout << std::boolalpha << "Order result - " << isSorted(arr, size, static_cast<SortingDirection>(order)) << std::endl;

    //3
    outPut2dArray(arr_2d, ROWS, COLUMNS);

}

