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
char trailing[3][10];
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

/* Compute TRAILING */
void computeTrailing(int idx) {
    char nt = nonterminals[idx];

    for (int i = 0; i < n; i++) {
        if (prod[i][0] == nt) {
            int len = strlen(prod[i]);
            char last = prod[i][len - 1];

            if (!isupper(last)) {
                if (!present(trailing[idx], last))
                    add(trailing[idx], last);
            } else {
                int j = indexOf(last);
                if (j != -1 && j != idx) {
                    computeTrailing(j);
                    for (int k = 0; trailing[j][k]; k++)
                        if (!present(trailing[idx], trailing[j][k]))
                            add(trailing[idx], trailing[j][k]);
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++)
        computeTrailing(i);

    printf("TRAILING sets:\n");
    for (int i = 0; i < 3; i++) {
        printf("TRAILING(%c) = { ", nonterminals[i]);
        for (int j = 0; trailing[i][j]; j++)
            printf("%c ", trailing[i][j]);
        printf("}\n");
    }

    return 0;
}
