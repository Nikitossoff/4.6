#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>

void Create(int **x, int n);
void Vvod(FILE *in, int *x, int n);
int poisk_2_chet(int *x, int n);
void SozdNov(int **nov, int first_val);
void DobNov(int **nov, int *k, int *x, int n, int start_idx);
void Vivod(FILE *out, int *x, int n);
void Ochistka(int **x);

#endif
