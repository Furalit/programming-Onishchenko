#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    int id;
    char make[50];
    int year;
} Car;

void readCarsFromFile(const char* filename, Car** cars, int* count);
void writeCarsToFile(const char* filename, Car* cars, int count);
void printCars(Car* cars, int count);
int compareByYear(const void* a, const void* b);

#endif // ENTITY_H
