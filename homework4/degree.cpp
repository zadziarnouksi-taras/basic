#include <iostream>

using namespace std;

/**
 *degree.cpp: DEGREE. Develop a function that raises x to the n power.
 * */

void inputNumber(int *number);

void inputDegree(int *degree);

void check(int *x);

int exponentiation(int x, int n);

int main() {
    int x, n, result;

    inputNumber(&x);
    check(&x);

    inputDegree(&n);
    check(&n);

    if (x == 0) {
        result = 0;
    } else if (x != 0 and n == 0) {
        result = 1;
    } else if (x != 0 and n == 1) {
        result = x;
    } else {
        result = exponentiation(x, n);
    }

    cout << "The result of raising to the power " << n << " of the number " << x << " is equal to "
         << result << endl;

    return 0;
}

int exponentiation(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * exponentiation(x, n - 1);
    }

}

void inputNumber(int *number) {
    cout << "Please, enter the number you want to raise to the power: ";
    cin >> *number;
}

void inputDegree(int *degree) {
    cout << "Enter the degree to which you want to raise the number: ";
    cin >> *degree;
}

void check(int *x) {
    while (*x < 0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}