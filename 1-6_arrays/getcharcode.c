#include <stdio.h>

int main()
{
	int c;

	
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			continue;
		printf("charcode of ");
 	 	putchar(c);
		printf(" is %d\n", c);
		
		if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9')) {
			printf("\t");
			putchar(c);
			printf(" is not alphanumeric\n");
		}
	}
}
