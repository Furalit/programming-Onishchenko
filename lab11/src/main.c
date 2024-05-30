//Лабораторна робота:11
//Завдання: Визначити добуток двох матриць.
#include <stdio.h>

void printMatrix(float matrix[3][3]) {
    for(int i = 0; i < 3; i++) {
        printf("[ ");
        for(int j = 0; j < 3; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("]\n");
    }
}

void multiplyMatrices(float matrix1[3][3], float matrix2[3][3], float result[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    printf("Автор: Онiщенко Данiiл\n");
    printf("Номер лабораторної роботи: 11\n");
    printf("Тема: Визначення добутку двох матриць\n");

    float matrix1[3][3];
    float matrix2[3][3];
    float result[3][3];

    printf("Введіть елементи першої матриці (3x3):\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("matrix1[%d][%d]: ", i, j);
            scanf("%f", &matrix1[i][j]);
        }
    }

    printf("Введіть елементи другої матриці (3x3):\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("matrix2[%d][%d]: ", i, j);
            scanf("%f", &matrix2[i][j]);
        }
    }

    multiplyMatrices(matrix1, matrix2, result);

    printf("Результат добутку матриць:\n");
    printMatrix(result);

    return 0;
}

