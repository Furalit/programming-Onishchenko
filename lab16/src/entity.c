#include "entity.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readCarsFromFile(const char* filename, CarList* list) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    int count;
    if (fscanf(file, "%d", &count) != 1) {
        fprintf(stderr, "Failed to read count from file\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        Car car;
        if (fscanf(file, "%d,%49[^,],%d", &car.id, car.make, &car.year) != 3) {
            fprintf(stderr, "Failed to read car data from file\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        addCarToList(list, car);
    }

    fclose(file);
}

void writeCarsToFile(const char* filename, CarList* list) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", list->count);
    Node* current = list->head;
    while (current != NULL) {
        fprintf(file, "%d,%s,%d\n", current->data.id, current->data.make, current->data.year);
        current = current->next;
    }

    fclose(file);
}

int compareByYear(const void* a, const void* b) {
    Car* carA = (Car*)a;
    Car* carB = (Car*)b;
    return carA->year - carB->year;
}
