#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <stdlib.h>
#include<string.h>
#include "fileIO.h"
enum ENC_ALGO{
    EAS,
    OTP 
};

struct State{
    char* key;
    char* filePath;
};


unsigned char* OTPAlgorithm (char key[], unsigned char* buffer,size_t keySize, size_t bufferSize){
    int i = 0;
    int j = 0;
    do
    {
        if(j + 1 > (int)keySize) j = 0;
        buffer[i] ^= key[j];
        i++;
        j++;
    }while(i < (int)bufferSize);
    return buffer;
};

void encryptFile(char filePath[], char fileOutput[], char key[]){
    unsigned char* buffer = readFileBuffer(filePath);
    size_t keysSize = strlen(key);
    size_t bufferSize = sizeof(buffer) / sizeof(unsigned char*);

    unsigned char* enc = OTPAlgorithm(key,buffer,keysSize,bufferSize);
    writeFile((char*)enc,fileOutput,"wb");    

};





#endif