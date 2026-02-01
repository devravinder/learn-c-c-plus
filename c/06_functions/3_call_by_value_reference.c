#include <stdio.h>


// complete pointers befor this

// call by value
void change(int x) { // the arg value will be copied to local varaible x

   x = 20; // we are chainging only local value // this doesn't change the arg value

   printf("value in change %d \n", x);


}

// call by reference
void modify(int *p) {
   *p = 20;

    printf("value in modify %d \n", *p);
}



int main(){

    printf("\n");

    int i = 10;

    printf("before call by value: value=%d \n",i);
    change(i);
    printf("after call by value: value=%d \n", i);

    printf("=========================\n");


    printf("before call by reference: value=%d \n", i);
    modify(&i);
    printf("after call by reference: value=%d \n", i);




}