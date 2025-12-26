#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char prod[10][10];
char first[10][10];

void addToFirst(int i, char c) {
    for (int k = 0; first[i][k]; k++)
        if (first[i][k] == c) return;
    int len = strlen(first[i]);
    first[i][len] = c;
    first[i][len + 1] = '\0';
}

void findFirst(int i) {
    for (int j = 3; prod[i][j] != '\0'; j++) {
        char c = prod[i][j];
        if (!isupper(c)) {
            addToFirst(i, c);
            return;
        } else {
            int k;
            for (k = 0; k < n; k++)
                if (prod[k][0] == c)
                    findFirst(k);
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    for (int i = 0; i < n; i++)
        findFirst(i);

    for (int i = 0; i < n; i++)
        printf("FIRST(%c) = { %s }\n", prod[i][0], first[i]);

    return 0;
}
