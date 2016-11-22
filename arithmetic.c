/*
Grammer:
E -> E+T | T
T -> T*F | F
F -> id

or 

E->E+E
E-<E*E
E->id


After removing left recursion
E -> TE'
E' -> +TE' | ε
T -> FT'
T' -> *FT' | ε
F ->id
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char input[10];
int i,error,a,b;

void E();
void T();
void Ep();
void Tp();
void F();
int main(int argc, char const *argv[])
{
	i=0;
	error=0;
	printf("Enter an arithmetic expression: ");
	gets(input);
	E();
	if (strlen(input)==i&&error==0){
		printf("Accepted!\n");
	}else printf("Rejected!\n");
	return 0;
}
void E(){
	T();
	Ep();
}
void Ep(){
	if (input[i]=='+'){
		i++;
		T();
		Ep();
	}
}
void T(){
	F();
	Tp();
}
void Tp(){
	if (input[i]=='*'){
		i++;
		F();
		Tp();
	}else if(isdigit(input[i])){
		F();
		Tp();
	}
}
void F(){
	if (isdigit(input[i])){
		i++;
	}else{
		error=1;
	}
}

