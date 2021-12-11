%{
    /* Definition section */
    #include <stdio.h>
    #include <stdlib.h>
    extern int yylex();
    void yyerror(char *s);
%}

%token NUMBER ID
// setting the precedence
// and associativity of operators
%left '+' '-'
%left '*' '/'

/* Rule Section */
%%
E:T {
    printf("Result = %d\n", $$);
    return 0;
};

T:
    T '+' T { $$ = $1 + $3; }
    | T '-' T { $$ = $1 - $3; }
    | T '*' T { $$ = $1 * $3; }
    | T '/' T { $$ = $1 / $3; }
    | '-' NUMBER { $$ = -$2; }
    | '-' ID { $$ = -$2; }
    | '(' T ')' { $$ = $2; }
    | NUMBER { $$ = $1; }
    | ID { $$ = $1; };
%%

int main() {
    printf("Enter the expression\n");
    yyparse();
    return 0;
}

/* For printing error messages */
void yyerror(char* s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}
