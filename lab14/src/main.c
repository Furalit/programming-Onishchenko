
#include "lib.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Car* cars = NULL;
    int count = 0;

    readCarsFromFile(argv[1], &cars, &count);
    printf("Cars from file:\n");
    printCars(cars, count);

    printf("\nCars sorted by year:\n");
    sortCars(cars, count, compareByYear);
    printCars(cars, count);

    printf("\nFinding cars by make 'Ford':\n");
    findCarsByMake(cars, count, "Ford");

    free(cars);
    return EXIT_SUCCESS;
}
