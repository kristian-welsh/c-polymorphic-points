#include <stdio.h>
#include <stdlib.h>
#include "polar.h"

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

