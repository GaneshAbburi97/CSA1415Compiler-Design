#include <stdio.h>

int main()
{
    char ch;

    printf("Enter an operator: ");
    scanf(" %c", &ch);

    switch (ch)
    {
        case '+':
            printf("Valid Operator: PLUS (+)\n");
            break;

        case '-':
            printf("Valid Operator: MINUS (-)\n");
            break;

        case '*':
            printf("Valid Operator: MULTIPLICATION (*)\n");
            break;

        case '/':
            printf("Valid Operator: DIVISION (/)\n");
            break;

        default:
            printf("Invalid Operator\n");
    }

    return 0;
}

