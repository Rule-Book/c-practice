#include <stdio.h>
#define MAXLINE	1000	/* maximum input line length */

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
		if (line[0] == '\n')
			continue;
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		if (len > 80)
			printf("%s\n", line);
	}
	if (max > 0) {	/* there was a line */
		printf("%s at length %d\n", longest, max);
	}
	return 0;
}

/* get_line:	read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i, j;

	int prev, last_space;
	prev = last_space = 0;
	j = 0;

	/* consume leading spaces without contributing to length */
	for (j=0; j < lim-1 && (c=getchar())!=EOF && c!='\n' && c==' '; ++j) {
		;
	}

	/* update char array if current character is not an end character */
	for (i=0; i < lim-1 && c!=EOF && c!='\n'; ++i) {
		s[i] = c;
		prev = c;
		c = getchar();
		/* update index of last trailing character excluding ' ' */
		if (c!=EOF&&c!='\n'&&((prev!=' ' && c==' ') || c!=' ')) {
			last_space = i+1;
		}
	}
	/* pseudo error code for lines to be ignored in main method */
	if (last_space <= 1 && (s[0] == ' ' || s[0] == '\n')) {
		s[0] = '\n';
		return 1;
	}
	/* if limit was reached without ending in newline or EOF, continue */
	while (c!='\n' && c!=EOF) {
		prev = c;
		++i;
		c = getchar();
		if (c!=EOF&&c!='\n'&&((prev!=' ' && c==' ') || c!=' ')) {
			last_space = i+1;
		}
	}
	/* cap overlimit strings to avoid print and program end issues */
	if (i >= lim-2) {
		s[lim-2] = '\n';
		s[lim-1] = '\0';
	}
	/* set length to end of last non space character */
	i = last_space;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	printf(" = %d\n", i);
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
