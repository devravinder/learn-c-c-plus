#include <stdio.h>


void printNumbers(int range){

    int index = 0;
    while( index <= range){
        printf("%d \n", index);
        index++;
    }

    printf("✅ Done \n");

}

int main() {

    printNumbers(5);
    printNumbers(5);
}