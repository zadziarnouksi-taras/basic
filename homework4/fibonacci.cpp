#include <iostream>

using namespace std;

/**
 * fibonacci.cpp : FIBONACCI. 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946
Find the dependency and develop a function that calculates the n-th term of the series.
 * */

int input(int x);

int check(int x);

int calculate(int n);

int main() {
    int n = 0;

    n = input(n);
    n = check(n);

    cout <<"At the " << n << " position of the Fibonacci row is the number " << calculate(n) << endl;

    return 0;
}

int input(int x) {
    cout << "Please enter the position, number of the Fibonacci series: ";
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

int calculate(int n) {
    int current = 0, previous = 0, tmp;

    for (int i = 1; i < n; i++) {
        if (current == 0) {
            current++;
        } else {
            tmp = current;
            current += previous;
            previous = tmp;
        }
    }
    return current;
}