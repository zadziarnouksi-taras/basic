#include <iostream>

using namespace std;

/**
 * numberoffate.cpp: NUMBER OF FATE. The digits of the full date of birth are added together until one digit is obtained.
 * Design a function and calculate your fate number.
 * */

#define MIN_DAY 1
#define MAX_DAY 31
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_YEAR 1960
#define MAX_YEAR 2015

int input(int x, const string& word);

int check(int x, int min, int max);

int calcNumberOfFate(int x, int y, int z);

int calcSumOfDigits(int number);


int main() {
    int day = 0, month = 0, year = 0;

    day = input(day, "day");
    day = check(day,MIN_DAY,MAX_DAY);

    month = input(month, "month");
    month = check(month,MIN_MONTH,MAX_MONTH);

    year = input(year, "year");
    year = check(year,MIN_YEAR,MAX_YEAR);

    cout << "Your number of fate is: " << calcNumberOfFate(day, month, year) << endl;
    return 0;
}

int input(int x, const string& word) {
    cout << "Enter " << word << ": ";
    cin >> x;
    return x;
}

int check(int x, int min, int max) {
    while (x < min || x > max || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> x;
    }
    return x;
}

int calcNumberOfFate(int day, int month, int year) {
    return calcSumOfDigits(day) + calcSumOfDigits(month) + calcSumOfDigits(year);
}

int calcSumOfDigits(int number) {
    int sum = 0;

    if (number / 10 == 0) return number;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}