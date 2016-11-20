%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}
%%
a	{return A;}
b	{return B;}
[ \t]	;
.	yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}

