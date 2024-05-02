#include <iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;

void arithmeticProgression() {
    bool isContinue = true;

    do {
        int firstElem;
        int step;
        int lastElemNumber;
        cout << "Please input first element, step and number of the last element of the arithmetic progression: " << endl;

        cin >> firstElem >> step >> lastElemNumber;

        if (step == 0) {
            cout << "Incorrect value in step variable, plase try again and input correct value" << endl;
            continue;
        }

        for (int i = 0; i < lastElemNumber; i++) {
            int currentValue = firstElem + i * step;
            cout << 'a' << i << ": " << currentValue << ' ';
        }

        isContinue = false;
    } while (isContinue);
    
}

void fibonacciNumber() {
    //fibonacci[98] -               135,301,852,344,706,746,049
    //max usigned long long value -  18,446,744,073,709,551,615
    bool isContinue = true;

    do {
        int elemNumber;
        unsigned long long currentElem = 1;
        unsigned long long addend = 0;
        unsigned long long nextElem;
        cout << "\nPlease input the Fibonacci element number:" << endl;
        cin >> elemNumber;

        if (elemNumber <= 0) {
            cout << "Incorrect Fibonacci element number, please try again and input correct value" << endl;
            continue;
        }
        else if (elemNumber == 1) {
            cout << "F1: " << 1 << endl;
            break;
        }

        for (int i = 2; i <= elemNumber; i++) {
            nextElem = addend + currentElem;
            addend = currentElem;
            currentElem = nextElem;
        }
        cout << 'F' << elemNumber << ": " << nextElem << endl;
        isContinue = false;
    } while (isContinue);
}

void factorial() {
    bool isContinue = true;

    do {
        int number;
        int result = 1;
        cout << "Please input a number to calculate its factorial:" << endl;
        cin >> number;

        if (number < 0) {
            cout << "Incorrect value, please try again and input correct value" << endl;
            continue;
        }

        for (int i = 0; i < number; i++) {
            result += result * i;
        }

        cout << number << "!: " << result << endl;

        isContinue = false;
    } while (isContinue);
}

void printGeometricShapes() {
    bool isContinue = true;

    do {
        int triangleWidth;
        int triangleHeight;

        int squareWidth;
        int squareHeight;

        bool symbol = true;

        cout << "Please input width and height for triangles:" << endl;
        cin >> triangleWidth >> triangleHeight;


        cout << "Please input width and height for squares:" << endl;
        cin >> squareWidth >> squareHeight;

        if (triangleWidth <= 0 || triangleHeight <= 0 || squareWidth <= 0 || squareHeight <= 0) {
            cout << "Icorrect values for width or height, please try again and input only positive numbers" << endl;
            continue;
        }

        cout << "\nA:" << endl;
        for (int i = 0; i < triangleHeight; i++) {
            cout << std::string(triangleWidth--, '*');
            cout << endl;
        }

        cout << "\nB:" << endl;
        for (int i = 1; i <= triangleHeight; i++) {
            cout << std::string(i, '*');
            cout << endl;
        }

        cout << "\nC:" << endl;
        for (int i = 1; i <= squareHeight; i++) {
            for (int j = 0; j < squareWidth; j++) {
                cout << '*';
            }
            cout << endl;
        }

        cout << "\nD:" << endl;
        for (int i = 0; i < squareHeight; i++) {
            cout << std::string(i, ' ');
            for (int j = 0; j < squareWidth; j++) {
                cout << '*';
            }
            cout << endl;
        }

        cout << "\nE:" << endl;
        for (int i = 0; i < triangleHeight; i++) {
            for (int j = 0; j <= i; j++) {
                cout << symbol;
                symbol = !symbol;
            }
            cout << endl;
        }

        isContinue = false;
    } while (isContinue);
}

int main()
{
    arithmeticProgression();
    fibonacciNumber();
    factorial();
    printGeometricShapes();
}
