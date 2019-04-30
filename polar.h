#ifndef p_point
#define p_point
// PolarPoint implements Point
typedef struct {
    char* (*describe)();
		float theta;
		float length;
} PolarPoint;
#endif

PolarPoint* new_PolarPoint(float theta, float length);

