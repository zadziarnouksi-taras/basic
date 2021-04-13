#include <iostream>

using namespace std;

/**
 * plusMinus.cpp: PLUS-MINUS. Replace every even digit in the string with pluses, and every odd one with minuses
 * in the amount equal to the value of the digit.
 * */

char *stringConversion(char string[]);

int strLen(const char str[]);

void input(char number[]);

int main() {
    char number[128] = {0};

    input(number);

    cout << "String conversion of " << number << " is " << stringConversion(number) << endl;

    return 0;
}

char *stringConversion(char string[]) {
    char sign = '-';
    int index = 0;
    int counter = 0;

    for (int i = 0; string[i]; ++i) {
        if (string[i] > 47 and string[i] < 58) {
            counter = string[i] - '0';

            sign == '-' ? sign = '+' : sign = '-';

            for (int j = strLen(string) - 1; j > i; --j) {
                string[j + counter - 1] = string[j];
            }
            for (int j = 0; j < counter; ++j) {
                string[index + j] = sign;
            }
            index += counter;
        }
    }
    return string;
}

int strLen(const char str[]) {
    int counter = 0;

    for (int i = 0; str[i]; ++i) {
        counter++;
    }
    return counter;
}

void input(char string[]) {
    cout << "Enter number, please: ";
    cin >> string;
}