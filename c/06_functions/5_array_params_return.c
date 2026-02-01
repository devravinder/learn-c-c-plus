#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char* moves 1 byte at a time
int* moves 4 bytes at a time

---

We can print entire string(char array) using %s,  reference
  - bcz, strings are special, C defines a convention for them.

  - We can't print entire any other array using reference
    - bcs there is no special formatter like %s

*/ 

/* =====================================================
   PASSING INT ARRAY (ARRAY SYNTAX)
   ===================================================== */

void printArray1(int arr[], int size) {   // array syntax
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* =====================================================
   PASSING INT ARRAY (POINTER SYNTAX)
   ===================================================== */

void printArray2(int *arr, int size) {    // pointer syntax (same internally)

    // int *arr = is only first element pointer actually ( single int ) [int pointer]
    // pointer for int address ( 4 bytes ) -> so pointer moves by 4 bytes every time


    for(int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

/* =====================================================
   RETURNING INT ARRAY (USING malloc)
   ===================================================== */

int* createIntArray(int size) {

    int *arr = malloc(size * sizeof(int));   // dynamic memory

    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for(int i = 0; i < size; i++)
        arr[i] = (i + 1) * 10;

    return arr;   // safe to return
}

/* =====================================================
   PASSING STRING (ARRAY SYNTAX)
   ===================================================== */

void greet1(char name[]) {
    printf("Hello %s (array syntax)\n", name);
}

/* =====================================================
   PASSING STRING (POINTER SYNTAX)
   ===================================================== */

void greet2(char *name) { // ***
    // strings are char array -> so pointer to char address ( single char ) [ char pointer ]
    // so the pointer moves by 1 byte ( that's why not int pointer  i.e int *name )

    printf("Hello %s (pointer syntax)\n", name);
       // we can print entire string with special formatter %s & using it reference(pointer)
}

/* =====================================================
   RETURNING STRING USING malloc + strcpy
   ===================================================== */

char* createMessage() {

    char *msg = malloc(30);   // allocate memory for string

    if(msg == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(msg, "Welcome to C pointers!");

    return msg;   // must be freed later
}

/* =====================================================
   MAIN FUNCTION
   ===================================================== */

int main() {

    /* ----- INT ARRAY EXAMPLES ----- */

    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Print using array syntax:\n");
    printArray1(nums, size);

    printf("Print using pointer syntax:\n");
    printArray2(nums, size);


    /* ----- RETURNED INT ARRAY ----- */

    int *dynamicArr = createIntArray(4);

    printf("Returned dynamic array:\n");
    for(int i = 0; i < 4; i++)
        printf("%d ", dynamicArr[i]);

    printf("\n");

    free(dynamicArr);   // VERY IMPORTANT


    /* ----- STRING PASSING ----- */

    char name[] = "Ravinder";

    greet1(name);
    greet2(name);


    /* ----- RETURNED STRING ----- */

    char *message = createMessage();

    printf("Returned string: %s\n", message);

    free(message);   // VERY IMPORTANT


    return 0;
}
