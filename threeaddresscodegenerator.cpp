#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char expr[50];
    char temp = '1';
    int i;

    printf("Enter the expression (example: a=b+c*d): ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");

    /* Handle multiplication and division first */
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '*' || expr[i] == '/')
        {
            printf("t%c = %c %c %c\n",
                   temp, expr[i - 1], expr[i], expr[i + 1]);

            expr[i - 1] = 't';
            expr[i] = temp;
            expr[i + 1] = ' ';
            temp++;
        }
    }

    /* Handle addition and subtraction */
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '+' || expr[i] == '-')
        {
            printf("t%c = %c %c %c\n",
                   temp, expr[i - 1], expr[i], expr[i + 1]);

            expr[i - 1] = 't';
            expr[i] = temp;
            expr[i + 1] = ' ';
            temp++;
        }
    }

    /* Final assignment */
    printf("%c = t%c\n", expr[0], temp - 1);

    return 0;
}

