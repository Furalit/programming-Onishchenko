#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readCarsFromFile(const char* filename, Car** cars, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "%d", count) != 1) {
        fprintf(stderr, "Failed to read count from file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    *cars = malloc((size_t)(*count) * sizeof(Car));
    if (*cars == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *count; i++) {
        if (fscanf(file, "%d,%49[^,],%d", &(*cars)[i].id, (*cars)[i].make, &(*cars)[i].year) != 3) {
            fprintf(stderr, "Failed to read car data from file\n");
            fclose(file);
            free(*cars);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void writeCarsToFile(const char* filename, Car* cars, int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d\n", cars[i].id, cars[i].make, cars[i].year);
    }

    fclose(file);
}

void printCars(Car* cars, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Make: %s, Year: %d\n", cars[i].id, cars[i].make, cars[i].year);
    }
}

int compareByYear(const void* a, const void* b) {
    Car* carA = (Car*)a;
    Car* carB = (Car*)b;
    return carA->year - carB->year;
}
