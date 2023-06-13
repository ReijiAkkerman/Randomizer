#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** strings[2];

void Read(int buffer_size, char* filename, int strings_number) {
    int counter = 0;
    char buffer[buffer_size];

    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Ошибка открытия файла %s\n", filename);
        exit(0);
    }

    while((fgets(buffer, buffer_size, fp)) != NULL) 
        counter++;

    strings[strings_number] = malloc(sizeof(char*) * counter);
    

    for(int i = 0; i < counter; i++) 
        strings[strings_number][i] = malloc(sizeof(char) * buffer_size);

    fseek(fp, 0, SEEK_SET);
    counter = 0;

    while((fgets(buffer, buffer_size, fp)) != NULL) {
        strcpy(strings[strings_number][counter], buffer);
        counter++;
    }
    for(int i = 0; i < counter; i++) {
        printf("%d\t%s", i, strings[strings_number][i]);
    }
}