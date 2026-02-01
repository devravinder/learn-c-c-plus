#include <stdio.h>

/*
 if,
 if-else
 if-else if ( ladder )

*/ 


int max(int f, int s){
    if( f < s)
      return s;
    else return f; 
}

int min(int f, int s){

    int min = (f < s) ? f : s;

    return min;
}

char* isMinor(int age){

    /* 
    char isMinor[] = age < 18 ? "Minor" : "Audult";
    // isMinor is a local array on the stack.
    // after function's end -> that points to invalid memory
    return isMinor;
     */


    return age < 18 ? "Minor" : "Audult";
}


int main(){

    printf("%d max \n", max(2,5));
    printf("%d min \n", min(7,3));

    printf("He is %s \n", isMinor(12));
}