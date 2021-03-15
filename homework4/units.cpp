#include <iostream>

using namespace std;

/**
 * units.cpp: UNITS. Find all natural numbers up to m whose binary notation consists of ones.
 * */

void input(int *x);

void check(int *x);

bool isConditionSatisfied(int x);


int main() {
    int x;

    input(&x);
    check(&x);

    cout << "Result is ";

    for (int i = 1; i < x; i++) {
        if (isConditionSatisfied(i)) {
            cout << i << " ";
        }
    }

    return 0;
}

void input(int *x) {
    cout << "Please, enter the number: ";
    cin >> *x;
}

void check(int *x) {
    while (*x < 1 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}

bool isConditionSatisfied(int x) {
    while (x > 0) {
        if (x % 2 == 0) {
            return false;
        }
        x /= 2;
    }
    return true;
}