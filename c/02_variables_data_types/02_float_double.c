#include <stdio.h>

int main() {


    printf("----------float vs double -------------\n");

    float f = 1.123456789;
    double d = 1.123456789;

    printf("float %f \n", f);
    printf("double %lf \n", d);   // printf shows only till 6 decimals by default

    printf("----------pricison formatting -------------\n");

    printf("pricison float %.2f \n", f); // %.[number]f // It controls digits after decimal point.
    printf("double %.15lf \n", d);


    printf("width + pricison float:%6.2f:\n", f); // %[width].[precision]f // total width 6 chars


    float height = 1.4244000;

    printf("height %g \n", height);   // %g removes height

    return 0;
}