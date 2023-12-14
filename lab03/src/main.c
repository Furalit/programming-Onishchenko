#include <stdio.h>

int main()
{   
    int r1;
    int r2;
    int r3;

    printf("Опір резистору r1: ");
    scanf("%d", &r1);
    printf("Опір резистору r2: ");
    scanf("%d", &r2);
    printf("Опір резистору r3: ");
    scanf("%d", &r3);


    
    float r = (float)(1/((1.0 / r1) + (1.0 / r2) + (1.0 / r3)));
    printf("Загальний опір паралельно з'єднаних резисторів: %f\n", r);

	return 0;
}
