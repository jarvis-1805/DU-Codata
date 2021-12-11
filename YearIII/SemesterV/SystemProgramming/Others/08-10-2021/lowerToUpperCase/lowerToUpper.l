/* Write a lex program that converts all lowercase letters to uppercase in a text file. */
%%
[a-z] { fprintf(yyout, "%c", yytext[0] - ('a' - 'A')); }
%%
int main() {
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    printf("Completed...\n");
    fclose(yyin);
    fclose(yyout);
    return 1;
}
int yywrap() {
    return 1;
}