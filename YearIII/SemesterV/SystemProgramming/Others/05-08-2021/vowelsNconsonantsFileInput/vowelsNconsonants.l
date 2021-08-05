/* Write a Lex program to count the number of vowels and characters in the input string. */
%{
    int count_vowels = 0;
    int count_consonants = 0;
%}
%%
a|e|i|o|u|A|E|I|O|U {count_vowels++;}
[a-zA-Z] {count_consonants++;}
%%
int main() {
    yyin = fopen("text.txt", "r");
    yylex();
    printf("No. of vowels: %d\n", count_vowels);
    printf("No. of consonants: %d\n", count_consonants);
    return 1;
}
int yywrap() {
    return 1;
}