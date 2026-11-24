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
    int na, nb, nc;

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

    int *A = NULL, *B = NULL, *C = NULL;
    Create(&A, na);
    Create(&B, nb);
    Create(&C, nc);

    Vvod(inA, A, na);
    Vvod(inB, B, nb);
    Vvod(inC, C, nc);

    int idx_a = poisk_2_chet(A, na);
    int idx_b = poisk_2_chet(B, nb);
    int idx_c = poisk_2_chet(C, nc);

    int *A1 = NULL, *B1 = NULL, *C1 = NULL;
    int ka = 0, kb = 0, kc = 0;

    FILE *out = fopen("output.txt", "w");
    fprintf(out, "Изначальный Массив А:\n");
    Vivod(out, A, na);
    fprintf(out, "Изначальный Массив B:\n");
    Vivod(out, B, nb);
    fprintf(out, "Изначальный Массив C:\n");
    Vivod(out, C, nc);

    if (idx_a != -1) {
        SozdNov(&A1, A[idx_a]);
        ka = 1;
        DobNov(&A1, &ka, A, na, idx_a);
        fprintf(out, "Массив A1 (количество элементов: %i):\n", ka);
        Vivod(out, A1, ka);
    }
    else {
        fprintf(out, "Новый массив A1 не сформирован (меньше 2 четных элементов).\n");
    }

    if (idx_b != -1) {
        SozdNov(&B1, B[idx_b]);
        kb = 1;
        DobNov(&B1, &kb, B, nb, idx_b);
        fprintf(out, "Массив B1 (количество элементов: %i):\n", kb);
        Vivod(out, B1, kb);
    }
    else {
        fprintf(out, "Новый массив B1 не сформирован (меньше 2 четных элементов).\n");
    }

    if (idx_c != -1) {
        SozdNov(&C1, C[idx_c]);
        kc = 1;
        DobNov(&C1, &kc, C, nc, idx_c);
        fprintf(out, "Массив C1 (количество элементов: %i):\n", kc);
        Vivod(out, C1, kc);
    }
    else {
        fprintf(out, "Новый массив C1 не сформирован (меньше 2 четных элементов).\n");
    }

    fclose(inA);
    fclose(inB);
    fclose(inC);
    fclose(out);
    printf("Результат успешно записан в output.txt!\n");
    Ochistka(&A);
    Ochistka(&B);
    Ochistka(&C);
    Ochistka(&A1);
    Ochistka(&B1);
    Ochistka(&C1);
    return 0;
}
