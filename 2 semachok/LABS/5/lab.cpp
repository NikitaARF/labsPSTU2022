#include <iostream>
#include "stdafx.h"
using namespace std;

//Для стековых и статических матриц.
void min(int m[], unsigned long h, unsigned long w, int** pmin);
//Для динамических матриц.
void min(int* m[], unsigned long h, unsigned long w, int** pmin);

int main() {
    const unsigned long H = 3;
    const unsigned long W = 4;

    int m[H][W] = {
        { 1,2,3,4 },
        { 9,0,1,7 },
        { 4,5,6,8 }
    };

    int* pmn = NULL;

    min((int*)m, H, W, &pmn);

    cout << "min: " << *pmn << endl;

    system("pause");
    return 0;
}

void min(int m[], unsigned long h, unsigned long w, int** pmin) {

    unsigned long i, j;

    *pmin = &m[0];

    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++) {
            if (m[i * w + j] < **pmin) *pmin = &m[i * w + j];
        }

}

//Для динамических матриц.
void max_min(int* m[], unsigned long h, unsigned long w, int** pmin) {

    unsigned long i, j;

    *pmin = &m[0][0];

    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++) {
            if (m[i][j] < **pmin) *pmin = &m[i][j];
        }

}