/* Write a Lex program to check if the entered word is a verb or not. */
%%
is|am|are|was|were {printf("%s is a verb!", yytext);}
[a-zA-Z]+ {printf("%s is not a verb!", yytext);}
%%
int main() {
    printf("Enter a word: ");
    yylex();
    return 1;
}
int yywrap() {
    return 1;
}