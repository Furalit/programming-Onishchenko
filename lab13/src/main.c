//Лабораторна робота №13. Взаємодія з файлами
//Завдання: 1. Розробити програму, що в заданому файлі створює суцільний рівнобедрений трикутник із заданих символів (наприклад, зірочок). Висота трикутника, символ заповнювача та ширина основи задається у вхідному файлу

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile = fopen("./assets/input.txt", "r");
    FILE *outputFile = fopen("./assets/output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        return 1; // Завершити програму, якщо файли не відкрилися
    }

    int height, base;
    char fillChar;

    fscanf(inputFile, "%d %d %c", &height, &base, &fillChar);

    // Визначити середину основи
    int mid = base / 2;

    for (int i = 0; i < height; i++) {
        int numChars = 2 * i + 1; // Кількість символів у рядку
        int padding = (base - numChars) / 2; // Кількість пробілів зліва

        for (int j = 0; j < padding; j++) {
            fputc(' ', outputFile);
        }
        for (int j = 0; j < numChars; j++) {
            fputc(fillChar, outputFile);
        }
        for (int j = 0; j < padding; j++) {
            fputc(' ', outputFile);
        }

        fputc('\n', outputFile); // Перехід на новий рядок
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

