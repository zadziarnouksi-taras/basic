#include <iostream>

using namespace std;

/**
 *degree.cpp: DEGREE. Develop a function that raises x to the n power.
 * */

int input(int x, string s);

int check(int x);

int exponentiation(int x, int n);

int main() {
    int x = 0, n = 0, result;


    x = input(x, "number");
    x = check(x);

    n = input(n, "power");
    n = check(n);

    if (x == 0) {
        result = 0;
    } else if (n == 0) {
        result = 1;
    } else if (n == 1) {
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

int input(int x, string s) {
    cout << "Enter the " << s << ": ";
    cin >> x;
    return x;
}

int check(int x) {
    while (x < 0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> x;
    }
    return x;
}