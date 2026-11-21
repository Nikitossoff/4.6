#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>

void Create(int **x, int n);
void Vvod(FILE *in, int *x, int n);
int poisk(int *x, int n, int z);
void FormNov(int **nov, int *k, int *x, int idx);
void Vivod(FILE *out, int *x, int n);
void Ochistka(int **x);

#endif
