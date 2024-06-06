#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu(CarList* list) {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Print car list\n");
        printf("2. Add a car\n");
        printf("3. Remove a car\n");
        printf("4. Sort car list by year\n");
        printf("5. Find cars by make\n");
        printf("6. Read cars from file\n");
        printf("7. Write cars to file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int index;
        Car car;
        char make[50];
        char filename[100];

        switch (choice) {
            case 1:
                printCarList(list);
                break;
            case 2:
                printf("Enter car details (id, make, year): ");
                scanf("%d,%49[^,],%d", &car.id, car.make, &car.year);
                addCarToList(list, car);
                break;
            case 3:
                printf("Enter index of car to remove: ");
                scanf("%d", &index);
                removeCarFromList(list, index);
                break;
            case 4:
                sortCarList(list, compareByYear);
                break;
            case 5:
                printf("Enter make to find: ");
                scanf("%s", make);
                findCarsByMake(list, make);
                break;
            case 6:
                printf("Enter filename to read from: ");
                scanf("%s", filename);
                readCarsFromFile(filename, list);
                break;
            case 7:
                printf("Enter filename to write to: ");
                scanf("%s", filename);
                writeCarsToFile(filename, list);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
}
