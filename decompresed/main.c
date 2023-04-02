#include "functions.h"


int main() {
    FILE *compressFile;
    if ((compressFile = fopen("D:/CLionProjects/laab2sem2/compress.txt", "r")) == NULL)
    {
        printf("Error file\n");
        exit(1);
    }

        int count = 0;
        char c;
        while ((c = fgetc(compressFile)) != '\n')
        {
            if (c == '$') {
                count++;
            }
        }

    fclose(compressFile);

    if ((compressFile = fopen("D:/CLionProjects/laab2sem2/compress.txt", "r")) == NULL)
    {
        printf("Error file\n");
        exit(1);
    }
    fseek(compressFile,0,SEEK_SET);
    int numReplacements;
    char** wordsA;
    char** wordsB;

    wordsA = (char**)calloc(count/2,sizeof(char*));
    wordsB = (char**)calloc(count/2,sizeof(char*));
    readWordsFromFile(compressFile,&wordsA,&wordsB,&numReplacements);

    int length1 = WordLength(wordsA,numReplacements)+ WordLength(wordsB,numReplacements) + numReplacements*2;

    fseek(compressFile,length1,SEEK_SET);
    FILE* decompressFile = fopen("D:/CLionProjects/laab2sem2/decompress.txt", "w");


    printCompressedFile(compressFile, decompressFile,wordsA,wordsB,numReplacements);

    fclose(compressFile);
    fclose(decompressFile);

    return 0;
}