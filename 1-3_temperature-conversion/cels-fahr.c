#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for celsius = 0, 5, ..., 100 */
int main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = 0;	/* lower limit of temperature scale */
	upper = 100; 	/* upper limit */
	step = 5;	/* step size */
	
	celsius = lower;
	printf("%7s\t%s\n", "Celsius", "Fahr");
	printf("===================\n");

	while (celsius <= upper) {
		fahr = celsius / (5.0/9.0) + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
