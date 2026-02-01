#include <stdio.h>

int main(){


    int arr[5] = {10, 20, 30, 40, 50};
    // int arr[] = {1, 2, 3, 4}; // auto sizing

    printf("1st elemnt %d \n", arr[0]); // index starts at zero (0)
    printf("2nd elemnt %d \n", arr[1]);


    int size = sizeof(arr) / sizeof(arr[0]); // sizeof gives memory size (bits)   ***

    printf("last element %d \n", arr[size-1]);


    arr[0] = 30;

    printf("after modification 1st elemnt %d \n", arr[0]);

    printf("==========char array============\n");

    char name[] = "Ravinder Reddy Kothabad"; // this is char array

    printf("name: %s \n", name);



    printf("======================\n");

    double prices[5]; // initializes to zero ( default values are set to zero )

    prices[1]=12.3;
    prices[2]=12.5;
    prices[3]=66.6;

    printf("The prices \n");
    for(int i = 0; i < 5; i++) {
    printf("%.3lf \n", prices[i]);
    }

    printf("5 th element %lf \n", prices[4]); // 0 default value



    printf("======================\n");
    int ranks[5]; // uninitialized array

     printf("The ranks \n");
    for(int i = 0; i < 5; i++) {
     printf("%d \n", ranks[i]); // Some random garbage values (unpredictable numbers)
    }

    printf(" 1st element uninitialize %d \n", ranks[0]);

    printf("======================\n");
    int makrs[5];

    for(int i = 0; i < 5; i++) {
        printf("Enter a number \n");
        scanf("%d", &makrs[i]);
    }

    int makrsSize = sizeof(makrs) / sizeof(makrs[0]); // sizeof gives memory size (bits)   ***

    printf("The %d numbers \n", makrsSize);
    for(int i = 0; i < 5; i++) {
     printf("%d \n", makrs[i]);
    }


 }