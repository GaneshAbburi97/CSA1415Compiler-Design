#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char str[])
{
    char *keywords[] = {
        "int", "float", "char", "double", "if", "else",
        "while", "for", "return", "void", "switch"
    };

    int i;
    for (i = 0; i < 11; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char id[50];
    int i, valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", id);

    /* Check first character */
    if (!(isalpha(id[0]) || id[0] == '_'))
        valid = 0;

    /* Check remaining characters */
    for (i = 1; id[i] != '\0'; i++)
    {
        if (!(isalnum(id[i]) || id[i] == '_'))
        {
            valid = 0;
            break;
        }
    }

    if (valid && !isKeyword(id))
        printf("Valid Identifier\n");
    else
        printf("Invalid Identifier\n");

    return 0;
}

