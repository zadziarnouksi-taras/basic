#include <iostream>

using namespace std;

/**
 *lcm.cpp : LCM. Find the least common multiple of two natural numbers.
 * */

void check(int *x);

void calcGCD(int a, int b, int *result);

int main() {
    int a = 0, b = 0, gcd = 0;       //Greatest Common Dividend

    cout << "Please, enter first natural number: ";
    cin >> a;

    check(&a);

    cout << "Please, enter second natural number: ";
    cin >> b;

    check(&b);

    calcGCD(a, b, &gcd);

    cout << "The least common multiple of " << a << " and " << b << " is " << a * b / gcd << endl;

    return 0;
}

void check(int *x) {
    while (*x < 0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}

void calcGCD(int a, int b, int *result) {
    for (int i = 1; i <= (a < b ? a : b); i++) {    //iterate to the smallest of two numbers
        if (a % i == 0 and b % i == 0) {
            *result = i;
        }
    }
}
