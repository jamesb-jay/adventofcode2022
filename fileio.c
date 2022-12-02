#include "headers/fileio.h"
#include <stdio.h>

int countFileLines(FILE *f)
{
	char ch = '0';
	int lines = 0;

	while ((ch = fgetc(file)) != EOF)
		if (ch == '\n')
			lines++;

	rewind(file);
	return lines;
}