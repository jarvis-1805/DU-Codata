/* Write a Lex program to count the number of identifiers in a C file. */

%{
    int count_identifiers = 0;
%}

%%
#include|main|printf|scanf|for|return {;}
char|int|float|double {;}
([<][a-zA-Z]*.h[>]) {;}
\"(.*)?\" {;}
[(){};,&\n ] {;}
[+|\-|*|/|%|^|<|>|=|<=|>=|==|!=|+=|\-=|*=|/=|%=|^=|++|\-\-] {;}
[+-]?[0-9]+ {;}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s ", yytext); count_identifiers++;}
%%

int main() {
    yyin = fopen("productOfDigits.c", "r");
    yylex();
    printf("\nNo. of identifiers: %d\n", count_identifiers);
    return 1;
}

int yywrap() {
    return 1;
}
