#include <stdio.h>
#include <ctype.h>
#include <string.h>

char prod[6][10] = {
    "E=E+T",
    "E=T",
    "T=T*F",
    "T=F",
    "F=(E)",
    "F=i"
};

char nonterminals[] = {'E','T','F'};
char leading[3][10];
int n = 6;

/* Check if character already present */
int present(char set[], char c) {
    for (int i = 0; set[i]; i++)
        if (set[i] == c)
            return 1;
    return 0;
}

/* Add character to set */
void add(char set[], char c) {
    int len = strlen(set);
    set[len] = c;
    set[len + 1] = '\0';
}

/* Get index of non-terminal */
int indexOf(char c) {
    for (int i = 0; i < 3; i++)
        if (nonterminals[i] == c)
            return i;
    return -1;
}

/* Compute LEADING */
void computeLeading(int idx) {
    char nt = nonterminals[idx];

    for (int i = 0; i < n; i++) {
        if (prod[i][0] == nt) {
            char first = prod[i][2];   // first symbol on RHS

            if (!isupper(first)) {
                if (!present(leading[idx], first))
                    add(leading[idx], first);
            } else {
                int j = indexOf(first);
                if (j != -1 && j != idx) {
                    computeLeading(j);
                    for (int k = 0; leading[j][k]; k++)
                        if (!present(leading[idx], leading[j][k]))
                            add(leading[idx], leading[j][k]);
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++)
        computeLeading(i);

    printf("LEADING sets:\n");
    for (int i = 0; i < 3; i++) {
        printf("LEADING(%c) = { ", nonterminals[i]);
        for (int j = 0; leading[i][j]; j++)
            printf("%c ", leading[i][j]);
        printf("}\n");
    }

    return 0;
}
