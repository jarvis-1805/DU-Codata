%{
    #include<stdio.h>
    #include<stdlib.h>
    extern int yylex();
    void yyerror(char *msg);
%}

%union{
    float f;
}
%token <f> NUM
%type <f> E T F

%%
S:E { printf("%f\n", $1); };

E:E'+'T { $$ = $1 + $3; }
  | E'-'T { $$ = $1 - $3; }
  | T;

T:T'*'F { $$ = $1 * $3; }
  | T'/'F { $$ = $1 / $3; }
  | F;

F:'('E')' { $$ = $2; }
  | '-'F { $$ = -$2; }
  | NUM { $$ = $1; };
%%

void yyerror(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}
