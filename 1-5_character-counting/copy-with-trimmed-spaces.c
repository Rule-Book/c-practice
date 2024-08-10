#include <stdio.h>

int main()
{
	int c;
	int prev;

	while ((c = getchar()) != EOF) {
		if (c == ' ' && prev == ' ') {
			continue;
		}
		putchar(c);
		prev = c;
	}
}
