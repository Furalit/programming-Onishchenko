#include "menu.h"
#include "list.h"
#include <stdlib.h>

int main() {
    CarList list = {NULL, 0};
    showMenu(&list);
    freeCarList(&list);
    return 0;
}
