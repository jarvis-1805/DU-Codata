/* Write a lex program that converts a hexadecimal number into its equivalent binary number in a file. */

%{
    #include<stdio.h>
    char i;
%}

digit [0-9a-zA-Z]*

%%

{digit}  {
        for(i=0; i<=yyleng; i++) {
            if(yytext[i]=='0')
            printf("0000"); 
            
            else if(yytext[i]=='1')
            printf("0001"); 
                
            else if(yytext[i]=='2')
            printf("0010"); 
                
            else if(yytext[i]=='3')
            printf("0011"); 
                
            else if(yytext[i]=='4')
            printf("0101"); 
                
            else if(yytext[i]=='5')
            printf("0101"); 
                
            else if(yytext[i]=='6')
            printf("0110"); 
                
            else if(yytext[i]=='7')
            printf("0111"); 
                
            else if(yytext[i]=='8')
            printf("1000"); 
                
            else if(yytext[i]=='9')
            printf("1001"); 
                
            else if(yytext[i]=='a'||yytext[i]=='A')
            printf("1010"); 
                
            else if(yytext[i]=='b'||yytext[i]=='B')
            printf("1011"); 
                
            else if(yytext[i]=='c'||yytext[i]=='C')
            printf("1100"); 
                
            else if(yytext[i]=='d'||yytext[i]=='D')
            printf("1101"); 
                
            else if(yytext[i]=='e'||yytext[i]=='E')
            printf("1110"); 
                
            else if(yytext[i]=='f'||yytext[i]=='F')
            printf("1111");
        }
    }
%%

int yywrap(void) {}

int main() {
    yyin = fopen("text.txt", "r");
    yylex();
    return 0;
}
