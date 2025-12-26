#include <stdio.h>
#include <string.h>

int main()
{
    char line[200];
    int i, len;

    printf("Enter a line of code:\n");
    fgets(line, sizeof(line), stdin);

    len = strlen(line);

    /* Check for single-line comment */
    if (line[0] == '/' && line[1] == '/')
    {
        printf("The given line is a SINGLE-LINE COMMENT\n");
        return 0;
    }

    /* Check for multi-line comment */
    if (line[0] == '/' && line[1] == '*')
    {
        for (i = 2; i < len - 1; i++)
        {
            if (line[i] == '*' && line[i + 1] == '/')
            {
                printf("The given line is a MULTI-LINE COMMENT\n");
                return 0;
            }
        }
        printf("The given line is NOT a COMMENT (Unterminated comment)\n");
        return 0;
    }

    printf("The given line is NOT a COMMENT\n");
    return 0;
}

