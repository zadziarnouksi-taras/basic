#include <iostream>

using namespace std;

/**
 * clearance.cpp : CLEARANCE. A cube consists of n3 transparent and opaque cubes. Is there at least one gap?
 * */

#define N 10
#define TRANSPARENT true
#define X_AXIS 1
#define Y_AXIS 2
#define Z_AXIS 3

void fillArrayValue(bool array[N][N][N], bool value);

void insertGapOnAxis(bool array[N][N][N], int axis, int firstCoordinate, int secondCoordinate);

void checkCubeForGapsAlongXAxis(bool array[N][N][N]);

void checkCubeForGapsAlongYAxis(bool array[N][N][N]);

void checkCubeForGapsAlongZAxis(bool array[N][N][N]);

int main() {
    bool cube[N][N][N];

    fillArrayValue(cube, !TRANSPARENT);

    insertGapOnAxis(cube, X_AXIS, 5, 5);
    insertGapOnAxis(cube, Y_AXIS, 5, 5);
    insertGapOnAxis(cube, Z_AXIS, 5, 5);

    //Inserting an opaque cube to obscure gaps
    cube[5][5][5] = !TRANSPARENT;

    checkCubeForGapsAlongXAxis(cube);
    checkCubeForGapsAlongYAxis(cube);
    checkCubeForGapsAlongZAxis(cube);

    return 0;
}

void fillArrayValue(bool array[N][N][N], bool value) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                array[i][j][k] = value;
            }
        }
    }
}

void insertGapOnAxis(bool array[N][N][N], int axis, int firstCoordinate, int secondCoordinate) {
    int i;
    switch (axis) {
        case X_AXIS:
            for (i = 0; i < N; ++i) {
                array[i][firstCoordinate][secondCoordinate] = TRANSPARENT;
            }
            break;
        case Y_AXIS:
            for (i = 0; i < N; ++i) {
                array[firstCoordinate][i][secondCoordinate] = TRANSPARENT;
            }
            break;
        case Z_AXIS:
            for (i = 0; i < N; ++i) {
                array[firstCoordinate][secondCoordinate][i] = TRANSPARENT;
            }
            break;
        default:
            break;
    }
}

void checkCubeForGapsAlongXAxis(bool array[N][N][N]) {
    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                if (!array[i][j][k]) {
                    break;
                }
                if (i == 9) {
                    cout << "By X-axis with coordinates [y = " << j + 1 << ",z = " << k + 1 << ']' << endl;
                }
            }
        }
    }
}

void checkCubeForGapsAlongYAxis(bool array[N][N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            for (int j = 0; j < N; ++j) {
                if (!array[i][j][k]) {
                    break;
                }
                if (j == 9) {
                    cout << "By Y-axis with coordinates [x = " << i + 1 << ",z = " << k + 1 << ']' << endl;
                }
            }
        }
    }
}

void checkCubeForGapsAlongZAxis(bool array[N][N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (!array[i][j][k]) {
                    break;
                }
                if (k == 9) {
                    cout << "By Z-axis with coordinates [x = " << i + 1 << ",y = " << j + 1 << ']' << endl;
                }
            }
        }
    }
}