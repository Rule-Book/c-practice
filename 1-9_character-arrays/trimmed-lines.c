#include <stdio.h>
#define MAXLINE	15	/* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		if (len > 80)
			printf("%s\n", line);
	}
		printf("hit3\n");
	if (max > 0) {	/* there was a line */
		printf("hit4\n");
		printf("%s at length %d", longest, max);
	}
	return 0;
}

/* get_line:	read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i, j, last_space, prev;

	j = prev = last_space = 0;
	for (j=0; j < lim-1 && (c=getchar())!=EOF && c!='\n' && c==' '; ++j) {
		;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}		
	for (i=0; i < lim-1 && c!=EOF && c!='\n'; ++i) {
		s[i] = c;
		if ((c==' ' && prev!=' ') || c!=' ')
			last_space = i;
		prev = c;
		c = getchar();
	//	printf("last space found at %d\n", last_space);
	}
	if (c == '\n') {
		printf("i = %d; c = %d\n", i, c);
		s[i] = c;
		++i;
	}
	else 
		if (c == EOF)
	//		printf("hit eof and ls=%d\n", last_space);
	/*else
		for (j = i; j<100 && c!='\n' && c!=EOF; ++j)
			if ((c==' ' && prev!=' ') || c!=' ') {
				printf("smth\n");
				last_space = j;
				c = getchar();
			}*/
//	putchar(c);
	printf("hit2 and i = %d\n", i);
	//printf("last space isnt \n");
	//printf("last space is %d\n", last_space);
	s[i] = '\0';
	//printf("hit5 and i = %d\n", i);
	//printf("last space is %d\n", last_space);

	i = ++last_space;
	printf("hit6 and i = %d\n\n\n", i);
	return i;
}

/* copy:	copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
