#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // <-- REQUIRED for exit()

int i = 0;
char input[50];

void E();
void E_prime();
void T();
void T_prime();
void F();

void E()
{
    T();
    E_prime();
}

void E_prime()
{
    if (input[i] == '+')
    {
        i++;
        T();
        E_prime();
    }
}

void T()
{
    F();
    T_prime();
}

void T_prime()
{
    if (input[i] == '*')
    {
        i++;
        F();
        T_prime();
    }
}

void F()
{
    if (input[i] == '(')
    {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else
        {
            printf("Invalid Expression\n");
            exit(0);
        }
    }
    else if (input[i] == 'i' && input[i + 1] == 'd')
    {
        i += 2;
    }
    else
    {
        printf("Invalid Expression\n");
        exit(0);
    }
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    E();

    if (i == strlen(input))
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}

