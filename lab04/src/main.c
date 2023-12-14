#include <stdio.h>

int main() {
    int a, b, c;

    printf("Введіть значення a: ");
    scanf("%d", &a);

    printf("Введіть значення b: ");
    scanf("%d", &b);

    printf("Введіть значення c: ");
    scanf("%d", &c);

    // Знаходження мінімального значення
        int min = a;
    
    if (b < min) {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    printf("Мінімальне значення: %d\n", min);

    return 0;
}

