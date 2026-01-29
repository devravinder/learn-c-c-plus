#include <stdio.h>

int main(){


    int age;
    double gpa;
    char name[20]; // length is mandatory for memory allocation
    char fullName[50];

    char village[20];
    char state[20];

    


    printf("enter your age\n");

    scanf("%d", &age); // & is pointer

    printf("your age is %d \n", age);


    //----
    printf("enter your gpa\n");

    scanf("%lf", &gpa);

    printf("your gpa is %0.2lf \n", gpa);

    //----
    printf("enter your name\n");

    scanf("%s", name); // &(pointer) is not needed
    // takes only one string
    // scanf("%s", &name);

    printf("your name is %s \n", name);


        //----
    printf("enter your village & state\n");


    scanf("%s%s", village, state); // two inputs at a time

    printf("your  village & state %s & %s \n", village, state);

    //----
    printf("enter your full name\n");

    getchar();  // CLEAR BUFFER // // consume leftover newline // else newline will be taken fgets as input

    fgets(fullName, 50, stdin); // multi string input 
        // variable, legth of chars, stdin(where to get the input)

    printf("your full name is %s \n", fullName);

    return 0;
}