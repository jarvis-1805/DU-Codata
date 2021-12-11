/* Write a Lex program that distinguishes keywords, integers, floats, identifiers, operators, and comments in any simple programming language. */

%{
    int count_keywords = 0;
    int count_integers = 0;
    int count_floats = 0;
    int count_identifiers = 0;
    int count_operators = 0;
    int count_comments = 0;
%}

%%
#include|main|printf|scanf {;}
([<][a-zA-Z]*.h[>]) {;}
\"(.*)?\" {;}
[(){};,\n ] {;}
auto|break|case|char|const|continue|default|double|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typeof|union|unsigned|void|volatile|while|do|else {count_keywords++;}
\+|\-|\*|\/|%|\+\+|\-\-|==|!=|>|<|>=|<=|&&|\|\||!|&|\||^|~|<<|>>|=|\+=|\-=|\*=|\/=|%=|<<=|>>=|&=|^=|\|=|\?: {count_operators++;}
[+-]?[0-9]+ {count_integers++;}
[+-]?[0-9]*[.][0-9]+ {count_floats++;}
[a-zA-Z_][a-zA-Z0-9_]* {count_identifiers++;}
(\/\/(.*))|\/\*[^*]*\*+(?:[^/*][^*]*\*+)*\/ {count_comments++;}
%%

int main() {
    yyin = fopen("productOfDigits.c", "r");
    yylex();
    printf("\nNo. of keywords: %d", count_keywords);
    printf("\nNo. of integers: %d", count_integers);
    printf("\nNo. of floats: %d", count_floats);
    printf("\nNo. of identifiers: %d", count_identifiers);
    printf("\nNo. of operators: %d", count_operators);
    printf("\nNo. of comments: %d\n", count_comments);
    return 1;
}

int yywrap() {
    return 1;
}
