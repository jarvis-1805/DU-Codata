/* Write a Lex program to count the number of vowels and consonants in the input file. */
%{
    int count_vowels = 0;
    int count_consonants = 0;
%}
%%
[aeiouAEIOU] {count_vowels++;}
[a-zA-Z] {count_consonants++;}
%%
int main() {
    printf("Enter the string: ");
    yylex();
    printf("No. of vowels: %d\n", count_vowels);
    printf("No. of consonants: %d\n", count_consonants);
    return 1;
}
int yywrap() {
    return 1;
}