#include <iostream>

using namespace std;

/**
 * units.cpp: UNITS. Find all natural numbers up to m whose binary notation consists of ones.
 * */

int input(int x);

int check(int x);

bool isConditionSatisfied(int x);


int main() {
    int x = 0;

    x = input(x);
    x = check(x);

    cout << "Result is ";

    for (int i = 1; i < x; i++) {
        if (isConditionSatisfied(i)) {
            cout << i << " ";
        }
    }

    return 0;
}

int input(int x) {
    cout << "Please, enter the number: ";
    cin >> x;
    return x;
}

int check(int x) {
    while (x < 1 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> x;
    }
    return x;
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