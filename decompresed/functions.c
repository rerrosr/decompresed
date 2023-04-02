
#include "functions.h"


void readWordsFromFile(FILE* file, char*** wordsA, char*** wordsB, int* numReplacements) {
    int size = 16;
    int sizeLittle = 4;
    char* word = (char*)calloc(size, sizeof(char));
    int i = 0;

    while (fscanf(file, "$%[^$\n]", word) == 1) {
        char* secondWord = (char*)calloc(sizeLittle, sizeof(char));
        fscanf(file, "$%[^$\n]\n", secondWord);
        (*wordsA)[i] = (char*)calloc(strlen(word) + 1, sizeof(char));
        (*wordsB)[i] = (char*)calloc(strlen(secondWord) + 1, sizeof(char));
        strcpy((*wordsA)[i], word);
        strcpy((*wordsB)[i], secondWord);
        free(secondWord);
        i++;
    }
    free(word);

    *numReplacements = i;
}

void printCompressedFile(FILE* file, FILE* compressedFile, char** wordsA, char** wordsB, int numCheck) {
    int size = 16;
    char *word = (char *) calloc(size, sizeof(char));

    while (fscanf(file, "%16s", word) == 1) {
        unsigned long len = strlen(word);
        char lastChar = '\0';

        if (ispunct(word[len - 1])) {
            lastChar = word[len - 1];
            word[len - 1] = '\0';
        }

        int i = 0;
        while (i < numCheck && strcmp(word, wordsA[i]) != 0 && strcmp(word, wordsB[i]) != 0) {
            i++;
        }

        if (i < numCheck) {
            if (strcmp(word, wordsA[i]) == 0) {
                fprintf(compressedFile, "%s", wordsB[i]);
            } else {
                fprintf(compressedFile, "%s", wordsA[i]);
            }
        } else {
            fprintf(compressedFile, "%s", word);
        }

        if (lastChar != '\0') {
            fprintf(compressedFile, "%c ", lastChar);
        } else {
            fprintf(compressedFile, " ");
        }
    }

    free(word);
    fseek(compressedFile,0,SEEK_END);

    ftruncate(fileno(compressedFile), ftell(compressedFile) - 1);
}

int WordLength(char** words, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += strlen(words[i]);
    }
    return sum;
}
