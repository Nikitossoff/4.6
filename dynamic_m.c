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


int poisk_2_chet(int *x, int n) {
    bool fl = true;
    int i = 0;
    int cnt = 0;
    while (i < n && fl) {
        if (x[i] % 2 == 0) {
            cnt++;
            if (cnt == 2) {
                fl = false;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    if (fl) {
        i = -1;
    }
    return i;
}


void SozdNov(int **nov, int first_val) {
    *nov = (int *)malloc(1 * sizeof(int));
    (*nov)[0] = first_val;
    return;
}

void DobNov(int **nov, int *k, int *x, int n, int start_idx) {
    int cnt = 0;
    for (int i = start_idx + 1; i < n; i++) {
        if (x[i] % 2 == 0) {
            cnt++;
            if (cnt % 2 == 0) {
                *nov = (int *)realloc(*nov, (*k + 1) * sizeof(int));
                (*nov)[*k] = x[i];
                (*k)++;
            }
        }
    }
    return;
}

void Vivod(FILE *out, int *x, int n) {
    fprintf(out, "==================================\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%4i ", x[i]);
    }
    fprintf(out, "\n");
    return;
}

void Ochistka(int **x) {
    if (*x != NULL) {
        free(*x);
        *x = NULL;
    }
    return;
}
