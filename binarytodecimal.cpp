#include <iostream>
#include <cmath>

using namespace std;

/**
 * binarytodecimal.cpp: Convert the number from binary to decimal.
 * */

#define B2D "b2d"
#define D2B "d2b"

int convertBinToDec(int bin, string *result);

int convertDecToBin(int dec, string *result);

bool isCheck(char option, int number);

int main() {
    string option, result;
    int x;

    cout << "Please, enter 'b2d' - if you want convert from binary to decimal"
            ", d2b - if you want convert from decimal to binary.\nYour choose: ";
    cin >> option;

    if (option == B2D) {
        myFirstLabel:
        cout << "From binary to decimal. Enter your number: ";
        cin >> x;

        if (isCheck('b', x)) {
            convertBinToDec(x, &result);
        } else {
            cout << "You entered a non-binary number!" << endl;
            return -1;
        }
    } else if (option == D2B) {
        cout << "From decimal to binary. Enter your number: ";
        cin >> x;

        if (isCheck('d', x)) {
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

int convertBinToDec(int bin, string *result) {
    int i = 0;
    int tmp;

    while (bin > 0) {
        tmp += ((bin % 10) * pow(2, i));
        i++;
        bin = bin / 10;
    }
    *result = to_string(tmp);

    return 0;
}

int convertDecToBin(int dec, string *result) {
    string tmp;

    while (dec > 0) {
        tmp.append(to_string(dec % 2));
        dec /= 2;
    }
    *result = tmp;

    return 0;
}

bool isCheck(char option, int number) {
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
