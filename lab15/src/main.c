#include "list.h"
#include "entity.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CarList list = {NULL, 0};

    readCarsFromFile(argv[1], &list.cars, &list.count);
    printf("Cars from file:\n");
    printCarList(&list);

    printf("\nCars sorted by year:\n");
    sortCarList(&list, compareByYear);
    printCarList(&list);

    printf("\nFinding cars by make 'Ford':\n");
    findCarsByMake(&list, "Ford");

    free(list.cars);
    return EXIT_SUCCESS;
}
