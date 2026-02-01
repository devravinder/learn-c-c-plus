#include <stdio.h>

int main(int argc, char const *argv[])
{
   int matrix[2][3] = {
        {1,2,3},
        {4,5,6}
    };


    printf("%d \n", matrix[0][1]);// access

    printf("=========loop============\n");

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
        


    // arr == &arr[0] // Array name = address of first element


    return 0;
}
