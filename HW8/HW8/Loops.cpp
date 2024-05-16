#include <iostream>

void printNaturalNumbersLoops(int count) {
    if (count < 0) {

        return;
    }

    std::cout << "\nFrom largest to smallest with loop" << std::endl;
    for (int i = count; i >= 0; i--) {
        std::cout << i << " ";
    }

    std::cout << "\nFrom smallest to largest with loop" << std::endl;
    for (int i = 0; i <= count; i++) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void countUserNumbers() {
    int userInputAmount = 0;

    std::cout << "Please enter the number of times you will transfer the numbers: " << std::endl;
    std::cin >> userInputAmount;

    int positiveNumbersAmount = 0;
    int negativeNumbersAmount = 0;
    int zeroNumbersAmount = 0;

    for (int i = userInputAmount; i > 0; i--) {
        int userNumber = 0;
        std::cout << "\nInput yout number: " << std::endl;
        std::cin >> userNumber;

        if (userNumber > 0) {
            positiveNumbersAmount++;
        }
        else if (userNumber < 0) {
            negativeNumbersAmount++;
        }
        else {
            zeroNumbersAmount++;
        }
    }

    std::cout << "\nPositive: " << positiveNumbersAmount
        << ", negative: " << negativeNumbersAmount
        << ", zeroes: " << zeroNumbersAmount << std::endl;
}