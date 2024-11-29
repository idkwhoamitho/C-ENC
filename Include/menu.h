//void LoadKey()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileIO.h"
#include "encrypt.h"


void generateKey(){
    int len;
    srand(time(0));
    printf("please choose your key length: ");
    scanf("%d",&len);
    char key[len];
    for(int i = 0;i < len;i++){
        if(i % 2 == 0){
            key[i] = (rand() % (90 - 65 + 1)) + 65;
        }
        else{
            key[i] = (rand() % (122 - 97 + 1)) + 97;
        }
    }
    printf("key: %s\n",key);
    printf("proccessing and saving key to key.txt  \n");
    writeFile(key,"./key","w");
    printf("\nWARNING: DO NOT LOSE YOUR KEY OR YOUR FILE CAN'T BE DECRYPTED");
}
void encrypt(){
    char keyFile[6] = "";
    printf("Please input your key file: ");
    scanf("%s",keyFile);
    unsigned char* key = readFileBuffer(keyFile);
    printf("%s",key);

}

void allMenu()
{
    int choose;
    while(1){
        printf("Main Menu ");
        printf("\n1. Generate key");
        printf("\n2. Encrypt file");
        printf("\n3. Decrypt file");
        printf("\n4. Exit");
        printf("\nYour choice: ");
        scanf("%d",&choose);

        if(choose == 4) break;
        if(choose == 1) generateKey();
        if(choose == 2) encrypt();
    }
}