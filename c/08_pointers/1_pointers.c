#include <stdio.h>

/*
pointer:-
 - is a variable that stores the address of another variable.
 - Instead of holding a value, it holds where the value lives in memory.
*/

int main(){

    int age = 10;
    int *pAge = &age; // * = pointer  & = address

    printf("age = %d\n", age);              // age value
    printf("address of age = %p\n", &age);  // age address
    printf("pAge = %p\n", pAge);              // age address ( pAge value )
    printf("de-referencing = value at pAge = %d\n", *pAge);    // age value ( value at pAge pointer )
                                              // *pAge is called de-referencing = accessing the value at the pointer
                                              // *pAge = *&age


    printf("=======changing value using pointer =====\n");
    *pAge = 20;
    printf("%d \n", age);   // 20



}