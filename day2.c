#include <stdio.h>
#include <string.h>

#include "headers/fileio.h"

int getGameResult(char player, char opponent);
int calculateScore(LoadedFile *input);
int getPoints(char choice);

int main(int argc, char **argv)
{
	FILE *inputFile;
    LoadedFile input;

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

    printf("Score: %d\n", calculateScore(&input));

    closeFile(input);
    fclose(inputFile);
    return 0;
}


int getGameResult(char player, char opponent)
{
    /*
    ascii codes:
    player - opponent:
            X   Y   Z
        A  23  24  25

        B  22  23  24

        C  21  22  23
    >23 win
    =23 draw
    <23 loss
    */

    
    int result = (int)(player - opponent);
    if (result == 23)
        return 0;
    else if (result == 25 || result == 22)
        return -1;
    else
        return 1;
}

int calculateScore(LoadedFile *input)
{
    int i, result, score = 0;
    char *buf, me, opp;

    for (i = 0; i < input->lineCount; i++)
    {
        buf = strtok(input->lineArray[i], " ");
        opp = buf[0];
        buf = strtok(NULL, " ");
        me = buf[0];

        result = getGameResult(me, opp);
        if (result > 0)
        {
            /* Win! */
            score += getPoints(me) + 6;

        }
        else if (result < 0)
        {
            /* Lose */
            score += getPoints(me);
        }
        else
        {
            /* Draw */
            score += getPoints(me) + 3;
        }
    }

    return score;
}

int getPoints(char choice)
{
    if (choice == 'A' || choice == 'X')
        return 1;
    if (choice == 'B' || choice == 'Y')
        return 2;
    if (choice == 'C' || choice == 'Z')
        return 3;
    
    return 0;
}
