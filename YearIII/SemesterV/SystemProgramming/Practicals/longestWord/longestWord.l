/* Write a Lex program that finds the longest word (defined as a contiguous string of upper-case and lower-case letters) in the input. */

%{
    int len_longest = 0;
    char word_longest[30];
%}

%%
[a-zA-Z]+ {
    if (yyleng > len_longest) {
        len_longest = yyleng;
        strcpy(word_longest, yytext);
    }
}
%%

int main(void) {
    printf("Enter a sentence: ");
    yylex();

    printf("Longest word: %s\n", word_longest);

    return 1;
}

int yywrap() {
    return 1;
}