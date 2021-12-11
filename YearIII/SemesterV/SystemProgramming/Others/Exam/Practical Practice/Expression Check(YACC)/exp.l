%{
	/* Definition section*/
    #include<stdio.h>
    #include<stdlib.h>
	#include "y.tab.h"
	extern int yylval;
%}

%option noyywrap

%%
[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}

[a-zA-Z]+ { return ID; }

[ \t]+ { ; } /*For skipping whitespaces*/

\n		 { return 0; }
.		 { return yytext[0]; }

%%
