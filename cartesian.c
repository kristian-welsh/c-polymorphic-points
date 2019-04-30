#include <stdio.h>
#include <stdlib.h>
#include "cartesian.h"

char* describe_C(CartesianPoint self);
void rotate90_C(CartesianPoint self);

char* describe_C(CartesianPoint self)
{
		char *str = malloc(sizeof(char)*128);
    sprintf(str, "(x: %.3f, y: %.3f)", self.x, self.y);
		return str;
}

void rotate90_C(CartesianPoint self)
{
		float oldx = self.x;
		self.x = -self.y;
		self.y = -oldx;
}

CartesianPoint* new_CartesianPoint(float x, float y)
{
    CartesianPoint *point = malloc(sizeof(CartesianPoint));
    point->describe = describe_C;
    point->rotate90 = rotate90_C;
		point->x = x;
		point->y = y;
    return point;
}

