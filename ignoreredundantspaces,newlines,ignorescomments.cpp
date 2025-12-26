#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch, next;

    printf("Enter the source code (Ctrl+Z + Enter to stop):\n");

    while ((ch = getchar()) != EOF)
    {
        /* Ignore whitespaces */
        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        /* Handle comments */
        if (ch == '/')
        {
            next = getchar();

            /* Single-line comment */
            if (next == '/')
            {
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }

            /* Multi-line comment */
            else if (next == '*')
            {
                while (1)
                {
                    ch = getchar();
                    next = getchar();
                    if (ch == '*' && next == '/')
                        break;
                }
                continue;
            }
            else
            {
                /* Not a comment */
                putchar(ch);
                ungetc(next, stdin);
            }
        }
        else
        {
            putchar(ch);
        }
    }

    printf("\n\nLexical analysis completed.\n");
    return 0;
}

