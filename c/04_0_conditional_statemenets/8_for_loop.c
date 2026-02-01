#include <stdio.h>

void printNumbers(int range)
{
    for (int i = 1; i <= range; i++)
    {
        printf("%d ", i);
    }
}

void skipNumbers(int range, int skip)
{
    for (int i = 1; i <= range; i++)
    {

        if (i == skip)
        {
            continue; // skip printing
        }

        printf("%d ", i);
    }
}

void table(int n)
{

    for (int i = n; i <= n * 10; i = i + n)
    {
        printf("%d ", i);
    }
}

int main()
{

    printNumbers(10);
    printf("\n");

    skipNumbers(10, 5);
    printf("\n");

    table(5);
    printf("\n");

    return 0;
}