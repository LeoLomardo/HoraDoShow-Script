#include <stdio.h> 
 
int main(void) { 
	unsigned int X;
	printf("RECEBA [X]: ");
	scanf("%d",&X); 
 
 	unsigned int Y;
	printf("RECEBA [Y]: ");
	scanf("%d",&Y); 
 
 	unsigned int Z;

	unsigned int X = 3;
	for (int i = 0; i < X; i++) {
	Y = Y + Y ;
	}

	printf("DEVOLVA: [Z] = %d \n", Z);
	return 0;
}