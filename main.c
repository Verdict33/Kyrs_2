#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

// Функция для проверки, содержится ли пара в множестве
bool contains(int set[][2], int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        if (set[i][0] == x && set[i][1] == y) {
            return true;
        }
    }
    return false;
}

// Функция для проверки включения A в B
bool isSubset(int A[][2], int sizeA, int B[][2], int sizeB) {
    for (int i = 0; i < sizeA; i++) {
        int x = A[i][0];
        int y = A[i][1];
        if (!contains(B, sizeB, x, y)) {
            return false;
        }
    }
    return true;
}

bool areEqual(int A[][2], int sizeA, int B[][2], int sizeB) {
    // Проверяем, является ли A подмножеством B
    bool A_in_B = isSubset(A, sizeA, B, sizeB);
    // Проверяем, является ли B подмножеством A
    bool B_in_A = isSubset(B, sizeB, A, sizeA);
    return A_in_B && B_in_A;
}

// Функция для проверки строгого включения A в B
bool isStrictSubset(int A[][2], int sizeA, int B[][2], int sizeB) {
    // Проверяем, является ли A подмножеством B
    bool A_in_B = isSubset(A, sizeA, B, sizeB);
    // Проверяем, что A и B не равны
    bool A_not_equal_B = !areEqual(A, sizeA, B, sizeB);
    return A_in_B && A_not_equal_B;
}

// Основная функция
int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Определяем множество A
    int A[][2] = {{3, 3},{2, 3}};
    int sizeA = sizeof(A) / sizeof(A[0]);

    // Определяем множество B
    int B[][2] = {{1, 2}, {2, 3}, {3, 4}};
    int sizeB = sizeof(B) / sizeof(B[0]);

    // Проверяем строгое включение A в B
    if (isStrictSubset(A, sizeA, B, sizeB)) {
        printf("Множество A строго включено в множество B.\n");
    } else {
        printf("Множество A не является строгим подмножеством множества B.\n");
    }

    return 0;
}