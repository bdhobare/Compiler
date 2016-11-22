%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}
%%
(a*)b\\n	{return A;}
[ \t]	;
.	yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}

