/* Lex program for decimal to hexadecimal conversion */

%{
	/* Definition section */
	#include<stdio.h>
	int num, r, digit=0, count, pcount=0, i=0, rem=0;
	char a[20];
%}

DIGIT [0-9]
/* Rule Section */
%%

{DIGIT}+ { num=atoi(yytext);
            int dec_value = 0;
        
            // Initializing base value to 1, i.e 8^0
            int base = 1;
        
            int temp = num;
            while (temp) {
        
                // Extracting last digit
                int last_digit = temp % 10;
                temp = temp / 10;
        
                // Multiplying last digit with appropriate
                // base value and adding it to dec_value
                dec_value += last_digit * base;
        
                base = base * 8;
            }

            num = dec_value;

            while(num!=0) {
                r=num%16;
                digit='0'+r;
                if(digit>'9')
                digit+=7;
                a[count++]=digit;
                num=num/16;

            }

            for(i=count-1;i>=pcount;--i)
                printf("%c", a[i]);
                pcount=count;

        }

.|\n ECHO;

%%

// driver code
int main() {
	yylex();
	return 0;
}	

int yywrap() {
	return 1;
}
