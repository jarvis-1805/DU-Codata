/* A program in Lex to recognize a valid arithmetic expression. */

%{
    #include <stdio.h>

	int operators_count = 0, operands_count = 0, brackets_count = 0;
%}

%%
[a-zA-Z]+[0-9a-zA-Z]* { operands_count++; }
\+|-|\*|\/ { operators_count++; }
"(" { brackets_count++; }
")" { brackets_count--; }
%%

int main(void) {
	printf("Enter the arithmetic expression: ");
	yylex();

	if ((operators_count+1 == operands_count) && brackets_count == 0) {
		printf("Valid Expression!\n");
	} else {
		printf("Invalid Expression!\n");
	}

	return 0;
}
