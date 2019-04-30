#include <stdio.h>
#include <stdlib.h>
#include "polar.h"

char* describe_P(PolarPoint self);
void rotate90_P(PolarPoint self);

char* describe_P(PolarPoint self)
{
		char *str = malloc(sizeof(char)*128);
    sprintf(str, "(theta: %.3f, length: %.3f)", self.theta, self.length);
		return str;
}

void rotate90_P(PolarPoint self)
{
		self.theta += 90;
}

PolarPoint* new_PolarPoint(float theta, float length)
{
    PolarPoint *point = malloc(sizeof(PolarPoint));
    point->describe = describe_P;
    point->rotate90 = rotate90_P;
    point->theta = theta;
    point->length = length;
    return point;
}

