#include <stdio.h>
#include <stdbool.h>

// Функция для проверки, содержится ли пара в множестве
bool contains(int set[][2], int size, int x, int y);

// Функция для проверки включения A в B
bool subset(int A[][2], int size_A, int B[][2], int size_B);

// Функция для проверки равенства множеств
bool equal(int A[][2], int size_A, int B[][2], int size_B);

// Функция для проверки строгого включения A в B
bool strict_subset(int A[][2], int size_A, int B[][2], int size_B);