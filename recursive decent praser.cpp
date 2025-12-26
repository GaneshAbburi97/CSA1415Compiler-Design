#include <stdio.h>
#include <string.h>

char input[50];
int i = 0, error = 0;
int level = 0;

void printIndent() {
    for (int k = 0; k < level; k++)
        printf("  ");
}

void E();
void Eprime();
void T();
void Tprime();
void F();

void E() {
    printIndent(); printf("E\n");
    level++;
    T();
    Eprime();
    level--;
}

void Eprime() {
    if (input[i] == '+') {
        printIndent(); printf("E'\n");
        level++;
        printIndent(); printf("+\n");
        i++;
        T();
        Eprime();
        level--;
    } else {
        printIndent(); printf("E' -> e\n");
    }
}

void T() {
    printIndent(); printf("T\n");
    level++;
    F();
    Tprime();
    level--;
}

void Tprime() {
    if (input[i] == '*') {
        printIndent(); printf("T'\n");
        level++;
        printIndent(); printf("*\n");
        i++;
        F();
        Tprime();
        level--;
    } else {
        printIndent(); printf("T' -> e\n");
    }
}

void F() {
    printIndent(); printf("F\n");
    level++;
    if (input[i] == 'i') {
        printIndent(); printf("id\n");
        i++;
    }
    else if (input[i] == '(') {
        printIndent(); printf("(\n");
        i++;
        E();
        if (input[i] == ')') {
            printIndent(); printf(")\n");
            i++;
        } else {
            error = 1;
        }
    }
    else {
        error = 1;
    }
    level--;
}

int main() {
    // ?? Input given inside code
    strcpy(input, "i+i*i");

    printf("Parse Tree:\n");
    E();

    if (strlen(input) == i && error == 0)
        printf("\nString is successfully parsed\n");
    else
        printf("\nError in parsing\n");

    return 0;
}
