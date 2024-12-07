//void LoadKey()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileIO.h"
#include "encrypt.h"
#include <sys/types.h>


void generateKey(){
    int len;
    srand(time(0));
    printf("please choose your key length(0 to exit): ");
    scanf("%d",&len);
    if(len == 0) return;
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
    printf("\nWARNING: DO NOT LOSE YOUR KEY OR YOUR FILE CAN'T BE DECRYPTED  \n\n");
}
void encrypt(){
    char keyFile[6] = "";
    char plaintext[100];

    printf("Please input your key file(0 to exit): ");
    scanf("%s",keyFile);
	if (strcmp(keyFile, "0") == 0) return;
    char* key = readFile(keyFile);
    printf("Please input your file (txt)(0 to exit): ");
    scanf("%s",plaintext);
	if (strcmp(plaintext, "0") == 0) return;
    encryptFile(plaintext,"./Encrypted",(char*)key);
    free(key);
}
void decrypt(){
    char keyFile[6] = "";
    char plaintext[100];

    printf("Please input your key file(0 to exit): ");
    scanf("%s",keyFile);
	if (strcmp(keyFile, "0") == 0) return;
    char* key = readFile(keyFile);
    printf("Please input your cipher (txt)(0 to exit): ");
    scanf("%s",plaintext);
	if (strcmp(plaintext, "0") == 0) return;
    encryptFile(plaintext,"./plaint",(char*)key);
    free(key);
}
void allMenu()
{
    int choose;
	printf("\n*************************\n");
    printf("**WELCOME TO KEY EDITOR**");
    while(1){
        printf("\n*************************");
        printf("\n	Main Menu	\n");
        printf("\n1. Generate key");
        printf("\n2. Encrypt file");
        printf("\n3. Decrypt file");
        printf("\n4. Exit");
        printf("\nYour choice: ");
        scanf("%d",&choose);

        if(choose == 4) break;
        if(choose == 1) generateKey();
        if(choose == 2) encrypt();
        if(choose == 3) decrypt();

    }
}
