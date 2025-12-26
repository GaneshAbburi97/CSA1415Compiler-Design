#include <stdio.h>
#include <string.h>

int main() {
    char A, alpha[10], beta[10];

    printf("Enter Non-terminal: ");
    scanf(" %c", &A);

    printf("Enter alpha (A -> Aalpha): ");
    scanf("%s", alpha);

    printf("Enter beta (A -> beta): ");
    scanf("%s", beta);

    printf("\nAfter Removing Left Recursion:\n");
    printf("%c -> %s%c'\n", A, beta, A);
    printf("%c' -> %s%c' | e\n", A, alpha, A);

    return 0;
}
