#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
void printConversion(int lower, int upper, int step);

int main()
{
	printConversion(0, 300, 20);
}

void printConversion(int lower, int upper, int step)
{
	int fahr;
	for (fahr = lower; fahr <= upper; fahr = fahr + step) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}
