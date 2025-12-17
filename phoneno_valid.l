%{
#include <stdio.h>
%}

%%

^[6-9][0-9]{9}$   { printf("\nMobile Number Valid\n"); }
.+               { printf("\nMobile Number Invalid\n"); }

%%

int yywrap(void)
{
    return 1;
}

int main()
{
    printf("Enter Mobile Number: ");
    yylex();
    return 0;
}
