#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10], follow[10][10];
int n;

void addFollow(int i, char c) {
    for (int k = 0; follow[i][k]; k++)
        if (follow[i][k] == c) return;
    int len = strlen(follow[i]);
    follow[i][len] = c;
    follow[i][len + 1] = '\0';
}

int indexOf(char c) {
    for (int i = 0; i < n; i++)
        if (prod[i][0] == c) return i;
    return -1;
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    addFollow(0, '$'); // start symbol

    for (int i = 0; i < n; i++) {
        for (int j = 3; prod[i][j]; j++) {
            if (isupper(prod[i][j])) {
                int idx = indexOf(prod[i][j]);
                if (prod[i][j + 1])
                    addFollow(idx, prod[i][j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("FOLLOW(%c) = { %s }\n", prod[i][0], follow[i]);

    return 0;
}
