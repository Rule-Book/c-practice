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
			if (wl > 0)
				++nword[wl-1];
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

	// normalize number of words to fit within 15 lines
	// divide each frequency by maxfreq then multiply by 15
	// increment for loop until greater than instead of flooring
	// allow FLT_DIG (6) + 2 digits length for max float size
	// separate histograms with ' | ' bracket
	
	// create array of normalized frequencies
	
// 	float normalizedfreq = 0;
	int freq = 0;
	int normalizedfreq[15];
	for (int i = 0; i < 15; ++i) {
		freq = nword[i];
		normalizedfreq[i] = (freq * 1.0f) / (maxfreq * 1.0f) * 15.0f;
	}

	printf("normalized word frequency by length:");
	for (int i = 0; i < 15; ++i)
		printf(" %d", normalizedfreq[i]);
	printf("\n");
	
	
	// threshold of frequency to register as visible from line
	// is the arrayLength - lineNumber 
	// if freq > threshold, draw graphic
	//   else fill with spaces
	
	float threshold;
	for (int line = 0; line < 15; ++line) {
		threshold = 15 - line;
		for (int i = 0; i < 15; i++) {
			// printf("freq=%d thresh=%f", normalizedfreq[i], threshold);
			if (normalizedfreq[i] > threshold)
				printf("A");
			else
				printf(".");
		}
		printf("\n");
	}
}
