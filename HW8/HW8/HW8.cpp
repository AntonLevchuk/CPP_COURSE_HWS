#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "headersLoops.h"
#include "headersRecursion.h"


float getArea(float radius) {
    return M_PI * radius * radius;
}

float getCircumference(float radius) {
    return M_PI * 2 * radius;
}

int main()
{
    countUserNumbers();

    while (true) {

        int number;
        std::cout << "Please input a number to calculate its factorial: ";
        std::cin >> number;
        std::cout << "\n" << factorialRecursion(number) << std::endl;
    
        break;
    }

    while (true) {
        int maxNuturalNumber;
        std::cout << "Enter max natural number: ";
        std::cin >> maxNuturalNumber;

        if (maxNuturalNumber <= 0) {
            std::cout << "Enter number that bigger than 0: " << std::endl;
            continue;
        }

        printNaturalNumbersLoops(maxNuturalNumber);
        std::cout << "\nFrom largest to smallest with recursion" << std::endl;
        printNaturalNumbersRecursion(maxNuturalNumber);
        std::cout << "\nFrom smallest to largest with recursion" << std::endl;
        printNaturalNumbersRecursion2(maxNuturalNumber);
        
        break;
    }

    while (true) {
        int radius;
        std::cout << "\nEnter radius of the circle: ";
        std::cin >> radius;

        if (radius <= 0) {
            std::cout << "\nRadius should be bigger than 0" << std::endl;
            continue;
        }

        std::cout << "\nArea of the circle - " << getArea(radius) << std::endl;
        std::cout << "Circumference - " << getCircumference(radius) << std::endl;

        break;
    }

}