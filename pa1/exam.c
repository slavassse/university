#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *string1;
} slovnik;

typedef struct {
    char *string2;
    int finded;
} seznam;

int main(void)
{
    int lenght = 0, strtok_need = 0, size1 = 2, i1 = -1, size2 = 2, i2 = -1, flag = 0, skip = 0;
    slovnik* slovo1 = (slovnik*)malloc(size1 * sizeof(slovnik));
    seznam* slovo2 = (seznam*)malloc(size2 * sizeof(seznam));
    printf("Slovnik:\n");
    size_t buffer_size = 1000;
    char *buffer = NULL;
    while(getline(&buffer, &buffer_size, stdin) != EOF) {
        if(buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        if(strcmp(buffer, "*****") == 0 && flag == 0) {
            flag = 1;
        }

        if(flag == 0) {
            strtok_need = 0;
            lenght = strlen(buffer);
            for(int j = 0; j < strlen(buffer); j++) {
                if(buffer[j] == ' ') {
                    strtok_need = 1;
                }
            }
            if(strtok_need == 0) {
                i1++;
                if(size1 >= i1) {
                    size1 += 2;
                    slovo1 = (slovnik*)realloc(slovo1, size1 * sizeof(slovo1));
                }
                slovo1[i1].string1 = (char*)malloc((lenght + 1) * sizeof(char));
                strcpy(slovo1[i1].string1, buffer);
            } else {
                char *token;
                token = strtok(buffer, " ");
                while(token != NULL) {
                    i1++;
                    if(size1 >= i1) {
                        size1 += 2;
                        slovo1 = (slovnik*)realloc(slovo1, size1 * sizeof(slovo1));
                    }
                    slovo1[i1].string1 = (char*)malloc((lenght + 1) * sizeof(char));
                    strcpy(slovo1[i1].string1, buffer);
                    token = strtok(NULL, " ");
                }
            }
        }

        if(flag == 2) {
            strtok_need = 0;
            lenght = strlen(buffer);
            for(int j = 0; j < strlen(buffer); j++) {
                if(buffer[j] == ' ') {
                    strtok_need = 1;
                }
            }
            if(strtok_need == 0) {
                i2++;
                if(size2 >= i2) {
                    size2 += 2;
                    slovo2 = (seznam*)realloc(slovo2, size2 * sizeof(slovo2));
                }
                slovo2[i2].string2 = (char*)malloc((lenght + 1) * sizeof(char));
                strcpy(slovo2[i2].string2, buffer);
                slovo2[i2].finded = 0;
            } else {
                char *token;
                token = strtok(buffer, " ");
                while(token != NULL) {
                    i2++;
                    if(size2 >= i2) {
                        size2 += 2;
                        slovo2 = (seznam*)realloc(slovo2, size2 * sizeof(slovo2));
                    }
                    slovo2[i2].string2 = (char*)malloc((lenght + 1) * sizeof(char));
                    strcpy(slovo2[i2].string2, buffer);
                    slovo2[i2].finded = 0;
                    token = strtok(NULL, " ");
                }
            }
        }

        if(flag == 1) {
            printf("Text:\n");
            flag = 2;
        }
    }

    if(flag == 0 && strcmp(buffer, "*****")) {
        printf("Nespravny vstup.\n");
        free(buffer);
        for(int j = 0; j <= i1; j++) {
            free(slovo1[j].string1);
        }
        free(slovo1);
        for(int j = 0; j <= i2; j++) {
            free(slovo2[j].string2);
        }
        free(slovo2);
        return 0;
    }

    for(int j = 0; j <= i2; j++) {
        for(int k = 0; k <= i1; k++) {
            if(strcasecmp(slovo2[j].string2, slovo1[k].string1) == 0) {
                slovo2[j].finded = 1;
            }
        }
    }

    int symbol_counter = 0;
    for(int j = 0; j <= i2; j++) {
        lenght = strlen(slovo2[j].string2);
        if(slovo2[j].finded == 1) {
            if((symbol_counter + (lenght + 1)) > 80) {
                printf("\n");
                symbol_counter = 0;
            } 
            if(symbol_counter > 0) printf(" ");
            printf("%s", slovo2[j].string2);
            symbol_counter += lenght;
        } else {
            if((symbol_counter + (lenght + 1 + 11)) > 80) {
                printf("\n");
                symbol_counter = 0;
            } 
            if(symbol_counter > 0) printf(" ");
            printf("<err>%s</err>", slovo2[j].string2);
            symbol_counter += (lenght + 1 + 11);
        }
        if(i2 == j) printf("\n");
    }

    free(buffer);
    for(int j = 0; j <= i1; j++) {
        free(slovo1[j].string1);
    }
    free(slovo1);
    for(int j = 0; j <= i2; j++) {
        free(slovo2[j].string2);
    }
    free(slovo2);
    return 0;
}






