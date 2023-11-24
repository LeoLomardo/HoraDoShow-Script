#include <stdio.h> 
 
int main(void) { 
	int X;
	printf("RECEBA [X]: ");
	scanf("%d", &X); 
 
 	int XX;
	printf("RECEBA [XX]: ");
	scanf("%d", &XX); 
 
 	int Z;
	Z = 0;
	Z = Z + 10 ;
	Z = Z;
	for (int i = 0; i < 3; i++) {

	Z = Z - 1 ;
	Z = Z - 1 ;
	Z = Z - 1 ;

	}

	printf("DEVOLVA [Z]: %d", Z);

	return 0;
}