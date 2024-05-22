#include <iostream>

const int translateArrayLength = 10;
const int asciiDifference = 32;
const int lineSize = 25;

void translateArray(int numbers[], int size) {
    std::cout << "Enter 10 numbers:" << std::endl;
    for (int i = 0; i < size; i++) {
        int number;
        std::cin >> number;

        if (number > 0) {
            numbers[i] = number * 2;
        }
        else {
            numbers[i] = 0;
        }
    }

    std::cout << "Result array: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
}

void toUppercase(char str[]) {
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= asciiDifference;
        }
    }
    std::cout << str << std::endl;
}

bool isPalindrom(const char str[]) {
    int size = std::strlen(str);
    for (int i = size - 1; i >= 0; i--) {
        if (str[i] != str[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount) {
    int size = std::strlen(str);

    for (int i = 0; i < size; i++) {
        char symbol = std::tolower(str[i]);
        if (symbol == 'a' || symbol == 'e' || symbol == 'i' ||
            symbol == 'o' || symbol == 'u' || symbol == 'y' || 
            symbol == 'a') {
            vowelsCount++;
        }
        else if (symbol == 'b' || symbol == 'c' || symbol == 'd' ||
            symbol == 'f' || symbol == 'g' || symbol == 'h' ||
            symbol == 'j' || symbol == 'k' || symbol == 'l' ||
            symbol == 'm' || symbol == 'n' || symbol == 'p' ||
            symbol == 'q' || symbol == 'r' || symbol == 's' ||
            symbol == 't' || symbol == 'v' || symbol == 'w' ||
            symbol == 'x' || symbol == 'z') {
            constonantsCount++;
        }
    }
}

bool isEqual(const char str1[], const char str2[]) {
    int size1 = sizeof(str1) / sizeof(str1[0]);
    int size2 = sizeof(str2) / sizeof(str2[0]);

    if (size1 != size2) {
        return false;
    }

    for (int i = 0; i < size1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    //1
    int translArray[translateArrayLength] = {};
    translateArray(translArray, translateArrayLength);

    //2
    std::cout << "\nEnter your symbols:" << std::endl;
    char charArray[lineSize] = "";
    std::cin >> charArray;
    toUppercase(charArray);

    //3
    std::cout << "Enter your palindrome:" << std::endl;
    char palindromeArray[lineSize] = "";
    std::cin.getline(palindromeArray, lineSize);
    std::cout << std::boolalpha << "Is palindrome - " << isPalindrom(palindromeArray) << std::endl;

    //4
    int vowelsCount = 0;
    int constonantsCount = 0;
    std::cout << "Enter your sentence: " << std::endl;
    char sentence[lineSize] = "";
    std::cin.getline(sentence, lineSize);
    parseStringLetters(sentence, vowelsCount, constonantsCount);
    std::cout << std::boolalpha << "Wowels - " << vowelsCount << " Consonants - " << constonantsCount << std::endl;

    //5
    std::cout << "Enter fisrt sentence: " << std::endl;
    char sentence1[lineSize] = "";
    char sentence2[lineSize] = "";
    std::cin.getline(sentence1, lineSize);
    
    std::cout << "Enter secon sentence: " << std::endl;
    std::cin.getline(sentence2, lineSize);

    std::cout << std::boolalpha << "Is equal - " << isEqual(sentence1, sentence2) << std::endl;
}