#include <stdio.h>
#include <string.h>

struct symbol {
    char name[20];
    char type[10];
    int size;
    int address;
};

struct symbol table[20];
int count = 0;

void insert() {
    printf("Enter name, type, size, address: ");
    scanf("%s %s %d %d",
          table[count].name,
          table[count].type,
          &table[count].size,
          &table[count].address);
    count++;
    printf("Symbol inserted successfully\n");
}

void search() {
    char key[20];
    int found = 0;
    printf("Enter symbol name to search: ");
    scanf("%s", key);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, key) == 0) {
            printf("Symbol found!\n");
            printf("Name: %s\nType: %s\nSize: %d\nAddress: %d\n",
                   table[i].name,
                   table[i].type,
                   table[i].size,
                   table[i].address);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Symbol not found\n");
}

void display() {
    printf("\nSymbol Table\n");
    printf("Name\tType\tSize\tAddress\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%d\n",
               table[i].name,
               table[i].type,
               table[i].size,
               table[i].address);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
