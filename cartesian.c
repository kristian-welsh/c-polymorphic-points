#include <stdio.h>
#include <stdlib.h>
#include "cartesian.h"

char* describeC(CartesianPoint self);

CartesianPoint* new_CartesianPoint(float x, float y)
{
    CartesianPoint *point = malloc(sizeof(CartesianPoint));
    point->describe = describeC;
		point->x = x;
		point->y = y;
    return point;
}

char* describeC(CartesianPoint self)
{
		char *str = malloc(sizeof(char)*128);
    sprintf(str, "(x: %.3f, y: %.3f)", self.x, self.y);
		return str;
}

