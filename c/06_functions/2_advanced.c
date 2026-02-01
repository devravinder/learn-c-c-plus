#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// complete pointers befor this

char* giveMessage() {

    //  char message[] = "Hello";
    //  return message;

    return "Hello";
}


char* giveName() {
    char *name = malloc(20);
    strcpy(name, "Ravinder");
    return name;
}


void setName(char name[]) {
    strcpy(name, "Reddy");
}


void printName(char name[]){
    printf("%s\n", name);
}


int main(){

    char *message = giveMessage();
    printf("%s\n", message);


    printf("=============\n");

    char *n = giveName(); // best way
    printf("%s\n", n);
    free(n);   // VERY important


    printf("===============\n");

    char name[20];
    setName(name); // re
    printName(name);



}