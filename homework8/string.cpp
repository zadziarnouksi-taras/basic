#include <iostream>
#include <cmath>

using namespace std;

/**
 * 1) strLen() - the function returns the length of the string.
 * 2) strCpy() - copy from source to destination.
 * 3) strCat() - concatenation of strings.
 * 4) strCmp() - return 0 if str1 = str2,
 *                     -1 if str1 < str2,
 *                     1  if str1 > str2
 * 5) isLetter() - return true - if a capital letter of the Latin alphabet is passed (according to those assignments),
 *                  otherwise return false.
 * 6) isWord() - return true - if the passed string contains only uppercase letters of the Latin alphabet,
 *                  otherwise return false.
 * 7) strToInt() - convert the passed string to int and return it.
 * */

int strLen(const char str[]);

void strCpy(char destination[], char source[]);

char *strCat(char *destination, char *source);

int strCmp(char *str1, char *str2);

bool isLetter(char letter);

bool isWord(char str[]);

int strToInt(char str[]);

int main() {
    char firstString[128] = "Hello ";
    char secondString[] = "World!!";

    cout << "strLen() : " << strLen("hello") << endl;
    cout << "strCat() : " << strCat(firstString, secondString) << endl;

    strCpy(firstString, secondString);
    cout << "strCpy() : " << firstString << endl;

    cout << "strCmp() : " << strCmp(firstString, secondString) << endl;
    cout << "isLetter() : " << isLetter('Q') << endl;
    cout << "isWord() : " << isWord("WORD") << endl;
    cout << "strToInt() : " << strToInt("1234");

    return 0;
}

int strLen(const char str[]) {
    int counter = 0;

    for (int i = 0; str[i]; ++i) {
        counter++;
    }
    return counter;
}

void strCpy(char destination[], char source[]) {
    for (int i = 0; source[i]; ++i) {
        destination[i] = source[i];
    }
    destination[strLen(source)] = '\0';
}

char *strCat(char *destination, char *source) {
    int length = strLen(destination);

    for (int i = 0; source[i]; ++i) {
        destination[length + i] = source[i];
    }
    return destination;
}

int strCmp(char *str1, char *str2) {
    for (int i = 0; strLen(str1) > strLen(str2) ? str1[i] : str2[i]; ++i) {
        if (str1[i] > str2[i]) {
            return 1;
        } else if ((str1[i] < str2[i])) {
            return -1;
        }
    }
    return 0;
}

bool isLetter(char letter) {
    return 64 < letter and letter < 91;
}

bool isWord(char str[]) {
    for (int i = 0; str[i]; ++i) {
        if (str[i] < 65 or str[i] > 90) {
            return false;
        }
    }
    return true;
}

int strToInt(char str[]) {
    int number = 0;
    int length = strLen(str) - 1;

    for (int i = 0; str[i]; ++i) {
        number += (str[i] - '0') * pow(10, length);
        length--;
    }

    return number;
}