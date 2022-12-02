#include <stdio.h>

#include "headers/fileio.h"

int main(int argc, char **argv)
{
	FILE *inputFile;
    LoadedFile input;
    int i;

	/* Check enough args */
	if (argc < 2)
	{
		printf("No input file specified!\n");
		return 1;
	}

    if (!checkFileReadOK(argv[1]))
    {
        printf("Unable to load file '%s'\n", argv[1]);
        return 2;
    }

    inputFile = fopen(argv[1], "r");
    input = loadFile(inputFile, 16);

    for (i = 0; i < input.lineCount; i++)
    {
        printf("Line %d: %s\n", i, input.lineArray[i]);
    }

    return 0;
}
