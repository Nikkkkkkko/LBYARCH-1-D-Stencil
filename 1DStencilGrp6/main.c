#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void stencilAsm(int n, double* X, float* Y);

float* stencilC(int moves, float* X, float* Y) {
    int l = 0;
    for (int k = 0; k < moves; k++) {
        for (int j = k; j < (7 + k); j++) {
            Y[l] += X[j];
        }
        l += 1;
    }
    return Y;
}

float* incArray(int n) {
    float* array = (double*)malloc(n * sizeof(float));

    if (array == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    float currentValue = 1.0;

    for (int i = 0; i < n; i++) {
        array[i] = currentValue;
        currentValue++;
    }

    return array;
}

float* zeroArray(int n) {
    float* array = (float*)malloc(n * sizeof(float));
    if (array == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    for (int i = 0; i < n; i++) {
        array[i] = 0.0;
    }
    return array;
}

int main() {


    int n = pow(2, 20);
    int moves = n - 6;
    int m;

    float* X = incArray(n);
    float* Y = zeroArray(n);

    float* Xasm = incArray(n);
    float* Yasm = zeroArray(n);


    clock_t start, end;
    double cpu_time_used;

    //Computes for Y values

    printf("[C Kernel]\n");

    stencilC(n, X, Y);

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
    for (int i = 1; i < 30; i++) {
        start = clock();
        stencilC(moves, X, Y);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", cpu_time_used);
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

    for (int i = 1; i < 30; i++) {
        start = clock();
        stencilAsm(moves, X, Y);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", cpu_time_used);
    }

    return 0;
}