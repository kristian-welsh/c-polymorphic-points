#ifndef c_point
#define c_point
// CartesianPoint implements Point
typedef struct {
    char* (*describe)();
    void (*rotate90)();
		float x;
		float y;
} CartesianPoint;

#endif
CartesianPoint* new_CartesianPoint(float x, float y);

