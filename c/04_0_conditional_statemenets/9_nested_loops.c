#include <stdio.h>

/*

height = 5

*
**
***
****
*****

*/
void pattern1(int height)
{

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void pattern2(int height)
{

    for (int i = 0; i < height; i++)
    {

        // for gaps
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < (2 * i) + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{

    pattern1(5);

    printf("\n");

    pattern2(5);
}