#include <stdio.h>
#include <ctype.h>

int main() {
    char input[] =
        "Hello World\n"
        "Compiler Design Lab\n"
        "Lexical Analyzer Program";

    int characters = 0, words = 0, lines = 1;
    int inWord = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        characters++;

        if (input[i] == '\n')
            lines++;

        if (isspace(input[i]))
            inWord = 0;
        else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    printf("Input String:\n%s\n\n", input);
    printf("Number of characters = %d\n", characters);
    printf("Number of words      = %d\n", words);
    printf("Number of lines      = %d\n", lines);

    return 0;
}
