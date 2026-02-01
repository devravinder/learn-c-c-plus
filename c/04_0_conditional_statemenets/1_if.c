#include <stdio.h>

/*
 if,
 if-else
 if-else if ( ladder )

 ----
 true - 1
 false - 0

*/ 



int main(){


    printf("==========if======\n");

    int age = 18;

    if (age >= 18) {
        printf("You can vote\n");
    }


    printf("=======if-else=======\n");


     age = 15;

     int isAudult = age >= 18;

     printf("is Adult %d \n", isAudult);


    if (isAudult) {
        printf("Adult\n");
    } else {
        printf("Minor\n");
    }



    printf("===========if-else if(ladder)========\n");

    int marks = 85;

    if (marks >= 90) {
        printf("Grade A\n");
    } 
    else if (marks >= 75) {
        printf("Grade B\n");
    }
    else if (marks >= 60) {
        printf("Grade C\n");
    }
    else {
        printf("Fail\n");
    }



}