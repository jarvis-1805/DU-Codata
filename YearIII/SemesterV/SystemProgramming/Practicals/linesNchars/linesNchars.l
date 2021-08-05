/* Write a Lex program to count the number of lines and characters in the input file. */
%{
    int count_lines = 0;
    int count_chars = 0;
%}
%%
[\n] {count_lines++;}
. {count_chars++;}
%%
int main() {
    yyin = fopen("text.txt", "r");
    yylex();
    printf("No. of lines: %d\n", count_lines+1);
    printf("No. of characters: %d\n", count_chars);
    return 1;
}
int yywrap() {
    return 1;
}