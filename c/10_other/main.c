#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

size
strcpy
free
mallaoc

rand, time, srand
*/ 

int main()
{

    printf("\n");
    printf("==========memory pointer===========\n");
    int i = 10;
    printf("memory address(pointer): %p \n", &i); // & for pointer

    printf("\n");
    printf("==========array length/size===========\n");

    int arr[5] = {10, 20, 30, 40, 50};

    int size = sizeof(arr) / sizeof(arr[0]); // sizeof gives memory size (bits)   ***

    printf("array size/length: %d \n", size);

    printf("\n");
    printf("==========random number===========\n");

    srand(time(NULL)); // seed ONCE  per program: to get random number on every call

    int random = rand(); // rand() gives same number on very calls, if don't set: srand(time(NULL));

    printf("random number: %d \n", random);


}
