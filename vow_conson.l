%{
#include <stdio.h>
int pos_no = 0, neg_no = 0;
%}

%%

-[0-9]+      { neg_no++; printf("Negative number = %s\n", yytext); }
[0-9]+       { pos_no++; printf("Positive number = %s\n", yytext); }
[ \t\n]+     ;   /* ignore spaces and newlines */

%%

int yywrap(void)
{
    return 1;
}

int main()
{
    printf("Enter numbers:\n");
    yylex();
    printf("\nNumber of Positive numbers = %d\n", pos_no);
    printf("Number of Negative numbers = %d\n", neg_no);
    return 0;
}
