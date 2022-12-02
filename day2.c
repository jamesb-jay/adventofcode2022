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


    closeFile(input);
    fclose(inputFile);
    return 0;
}


int getGameResult(char player, char opponent)
{
    /*
    ascii codes:
    opponent - player:
            X   Y   Z
        A  23  24  25

        B  22  23  24

        C  21  22  23
    >23 win
    =23 draw
    <23 loss
    */
    
    int result = (int)(opponent - player);

    if (result > 23)
        return 1;
    else if (result < 23)
        return -1;
    else
        return 0;
}