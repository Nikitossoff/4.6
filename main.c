#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *inA = fopen("t1_A.txt", "r");
    FILE *inB = fopen("t1_B.txt", "r");
    FILE *inC = fopen("t1_C.txt", "r");
    int na, nb, nc, y;
    do {
        printf("Введите количество элементов N массива А: ");
        scanf("%i", &na);
        if (na <= 1 || na > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (na <= 1 || na > 100);
    do {
        printf("Введите количество элементов N массива B: ");
        scanf("%i", &nb);
        if (nb <= 1 || nb > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (nb <= 1 || nb > 100);
    do {
        printf("Введите количество элементов N массива C: ");
        scanf("%i", &nc);
        if (nc <= 1 || nc > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (nc <= 1 || nc > 100);

    printf("Задайте число Y: ");
    scanf("%i", &y);

    int *A = NULL, *B = NULL, *C = NULL;
    Create(&A, na);
    Create(&B, nb);
    Create(&C, nc);

    Vvod(inA, A, na);
    Vvod(inB, B, nb);
    Vvod(inC, C, nc);

    int idx_a = poisk(A, na, y);
    int idx_b = poisk(B, nb, y);
    int idx_c = poisk(C, nc, y);

    FILE *out = fopen("output.txt", "w");

    if (idx_a > 0 && idx_b > 0 && idx_c > 0) {
        fprintf(out, "Новые массивы сформированы!\n");
        rebirth(&A, idx_a);
        rebirth(&B, idx_b);
        rebirth(&C, idx_c);
        fprintf(out, "Массив А:\n");
        Vivod(out, A, idx_a);
        fprintf(out, "Массив B:\n");
        Vivod(out, B, idx_b);
        fprintf(out, "Массив C:\n");
        Vivod(out, C, idx_c);
    }
    else if (idx_a <= 0 && idx_b > 0 && idx_c > 0) {
        fprintf(out, "Новые массивы B и С сформированы!\n");
        rebirth(&B, idx_b);
        rebirth(&C, idx_c);
        fprintf(out, "Массив B:\n");
        Vivod(out, B, idx_b);
        fprintf(out, "Массив C:\n");
        Vivod(out, C, idx_c);
    }
    else if (idx_a <= 0 && idx_b <= 0 && idx_c > 0) {
        fprintf(out, "Новый массив С сформирован!\n");
        rebirth(&C, idx_c);
        fprintf(out, "Массив C:\n");
        Vivod(out, C, idx_c);
    }
    else if (idx_a > 0 && idx_b <= 0 && idx_c > 0) {
        fprintf(out, "Новые массивы A и С сформированы!\n");
        rebirth(&A, idx_a);
        rebirth(&C, idx_c);
        fprintf(out, "Массив А:\n");
        Vivod(out, A, idx_a);
        fprintf(out, "Массив C:\n");
        Vivod(out, C, idx_c);
    }
    else if (idx_a > 0 && idx_b > 0 && idx_c <= 0) {
        fprintf(out, "Новые массивы A и B сформированы!\n");
        rebirth(&A, idx_a);
        rebirth(&B, idx_b);
        fprintf(out, "Массив А:\n");
        Vivod(out, A, idx_a);
        fprintf(out, "Массив B:\n");
        Vivod(out, B, idx_b);
    }
    else if (idx_a > 0 && idx_b <= 0 && idx_c <= 0) {
        fprintf(out, "Новый массив A сформирован!\n");
        rebirth(&A, idx_a);
        fprintf(out, "Массив А:\n");
        Vivod(out, A, idx_a);
    }
    else if (idx_a <= 0 && idx_b > 0 && idx_c <= 0) {
        fprintf(out, "Новый массив B сформирован!\n");
        rebirth(&B, idx_b);
        fprintf(out, "Массив B:\n");
        Vivod(out, B, idx_b);
    }
    else {
        fprintf(out, "Все новые массивы содержат 0 элементов (или число Y не найдено)\n");
    }

    fclose(inA);
    fclose(inB);
    fclose(inC);
    fclose(out);
    printf("Результат успешно записан в output.txt!");
    Ochistka(&A);
    Ochistka(&B);
    Ochistka(&C);
    return 0;
}
