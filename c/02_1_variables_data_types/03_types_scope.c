#include <stdio.h>

// complete functions before this
/*
 Types
 1. Local   : Declared inside function:
 2. Global  : Declared outside all functions:
 3. static  : inside function & Keeps value between function calls 
 4. extended: Used to share variable between files (advanced).

---
🧠 Default values (important!)

Variable	Default
-------------------------
Local	    garbage value ❗
Global	    0
Static	    0

*/ 

int calls = 0; // global

int main(){


    testLocal();
    counter();
    counter();
    testLocal();



    calls++;
    printf("total function calls is %d \n", calls);
    return 0;
}

void testLocal() {
    int l = 10;
    l++;

    printf("local is %d \n",l);
    
    //
    calls++;
    printf("function calls is %d \n", calls);
}

void counter() {
    static int c = 0;
    c++;

    printf("counter %d \n", c);
    
    //
    calls++;
    printf("function calls is %d \n", calls);

}
