#include <stdio.h>
// do while executes at least one time


void printNumbers(int range){

    int index = 0;
    do {
        printf("%d \n", index);
        index++;
    }
    while( index <= range);

    printf("✅ Done \n");

}
int main() {

    printNumbers(5);
    printNumbers(5);

}