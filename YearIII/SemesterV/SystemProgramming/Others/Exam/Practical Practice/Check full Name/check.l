%{
    #include<stdlib.h>
    #include<stdio.h>
    #include "y.tab.h"
%}

%option noyywrap

%%
[0-9]+ { printf("\nIncorrect"); exit(0); }
[a-z A-Z]* { return NAME; }
[\n] { return NewLine; }
[\t]+ { ; }
. { ; }
%%
