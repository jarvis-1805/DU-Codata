/* Write a Lex program to count the number of words, characters, blank spaces and lines in a C file. */

%{
    int count_words = 0;
    int count_characters = 0;
    int count_spaces = 0;
    int count_lines = 0;
%}

%%
\n {count_lines++;}
[ ] {count_spaces++;}
[a-zA-Z]+ {count_words++; count_characters += yyleng;}
. {count_characters++;}
%%

int main() {
    yyin = fopen("sample.txt", "r");
    yylex();
    printf("\nNo. of words: %d", count_words);
    printf("\nNo. of characters: %d", count_characters);
    printf("\nNo. of blank spaces: %d", count_spaces);
    printf("\nNo. of lines: %d\n", count_lines+1);
    return 1;
}

int yywrap() {
    return 1;
}
