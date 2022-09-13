#include <stdio.h>
#include <stdlib.h>

void _reorder_NW(void);
void _reorder_TNW(void);

int main(void) {
    const short int amount = 256;
    char char_array[amount];
    int counter = 0;
    int x = 0;
    FILE *fp;
    if((fp = fopen("NW.txt", "r")) == NULL) {
        perror("Ошибка чтения файла NW.txt");
        exit(0);
    }
    while((fgets(char_array, amount, fp)) != NULL) {
        counter++;
    }
    fclose(fp);
    if((fp = fopen("NW.txt", "r")) == NULL) {
        perror("Ошибка чтения файла NW.txt");
        exit(0);
    }
    char *pointers_array[counter];
    char *pointers_array1[counter];
    int array1[counter];
    int array2[counter];
    for(int i = 0; i < counter; i++) {
        pointers_array[i] = malloc(amount);
        pointers_array1[i] = malloc(amount);
    }
    for(int i = 0; i < counter; i++) {
        for(int j = 0; j < amount; j++) {
            pointers_array[i][j] = '\0';
            pointers_array1[i][j] = '\0';
        }
    }
    for(int i = 0; i < counter; i++) {
        array1[i] = array2[i] = -1;
    }
    counter = 0;
    while((fgets(pointers_array[counter], amount, fp)) != NULL) {
        counter++;
    }
    for(int i = 0; i < counter; i++) {
        x = rand();
        x %= counter;
        if(array1[x] < 0) {
            array1[x] = x;
            array2[i] = x;
        }
        else {
            do {
                x = rand();
                x %= counter;
            } while(array1[x] >= 0);
            array1[x] = x;
            array2[i] = x;
        }
    }
    int k;
    int a = 0;
    for(int i = 0; i < counter; i++) {
        k = 0;
        while(pointers_array[i][k] != '\0') {
            pointers_array1[array2[i]][k] = pointers_array[i][k];
            k++;
            a++;
        }
    }
    char *words_array = malloc(a + 1);
    a = 0;
    for(int i = 0; i < counter; i++) {
        k = 0;
        while(pointers_array1[i][k] != '\0') {
            words_array[a] = pointers_array1[i][k];
            a++;
            k++;
        }
    }
    words_array[a] = '\0';
    fclose(fp);
    if((fp = fopen("reordered_NW.txt", "w")) == NULL) {
        perror("Ошибка создания файла reordered_NW.txt");
        exit(0);
    }
    fputs(words_array, fp);
    fclose(fp);
    free(words_array);

    if((fp = fopen("TNW.txt", "r")) == NULL) {
        perror("Ошибка чтения файла TNW.txt");
        exit(0);
    }
    for(int i = 0; i < counter; i++) {
        for(int j = 0; j < amount; j++) {
            pointers_array[i][j] = '\0';
            pointers_array1[i][j] = '\0';
        }
    }
    for(int i = 0; i < counter; i++) {
        array1[i] = array2[i] = -1;
    }
    counter = 0;
    while((fgets(pointers_array[counter], amount, fp)) != NULL) {
        counter++;
    }
    for(int i = 0; i < counter; i++) {
        x = rand();
        x %= counter;
        if(array1[x] < 0) {
            array1[x] = x;
            array2[i] = x;
        }
        else {
            do {
                x = rand();
                x %= counter;
            } while(array1[x] >= 0);
            array1[x] = x;
            array2[i] = x;
        }
    }
    a = 0;
    for(int i = 0; i < counter; i++) {
        k = 0;
        while(pointers_array[i][k] != '\0') {
            pointers_array1[array2[i]][k] = pointers_array[i][k];
            k++;
            a++;
        }
    }
    words_array = malloc(a + 1);
    a = 0;
    for(int i = 0; i < counter; i++) {
        k = 0;
        while(pointers_array1[i][k] != '\0') {
            words_array[a] = pointers_array1[i][k];
            a++;
            k++;
        }
    }
    words_array[a] = '\0';
    fclose(fp);
    if((fp = fopen("reordered_TNW.txt", "w")) == NULL) {
        perror("Ошибка создания файла reordered_TNW.txt");
        exit(0);
    }
    fputs(words_array, fp);
    fclose(fp);
    return 0;
}

int _amountCicles(int counter, int finding_number) {
    int temp;
    int y = 0;
    int count = 0;
    temp = counter;
    do {
        if(temp >= 2)
            temp /= 2;
        else
            temp = 1;
        if(y < finding_number)
            y += temp;
        else 
            y -= temp;
        count++;
    } while(y != finding_number);
    return count;
} 