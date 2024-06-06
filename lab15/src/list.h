#ifndef LIST_H
#define LIST_H

#include "entity.h"

typedef struct {
    Car* cars;
    int count;
} CarList;

void printCarList(CarList* list);
void addCarToList(CarList* list, Car car);
void removeCarFromList(CarList* list, int index);
void sortCarList(CarList* list, int (*comparator)(const void*, const void*));
void findCarsByMake(CarList* list, const char* make);

#endif // LIST_H
