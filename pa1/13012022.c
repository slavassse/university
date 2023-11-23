#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LIST
{
    char *full_name;
} DOMINOS_LIST;

int main(void) 
{
    int i = -1, size = 2;
    DOMINOS_LIST* domino = (DOMINOS_LIST*)malloc(size * sizeof(DOMINOS_LIST));
    char *buffer;
    size_t buffer_size = 1000;
    buffer = (char*)malloc(buffer_size * sizeof(char));
    int input_size = 0, unique = 0;

    while(getline(&buffer, &buffer_size, stdin) != EOF) {
        input_size = strlen(buffer);
        if(buffer[strlen(buffer) - 1] == '\n' && strlen(buffer) != 1) {
            buffer[strlen(buffer) - 1] = '\0';
        }
    
        i++;
        if(i >= size) {
            size *= 2;
            domino = (DOMINOS_LIST*)realloc(domino, size * sizeof(*domino));
        }

        const char delim[4] = "[,-]";
        char *token;
        token = strtok(buffer, delim);
            
        domino[i].full_name = (char*)malloc(input_size * sizeof(char));
        int j = -1;
        while(token != NULL) {
            j++;
            if(j > 0) {
                strcat(domino[i].full_name, token);
            } else {
                strcpy(domino[i].full_name, token);
            }
            token = strtok(NULL, delim);
        }

        int flag = 0;
        for(int k = 0; k <= i; k++) {
            if(strstr(domino[k].full_name, domino[i].full_name) && i != k) {
                flag = 1;
                break;
            }   
        } 
        if(flag == 0) {
                unique++;
        }

        char *temp = (char*)malloc(input_size * sizeof(char));
        strcpy(temp, domino[i].full_name);
        strcat(domino[i].full_name, temp);
        
    }
    if(i < 0) {
        printf("Nespavny vstup.\n");
        free(buffer);
        free(domino);
        return 0;
    }

    printf("Unikatni: %d\n", unique);

    for(int k = 0; k <= i; k++) {
            free(domino[k].full_name);
    }
    free(domino);

    return 0;
}