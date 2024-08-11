#include <stdio.h>

void reverse(char i[], int length, char o[]);

int main()
{
	char s[] = { 100, 100, 99, 117, 32, 110, 110, 97, '\0'};
	char s_[] = { 112, 112, 112, 112, 112, 112, 112, 112, 112};

	reverse(s, 9, s_);
	printf("%s\n", s);
	printf("%s\n", s_);
}

void reverse(char i[], int length, char o[])
{
	if (length <=1) {
		o[0] = i[0];
		return;
	}

	int x;

	o[length-1] = '\0';
	for (x=0; i[x]!='\0' && x<length; x++)
		o[length-x-2] = i[x];
}
