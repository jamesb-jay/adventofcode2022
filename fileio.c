#include "headers/fileio.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int checkFileReadOK(const char* filepath)
{
	if(access(filepath, R_OK) < 0)
	{
		return 0;
	}
	return 1;
}

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

LoadedFile loadFile(FILE *file, int maxLineSize)
{
	LoadedFile of = {file, 0, 0};

	char lineBuffer = calloc(maxLineSize, sizeof(char));
	int i = 0;

    /* Get number of lines in file */
    of.lineCount = countFileLines(file);
    if (!of.lineCount )
        return of;

    /* Allocate memory to load strings */
    of.lineArray = calloc(of.lineCount , sizeof(char*));

    for (i = 0; i < of.lineCount ; i++)
        of.lineArray[i] = calloc(maxLineSize, sizeof(char));

	i = 0;
	while (fgets(lineBuffer, maxLineSize, file) != NULL)
		strcpy(of.lineArray[i++], lineBuffer);

	rewind(file);
	return of;
}

void closeFile(LoadedFile file)
{
	int i;
	for (i = 0; i < file.lineCount; i++)
		free(file.lineArray[i]);
	free(file.lineArray);
	return;
}