#include <stdio.h> 
 
int main(void) { 
	int X;
	printf("RECEBA [X]: ");
	scanf("%d", &X); 
 
 	int Z;
 
 	X = 3;
	Z = 0;
	while	(X != 4){

	X = X + 1 ;
	Z = Z + 1 ;

	}

	printf("DEVOLVA [Z]: %d", Z);

	return 0;
}