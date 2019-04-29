#include <stdio.h>
#include <stdlib.h>

// Point interface
typedef struct {
    //int func(int input); (no param defined here though)
    char* (*describe)();
} Point;
// end Point 

// CartesianPoint implements Point
typedef struct {
    char* (*describe)();
		float x;
		float y;
} CartesianPoint;

char* describeC(CartesianPoint self)
{
		char *str = malloc(sizeof(char)*128);
    sprintf(str, "(x: %.3f, y: %.3f)", self.x, self.y);
		return str;
}

CartesianPoint* new_CartesianPoint(float x, float y)
{
    CartesianPoint *point = malloc(sizeof(CartesianPoint));
    point->describe = describeC;
		point->x = x;
		point->y = y;
    return point;
}
// end Point

// PolarPoint implements Point
typedef struct {
    char* (*describe)();
		float theta;
		float length;
} PolarPoint;

char* describeP(PolarPoint self)
{
		char *str = malloc(sizeof(char)*128);
    sprintf(str, "(theta: %.3f, length: %.3f)", self.theta, self.length);
		return str;
}

PolarPoint* new_PolarPoint(float theta, float length)
{
    PolarPoint *point = malloc(sizeof(PolarPoint));
    point->describe = describeP;
    point->theta = theta;
    point->length = length;
    return point;
}
// end PolarPoint

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
