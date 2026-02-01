#include <stdio.h>

/*

open terminal in this folder
build: gcc 2_cmd_args.c -o 2_cmd_args
run  : ./2_cmd_args hello 123 world


*/ 

int main(int argc, char const *argv[]) // arg count, aruguments
{
     printf("Argument count: %d\n", argc);

    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}
