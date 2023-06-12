#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* filename;
char* pathname;
char* fullname;
char** NW_array;
char* counter_array;

void Read() {
    register int counter = 0;
    char buffer[256];

    FILE* fp = fopen("NW.txt", "r");
    if(fp == NULL) {
        perror("Ошибка открытия потока\n");
        exit(0);
    }
    while((fgets(buffer, 256, fp)) != NULL) 
        counter++;

    counter_array = malloc(counter * sizeof(char));     // массив для количества символов в строке 
    NW_array = malloc(counter * sizeof(char*));         // массив указателей на строки
    for(register int i = 0; i < counter; i++) 
        NW_array[i] = malloc(256);

    fseek(fp, 0, SEEK_SET);
    register int i = 0;
    while((fgets(buffer, 256, fp)) != NULL) {
        register int j = 0;
        while(buffer[j] != '\n') {
            NW_array[i][j] = buffer[j];
            j++;
        }
        NW_array[i][j] = '\n';
        j++;
        counter_array[i] = j;
        j = 0;
        i++;
    }
    fclose(fp);
    for(int i = 0; i < counter; i++) {
        printf("%d\t%d\t%s", i, counter_array[i], NW_array[i]);
    }
}