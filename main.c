#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "cartesian.h"
#include "polar.h"

void printCartesian()
{
    CartesianPoint *point = new_CartesianPoint(1, 1);
    char* out = point->describe(point);
    printf("Cartesian: %s\n", out);
}

void printPolar()
{
    PolarPoint *point = new_PolarPoint(1, 1);
    char* out = point->describe(point);
    printf("polar: %s\n", out);
}

// Depends only on Point interface
void printInjected(Point* injection)
{
    char* out = injection->describe(injection);
    printf("injected as base: %s\n", out);
}

int main()
{
		Point *polar = (Point*)new_PolarPoint(45, 1.414);
		Point *cartesian = (Point*)new_CartesianPoint(2, 1);

    printf("input: (1, 1)\n");
    printCartesian();
    printPolar();

    printf("Cartesian ");
    printInjected(cartesian);
		cartesian->rotate90(cartesian);
    printInjected(cartesian);

    printf("Polar ");
    printInjected(polar);
		polar->rotate90(polar);
    printInjected(polar);
    
    return 0;
}
