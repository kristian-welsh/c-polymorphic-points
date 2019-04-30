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
    printf("input: (1, 1)\n");
    
    printCartesian();
    printPolar();
    printf("Cartesian ");
    printInjected((Point*)new_CartesianPoint(1, 1));
    printf("Polar ");
    printInjected((Point*)new_PolarPoint(45, 1.41421356));
    
    return 0;
}
