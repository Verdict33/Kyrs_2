# include <stdio.h>
# include <malloc.h>
# include <stdbool.h>
# include <assert.h>

typedef struct matrix {
    int** values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

// размещает в динамической памяти матрицу размером nRows на nCols
matrix rel_get_mem(int nRows, int nCols);

// освобождает память, выделенную под хранение матрицы m
void rel_free_mem(matrix* m);

// вывод матрицы m
void outputMatrix(matrix m);

// вывод матрицы m
void rel_output(matrix m);

