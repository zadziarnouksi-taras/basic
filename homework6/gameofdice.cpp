#include <iostream>

using namespace std;

#define N 13
#define ROLL 10000

int rollDice();

int main() {
    int stat[N] = {0}, i;

    for (i = 0; i < ROLL; ++i) {
        stat[rollDice()]++;
    }

    for (i = 2; i < N; ++i) {
        cout.width(2);
        cout << i << ": ";
        cout.width(6);
        cout << stat[i] << ' ';
        cout.width(6);
        cout << 100.00 * stat[i] / ROLL << " %" << endl;
    }

    return 0;
}

int rollDice() {
    return (1 + rand() % 6) + (1 + rand() % 6);
}