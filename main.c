//# include <stdio.h>
//# include <malloc.h>
//# include <assert.h>
//
//typedef struct matrix {
//    int** values; // элементы матрицы
//    int nRows; // количество рядов
//    int nCols; // количество столбцов
//} matrix;
//
//matrix rel_get_mem(int nRows, int nCols) {
//    int** values = (int**)malloc(sizeof(int*) * nRows);
//
//    for (int i = 0; i < nRows; i++)
//        values[i] = (int*)malloc(sizeof(int) * nCols);
//
//    return (matrix) { values, nRows, nCols };
//}
//
//matrix rel_create_from_array(const int* a, size_t nRows, size_t nCols) {
//    matrix m = rel_get_mem(nRows, nCols);
//    int k = 0;
//
//    for (int i = 0; i < nRows; i++)
//        for (int j = 0; j < nCols; j++)
//            m.values[i][j] = a[k++];
//
//    return m;
//}
//
//matrix rel_composition(matrix *A, matrix* B) {
//    matrix compos = rel_get_mem(A->nRows, A->nCols);
//
//    for (int i = 0; i < A->nRows; i++)
//        for (int j = 0; j < A->nCols; j++)
//            for (int z = 0; z < A->nCols; z++)
//                if (A->values[i][z] && B->values[z][j]) {
//                    compos.values[i][j] = 1;
//                    break;
//                }
//                else
//                    compos.values[i][j] = 0;
//
//    return compos;
//}
//
//matrix rel_degree(matrix A, int degree) {
//    assert(degree > -1);
//
//    matrix deg_of_rel;
//
//    if (degree == 0) {
//        deg_of_rel = rel_get_mem(A.nRows, A.nCols);
//
//        for (int i = 0; i < A.nRows; i++)
//            for (int j = 0; j < A.nCols; j++)
//                if (i == j)
//                    A.values[i][j] = 1;
//    }
//    else if (degree == 1)
//        return A;
//
//    else{
//
//        deg_of_rel = A;
//
//        for (int i = 0; i < degree - 1; i++)
//            deg_of_rel = rel_composition(&deg_of_rel, &A);
//    }
//
//    return deg_of_rel;
//}
//
//matrix rel_inverse(matrix A) {
//    matrix req = A;
//
//    for (int i = 0; i < req.nRows; i++)
//        for (int j = 0; j < req.nCols; j++)
//            if (i < j) {
//                int temp = req.values[i][j];
//
//                req.values[i][j] = req.values[j][i];
//                req.values[j][i] = temp;
//            }
//
//    return req;
//}
//
//matrix rel_difference(matrix* A, matrix* B) {
//    matrix diff = rel_get_mem(A->nRows, A->nCols);
//
//    for (int i = 0; i < A->nRows; i++)
//        for (int j = 0; j < A->nCols; j++)
//            diff.values[i][j] = A->values[i][j] && (!B->values[i][j]);
//
//    return diff;
//}
//
//matrix rel_union(matrix* A, matrix* B) {
//    matrix uni = rel_get_mem(A->nRows, A->nCols);
//
//    for (int i = 0; i < A->nRows; i++)
//        for (int j = 0; j < A->nCols; j++)
//            uni.values[i][j] = A->values[i][j] || B->values[i][j];
//
//    return uni;
//}
//
//void rel_output(matrix m) {
//    for (int i = 0; i < m.nRows; i++) {
//        for (int j = 0; j < m.nCols; j++)
//            printf("%d ", m.values[i][j]);
//
//        printf("\n");
//    }
//}
//
//int main() {
//    matrix A = rel_create_from_array((int[])
//                                             {
//                                                     0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
//                                                     1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
//                                                     0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
//                                                     0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
//                                                     1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
//                                                     0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
//                                                     0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
//                                                     1, 0, 0, 1, 0, 0, 1, 0, 0, 1,
//                                                     0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
//                                                     0, 1, 0, 0, 1, 0, 0, 1, 0, 0
//                                             }, 10, 10);
//
//    matrix B = rel_create_from_array((int[])
//                                             {
//                                                     0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
//                                                     0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//                                                     0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
//                                                     0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
//                                                     0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
//                                             }, 10, 10);
//
//    matrix C = rel_create_from_array((int[])
//                                             {
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
//                                                     1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
//                                                     1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
//                                                     1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
//                                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                                             }, 10, 10);
//
//    matrix first_step = rel_degree(A, 2);
//
//    printf("degree A^2:\n");
//    rel_output(first_step);
//    printf("\n");
//
//    matrix second_step = rel_inverse(A);
//
//    printf("inverse A:\n");
//    rel_output(second_step);
//    printf("\n");
//
//    matrix third_step = rel_composition(&second_step, &C);
//
//    printf("composition (inverse A and C):\n");
//    rel_output(third_step);
//    printf("\n");
//
//    matrix fourth_step = rel_difference(&first_step, &B);
//
//    printf("difference (Degree A^2 and B):\n");
//    rel_output(fourth_step);
//    printf("\n");
//
//    matrix fifth_step = rel_union(&fourth_step, &third_step);
//
//    printf("union ((difference (Degree A^2 and B)) and composition (inverse A and C)):\n");
//    rel_output(fifth_step);
//    printf("\n");
//
//    return 0;
//}
