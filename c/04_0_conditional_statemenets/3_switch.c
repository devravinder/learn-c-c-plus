#include <stdio.h>


// good for fixed values
double math(char operator, double f, double s){

    double result; // default value is zero

    switch (operator)
    {
    case '+':
        result = f + s;
        // retrun f+s;
        break;

    case '-':
         result = f - s;
        break;

    case '*':
         result = f * s;
        break;

    case '/':
         result = f / s;
        break;
    
    default:
        printf("Invalid operator & ignore the answer \n");
        break;
    }

  return result;


}

int main(){

     double f,s;
     char operator;

     printf("Enter in format: number operattor number \n");

     scanf("%lf %c %lf", &f, &operator, &s);


    double result =  math(operator, f, s);

    printf("The result: %.2lf %c %.2lf = %.2lf \n", f, operator, s, result);

}