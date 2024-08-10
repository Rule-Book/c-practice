#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

int main()
{
	int c, nw, wl, state;
	int nword[15];

	for (int i = 0; i < 15; ++i)
		nword[i] = 0;

	// get length of longest word
	state = OUT;
	nw = wl = 0;
	while ((c = getchar()) != EOF) {
		if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9')) {
			state == OUT;
			++nword[wl];
			wl = 0;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
			++wl;
		}
		else
			++wl;
	}
	printf("word frequency by length:");
	for (int i = 0; i < 15; ++i)
		printf(" %d", nword[i]);
	printf("\n");
	
	float maxfreq = 0;
	for (int i = 0; i < 15; ++i)
		if (nword[i] > maxfreq)
			maxfreq = nword[i];

	// normalize number of words to fit within 50 characters rounded down
	// divide each frequency by maxfreq then multiply by 50
	// increment for loop until greater than instead of flooring
	// allow FLT_DIG (6) + 2 digits length for max float size
	// separate histograms with ' | ' bracket
	
	float normalizedfreq = 0;
	int freq = 0;
	for (int i = 0; i < 15; ++i) {
		freq = nword[i];
		normalizedfreq = (freq * 1.0f) / (maxfreq * 1.0f) * 50.0f;
		printf("freq=%6d for length %2d |", freq, i);
		for (int i = 0; i < normalizedfreq; i++)
			printf("]");
		printf("\n");
	}
}
