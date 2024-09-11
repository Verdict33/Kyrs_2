#include "otnochenia.h"

bool contains(int set[][2], int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        if (set[i][0] == x && set[i][1] == y) {
            return true;
        }
    }
    return false;
}

bool subset(int A[][2], int size_A, int B[][2], int size_B) {
    for (int i = 0; i < size_A; i++) {
        int x = A[i][0];
        int y = A[i][1];
        if (!contains(B, size_B, x, y)) {
            return false;
        }
    }
    return true;
}

bool equal(int A[][2], int size_A, int B[][2], int size_B) {
    // Проверяем, является ли A подмножеством B
    bool A_in_B = subset(A, size_A, B, size_B);

    // Проверяем, является ли B подмножеством A
    bool B_in_A = subset(B, size_B, A, size_A);
    return A_in_B && B_in_A;
}

// Функция для проверки строгого включения A в B
bool strict_subset(int A[][2], int size_A, int B[][2], int size_B) {
    // Проверяем, является ли A подмножеством B
    bool A_in_B = subset(A, size_A, B, size_B);
    // Проверяем, что A и B не равны
    bool A_not_equal_B = !equal(A, size_A, B, size_B);
    return A_in_B && A_not_equal_B;
}