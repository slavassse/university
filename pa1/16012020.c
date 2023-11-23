#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int count;
} products;

typedef struct
{
    char *name;
    int count;
} lack;

int main(void) 
{
    int i = -1, size = 2, flag = 0, flag3 = 0, k = -1, size2 = 2, flag2 = 0;
    char *buffer = NULL;
    size_t buffer_size;

    lack* product2 = (lack*)malloc(size2 * sizeof(lack)); 
    products* product = (products*)malloc(size * sizeof(products)); 

    printf("Sklad:\n");
    while(getline(&buffer, &buffer_size, stdin) != EOF) {
        if(strcmp(buffer, "\n") == 1 && flag3 == 0) {
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            if(strlen(buffer) > 100 || strlen(buffer) < 5) {
                printf("Nespravny vstup.\n");
                free(buffer);
                for(int j = 0; j <= i; j++) {
                    free(product[j].name);
                }
                free(product);
                return 0;
            }
            flag = 0;
            if(i >= 0) {
                for(int j = 0; j <= i; j++) {
                    if(strcmp(product[j].name, buffer) == 0) {
                        product[j].count++;
                        flag = 1;
                    }
                }
            }
            if(flag == 0) {
                i++;
                if(i >= size) {
                    size *= 2;
                    product = (products*)realloc(product, size * sizeof(products));
                }
                product[i].name = (char*)malloc((101) * sizeof(char));
                strcpy(product[i].name, buffer);
                product[i].count = 1;
            } 
        } else if(strcmp(buffer, "\n") == 0 && flag3 == 0) {
            flag3 = 1;
            printf("Inventura:\n");
            for(int j = 0; j <= i; j++) {
                printf("%s: %d x\n", product[j].name, product[j].count);
            }
        } else {
            if(buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            if(strlen(buffer) > 100 || strlen(buffer) < 5) {
                printf("Nespravny vstup.\n");
                free(buffer);
                for(int j = 0; j <= i; j++) {
                    free(product[j].name);
                }
                free(product);
                return 0;
            }
            flag = 0;
            for(int j = 0; j <= i; j++) {
                if(strcmp(product[j].name, buffer) == 0 && product[j].count == 0) {
                    flag = 0;
                } else if(strcmp(product[j].name, buffer) == 0 && product[j].count > 0) {
                    flag = 1;
                    if(product[j].count > 0) {
                        product[j].count--;
                    }
                } 
            }
            if(flag == 0) {
                flag2 = 0;
                for(int j = 0; j <= k; j++) {
                    if(strcmp(product2[j].name, buffer) == 0) {
                        product2[j].count++;
                        flag2 = 1;
                    }
                }
                if(flag2 == 0) {
                    k++;
                    if(k >= size2) {
                        size2 *= 2;
                        product2 = (lack*)realloc(product2, size2 * sizeof(lack));
                    }
                    product2[k].name = (char*)malloc((101) * sizeof(char));
                    strcpy(product2[k].name, buffer);
                    product2[k].count = 1;

                }
            }
        }
    }

    for(int j = 0; j <= k; j++) { 
        for(int q = 0; q <= k; q++) {  
            if(product2[j].count > product2[q].count) {
                int temp = product2[j].count;
                product2[j].count = product2[q].count;
                product2[q].count = temp; 
                char *temp2 = (char*)malloc((101) * sizeof(char));
                strcpy(temp2, product2[j].name);
                strcpy(product2[j].name, product2[q].name);
                strcpy(product2[q].name, temp2); 
            }
        }
    }

    printf("Chybi:\n");
    int counter = 0;
    if(k < 10) {
        for(int j = 0; j <= k; j++) {
            if(product2[j].count != 0) {
                printf("%s: %d x\n", product2[j].name, product2[j].count);
            }
            counter += product2[j].count;
        }
    } else {
        for(int j = 0; j <= 10; j++) {
            if(product2[j].count != 0) {
                printf("%s: %d x\n", product2[j].name, product2[j].count);
            }
            counter += product2[j].count;
        }
    }

    printf("Celkem: %d\n", counter);

    free(buffer);
    for(int j = 0; j <= i; j++) {
        free(product[j].name);
    }
    free(product);

    return 0;
}