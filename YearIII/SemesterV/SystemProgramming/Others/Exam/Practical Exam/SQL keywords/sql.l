%{ 
int i=0; 
%}
%%

[s|S][e|E][l|L][e|E][c|C][t|T] {printf("Select keyword");}
[f|F][r|R][o|O][m|M] {printf("from keyword");}
[w|W][h|H][e|E][r|R][e|E] {printf("where keyword");}
[A-Za-z][a-zA-Z0-9]* {i++;} 
%%
int main() {
    yyin=fopen("test.sql","r"); 
    yylex(); 
    printf("\ntotal number of identifiers are %d",i); 
} 

int yywrap() {
    return 1; 
}