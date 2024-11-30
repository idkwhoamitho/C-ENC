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


unsigned char* OTPAlgorithm (char key[], unsigned char* buffer,int keySize, int bufferSize){
    int i = 0;
    int j = 0;
    do
    {
        if(j + 1 > keySize) j = 0;
        buffer[i] ^= key[j];
        i++;
        j++;
    }while(i < bufferSize);
    return buffer;
};

void encryptFile(char filePath[], char fileOutput[], char key[]){
    size_t fileSize;
    char* buffer = (char*)readFileBuffer(filePath,&fileSize);
    size_t keysSize = strlen(key);
    //size_t bufferSize =strlen((char*)buffer);

    unsigned char* enc = OTPAlgorithm(key,(unsigned char*)buffer,keysSize,(int)fileSize);
    writeFile((char*)enc,fileOutput,"wb");    

};





#endif