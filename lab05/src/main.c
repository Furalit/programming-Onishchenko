#include <stdio.h>

int main() {
    // Значення змінної
    int num;
    int prime = 1;
    
    // Зчитування значення змінної
    printf("Введіть ціле число: ");
    scanf("%d", &num);

    if (num <= 1) {
        prime = 0; // Всі числа менше або рівні 1 не є простими
    } else {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                prime = 0; // Якщо num ділиться на i, то num не є простим числом
                break;
            }
        }
    }

    // Виведення результату
    
    if (prime) {
        printf("%d є простим числом.\n", num);
    } else {
        printf("%d не є простим числом.\n", num);
    }

    return 0;
}

