#include <stdio.h> 
 
int main(void) { 
	unsigned int X;
	printf("RECEBA [X]: ");
	scanf("%d", &X); 
 
 	unsigned int Z;
	unsigned int NUM;
	NUM = 0;
	unsigned int RESULT;
	RESULT = 1;
	while(X > NUM){
	NUM = NUM + 1 ;
	NUM = NUM;
	RESULT = RESULT * NUM;
	RESULT = RESULT;
	Z = RESULT;
	}
	printf("DEVOLVA [Z]: %d", Z);
	return 0;
}