/* Write a Lex program that implements the Caesar cipher: it replaces every letter with the one three letters after in alphabetical order, wrapping around at Z. e.g. a is replaced by d, b by e, and so on z by c. */
%{
    #include <string.h>
    int functionChoice, methodChoice;
    int KEY;
    char ch;
    char ciphertext[100] = "";
    char plaintext[100] = "";
%}
%%
[a-zA-Z] {
            ch = *yytext;
            if (functionChoice == 1) {
                if (ch >= 'a' && ch <= 'z') {
                    ch += KEY;
                    if (ch > 'z') {
                        ch = ch - 'z' + 'a' - 1;
                    }
                } else if (ch >= 'A' && ch <= 'Z') {
                    ch += KEY;
                    if (ch > 'Z') {
                        ch = ch - 'Z' + 'A' - 1;
                    }
                }
                strcat(ciphertext, &ch);
            } else if (functionChoice == 2) {
                if(ch >= 'a' && ch <= 'z') {
                    ch -= KEY;
                    if(ch < 'a'){
                        ch = ch + 'z' - 'a' + 1;
                    }
                } else if (ch >= 'A' && ch <= 'Z') {
                    ch -= KEY;
                    if (ch < 'A') {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                }
                strcat(plaintext, &ch);
            }
            //printf("%s", &ch);
        }
%%
int main() {
    printf("\n----- CEASER CIPHER -----\n1) Encryption\n2) Decryption\n> ");
    scanf("%d", &functionChoice);

    if ((functionChoice == 1) || (functionChoice == 2)) {
        printf("\nEnter the key\n> ");
        scanf("%d", &KEY);

        printf("\nEnter Method:\n1) User Input\n2) Text File\n> ");
        scanf("%d", &methodChoice);

        if (methodChoice == 1) {
            printf("\nEnter the plaintext:");
            yylex();
            printf("\nCipher Text: ");
            puts(ciphertext);
        } else if (methodChoice == 2) {
            yyin = fopen("plaintext.txt", "r");
            if (functionChoice == 1) {
                yyout = fopen("output_ciphertext.txt", "w");
            } else {
                yyout = fopen("output_plaintext.txt", "w");
            }
            yylex();
            if (functionChoice == 1) {
                fprintf(yyout, "%s", ciphertext);
            } else {
                fprintf(yyout, "%s", plaintext);
            }
            fclose(yyin);
            fclose(yyout);
        } else {
            printf("\nWrong Choice!\n");
        }
    } else {
        printf("\nWrong Choice!\n");
    }
    return 1;
}
int yywrap() {
    return 1;
}