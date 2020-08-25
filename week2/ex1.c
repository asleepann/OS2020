#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("int value: %d size: %lu\n", a, sizeof(a));
    printf("float value: %f size: %lu\n", b, sizeof(b));
    printf("double value: %f size: %lu\n", c, sizeof(c));
    return 0;
}
