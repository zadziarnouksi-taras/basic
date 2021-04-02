#include <iostream>

using namespace std;

/**
 * recruits.cpp: RECRUITS. The recruits are lined up. At the command NALE-VO! some of them turn left, while others
 * turn right. This is the starting position of the line. Further, each recruit acts as follows: seeing the face
 * of a neighbor in front of him, he turns around in exactly a second. Eventually the turns will stop and the
 * sergeant will sound the horn.
 * */

#define NUMBER_OF_PEOPLE_IN_LINE 10
#define POSITION_RECRUIT_WHO_TURNED_LEFT 8

void fillArray(char array[]);

void printLine(char array[]);

void printSoundSignal();

bool isOppositeEachOther(char line[], int position);

void turnAwayFromEachOther(char line[], int position);

int main() {
    int counter = -1;
    char line[NUMBER_OF_PEOPLE_IN_LINE];

    fillArray(line);

    line[POSITION_RECRUIT_WHO_TURNED_LEFT] = '<';

    while (true) {
        if (!counter) {
            printSoundSignal();
            break;
        }
        counter = 0;

        printLine(line);

        for (int i = 0; i < NUMBER_OF_PEOPLE_IN_LINE; ++i) {
            if (isOppositeEachOther(line, i)) {
                turnAwayFromEachOther(line, i);
                counter++;
                break;
            }
        }
    }

    return 0;
}

void fillArray(char array[]) {
    for (int i = 0; i < NUMBER_OF_PEOPLE_IN_LINE; ++i) {
        array[i] = '>';
    }
}

void printLine(char array[]) {
    for (int i = 0; i < NUMBER_OF_PEOPLE_IN_LINE; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

void printSoundSignal() {
    cout << "A SOUND SIGNAL!!!!" << endl;
}

bool isOppositeEachOther(char line[], int position) {
    return line[position] == '>' and line[position + 1] == '<';
}

void turnAwayFromEachOther(char line[], int position) {
    line[position] = '<';
    line[position + 1] = '>';
}