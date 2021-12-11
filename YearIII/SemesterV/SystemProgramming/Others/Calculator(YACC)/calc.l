%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
%}

%option noyywrap

%%
([0-9]+)(\.[0-9]+)? { yylval.f = atof(yytext);
                    return NUM; }

[-+()*/] { return yytext[0]; }

[ \t\n] { ; }
%%
