// Copyright 2021 Marina Usova

/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции.
Помогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/// <summary>
/// генерация рандомного числа из указанного диапозона
/// </summary>
/// <param name="maximum">максимальное допустимое значение рандома</param>
/// <param name="minimun">минимальное допустимое значение рандома</param>
/// <returns>сгенерированное случайное значение</returns>
int generateRandNumber(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

/// <summary>
/// выделение указаного размера памяти
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// вывод матрицы на экран
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/// <summary>
/// Умножение матрицы на число
/// </summary>
/// <param name="matrix"></param>
/// <param name="n">Число строк</param>
/// <param name="m">Число столбцов</param>
/// <param name="value">Число на которое нужно умножить матрицу</param>
/// <returns></returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* value) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*value);
        }
    }
    return res;
}

void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = generateRandNumber(max, min);
        }
    }
}

void freeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = setMemory(matrix, n, m);
    fillArrayRandValues(matrix, n, m, max, min);
    printf("Matrix %c =\n", name);
    printMatrix(matrix, n, m);
    return matrix;
}

void inputData(int* n, int* m, int* k, int* max, int* min) {
    // только printf scanf_s
    printf("Введите кол-во строк: ");
    scanf_s("%d", n);
    printf("Введите кол-во столбцов: ");
    scanf_s("%d", m);
    printf("Введите кол-во столбцов второй матрицы: ");
    scanf_s("%d", k);
    printf("Введите максимальный элемент: ");
    scanf_s("%d", max);
    printf("Введите минимальный элемент: ");
    scanf_s("%d", min);
}
/// <summary>
/// Транспонирование матрицы
/// </summary>
/// <param name="matrix"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <returns></returns>
int** TransMatrix(int** matrix, int n, int m) {
    int** res = NULL;
    res = setMemory(res, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}
/// <summary>
/// Произведение матрицы А и матрицы В
/// </summary>
/// <param name="matrix_a"></param>
/// <param name="matrix_b"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="k"></param>
/// <returns></returns>
int** ProizMatrix(int** matrix_a, int** matrix_b, int n, int m, int k) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    return res;
}
/// <summary>
/// Сложение матрицы A и матрицы B
/// </summary>
/// <param name="matrix_a"></param>
/// <param name="matrix_b"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="k"></param>
/// <returns></returns>
int** MatrixSum(int** matrix_a, int** matrix_b, int n, int m, int k) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            res[i][j] += matrix_a[i][j] + matrix_b[i][j];
        }
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int** matrix_A = NULL, ** matrix_B = NULL, ** result = NULL;
    int max = 4, min = 0, value = 0, N = 0, M = 0, K = 0;

    //srand(time(0));

    inputData(&N, &M, &K, &max, &min);

    matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
    matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
    value = generateRandNumber(max, min);

    // умножение матрицы на число
    result = setMemory(result, N, M);
    result = multMatrixOnNumber(matrix_A, N, M, &value);
    printf("Matrix A x %d =\n", value);
    printMatrix(result, N, M);
    freeMemory(result, N, M);

    // транспонирование матрицы
    result = setMemory(result, M, N);
    result = TransMatrix(matrix_A, N, M);
    printf("Matrix AT =\n");
    printMatrix(result, M, N);
    // очищение результата после вывода
    freeMemory(result, M, N);

    // умножение двух матриц
    result = setMemory(result, N, K);
    result = ProizMatrix(matrix_A, matrix_B, N, M, K);
    printf("Matrix A x B =\n");
    printMatrix(result, N, K);
    // очищение результата после вывода
    freeMemory(result, N, K);

    // сложение двух матриц
    result = setMemory(result, N, M);
    if (N == M && M == K) {
        result = MatrixSum(matrix_A, matrix_B, N, M, K);
        printf("Matrix A + B =\n");
        printMatrix(result, N, M);
    }
    freeMemory(result, N, M);

    // очищение всей выделенной памяти
    freeMemory(matrix_A, N, M);
    freeMemory(matrix_B, M, K);
}
