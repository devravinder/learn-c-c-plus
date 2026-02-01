#include <stdio.h>

/*

variable:  to hold some data(value)
---
Types:-

Type	Size (usually)	    Example
---------------------------------------
int	    4 bytes	            int x = 10;
float	4 bytes	            float f = 3.5;
double	8 bytes	            double d = 9.8;
char	1 byte	            char c = 'A';

----
📍 Variable naming rules

✅ Start with letter or _
✅ Can contain numbers
❌ No spaces
❌ No keywords (int, for, return)


----
float vs double (important!)

Feature	    float	        double
----------------------------------
Size	    4 bytes	        8 bytes
Precision	~6 digits	    ~15 digits
Speed	    slightly f      aster	slightly slower
Accuracy	lower	        much higher
Default 	❌	✅


*/ 

int main(){
    int age = 20;
    printf("age is %d \n", age); // formatting // value substitution

    float price = 11.2f;

    printf("price is %f \n", price);

    double distance = 12229.8;

    printf("distance is %lf \n", distance); // %f also works printf, but for scanf only lf


    char c = 'C';

    printf("char is %c \n", c);


    char name[] = "Ravinder"; // not 'Ravinder'
    printf("name %s \n", name);


    int i; // only declare

    i = 20; // assigning

    int x = 10; // Declare + initialize:

    int a = 1, b = 2, d = 3; // multiple at one

    printf("i=%d, x=%d, a=%d, b=%d, d=%d \n", i,x,a,b,d);



}