#include <iostream>

using namespace std;

/**
 * fieldOfMiracles.cpp: FIELD OF MIRACLES. Program the game: open the letters, guess the word,
 * at the end - Yakubovich's joke.
 * */

#define QUESTION "In winter and summer in one color?"
#define ANSWER "fir-tree"

int strLen(const char str[]);

void fillScoreboard(char scoreboard[], int n);

bool isNotGuessed(char scoreboard[]);

void print(char string[]);

void printScoreboard(char scoreboard[]);

void input(char userOpinion[]);

void checkCorrectInput(char *userOpinion);

bool isValidCharacter(char character);

bool isThereSuchLetter(char userOpinion[]);

void openLetterOnScoreboard(char scoreboard[], char userOpinion[]);

bool checkTheWholeWord(char userOpinion[]);

int main() {
    char userOpinion[128] = {0};
    char scoreboard[128] = {0};

    fillScoreboard(scoreboard, strLen(ANSWER));

    while (isNotGuessed(scoreboard)) {
        print(QUESTION);
        printScoreboard(scoreboard);

        input(userOpinion);
        checkCorrectInput(userOpinion);

        if (strLen(userOpinion) == 1) {
            if (isThereSuchLetter(userOpinion)) {
                openLetterOnScoreboard(scoreboard, userOpinion);
            } else {
                cout << "There is no such letter!" << endl;
            }
        } else if (checkTheWholeWord(userOpinion)) {
            break;
        } else {
            cout << "Wrong!" << endl;
        }
    }
    cout << "You WON!" << endl;
    printScoreboard(ANSWER);

    return 0;
}

int strLen(const char str[]) {
    int counter = 0;

    for (int i = 0; str[i]; ++i) {
        counter++;
    }
    return counter;
}

bool isNotGuessed(char scoreboard[]) {
    for (int i = 0; scoreboard[i]; ++i) {
        if (scoreboard[i] == '*') {
            return true;
        }
    }
    return false;
}

void fillScoreboard(char scoreboard[], int n) {
    for (int i = 0; i < n; ++i) {
        scoreboard[i] = '*';
    }
}

void print(char string[]) {
    cout << string << endl;
}

void printScoreboard(char scoreboard[]) {
    cout << "|";
    for (int i = 0; scoreboard[i]; ++i) {
        cout << scoreboard[i] << "|";
    }
    cout << endl;
}

void input(char userOpinion[]) {
    cout << "Enter a letter or whole word: ";
    cin >> userOpinion;
}

void checkCorrectInput(char *userOpinion) {
    bool flag = true;

    while (flag) {
        for (int i = 0; userOpinion[i]; ++i) {
            if (!isValidCharacter(userOpinion[i])) {
                cout << "Incorrect input(use please only A-Z, a-z and '-'). Try again: ";
                cin >> userOpinion;
                break;
            }
        }
        flag = false;
    }
}

bool isValidCharacter(char character) {
    return character == '-' or
           (character >= 'A' and character <= 'Z') or
           (character >= 'a' and character <= 'z');
}

bool isThereSuchLetter(char userOpinion[]) {
    for (int i = 0; ANSWER[i]; ++i) {
        if (userOpinion[0] == ANSWER[i]) {
            return true;
        }
    }
    return false;
}

void openLetterOnScoreboard(char scoreboard[], char userOpinion[]) {
    for (int i = 0; scoreboard[i]; ++i) {
        if (ANSWER[i] == userOpinion[0]) {
            scoreboard[i] = ANSWER[i];
        }
    }
}

bool checkTheWholeWord(char userOpinion[]) {
    if (strLen(userOpinion) != strLen(ANSWER)) {
        return false;
    }
    for (int i = 0; ANSWER[i]; ++i) {
        if (userOpinion[i] != ANSWER[i]) {
            return false;
        }
    }
    return true;
}