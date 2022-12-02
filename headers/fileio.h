#ifndef _FILEIO_H

#define _FILEIO_H

#include <stdio.h>

typedef struct LoadedFile
{
    FILE *file;
    char **lineArray;
    int lineCount;
} LoadedFile;

/* Check if a file is accessible */
int checkFileReadOK(const char* filepath);

/* Count the number of lines in a file */
int countFileLines(FILE *f);

/* Load a file */
LoadedFile loadFile(FILE *file, int maxLineSize);

/* Unload a file */
void closeFile(LoadedFile file);

#endif
