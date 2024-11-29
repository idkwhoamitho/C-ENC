#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>
#define BYTES_PER_LINE 16
void writeFile(char contents[], char fileName[],const char* modes){
    FILE* file;
    file = fopen(fileName,modes);
    if(file == NULL){
        printf("Error while creating a file");
        exit(1);
    }
    fputs(contents,file);
    fclose(file);
    printf("Writed succesfully\n\n");
}



unsigned char* readFileBuffer (char filePath[]){
    FILE *fin = fopen(filePath,"rb");
    if(!fin) perror("File is not found");
    fseek(fin,0,SEEK_END);
    size_t file_size = ftell(fin);
    rewind(fin);

    unsigned char* buffer = (unsigned char* )malloc(file_size);
    if(!buffer) perror("Memory allocation failed");
    fread(buffer, 1,file_size, fin);
    fclose(fin);

    return buffer;

    free (buffer);
}

#endif