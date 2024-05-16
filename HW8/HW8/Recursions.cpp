#include <iostream>

int factorialRecursion(int count) {
    if (count > 1) {
        return count * factorialRecursion(count - 1);
    }
    else {
        return 1;
    }
}


void printNaturalNumbersRecursion(int count) {
    // From largest to smallest with recursion 
    if (count < 0) {
        return;
    }
    std::cout << count << " ";
    count -= 1;
    printNaturalNumbersRecursion(count);
}

void printNaturalNumbersRecursion2(int count) {
    // From smallest to largest with recursion
    if (count > 0) {
        printNaturalNumbersRecursion2(count - 1);
    }
    std::cout << count << " ";
}