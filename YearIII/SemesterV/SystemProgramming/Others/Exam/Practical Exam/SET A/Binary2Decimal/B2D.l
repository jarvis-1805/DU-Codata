/* Lex program for decimal to binary conversion */

%{
    /* Definition section */
    #include<stdio.h>
    int num;
%}
%option noyywrap
/* Rule Section */
%%
[0|1]+ { num=atoi(yytext);

            int dec_value = 0;
        
            // Initializing base value to 1, i.e 2^0
            int base = 1;
        
            int temp = num;
            while (temp) {
                int last_digit = temp % 10;
                temp = temp / 10;
        
                dec_value += last_digit * base;
        
                base = base * 2;
            }
			printf("%d", dec_value);
		}
.|\n { ; }
%%

// driver code
int main()
{
	yylex();
	return 0;
}	
