#include <iostream>

using namespace std;

/**
 *lcm.cpp : LCM. Find the least common multiple of two natural numbers.
 * */


void inputAndCheck(int *x);
int calcLCM(int a, int b);

int main() {
    int a = 0, b = 0;

    inputAndCheck(&a);
    inputAndCheck(&b);
    calcLCM(a, b);

    return 0;
}

void inputAndCheck(int *x) {
    cout << "Please, enter natural number : ";
    cin >> *x;

    while (*x < 0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}

int calcLCM(int a, int b) {
    int gcd = 0;                 //Greatest Common Dividend

    for (int i = 1; i <= (a > b ? b : a); i++) {
        if (a % i == 0 and b % i == 0) {
            gcd = i;
        }
    }

    cout << "Result is " << a * b / gcd << endl;
}

