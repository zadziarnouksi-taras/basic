#include <iostream>
#include <cmath>

using namespace std;

/**
 * triangle.cpp: Three numbers are given. Find out what kind of triangle with these side lengths:
 * equilateral, rectangular, isosceles, or general.
 * */

bool isRectangular(double firstLeg, double secondLeg, double hypotenuse);

void check(double *x);

int main() {
    double a, b, c;
    string result;

    cout << "Please, enter the value of the side of the triangle : ";
    cin >> a;

    check(&a);

    cout << "Please, enter the value of the side of the triangle : ";
    cin >> b;

    check(&b);

    cout << "Please, enter the value of the side of the triangle : ";
    cin >> c;

    check(&c);

    if ((a < b + c) and (b < a + c) and (c < a + b)) {
        result = "The triangle is general.";

        if (a == b and a == c and b == c) {
            result = "The triangle is equilateral.";
        } else if (a == b or a == c or b == c) {
            result = "The triangle is isosceles.";
        } else if (isRectangular(a, b, c) or isRectangular(a, c, b) or isRectangular(b, c, a)) {
            result = "The triangle is rectangular";
        } else {}

        cout << result << endl;
    } else {
        printf("Triangle with sides a = %4.3f , b = %4.3f , c = %4.3f cannot exist.", a, b, c);
    }
    return 0;
}

void check(double *x) {
    while (*x < 0.0 || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> *x;
    }
}

bool isRectangular(double firstLeg, double secondLeg, double hypotenuse) {
    if (pow(firstLeg, 2) + pow(secondLeg, 2) == pow(hypotenuse, 2)) {
        return true;
    } else {
        return false;
    }
}