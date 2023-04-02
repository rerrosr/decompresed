
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


#ifndef DECOMPRESED_FUNCTIONS_H
#define DECOMPRESED_FUNCTIONS_H

void readWordsFromFile(FILE*, char***, char***, int*);
void printCompressedFile(FILE*,FILE*,char**,char**,int);
int WordLength(char**, int);

#endif //DECOMPRESED_FUNCTIONS_H
