#include <stdio.h>

int main() {

    double num1, num2;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);   // space before %c is IMPORTANT

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (op) {
        case '+':
            printf("Result = %.2lf\n", num1 + num2);
            break;

        case '-':
            printf("Result = %.2lf\n", num1 - num2);
            break;

        case '*':
            printf("Result = %.2lf\n", num1 * num2);
            break;

        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
            } else {
                printf("Result = %.2lf\n", num1 / num2);
            }
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
