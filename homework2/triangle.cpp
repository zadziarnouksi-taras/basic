#include <iostream>
#include <cmath>

using namespace std;

/**
 * triangle.cpp: Three numbers are given. Find out what kind of triangle with these side lengths:
 * equilateral, rectangular, isosceles, or general.
 * */

void inputAndCheck(double *x);

int main() {
    double a, b, c;
    string result;

    inputAndCheck(&a);
    inputAndCheck(&b);
    inputAndCheck(&c);

    if ((a < b + c) and (b < a + c) and (c < a + b)) {
        result = "The triangle is general.";

        if (a == b and a == c and b == c) {
            result = "The triangle is equilateral.";
        } else if (a == b or a == c or b == c) {
            result = "The triangle is isosceles.";
        } else if ((pow(a, 2) == pow(b, 2) + pow(c, 2)) or
                   (pow(b, 2) == pow(a, 2) + pow(c, 2)) or
                   (pow(c, 2) == pow(a, 2) + pow(b, 2))) {
            result = "The triangle is rectangular";
        } else {}

        cout << result << endl;
    } else {
        printf("Triangle with sides a = %4.3f , b = %4.3f , c = %4.3f cannot exist.", a, b, c);
    }
    return 0;
}

void inputAndCheck(double *x) {
    cout << "Please, enter the value of the side of the triangle : ";
    cin >> *x;

    while (*x < 0.0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}