
#ifndef LIB_H
#define LIB_H

#include <stdio.h>

typedef struct {
    int id;
    char make[50];
    int year;
} Car;

void readCarsFromFile(const char* filename, Car** cars, int* count);
void writeCarsToFile(const char* filename, Car* cars, int count);
void printCars(Car* cars, int count);
void findCarsByMake(Car* cars, int count, const char* make);
void sortCars(Car* cars, int count, int (*comparator)(const void*, const void*));
int compareByYear(const void* a, const void* b);

#endif // LIB_H
