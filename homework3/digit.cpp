#include <iostream>
#include <regex>

using namespace std;

const regex REGEX_DOUBLE("^[0-9]+[.]+[0-9]+");

/**
 * digit.cpp: Print out the first digit from the fractional part of a positive real number.
 * */

int main() {
    string number;   //number in string representation

    cout << "Please, enter a positive real number: ";
    cin >> number;

    while (!regex_match(number, REGEX_DOUBLE) || !cin) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> number;  
    }

    cout << "First digit is " << number[0] << endl;
    
    return 0;
}
