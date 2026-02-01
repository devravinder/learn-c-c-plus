#include <stdio.h>



void greet(){
    printf("Hello! How are you?\n");
}

char giveChar(){
    return 'A';
}

int add(int f, int s){
    return f+s;
}

// declare functions first then use

int main(int argc, char const *argv[])
{
    printf("Main function\n");
    greet();

    char ch = giveChar();

    printf("char is %c \n", ch);


    int sum = add(2, 4);

    printf("The sum is %d \n", sum);

    sum = add(2, 2);

    printf("The sum is %d \n", sum);


    return 0;
}
