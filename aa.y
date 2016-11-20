%{
	#include <stdio.h>
	int yylex(void);
	int count=0;
	void yyerror(char *);

%}

%token A
%token B

%%
program:
	B 	{ printf("Count: %d\n",count);}
	|a_expr program
	;
a_expr:
	A	{++count;}
	;
%%
void yyerror(char *s){
	printf("%s\n",s);
}
int main(void){
	yyparse();
	return 0;

}
