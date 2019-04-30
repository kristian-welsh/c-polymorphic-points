#ifndef c_point
#define c_point
// CartesianPoint implements Point
typedef struct {
    char* (*describe)();
		float x;
		float y;
} CartesianPoint;
CartesianPoint* new_CartesianPoint(float x, float y);
#endif

