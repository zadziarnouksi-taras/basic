#include <iostream>

#include <random>

using namespace std;

/**
 * tictactoe.cpp : TIC-TAC-TOE. Program and play the Tic-Tac-Toe game with the computer.
 * */

#define N 3
#define CROSS 'X'
#define ZERO 'O'

void initializeField(char field[N][N]);

void printFieldState(char field[N][N]);

int randomNumber(int n);

int input(int x, string s);

int checkCorrectInput(int x);

bool checkForWinner(char field[N][N]);

bool randomChoiceOfTheFirst();

char gameChipSwitch(char gameChip);

bool checkForPossibleMoves(char field[N][N]);

void printStart(bool isPlayer);

void printWinner(bool isPlayer);

int main() {
    int vertCoordinate, horizCoordinate;
    bool isPlayer;
    char field[N][N];
    char currentTurn = CROSS;

    isPlayer = randomChoiceOfTheFirst();
    initializeField(field);

    printStart(isPlayer);

    while (!checkForWinner(field)) {
        if (!checkForPossibleMoves(field)) {
            cout << "Friendship won!!!" << endl;

            break;
        }
        while (true) {
            if (isPlayer) {
                vertCoordinate = input(vertCoordinate, "vertical");
                vertCoordinate = checkCorrectInput(vertCoordinate);

                horizCoordinate = input(horizCoordinate, "horizontal");
                horizCoordinate = checkCorrectInput(horizCoordinate);
            } else {
                vertCoordinate = randomNumber(N);
                horizCoordinate = randomNumber(N);
            }
            if (field[vertCoordinate - 1][horizCoordinate - 1] == '+') {
                field[vertCoordinate - 1][horizCoordinate - 1] = currentTurn;

                cout << (isPlayer ? "You" : "Computer") << " made move [" << vertCoordinate << ','
                     << horizCoordinate << "]: " << endl;

                printFieldState(field);

                isPlayer = !isPlayer;
                currentTurn = gameChipSwitch(currentTurn);
                break;
            } else {
                if (isPlayer) {
                    printFieldState(field);

                    cout << "This field is busy! Enter another coordinate!" << endl;
                }
            }
        }
    }
    printWinner(isPlayer);

    return 0;
}

void initializeField(char field[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            field[i][j] = '+';
        }
    }
}

void printFieldState(char field[N][N]) {
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

int input(int x, string s) {
    cout << "Your " << s << " coordinate: ";
    cin >> x;

    return x;
}

int checkCorrectInput(int x) {
    while (x < 1 or x > 3) {
        cout << "Your input is wrong! Try again : ";

        cin.clear();
        while (cin.get() != '\n') fflush(stdin);

        cin >> x;
    }
    return x;
}

bool checkForWinner(char field[N][N]) {
    if ((field[0][0] == field[0][1] and field[0][1] == field[0][2] and field[0][0] != '+') or    //vertical checking
        (field[1][0] == field[1][1] and field[1][1] == field[1][2] and field[1][0] != '+') or
        (field[2][0] == field[2][1] and field[2][1] == field[2][2] and field[2][0] != '+')) {
        return true;
    } else if ((field[0][0] == field[1][0] and field[1][0] == field[2][0] and field[0][0] != '+') or
               //horizontal checking
               (field[0][1] == field[1][1] and field[1][1] == field[2][1] and field[0][1] != '+') or
               (field[0][2] == field[1][2] and field[1][2] == field[2][2] and field[0][2] != '+')) {
        return true;
    } else if ((field[0][0] == field[1][1] and field[1][1] == field[2][2] and field[0][0] != '+') or    //cross checking
               (field[2][0] == field[1][1] and field[1][1] == field[0][2] and field[2][0] != '+')
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

bool checkForPossibleMoves(char field[N][N]) {
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