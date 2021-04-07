#include <iostream>

#include <random>

using namespace std;

/**
 * tictactoe.cpp : TIC-TAC-TOE. Program and play the Tic-Tac-Toe game with the computer.
 * */

#define N 3
#define CROSS 'X'
#define ZERO 'O'

void movePerNumberedCell(int position);

void initializeField();

void printFieldState();

int randomNumber(int n);

int inputNumber(int x);

int checkCorrectInput(int x);

bool checkForWinner();

bool randomChoiceOfTheFirst();

char gameChipSwitch(char gameChip);

bool checkForPossibleMoves();

void printStart(bool isPlayer);

void printWinner(bool isPlayer);

char checkValue(int number);

int transitionFromCoordToNum(int x, int y);

int obligatoryMove();

char field[N][N];
char currentTurn = CROSS;

int main() {
    int counterOfMovies = 0, input = 0;
    bool isPlayer;

    isPlayer = randomChoiceOfTheFirst();
    initializeField();

    printStart(isPlayer);

    while (!checkForWinner()) {

        if (!checkForPossibleMoves()) {
            cout << "Friendship won!!!" << endl;

            break;
        }
        while (true) {
            if (isPlayer) {
                input = inputNumber(input);
                input = checkCorrectInput(input);
            } else {
                if (obligatoryMove()) {
                    input = obligatoryMove();
                } else if (counterOfMovies == 0 or (counterOfMovies == 1 and checkValue(5) == '+')) {
                    input = 5;
                } else if (counterOfMovies == 1 or
                           (checkValue(1) == '+' or checkValue(3) == '+' or checkValue(5) == '+' or
                            checkValue(7) == '+')) {
                    do {
                        input = 1 + randomNumber(8);
                    } while (input % 2 == 0);
                } else {
                    input = 1 + randomNumber(8);
                }
            }
            if (checkValue(input) == '+') {
                movePerNumberedCell(input);

                counterOfMovies++;

                printFieldState();

                cout << "-----" << endl;

                isPlayer = !isPlayer;
                currentTurn = gameChipSwitch(currentTurn);
                break;
            } else {
                if (isPlayer) {
                    printFieldState();

                    cout << "This field is busy! Enter another coordinate!" << endl;
                }
            }
        }
    }

    if (checkForWinner()) printWinner(isPlayer);

    return 0;
}

void initializeField() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            field[i][j] = '+';
        }
    }
}

void printFieldState() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
}

int randomNumber(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n);
    return dis(gen);
}

int inputNumber(int x) {
    cout << "Your move: ";
    cin >> x;

    return x;
}

int checkCorrectInput(int x) {
    while (x < 1 or x > 9) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> x;
    }
    return x;
}

bool checkForWinner() {
    if ((checkValue(1) == checkValue(4) and
         checkValue(4) == checkValue(7) and
         checkValue(1) != '+') or    //vertical checking
        (checkValue(2) == checkValue(5) and
         checkValue(5) ==
         checkValue(8) and
         checkValue(2) != '+') or
        (checkValue(3) ==
         checkValue(6) and
         checkValue(6) ==
         checkValue(9) and checkValue(3) != '+')) {
        return true;
    } else if ((checkValue(1) == checkValue(2) and
                checkValue(2) == checkValue(3) and
                checkValue(1) != '+') or
               //horizontal checking
               (checkValue(4) == checkValue(5) and
                checkValue(5) == checkValue(6) and
                checkValue(4) != '+') or
               (checkValue(7) == checkValue(8) and
                checkValue(8) == checkValue(9) and
                checkValue(7) != '+')) {
        return true;
    } else if ((checkValue(1) == checkValue(5) and
                checkValue(5) == checkValue(9) and
                checkValue(1) != '+') or    //cross checking
               (checkValue(3) == checkValue(5) and
                checkValue(5) == checkValue(7) and checkValue(3) != '+')
            ) {
        return true;
    } else {
        return false;
    }
}

bool randomChoiceOfTheFirst() {
    return randomNumber(1);
}

char gameChipSwitch(char gameChip) {
    if (gameChip == ZERO) {
        return CROSS;
    } else {
        return ZERO;
    }
}

bool checkForPossibleMoves() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j] == '+') {
                return true;
            }
        }
    }
    return false;
}

void printStart(bool isPlayer) {
    if (isPlayer) {
        cout << "Player starts first." << endl;
    } else {
        cout << "Computer starts first." << endl;
    }
}

void printWinner(bool isPlayer) {
    if (!isPlayer) {
        cout << "YOU WON" << endl;
    } else {
        cout << "PC WON" << endl;
    }
}

void movePerNumberedCell(int position) {
    switch (position) {
        case 1:
            field[0][0] = currentTurn;
            break;
        case 2:
            field[0][1] = currentTurn;
            break;
        case 3:
            field[0][2] = currentTurn;
            break;
        case 4:
            field[1][0] = currentTurn;
            break;
        case 5:
            field[1][1] = currentTurn;
            break;
        case 6:
            field[1][2] = currentTurn;
            break;
        case 7:
            field[2][0] = currentTurn;
            break;
        case 8:
            field[2][1] = currentTurn;
            break;
        case 9:
            field[2][2] = currentTurn;
            break;
        default:
            break;
    }
}

char checkValue(int number) {
    char value;
    switch (number) {
        case 1:
            value = field[0][0];
            break;
        case 2:
            value = field[0][1];
            break;
        case 3:
            value = field[0][2];
            break;
        case 4:
            value = field[1][0];
            break;
        case 5:
            value = field[1][1];
            break;
        case 6:
            value = field[1][2];
            break;
        case 7:
            value = field[2][0];
            break;
        case 8:
            value = field[2][1];
            break;
        case 9:
            value = field[2][2];
            break;
        default:
            break;
    }
    return value;
}

int obligatoryMove() {
    char current = currentTurn;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j] == '+') {
                field[i][j] = current;
                if (checkForWinner()) {
                    field[i][j] = '+';
                    return transitionFromCoordToNum(i, j);
                } else {
                    field[i][j] = '+';
                }
            }
        }
    }

    current = gameChipSwitch(current);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j] == '+') {
                field[i][j] = current;
                if (checkForWinner()) {
                    field[i][j] = '+';
                    return transitionFromCoordToNum(i, j);
                } else {
                    field[i][j] = '+';
                }
            }
        }
    }
    return 0;
}

int transitionFromCoordToNum(int x, int y) {
    if (x == 0 and y == 0) {
        return 1;
    } else if (x == 0 and y == 1) {
        return 2;
    } else if (x == 0 and y == 2) {
        return 3;
    } else if (x == 1 and y == 0) {
        return 4;
    } else if (x == 1 and y == 1) {
        return 5;
    } else if (x == 1 and y == 2) {
        return 6;
    } else if (x == 2 and y == 0) {
        return 7;
    } else if (x == 2 and y == 1) {
        return 8;
    } else if (x == 2 and y == 2) {
        return 9;
    }
}