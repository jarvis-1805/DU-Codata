%{
    #include<stdio.h>
    #include<stdlib.h>
    extern int yylex();
    void yyerror(char *errmsg);
%}

%token NAME NewLine

%%
S:E NewLine { printf("\nCorrect\n"); exit(0); };

E:NAME E
  | NAME;
%%

void yyerror(char *errmsg) {
    printf("\nIncorrect\n");
    exit(1);
}

int main() {
    printf("\nEnter your name to be check\n");
    yyparse();
    return 0;
}
