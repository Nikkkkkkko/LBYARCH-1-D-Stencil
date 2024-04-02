#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

//Other Code
extern void stencilAsm(int n, float* X, float* Y);

void stencil(float X[32768], float Y[32768], int moves) {
    int j, k; //loop counters
    int l = 0; //index for Y array

    for (k = 0; k < moves; k++) {
        for (j = k; j < (7 + k); j++) {
            Y[l] += X[j];
        }
        l += 1;
    }

}

int main() {
    int n = 32768; //2^15
    int moves = n - 6; //Number of times the window will move right.
    int m;
    float X[32768] = {};
    float Y[32768] = {};
    float Xasm[32768] = {};
    float Yasm[32768] = {};

    //Initializes X values.W
    int i;
    for (i = 0; i < n; i++) {
        X[i] = i + 1;
    }

    //Other Code
    for (i = 0; i < n; i++) {
        Xasm[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        Yasm[i] = 0;
    }

    //Computes for Y values

    printf("[C Kernel]\n");

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    stencil(X, Y, moves);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; 

    printf("Execution time: %lf \n", cpu_time_used);

    //Prints first 10 Y values
    printf("Elements of vector Y: \n");

    if (moves <= 10) {
        for (m = 1; m <= moves; m++) {
            printf("%d.): %f \n", m, Y[m - 1]);
        }
    }
    else {
        for (m = 1; m <= 10; m++) {
            printf("%d.): %f \n", m, Y[m - 1]);
        }
    }

    printf("[x86-64 Kernel]\n");

    //Other Code
    stencilAsm(n, Xasm, Yasm);

    //Prints first 10 Y values
    printf("Elements of vector Y: \n");

    if (moves <= 10) {
        for (m = 1; m <= moves; m++) {
            printf("%d.): %f \n", m, Yasm[m - 1]);
        }
    }
    else {
        for (m = 1; m <= 10; m++) {
            printf("%d.): %f \n", m, Yasm[m - 1]);
        }
    }
    return 0;
}

//*The must be 2 versions of the computation portion; In C and in ASM.

//Step 1: Ask for n; n is length of X and Y

//Step 2: Initialize X as array with variable 1 to n
//Ex.
//if X = 4, then X -> 1, 2, 3, 4
//if X = 7, then X -> 1, 2, 3, 4, 5, 6, 7

//Step 3 : Get Y which is the sum of 7 elements in X
//Ex.If n = 9
//Y[0] = 1 + 2 + 3 + 4 + 5 + 6 + 7
//Y[1] = 2 + 3 + 4 + 5 + 6 + 7 + 8
//Y[2] = 3 + 4 + 5 + 6 + 7 + 8 + 9
//* *If moving sum window reaches end of array then end.

//Step 4: Display elements of vector Y up to the 10th element.

//Step 5 : Display the average execution time it took to compute for C and ASM

//** Test Case n[2 ^ 20, 2 ^ 24, and 2 ^ 30]; if 2 ^ 30 is unfeasible then lower it by 1 until it can be done.

//Step 6: Screenshot the output and place in Github.

//Step 7 : Include details of output and make compariative description.