//Лабораторна робота №12. Строки (Null-terminated C Strings)
//Завдання: 14. (*) “Зашифрувати” вхідний текст шифром “Цезаря”

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000
#define SHIFT 9 // Зсув для шифру Цезаря

void caesarCipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

int main() {
    char buffer[BUFFER_SIZE];

    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Видалення символу нового рядка, якщо він є
        buffer[strcspn(buffer, "\n")] = '\0';
        
        caesarCipher(buffer, SHIFT);
        
        printf("Зашифрований текст: %s\n", buffer);
    } else {
        fprintf(stderr, "Помилка зчитування даних\n");
        return 1;
    }

    return 0;
}

