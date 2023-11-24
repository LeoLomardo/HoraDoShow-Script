#include <stdio.h> 
 
int main(void) { 
	int X;
	printf("RECEBA [X]: ");
	scanf("%d", &X); 
 
 	int XX;
	printf("RECEBA [XX]: ");
	scanf("%d", &XX); 
 
 	int A;
	printf("RECEBA [A]: ");
	scanf("%d", &A); 
 
 	int Z;
	X = 0;
	X = X << 10 ;
	Z = X;

	if	(X > 3){

	Z = Z - 4 ;
	Z = Z;

	} else {

	Z = 0;

	}

	printf("DEVOLVA [Z]: %d", Z);

	return 0;
}