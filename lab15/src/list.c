#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printCarList(CarList* list) {
    for (int i = 0; i < list->count; i++) {
        printf("ID: %d, Make: %s, Year: %d\n", list->cars[i].id, list->cars[i].make, list->cars[i].year);
    }
}

void addCarToList(CarList* list, Car car) {
    list->cars = realloc(list->cars, (size_t)(list->count + 1) * sizeof(Car));
    if (list->cars == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    list->cars[list->count] = car;
    list->count++;
}

void removeCarFromList(CarList* list, int index) {
    if (index < 0 || index >= list->count) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    for (int i = index; i < list->count - 1; i++) {
        list->cars[i] = list->cars[i + 1];
    }
    list->count--;
    list->cars = realloc(list->cars, (size_t)list->count * sizeof(Car));
    if (list->count > 0 && list->cars == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
}

void sortCarList(CarList* list, int (*comparator)(const void*, const void*)) {
    qsort(list->cars, (size_t)list->count, sizeof(Car), comparator);
}

void findCarsByMake(CarList* list, const char* make) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->cars[i].make, make) == 0) {
            printf("ID: %d, Make: %s, Year: %d\n", list->cars[i].id, list->cars[i].make, list->cars[i].year);
        }
    }
}
