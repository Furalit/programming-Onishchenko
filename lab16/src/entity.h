#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
    int id;
    char make[50];
    int year;
} Car;

int compareByYear(const void* a, const void* b);

#endif // ENTITY_H
