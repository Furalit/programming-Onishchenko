#include <stdio.h>

// Функція для введення значення змінної
int getNum() {
    int num;
    printf("Введіть ціле число: ");
    scanf("%d", &num);
    return num;
}

// Функція для перевірки, чи число є простим
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Всі числа менше або рівні 1 не є простими
    } else {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return 0; // Якщо num ділиться на i, то num не є простим числом
            }
        }
        return 1; // Якщо жодне число не ділить num, то num є простим числом
    }
}

int main() {
    // Значення змінної
    int num;
    int prime = 1;

    // Використання функцій для введення та перевірки числа на простоту
    num = getNum();
    prime = isPrime(num);

    // Виведення результату
    if (prime) {
        printf("%d є простим числом.\n", num);
    } else {
        printf("%d не є простим числом.\n", num);
    }

    return 0;
}


