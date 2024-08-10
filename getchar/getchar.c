#include <stdio.h>

int main() 
{
	printf("Enter any random character between a-z: ");
	int character;
	character = getchar();

	printf("The entered character is : ");
	putchar(character);
	return 0;
}
