#include <stdio.h>

// Визначення максимального розміру матриці
#define MAX_SIZE 100

int main() {
    
    // Оголошення матриці для введених значень
    int matrix[MAX_SIZE][MAX_SIZE];
    
    // Оголошення матриці для результатів множення
    int result[MAX_SIZE][MAX_SIZE];
    
    // Оголошення змінної для розміру матриці
    int N;

    // Введення розміру матриці
    printf("Введіть розмір матриці N: ");
    scanf("%d", &N);

    // Перевірка на коректність введеного розміру
    if (N <= 0 || N > MAX_SIZE) {
        printf("Некоректний розмір матриці. Розмір повинен бути від 1 до %d.\n", MAX_SIZE);
        return 1; // Повертаємо код помилки
    }

    // Введення елементів матриці
    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Елемент [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Множення матриці саму на себе
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    // Виведення результату множення
    printf("Результат множення матриці самої на себе:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

