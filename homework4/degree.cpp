#include <iostream>

using namespace std;

/**
 *degree.cpp: DEGREE. Develop a function that raises x to the n power.
 * */

void check(int *x);
int exponentiation(int x, int n);

int main() {
    int x, n;

    cout << "Please, enter the number you want to raise to the power: ";
    cin >> x;

    check(&x);

    cout << "Enter the degree to which you want to raise the number: ";
    cin >> n;

    check(&n);

    cout << "The result of raising to the power " << n << " of the number " << x << " is equal to "
         << exponentiation(x, n) << endl;

    return 0;
}

int exponentiation(int x, int n) {
    if (x == 0 and n == 0) {
        return 0;
    } else if (x != 0 and n == 0) {
        return 1;
    } else if (x != 0 and n == 1) {
        return x;
    } else {
        if (n == 0) {
            return 1;
        } else {
            return x * exponentiation(x, n - 1);
        }
    }
}

void check(int *x) {
    while (*x < 0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}