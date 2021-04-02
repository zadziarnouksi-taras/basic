#include <iostream>

using namespace std;

/**
 * observationsystem.cpp: OBSERVATION SYSTEM. The array stores the values of the terrain profile heights with
 * a constant horizontal step. Find areas (elevation points) that are invisible to the observer at the first point.
 * */

#define LENGTH_OF_ARRAY 10
#define DISTANCE_BETWEEN_POINTS 1.0
#define SYSTEM_HEIGHT_FROM_THE_GROUND 0

double inputHeightValue(int position, double value);

void printPointWithElevation(int number, double array[]);

void calcOfBlindSpots(double map[]);

double calcDistance(int position);

bool isFirstBlindSpot(int counter);

void printStartOfLine();

int main() {
    double map[LENGTH_OF_ARRAY + 1] = {0};
    double heightValue = 0;

    for (int i = 0; i < LENGTH_OF_ARRAY; ++i) {
        heightValue = inputHeightValue(i, heightValue);
        if ((bool) heightValue) {
            map[i] = heightValue;
        } else {
            break;
        }
    }

    calcOfBlindSpots(map);

    return 0;
}

double inputHeightValue(int position, double value) {
    cout << "Enter the height value for point number " << position + 1 << " (0 - Exit):";
    cin >> value;
    return value;
}

void calcOfBlindSpots(double map[]) {
    double top = map[1];
    int unitsFromSystemToTop = 1, counter = 0;

    for (int i = 2; map[i]; ++i) {
        if (top >= map[0]) {
            if ((map[i] - map[0] - SYSTEM_HEIGHT_FROM_THE_GROUND) / calcDistance(i) >
                (top - map[0] - SYSTEM_HEIGHT_FROM_THE_GROUND) / calcDistance(unitsFromSystemToTop)) {
                top = map[i];
                unitsFromSystemToTop = i;
            } else {
                if (isFirstBlindSpot(counter)) {
                    printStartOfLine();
                }
                printPointWithElevation(i, map);
                counter++;
            }
        } else {
            if ((map[0] - map[i] + SYSTEM_HEIGHT_FROM_THE_GROUND) / calcDistance(i) <
                (map[0] - top + SYSTEM_HEIGHT_FROM_THE_GROUND) / calcDistance(unitsFromSystemToTop)) {
                top = map[i];
                unitsFromSystemToTop = i;
            } else {
                if (isFirstBlindSpot(counter)) {
                    printStartOfLine();
                }
                printPointWithElevation(i, map);
                counter++;
            }
        }
    }
    if (counter == 0) {
        cout << "No blind spots found!" << endl;
    }
}

double calcDistance(int position) {
    return position * DISTANCE_BETWEEN_POINTS;
}

void printPointWithElevation(int number, double array[]) {
    cout << '[' << number + 1 << "]= " << array[number] << ' ';
}

bool isFirstBlindSpot(int counter) {
    return counter == 0;
}

void printStartOfLine() {
    cout << "Points in the blind spot :" << endl;
}