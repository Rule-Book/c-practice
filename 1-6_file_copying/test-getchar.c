#include <stdio.h>

int main() 
{
	int c;
	int count;
	while ((c = getchar()) != EOF && c != 10 && count++) {
		//printf("found space");
		putchar(c);
	}
	printf("left\n");
	int operand = getchar();
	printf("operand = %d\n", operand);
	putchar(operand);
}
