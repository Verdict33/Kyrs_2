#include "otnochenia_not.h"

bool rel_contains(int set[][2], int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        if (set[i][0] == x && set[i][1] == y) {
            return true;
        }
    }
    return false;
}

bool rel_subset(int A[][2], int size_A, int B[][2], int size_B) {
    for (int i = 0; i < size_A; i++) {
        int x = A[i][0];
        int y = A[i][1];
        if (!rel_contains(B, size_B, x, y)) {
            return false;
        }
    }
    return true;
}

bool rel_equal(int A[][2], int size_A, int B[][2], int size_B) {
    // Проверяем, является ли A подмножеством B
    bool A_in_B = rel_subset(A, size_A, B, size_B);

    // Проверяем, является ли B подмножеством A
    bool B_in_A = rel_subset(B, size_B, A, size_A);
    return A_in_B && B_in_A;
}

bool rel_strict_subset(int A[][2], int size_A, int B[][2], int size_B) {
    // Проверяем, является ли A подмножеством B
    bool A_in_B = rel_subset(A, size_A, B, size_B);
    // Проверяем, что A и B не равны
    bool A_not_equal_B = !rel_equal(A, size_A, B, size_B);
    return A_in_B && A_not_equal_B;
}

// Функция для объединения двух отношений A и B
void rel_union(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res){
    int index = 0;

    // Добавляем все пары из A в результат
    for (int i = 0; i < size_A; i++) {
        result[index][0] = A[i][0];
        result[index][1] = A[i][1];
        index++;
    }

    // Добавляем пары из B, которые еще не содержатся в результате
    for (int i = 0; i < size_B; i++) {
        if (!rel_contains(result, index, B[i][0], B[i][1])) {
            result[index][0] = B[i][0];
            result[index][1] = B[i][1];
            index++;
        }
    }

    *size_res = index;
}

void rel_print(int relation[][2], int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", relation[i][0], relation[i][1]);
    }
    printf("\n");
}

void rel_intersection(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res) {
    int index = 0;

    // Проверяем каждую пару из A, содержится ли она в B
    for (int i = 0; i < size_A; i++) {
        if (rel_contains(B, size_B, A[i][0], A[i][1])) {
            result[index][0] = A[i][0];
            result[index][1] = A[i][1];
            index++;
        }
    }

    *size_res = index;
}

void rel_difference(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res) {
    int index = 0;

    // Проверяем каждую пару из A, не содержится ли она в B
    for (int i = 0; i < size_A; i++) {
        if (!rel_contains(B, size_B, A[i][0], A[i][1])) {
            result[index][0] = A[i][0];
            result[index][1] = A[i][1];
            index++;
        }
    }

    *size_res = index;
}

void rel_symmetric_difference(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res) {
    int index = 0;

    // Проверяем каждую пару из A, не содержится ли она в B
    for (int i = 0; i < size_A; i++) {
        if (!rel_contains(B, size_B, A[i][0], A[i][1])) {
            result[index][0] = A[i][0];
            result[index][1] = A[i][1];
            index++;
        }
    }

    // Проверяем каждую пару из B, не содержится ли она в A
    for (int i = 0; i < size_B; i++) {
        if (!rel_contains(A, size_A, B[i][0], B[i][1])) {
            result[index][0] = B[i][0];
            result[index][1] = B[i][1];
            index++;
        }
    }

    *size_res = index;
}

void rel_complement(int A[][2], int size_A, int U[][2], int size_U, int result[][2], int *size_res) {
    int index = 0;

    // Проверяем каждую пару из U, не содержится ли она в A
    for (int i = 0; i < size_U; i++) {
        if (!rel_contains(A, size_A, U[i][0], U[i][1])) {
            result[index][0] = U[i][0];
            result[index][1] = U[i][1];
            index++;
        }
    }

    *size_res = index;
}

void rel_inverse(int A[][2], int size_A, int result[][2], int *size_res) {
    for (int i = 0; i < size_A; i++) {
        result[i][0] = A[i][1];
        result[i][1] = A[i][0];
    }
    *size_res = size_A;
}

void rel_composition(int A[][2], int size_A, int B[][2], int size_B,  int result[][2], int *size_res) {
    int index = 0;

    // Проверяем каждую пару из A и B
    for (int i = 0; i < size_A; i++) {
        for (int j = 0; j < size_B; j++) {
            if (A[i][1] == B[j][0]) {
                // Если (x, z) из A и (z, y) из B, то добавляем (x, y) в результат
                result[index][0] = A[i][0];
                result[index][1] = B[j][1];
                index++;
            }
        }
    }

    *size_res = index;
}