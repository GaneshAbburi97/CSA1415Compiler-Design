#include <stdio.h>
#include <string.h>

int main() {
    char nt;
    char p1[20], p2[20], p3[20];
    int i = 0;

    printf("Enter Non-terminal: ");
    scanf(" %c", &nt);

    printf("Enter production 1: ");
    scanf("%s", p1);

    printf("Enter production 2: ");
    scanf("%s", p2);

    printf("Enter production 3: ");
    scanf("%s", p3);

    while (p1[i] == p2[i])
        i++;

    printf("\nAfter Left Factoring:\n");
    printf("%c -> ", nt);

    for (int j = 0; j < i; j++)
        printf("%c", p1[j]);

    printf("%c' | %s\n", nt, p3);

    printf("%c' -> %s | #\n", nt, p2 + i);

    return 0;
}
