//Лабораторна робота №10
//Завдання: 10. (*) Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, отриманий масив упорядкувати за зростанням.

#include <stdio.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    printf("Введіть розмір матриці N: ");
    scanf("%d", &N);

    int matrix[N][N];
    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int diag[N];
    for (int i = 0; i < N; i++) {
        diag[i] = matrix[i][i];
    }

    sortArray(diag, N);

    printf("Відсортовані елементи головної діагоналі: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", diag[i]);
    }
    printf("\n");

    return 0;
}
