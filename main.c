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

// Основная функция
int main() {

    SetConsoleOutputCP(CP_UTF8);

    // Определяем множество A
    int A[][2] = {{1, 2}};
    int sizeA = sizeof(A) / sizeof(A[0]);

    // Определяем множество B
    int B[][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int sizeB = sizeof(B) / sizeof(B[0]);

    // Проверяем, является ли A подмножеством B
    if (isSubset(A, sizeA, B, sizeB)) {
        printf("Множество A является подмножеством множества B.\n");
    } else {
        printf("Множество A не является подмножеством множества B.\n");
    }

    return 0;
}
