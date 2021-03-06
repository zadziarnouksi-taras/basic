#include <iostream>
#include <cmath>

using namespace std;

/**
 * binarytodecimal.cpp: Convert the number from binary to decimal.
 * */

const string B2D = "b2d";
const string D2B = "d2b";

int convertBinToDec(int bin, int *result);

int convertDecToBin(int dec, int *result);

bool check(char option, int number);


int main() {
    string option;
    int x, result = 0;

    cout << "Please, enter 'b2d' - if you want convert from binary to decimal"
            ", d2b - if you want convert from decimal to binary." << endl;
    cin >> option;

    if (!option.compare(B2D)) {
        myFirstLabel:
        cout << "From binary to decimal. Enter your number: ";
        cin >> x;

        if (check('b', x)) {
            convertBinToDec(x, &result);
        } else {
            cout << "You entered a non-binary number!" << endl;
            return -1;
        }
    } else if (!option.compare(D2B)) {
        cout << "From decimal to binary. Enter your number: ";
        cin >> x;

        if (check('d', x)) {
            convertDecToBin(x, &result);
        } else {
            cout << "You entered a non-decimal number!" << endl;
            return -1;
        }
    } else {
        cout << "By default, the converter performs from binary to decimal!" << endl;

        goto myFirstLabel;  //wanted to try
    }


    cout << "Result is " << result << endl;

    return 0;
}

int convertBinToDec(int bin, int *result) {
    int i = 0;

    while (bin > 0) {
        *result += ((bin % 10) * pow(2, i));
        i++;
        bin = bin / 10;
    }

    return 0;
}

int convertDecToBin(int dec, int *result) {
    string tmp;

    while (dec > 0) {
        tmp.append(to_string(dec % 2));
        dec /= 2;
    }
    *result = stoi(tmp);

    return 0;
}

bool check(char option, int number) {
    string tmp;

    tmp.append(to_string(number));
    if (option == 'b') {
        for (int i = 0; i < tmp.length(); ++i) {
            if (tmp[i] != '0' and tmp[i] != '1') {
                return false;
            }
        }
        return true;
    } else if (option == 'd') {
        for (int i = 0; i < tmp.length(); ++i) {
            if (!isdigit(tmp[i])) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

