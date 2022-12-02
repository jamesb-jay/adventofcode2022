#include "headers/fileio.h"
#include <stdio.h>

int countFileLines(FILE *file)
{
	char ch = '0';
	int lines = 0;

	while ((ch = fgetc(file)) != EOF)
		if (ch == '\n')
			lines++;

	rewind(file);
	return lines;
}

char **loadFileStrings(FILE *file, int maxLineSize)
{
	char lineBuffer = calloc(maxLineSize, sizeof(char));
    char **fileStrings;

	int lines = 0, sum = 0, i = 0;

    /* Get number of lines in file */
    lines = countFileLines(file);
    if (!lines)
        return NULL;

    /* Allocate memory to load strings */
    fileStrings = calloc(lines, sizeof(char*));

    for (i = 0; i < lines; i++)
        fileStrings = calloc(maxLineSize, );


	while (fgets(lineBuffer, maxLineSize, file) != NULL)
	{
		
	}

	rewind(file);
	return;
}

void closeFileStrings(FILE *f)
{

}