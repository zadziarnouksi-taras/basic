#include <iostream>

using namespace std;

/**
 * guessnumber.cpp: //Develop a game: the computer guesses a number and gives hints ("more or less") to the user.
 * */

#define MAX 100
#define NUMBER_OF_ATTEMPTS 7

int main() {
    srand(time(0));

    int userNumber, attempt = 0;
    int randomNumber = rand() % MAX;

    cout << "The computer guesses a number from 1 to " << MAX << ". You have " << NUMBER_OF_ATTEMPTS
         << " attempts. What is the number?"
         << endl;

    while (attempt < NUMBER_OF_ATTEMPTS) {
        attempt++;

        cout << "Please, enter number: ";
        cin >> userNumber;

        while (userNumber < 0 || userNumber > MAX || !cin) {
            cout << "Your input is wrong (must be a number between 0 and " << MAX << ").Try again: ";

            cin.clear();
            while (cin.get() != '\n') fflush(stdin);

            cin >> userNumber;
        }

        if (randomNumber > userNumber) {
            cout << "More! You have " << NUMBER_OF_ATTEMPTS - attempt << " attempt(s) left." << endl;
        } else if (randomNumber < userNumber) {
            cout << "Less! You have " << NUMBER_OF_ATTEMPTS - attempt << " attempt(s) left." << endl;
        } else {
            cout << "You WON!!!" << endl;

            return 0;
        }

    }

    cout << "You lose. Computer number is " << randomNumber << endl;

    return 0;
}
