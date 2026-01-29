#include <stdio.h>
int main() {

    int i = 10;
    printf("%d \n", i);

    i = 20;
    printf("%d \n", i);


    const int c = 10;
    printf("%d \n", c);

    // c = 20; // throws errorr
    printf("%d \n", c);

    return 0;
}