#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printCarList(CarList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("ID: %d, Make: %s, Year: %d\n", current->data.id, current->data.make, current->data.year);
        current = current->next;
    }
}

void addCarToList(CarList* list, Car car) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_node->data = car;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->count++;
}

void removeCarFromList(CarList* list, int index) {
    if (index < 0 || index >= list->count) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;

    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    list->count--;
}

void sortCarList(CarList* list, int (*comparator)(const void*, const void*)) {
    if (list->count < 2) return;

    for (int i = 0; i < list->count - 1; i++) {
        Node* current = list->head;
        Node* next = current->next;
        for (int j = 0; j < list->count - 1 - i; j++) {
            if (comparator(&current->data, &next->data) > 0) {
                Car temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            current = next;
            next = next->next;
        }
    }
}

void findCarsByMake(CarList* list, const char* make) {
    Node* current = list->head;
    while (current != NULL) {
        if (strcmp(current->data.make, make) == 0) {
            printf("ID: %d, Make: %s, Year: %d\n", current->data.id, current->data.make, current->data.year);
        }
        current = current->next;
    }
}

void freeCarList(CarList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->count = 0;
}
