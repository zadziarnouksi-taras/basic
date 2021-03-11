#include <iostream>
#include <cmath>

using namespace std;

/**
 * triangle.cpp: Three numbers are given. Find out what kind of triangle with these side lengths:
 * equilateral, rectangular, isosceles, or general.
 * */

bool isRectangular(double firstLeg, double secondLeg, double hypotenuse);
void input(double *x);
void check(double *x);

int main() {
    double a, b, c;
    string result;

    input(&a);
    check(&a);

    input(&b);
    check(&b);

    input(&c);
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

void input(double *x) {
    cout << "Please, enter the value of the side of the triangle : ";
    cin >> *x;
}

bool isRectangular(double firstLeg, double secondLeg, double hypotenuse) {
    return pow(firstLeg, 2) + pow(secondLeg, 2) == pow(hypotenuse, 2);
}
