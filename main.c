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

    int *A1 = NULL, *B1 = NULL, *C1 = NULL;
    int ka = 0, kb = 0, kc = 0;

    FILE *out = fopen("output.txt", "w");
    fprintf(out, "Изначальный Массив А:\n");
    Vivod(out, A, na);
    fprintf(out, "Изначальный Массив B:\n");
    Vivod(out, B, nb);
    fprintf(out, "Изначальный Массив C:\n");
    Vivod(out, C, nc);

    if (idx_a > 0 && idx_b > 0 && idx_c > 0) {
        fprintf(out, "Новые массивы сформированы!\n");
        FormNov(&A1, &ka, A, idx_a);
        FormNov(&B1, &kb, B, idx_b);
        FormNov(&C1, &kc, C, idx_c);
        fprintf(out, "Массив A1 (количество элементов: %i):\n", ka);
        Vivod(out, A1, ka);
        fprintf(out, "Массив B1 (количество элементов: %i):\n", kb);
        Vivod(out, B1, kb);
        fprintf(out, "Массив C1 (количество элементов: %i):\n", kc);
        Vivod(out, C1, kc);
    }
    else if (idx_a <= 0 && idx_b > 0 && idx_c > 0) {
        fprintf(out, "Новые массивы B и С сформированы!\n");
        FormNov(&B1, &kb, B, idx_b);
        FormNov(&C1, &kc, C, idx_c);
        fprintf(out, "Массив B1 (количество элементов: %i):\n", kb);
        Vivod(out, B1, kb);
        fprintf(out, "Массив C1 (количество элементов: %i):\n", kc);
        Vivod(out, C1, kc);
    }
    else if (idx_a > 0 && idx_b <= 0 && idx_c > 0) {
        fprintf(out, "Новые массивы A и С сформированы!\n");
        FormNov(&A1, &ka, A, idx_a);
        FormNov(&C1, &kc, C, idx_c);
        fprintf(out, "Массив A1 (количество элементов: %i):\n", ka);
        Vivod(out, A1, ka);
        fprintf(out, "Массив C1 (количество элементов: %i):\n", kc);
        Vivod(out, C1, kc);
    }
    else if (idx_a > 0 && idx_b > 0 && idx_c <= 0) {
        fprintf(out, "Новые массивы A и B сформированы!\n");
        FormNov(&A1, &ka, A, idx_a);
        FormNov(&B1, &kb, B, idx_b);
        fprintf(out, "Массив A1 (количество элементов: %i):\n", ka);
        Vivod(out, A1, ka);
        fprintf(out, "Массив B1 (количество элементов: %i):\n", kb);
        Vivod(out, B1, kb);
    }
    else if (idx_a > 0 && idx_b <= 0 && idx_c <= 0) {
        fprintf(out, "Новый массив A сформирован!\n");
        FormNov(&A1, &ka, A, idx_a);
        fprintf(out, "Массив A1 (количество элементов: %i):\n", ka);
        Vivod(out, A1, ka);
    }
    else if (idx_a <= 0 && idx_b > 0 && idx_c <= 0) {
        fprintf(out, "Новый массив B сформирован!\n");
        FormNov(&B1, &kb, B, idx_b);
        fprintf(out, "Массив B1 (количество элементов: %i):\n", kb);
        Vivod(out, B1, kb);
    }
    else if (idx_a <= 0 && idx_b <= 0 && idx_c > 0) {
        fprintf(out, "Новый массив С сформирован!\n");
        FormNov(&C1, &kc, C, idx_c);
        fprintf(out, "Массив C1 (количество элементов: %i):\n", kc);
        Vivod(out, C1, kc);
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
    Ochistka(&A1);
    Ochistka(&B1);
    Ochistka(&C1);
    return 0;
}
