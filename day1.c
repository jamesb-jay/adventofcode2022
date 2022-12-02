#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_BUF_SIZE 128

int getInputLineCount(FILE *file);
int countElves(FILE *file);
void loadCals(FILE *file, int *ea);
int max(int *arr, int size);

int main(int argc, char **argv)
{
	FILE *inputFile;
	int *caloriesArr, elves = 0, maxCal = 0;

	/* Check enough args */
	if (argc < 2)
	{
		printf("No input file specified!\n");
		return 1;
	}

	if(access(argv[1], R_OK) < 0)
	{
		printf("Could not access file '%s'\n", argv[1]);
		return 3;
	}

	inputFile = fopen(argv[1], "r");

	printf("Got %d lines\n", getInputLineCount(inputFile));

	elves = countElves(inputFile);
	printf("Got %d elves\n", elves);

	caloriesArr = calloc(elves, sizeof(int));

	printf("Calculating calorie totals...\n");
	loadCals(inputFile, caloriesArr);

	maxCal = max(caloriesArr, elves);
	printf("Highest total:\n%d\n", maxCal);

	free(caloriesArr);
	return 0;
}

int getInputLineCount(FILE *file)
{
	char ch = '0';
	int lines = 0;

	while ((ch = fgetc(file)) != EOF)
		if (ch == '\n')
			lines++;

	rewind(file);
	return lines;
}

int countElves(FILE *file)
{
	char lineBuffer[LINE_BUF_SIZE];
	int elves = 0;

	while (fgets(lineBuffer, LINE_BUF_SIZE, file) != NULL)
	{
		if (strlen(lineBuffer) <= 1)
			elves++;
	}

	rewind(file);
	return elves;
}

void loadCals(FILE *file, int *ea)
{
	char lineBuffer[LINE_BUF_SIZE];
	int sum = 0, i = 0;

	while (fgets(lineBuffer, LINE_BUF_SIZE, file) != NULL)
	{
		if (strlen(lineBuffer) <= 1)
		{
			ea[i++] = sum;
			sum = 0;
			continue;
		}
		sum += atoi(lineBuffer);
	}

	rewind(file);
	return;
}

int max(int *arr, int size)
{
	int i, high = 0;

	for (i = 0; i < size; i++)
		if (arr[i] > high)
			high = arr[i];

	return high;
}