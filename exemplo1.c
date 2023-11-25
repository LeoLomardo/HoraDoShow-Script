#include <stdio.h> 
 
int main(void) { 
	int X;
	printf("RECEBA [X]: ");
	scanf("%i", &X); 
 
 	int Y;
	printf("RECEBA [Y]: ");
	scanf("%i", &Y); 
 
 	int Z;
 
 
	for (int a = 0; a < X; a++) {

	Y = Y + 2 ;
	}
	Z = Y;

	printf("DEVOLVA [Z]: %d", Z);

	return 0;
}