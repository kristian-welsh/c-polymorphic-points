// kristian point, because point is defined in a std lib
#ifndef k_point
#define k_point
// Point interface
typedef struct {
    //int func(int input); (no param defined here though)
    char* (*describe)();
    void (*rotate90)();
} Point;
// end Point 
#endif

