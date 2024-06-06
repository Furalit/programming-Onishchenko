#include "list.h"
#include "entity.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CarList list = {NULL, 0};
    
    Car car1 = {1, "Ford", 2005};
    Car car2 = {2, "Toyota", 2010};
    Car car3 = {3, "Ford", 2012};
    
    addCarToList(&list, car1);
    addCarToList(&list, car2);
    addCarToList(&list, car3);

    printf("Initial list:\n");
    printCarList(&list);

    printf("\nList after removing second car:\n");
    removeCarFromList(&list, 1);
    printCarList(&list);

    printf("\nList after sorting by year:\n");
    sortCarList(&list, compareByYear);
    printCarList(&list);

    freeCarList(&list);
    return 0;
}
