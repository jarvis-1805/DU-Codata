/* Write a Lex program that implements the Caesar cipher: it replaces every letter with the one three letters after in alphabetical order, wrapping around at Z. e.g. a is replaced by d, b by e, and so on z by c. */

%{
    int KEY;
    int functionChoice;
%}

%%
[a-z] { if (functionChoice == 1) {
            fprintf(yyout, "%c", (yytext[0] - 'a' + 26 + KEY) % 26 + 'a');
        } else if (functionChoice == 2) {
            fprintf(yyout, "%c", (yytext[0] - 'a' + 26 - KEY) % 26 + 'a');
        }
    }
[A-Z] { if (functionChoice == 1) {
            fprintf(yyout, "%c", (yytext[0] - 'A' + 26 + KEY) % 26 + 'A');
        } else if (functionChoice == 2) {
            fprintf(yyout, "%c", (yytext[0] - 'A' + 26 - KEY) % 26 + 'A');
        }
    }
. { fprintf(yyout, "%s", yytext); }
%%

int main(void) {
    printf("\n----- CEASER CIPHER -----\n1) Encryption\n2) Decryption\n> ");
    scanf("%d", &functionChoice);

    printf("Enter the key: ");
    scanf("%d", &KEY);

    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "a");
    yylex();
    fprintf(yyout, "\n");
    fclose(yyin);
    fclose(yyout);
    return 1;
}

int yywrap() {
    return 1;
}
