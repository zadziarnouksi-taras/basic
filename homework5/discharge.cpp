#include <iostream>
#include <cmath>

using namespace std;

/**
 *discharge.cpp: DISCHARGES. Develop a function that "flips" the integer passed to it, for example: 1234 -> 4321
 * */

int input(int x, string word);

int calcNumberOfDigits(int number);

int flipNumber(int number);

int main() {
    int number = 0;

    number = input(number, "number");

    cout << "Flip number " << number << " is " << flipNumber(number);

    return 0;
}

int input(int x, string word) {
    cout << "Enter " << word << ", please: ";
    cin >> x;
    return x;
}

int flipNumber(int number) {
    int result = 0;

    for (int i = calcNumberOfDigits(number); i > 0; i--) {
        result += (number % 10) * pow(10, i - 1);
        number /= 10;
    }
    return result;

}

int calcNumberOfDigits(int number) {
    int numberOfDigits = 0;

    while (number > 0) {
        number /= 10;
        numberOfDigits++;
    }
    return numberOfDigits;
}