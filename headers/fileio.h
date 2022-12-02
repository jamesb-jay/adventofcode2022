#ifndef _FILEIO_H

#define _FILEIO_H

/* Count the number of lines in a file */
int countFileLines(FILE *f);

/* Load an array of strings containing each line of the file. */
char **loadFileStrings(FILE *f, int maxLineSize);

void closeFileStrings(FILE *f);

#endif
