#include <iostream>

const int arrLenght = 5;

void swap1(int& a, int& b) {
    std::cout << "Function swap1" << std::endl;
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int* b) {
    std::cout << "Function swap2" << std::endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }

    
    if (arrSize > 0) {
        return true;
    }
    return false;
}

bool find(const int* arr, int size, int elem) {
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

double countArrayAvg(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    double result = static_cast<double>(sum) / size;
    return result;
}

int main()
{
    //1
    int a;
    int b;

    std::cout << "Enter two numbers" << std::endl;
    std::cin >> a >> b;
    swap1(a, b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    swap2(&a, &b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    //2
    double sumArr[arrLenght] = {2.1, 10.8, 15.0, -2.5, 6.3};
    double sum = 0;
    calculateSum(sumArr, arrLenght, sum);
    std::cout << "Array sum - " << sum << std::endl;

    //3
    int findElem;
    int findArr[arrLenght] = { 1, 5, 4, 2, 6 };
    std::cout << "Enter elem to find in array" << std::endl;
    std::cin >> findElem;
    std::cout << std::boolalpha << "Is elem in array - " << find(findArr, arrLenght, findElem) << std::endl;

    //4
    int avgArr[arrLenght];
    std::cout << "Enter 5 int numbers to count their avg" << std::endl;
    for (int i = 0; i < arrLenght; i++) {
        std::cin >> avgArr[i];
    }
    std::cout << "Avg of your numbers - " << countArrayAvg(avgArr, arrLenght) << std::endl;
}
