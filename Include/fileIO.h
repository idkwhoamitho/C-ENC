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

char* readFile(char filePath[]){
    FILE *fin = fopen(filePath,"rb");
    if(!fin) perror("File is not found");
    
    fseek(fin, 0, SEEK_END);
    long fileSize = ftell(fin);
    fseek(fin,0,SEEK_SET);

    char* content = (char*)malloc(fileSize + 1);
    if(!content) perror("Memory allocation in readFile has failed");

    fread(content,1,fileSize,fin);
    content[fileSize] = '\0';

    fclose(fin);
    return content;
}




char* readFileBuffer (char filePath[],size_t* fileSize){
    FILE *fin = fopen(filePath,"rb");
    if(!fin) perror("File is not found");
    
    fseek(fin, 0, SEEK_END);
    *fileSize = ftell(fin);
    fseek(fin,0,SEEK_SET);

    char* buffer = (char*)malloc(*fileSize);
    if(!buffer) perror("Memory allocation failed");

    fread(buffer,1,*fileSize,fin);
    fclose(fin);
    return buffer;


}

#endif