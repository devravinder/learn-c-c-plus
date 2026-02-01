#include <stdio.h>

/*
 operators
 ---
 arithmetic: +, -, *, /, %
 relational: <, >, <=, >=, ==, !=
 logical: &&, ||, !
 self assignment: +=, -=, *=, /=, %=
 increament/decreament: ++, --
 ternary: ? :
 bitwise: &, | , ^, <<, >>, ~
 pointer: &, *
 size: size()

*/

int main() {

    /* ======================================
       ARITHMETIC OPERATORS
       ====================================== */

    int a = 10, b = 3;

    printf("Arithmetic Operators\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);   // integer division
    printf("a %% b = %d\n\n", a % b); // first % in %% is escape char


    /* ======================================
       RELATIONAL OPERATORS
       ====================================== */

    printf("Relational Operators\n");
    printf("a > b  = %d\n", a > b);
    printf("a < b  = %d\n", a < b);
    printf("a >= b = %d\n", a >= b);
    printf("a <= b = %d\n", a <= b);
    printf("a == b = %d\n", a == b);
    printf("a != b = %d\n\n", a != b);


    /* ======================================
       LOGICAL OPERATORS
       ====================================== */

    int x = 1, y = 0;

    printf("Logical Operators\n");
    printf("x && y = %d\n", x && y);
    printf("x || y = %d\n", x || y);
    printf("!x     = %d\n\n", !x);


    /* ======================================
       ASSIGNMENT OPERATORS
       ====================================== */

    int c = 5;

    printf("Assignment Operators\n");
    c += 3;
    printf("c += 3 -> %d\n", c);

    c -= 2;
    printf("c -= 2 -> %d\n", c);

    c *= 2;
    printf("c *= 2 -> %d\n", c);

    c /= 2;
    printf("c /= 2 -> %d\n\n", c);


    /* ======================================
       INCREMENT / DECREMENT
       ====================================== */

    int i = 5;

    printf("Increment / Decrement\n");
    printf("i++ = %d\n", i++);
    printf("Now i = %d\n", i);

    printf("--i = %d\n\n", --i);


    /* ======================================
       TERNARY OPERATOR
       ====================================== */

    int max = (a > b) ? a : b;

    printf("Ternary Operator\n");
    printf("Max of %d and %d is %d\n\n", a, b, max);


    /* ======================================
       BITWISE OPERATORS
       ====================================== */

    int p = 5;   // 0101
    int q = 3;   // 0011

    printf("Bitwise Operators\n");
    printf("p & q = %d\n", p & q);
    printf("p | q = %d\n", p | q);
    printf("p ^ q = %d\n", p ^ q);
    printf("~p    = %d\n", ~p);
    printf("p << 1 = %d\n", p << 1);
    printf("p >> 1 = %d\n\n", p >> 1);


    /* ======================================
       POINTER OPERATORS (& and *)
       ====================================== */

    int num = 10;
    int *ptr = &num;

    printf("Pointer Operators\n");
    printf("Address of num = %p\n", &num);
    printf("Value via pointer = %d\n\n", *ptr);


    /* ======================================
       sizeof OPERATOR
       ====================================== */

    printf("sizeof Operator\n");
    printf("sizeof(int) = %lu bytes\n", sizeof(int)); // % = format start;  lu = long unsigned
    printf("sizeof(double) = %lu bytes\n", sizeof(double));
    printf("sizeof(num) = %lu bytes\n\n", sizeof(num));


    /* ======================================
       STRUCT ACCESS OPERATORS (example preview)
       ====================================== */

    struct Test {
        int value;
    };

    struct Test t;
    t.value = 100;

    struct Test *tp = &t;

    printf("Struct Operators\n");
    printf("Using dot: %d\n", t.value);
    printf("Using arrow: %d\n\n", tp->value); // ***


    printf("All operators demonstrated successfully!\n");

    return 0;
}
