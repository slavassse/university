#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TITEM
{
    char *first_name;
    int count;
} PEOPLE;

int main(void) 
{
    int i = -1, size = 2;
    PEOPLE* person = (PEOPLE*)malloc(size * sizeof(PEOPLE));
    char *buffer = NULL;
    char *buffer_copy = NULL;
    size_t buffer_size;
    int max = 0, words_counter = 0;;

    while(getline(&buffer, &buffer_size, stdin) != EOF) {
        if(buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        
        buffer_copy = (char*)malloc(strlen(buffer) + 1);
        strcpy(buffer_copy, buffer);
        words_counter = 0;
        char *token = strtok(buffer, " ");
        while(token != NULL) {
            token = strtok(NULL, " ");
            words_counter++;
        }

        char *token2 = strtok(buffer_copy, " ");
        
        int match_counter = 0;
        for(int j = 0; j < words_counter - 1; j++) {
            if(i >= 0) {
                for(int k = 0; k <= i; k++) {
                    if(strcmp(person[k].first_name, token2) == 0) {
                        match_counter++;
                        person[k].count++;
                        if(person[k].count > max) {
                            max = person[k].count;
                        }
                    }
                }
            }
            if(match_counter == 0) {
                i++;
                if(i >= size) {
                    size *= 2;
                    person = (PEOPLE*)realloc(person, size * sizeof(PEOPLE));
                }
                char *temp;
                temp = (char*)malloc(strlen(token2) + 1);
                strcpy(temp, token2);
                person[i].first_name = temp;
                person[i].count = 1;
            }
            token2 = strtok(NULL, " ");
        }
        free(buffer_copy);
    }

    printf("Nejcastejsi jmeno: %d x\n", max);
    for(int q = 0; q < i; q++) {
        if(person[q].count == max) {
            printf("%s\n", person[q].first_name);
        }   
    }

    free(buffer);
    free(person);

    return 0;
}