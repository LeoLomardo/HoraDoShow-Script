#include <stdio.h> 
 
int main(void) { 
	int X;
	printf("RECEBA [X]: ");
	scanf("%d",&X); 
 
 	int Y;
	printf("RECEBA [Y]: ");
	scanf("%d",&Y); 
 
 	int Z;

	int K = X;
	for (int i = 0; i < Y; i++) {
	X = X + Y ;
	}
	printf("DEVOLVA: [Z] = %d \n", Z);
	return 0;
}