# include "relation.h"

matrix rel_get_mem(int nRows, int nCols) {
    int** values = (int**)malloc(sizeof(int*) * nRows);

    for (int i = 0; i < nRows; i++)
        values[i] = (int*)malloc(sizeof(int) * nCols);

    return (matrix) { values, nRows, nCols };
}

void rel_free_mem(matrix* m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);

    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

// возвращает матрицу размера nRows на nCols, построенную из элементов массива a
matrix rel_create_from_array(const int* a, size_t nRows, size_t nCols) {
    matrix m = rel_get_mem(nRows, nCols);
    int k = 0;

    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

// вывод матрицы m.
void rel_output(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);

        printf("\n");
    }
}

bool rel_subset(matrix* A, matrix* B) {
    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            if (A->values[i][j] > B->values[i][j])
                return 0;

    return 1;
}

bool rel_equal(matrix* A, matrix* B) {
    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            if (A->values[i][j] != B->values[i][j])
                return 0;

    return 1;
}

bool rel_strict_subset(matrix* A, matrix* B) {
    bool is_less_one = 0;

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            if (A->values[i][j] > B->values[i][j])
                return 0;
            else if (A->values[i][j] < B->values[i][j])
                is_less_one = 1;

    return is_less_one;
}

matrix rel_union(matrix* A, matrix* B) {
    matrix uni = rel_get_mem(A->nRows, A->nCols);

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            uni.values[i][j] = A->values[i][j] || B->values[i][j];

    return uni;
}

matrix rel_intersection(matrix* A, matrix* B) {
    matrix intersct = rel_get_mem(A->nRows, A->nCols);

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            intersct.values[i][j] = A->values[i][j] && B->values[i][j];

    return intersct;
}

matrix rel_difference(matrix* A, matrix* B) {
    matrix diff = rel_get_mem(A->nRows, A->nCols);

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            diff.values[i][j] = A->values[i][j] && (!B->values[i][j]);

    return diff;
}

matrix rel_symmetric_difference(matrix* A, matrix* B) {
    matrix sym_diff = rel_get_mem(A->nRows, A->nCols);

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            sym_diff.values[i][j] = (A->values[i][j] && (!B->values[i][j])) || ((!A->values[i][j]) && B->values[i][j]);

    return sym_diff;
}

matrix rel_complement(matrix* A) {
    matrix comp = rel_get_mem(A->nRows, A->nCols);

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            comp.values[i][j] = !A->values[i][j];

    return comp;
}

matrix rel_inverse(matrix A) {
    matrix req = A;

    for (int i = 0; i < req.nRows; i++)
        for (int j = 0; j < req.nCols; j++)
            if (i < j) {
                int temp = req.values[i][j];

                req.values[i][j] = req.values[j][i];
                req.values[j][i] = temp;
            }

    return req;
}

matrix rel_composition(matrix *A, matrix* B) {
    matrix compos = rel_get_mem(A->nRows, A->nCols);

    for (int i = 0; i < A->nRows; i++)
        for (int j = 0; j < A->nCols; j++)
            for (int z = 0; z < A->nCols; z++)
                if (A->values[i][z] && B->values[z][j]) {
                    compos.values[i][j] = 1;
                    break;
                }
                else
                    compos.values[i][j] = 0;

    return compos;
}

matrix rel_degree(matrix A, int degree) {
    assert(degree > -1);

    matrix deg_of_rel;

    if (degree == 0) {
        deg_of_rel = rel_get_mem(A.nRows, A.nCols);

        for (int i = 0; i < A.nRows; i++)
            for (int j = 0; j < A.nCols; j++)
                if (i == j)
                    A.values[i][j] = 1;
    }
    else if (degree == 1)
        return A;
    else{
        deg_of_rel = A;

        for (int i = 0; i < degree - 1; i++)
            deg_of_rel = rel_composition(&deg_of_rel, &A);
    }

    return deg_of_rel;
}
