#include <stdio.h>
 
int tobase10(char c);
int htoi(int i1, int i2);

/* convers a string of hexadecimal digits into integer value */
int main()
{
	int c1, c2, h1, h2, i;
	char input[] = { '0', '0', '\0', '\0' };

	/* assuming allowable digits are 0-9 a-f A-F */
	/* assuming 8bit hex ie. 0xff */
	while ((c1=getchar())!=EOF&&(c2=getchar())!=EOF) {
		if (c2 == '\n')
			continue;
		if (c1 == '\n') {
			c1 = c2;
			if ((c2=getchar()) == '\n')
				continue;
			else if(c2 == EOF)
				break;
		}

		/* get hex values */
		// consume 2 characters, discard both if 0x or 0X
		if (c1 == '0' && (c2 == 'x' || c2 == 'X'))
			continue;
		// convert chars to int from 0-15, discard both if non hex
		if ((h1=tobase10(c1)) != -1 && (h2=tobase10(c2)) != -1) {
			i = htoi(h1, h2);
			input[0] = c1;
			input[1] = c2;
			input[2] = '\0';
			printf("hex 0x%s : dec = %d\n", input, i);
		}
			
	}
}

/* parse atoi */
int tobase10(char c) {
	int base10;

	if (c >= '0' && c <= '9') {
		base10 = c - '0';
		return base10;
	}
	else if (c >= 'a' && c <= 'f') {
		base10 = c - 'a' + 10;
		return base10;
	}
	else if (c >= 'A' && c <= 'F') {
		base10 = c - 'A' + 10;
		return base10;
	}
	return -1;
}

/* turn a 2bytes of hex chars to decimal integer */
int htoi(int i1, int i2)
{
	int result;

	if (i1 == -1 || i2 == -1)
		return -1;

	result = 16 * i1 + i2;
	return result;
}
