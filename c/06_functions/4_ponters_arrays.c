#include <stdio.h>


int main(){

    printf("\n");

    int arr[3] = {10,20,30};

    int *p = arr;   // the pointer points first element adress
                    // array it self is a address reference, so &arr is not required

    printf("%d \n", *p);
    printf("%d \n", *(p+1)); // next pointer
    printf("%d \n", *(p+2));

    printf("===loop======\n");

     for(int i = 0; i < 3; i++) {

        printf("arr[%d] = %d\n", i, arr[i]);
        printf("*(arr + %d) = %d\n\n", i, *(arr + i)); // value at address ( array first element + i )
    }


}