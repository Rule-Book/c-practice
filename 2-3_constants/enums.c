#include <stdio.h>

int main()
{
	enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
	printf("%d\n", JAN);
	enum months this_month = AUG;
	
	printf("%d\n", FEB);
	printf("%d\n", this_month);
}
