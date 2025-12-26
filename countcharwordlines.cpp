#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("input123.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            inWord = 0;
        }
        else
        {
            if (inWord == 0)
            {
                inWord = 1;
                words++;
            }
        }
    }

    fclose(fp);

    printf("Number of Characters : %d\n", characters);
    printf("Number of Words      : %d\n", words);
    printf("Number of Lines      : %d\n", lines);

    return 0;
}

