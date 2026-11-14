#include "dynamic_m.h"
#include <malloc.h>
#include <stdbool.h>

void Create(int **x, int n) {
    *x = (int *)malloc(n * sizeof(int));
    return;
}

void Vvod(FILE *in, int *x, int n) {
    for (int i = 0; i < n; i++) {
        fscanf(in, "%i", &x[i]);
    }
    return;
}


int poisk(int *x, int n, int z) {
    bool fl = true;
    int i = n - 1;
    while (i >= 0 && fl) {
        if (x[i] == z) {
            fl = false;
        }
        else {
            i--;
        }
    }
    return i;
}

void rebirth(int **x, int k) {
    *x = (int *)realloc(*x, k * sizeof(int));
    return;
}

void Vivod(FILE *out, int *x, int n) {
    fprintf(out, "==================================\n");
    fprintf(out, "Новый массив:\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%4i ", x[i]);
    }
    fprintf(out, "\n");
    return;
}

void Ochistka(int **x) {
    free((*x));
    return;
}
