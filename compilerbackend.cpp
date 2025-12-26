#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char op[5], arg1[10], arg2[10], result[10];

    printf("Enter number of three address statements: ");
    scanf("%d", &n);

    printf("\nEnter the statements in format:\n");
    printf("op arg1 arg2 result\n");
    printf("Example: + a b t1\n\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s %s %s %s", op, arg1, arg2, result);

        if (strcmp(op, "+") == 0)
        {
            printf("MOV %s, R0\n", arg1);
            printf("ADD %s, R0\n", arg2);
            printf("MOV R0, %s\n\n", result);
        }
        else if (strcmp(op, "-") == 0)
        {
            printf("MOV %s, R0\n", arg1);
            printf("SUB %s, R0\n", arg2);
            printf("MOV R0, %s\n\n", result);
        }
        else if (strcmp(op, "*") == 0)
        {
            printf("MOV %s, R0\n", arg1);
            printf("MUL %s, R0\n", arg2);
            printf("MOV R0, %s\n\n", result);
        }
        else if (strcmp(op, "/") == 0)
        {
            printf("MOV %s, R0\n", arg1);
            printf("DIV %s, R0\n", arg2);
            printf("MOV R0, %s\n\n", result);
        }
        else if (strcmp(op, "=") == 0)
        {
            printf("MOV %s, %s\n\n", arg1, result);
        }
    }

    return 0;
}

