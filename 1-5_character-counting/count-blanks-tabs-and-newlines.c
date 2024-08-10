#include <stdio.h>

/* count lines in input */
int main() {
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n' || c == ' ' || c == '\t')
			++nl;
	printf("Input had %d total blanks, tabs, and newlines\n", nl);
}
