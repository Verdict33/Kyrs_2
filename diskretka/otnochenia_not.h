#include <stdio.h>
#include <stdbool.h>

// Функция для проверки, содержится ли пара в множестве
bool rel_contains(int set[][2], int size, int x, int y);

// Функция для проверки включения A в B
bool rel_subset(int A[][2], int size_A, int B[][2], int size_B);

// Функция для проверки равенства множеств
bool rel_equal(int A[][2], int size_A, int B[][2], int size_B);

// Функция для проверки строгого включения A в B
bool rel_strict_subset(int A[][2], int size_A, int B[][2], int size_B);

void rel_union(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res);

// Функция для вывода отношения
void rel_print(int relation[][2], int size);

// Функция для пересечения двух отношений A и B
void rel_intersection(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res);

// Функция для разности двух отношений A и B
void rel_difference(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res);

// Функция для симметрической разности двух отношений A и B
void rel_symmetric_difference(int A[][2], int size_A, int B[][2], int size_B, int result[][2], int *size_res);

// Функция для дополнения отношения A до универсального отношения U
void rel_complement(int A[][2], int size_A, int U[][2], int size_U, int result[][2], int *size_res);

// Функция для обращения отношения A
void rel_inverse(int A[][2], int size_A, int result[][2], int *size_res);

// Функция для композиции отношений A и B
void rel_composition(int A[][2], int size_A, int B[][2], int size_B,  int result[][2], int *size_res);