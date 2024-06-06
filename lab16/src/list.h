#ifndef LIST_H
#define LIST_H

#include "entity.h"

typedef struct Node {
    Car data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} CarList;

void printCarList(CarList* list);
void addCarToList(CarList* list, Car car);
void removeCarFromList(CarList* list, int index);
void sortCarList(CarList* list, int (*comparator)(const void*, const void*));
void findCarsByMake(CarList* list, const char* make);
void freeCarList(CarList* list);
void readCarsFromFile(const char* filename, CarList* list);
void writeCarsToFile(const char* filename, CarList* list);

#endif // LIST_H
