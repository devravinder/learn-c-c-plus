#include <stdio.h>

int table(int n)
{

    printf("%d table \n", n);

    int max = n * 10;
    int i = 1;

    while (1)
    { // infinite loop ( always true )
        i++;

        if (i % n != 0)
            continue;

        printf("%d ", i);

        if (i == max)
            break;
    }
    printf("\n");

    printf("Done \n");
}

int main()
{

    table(5);
}