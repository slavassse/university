#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int toint(const char* input, int characters_without_hashtag){
    int number = 0;
    int i = 1;
    if(strlen(input) < 2) {
        return -1;
    }
    for(int i = 1; i < characters_without_hashtag; i++) {
        if(!(isdigit(input[i]))) {
            return -1;
        }
    }
    while (input[i] && (input[i] >= '0' && input[i] <= '9')){
        number = number * 10 + (input[i] - '0');
        i++;
    }
    return number;
}

typedef struct shop {
    char *product_name;
    int shelf_number;
} products_in_shop;

typedef struct list {
    char *product_name;
    int is_finded;
    int list_number;
} products_in_list;

typedef struct output {
    char *list_product_name;
    char *finded_product_name;
    int shelf_number_out;
    int list_number_out;
    int product_number_out;
} sorted_list;

int main(void)
{
    int i_shop = -1, i_list = -1, size_of_shop_struct = 2, size_of_list_struct = 2, input_shelf_number = -1, common_counter = 0, check_shelf, size_of_sorted_struct = 2;    
    products_in_shop* product = (products_in_shop*)malloc(size_of_shop_struct * sizeof(products_in_shop));
    products_in_list* product2 = (products_in_list*)malloc(size_of_list_struct * sizeof(products_in_list));
    char *input;
    size_t input_size = 100000;
    input = (char*)malloc(input_size * sizeof(char));
    int input_stage = -1, space_entered = 0;

    while(getline(&input, &input_size, stdin) != EOF) {
        if(input[strlen(input) - 1] == '\n' && strlen(input) != 1) {
            input[strlen(input) - 1] = '\0';
        }
        if(input[0] == '\n') {
            if(input_shelf_number == -1) {
                free(input);
                printf("Nespravny vstup.\n");
                for(int j = 0; j <= i_shop; j++) {
                    free(product[j].product_name);
                }
                for(int j = 0; j <= i_list; j++) {
                    free(product2[j].product_name);
                }
                free(product);
                free(product2);
                return 0;
            }
            input_stage++;
            space_entered++;
        } else {
            space_entered = 0;
        }
        if(input_shelf_number == -1 && input[0] != '#') {
            free(input);
            printf("Nespravny vstup.\n");
            for(int j = 0; j <= i_shop; j++) {
                free(product[j].product_name);
            }
            for(int j = 0; j <= i_list; j++) {
                free(product2[j].product_name);
            }
            free(product);
            free(product2);
            return 0;
        }
        if(input_stage == -1) {
            if(input[0] == '#') {
                input_shelf_number++;
                check_shelf = toint(input, strlen(input) - 1);
                if(check_shelf == -1 || check_shelf != input_shelf_number) {
                    free(input);
                    printf("Nespravny vstup.\n");
                    for(int j = 0; j <= i_shop; j++) {
                        free(product[j].product_name);
                    }
                    for(int j = 0; j <= i_list; j++) {
                        free(product2[j].product_name);
                    }
                    free(product);
                    free(product2);
                    return 0;
                }
            } else {
                i_shop++;
                if(i_shop >= size_of_shop_struct) {
                    size_of_shop_struct *= 2;
                    product = (products_in_shop*)realloc(product, size_of_shop_struct * sizeof(*product));
                }   
                product[i_shop].product_name = (char*)malloc((strlen(input) + 1) * sizeof(char));
                strcpy(product[i_shop].product_name, input);
                product[i_shop].shelf_number = input_shelf_number;
            }

        } else if(input_stage >= 0 && space_entered == 0) {
            i_list++;
            if(i_list >= size_of_list_struct) {
                size_of_list_struct *= 2;
                product2 = (products_in_list*)realloc(product2, size_of_list_struct * sizeof(*product2));
            }
            product2[i_list].product_name = (char*)malloc((strlen(input) + 1) * sizeof(char));
            strcpy(product2[i_list].product_name, input);
            product2[i_list].list_number = input_stage;
            product2[i_list].is_finded = 0;
        } 
        if(space_entered > 1) {
            free(input);
            printf("Nespravny vstup.\n");
            for(int j = 0; j <= i_shop; j++) {
                free(product[j].product_name);
            }
            for(int j = 0; j <= i_list; j++) {
                free(product2[j].product_name);
            }
            free(product);
            free(product2);
            return 0;
        }
        common_counter++;
    }

    if(i_list < 0) {
        free(input);
        printf("Nespravny vstup.\n");
        for(int j = 0; j <= i_shop; j++) {
            free(product[j].product_name);
        }
        for(int j = 0; j <= i_list; j++) {
            free(product2[j].product_name);
        }
        free(product);
        free(product2);
        return 0;
    }

    sorted_list* product3 = (sorted_list*)malloc(size_of_sorted_struct * sizeof(sorted_list));
    int counter = -1, product_number = -1;
    for(int j = 0; j <= i_list; j++) {
        char *tmp2 = (char*)malloc((strlen(product2[j].product_name) + 1) * sizeof(char));
        strcpy(tmp2, product2[j].product_name);
        for(int i = 0; tmp2[i]; i++){
                tmp2[i] = tolower(tmp2[i]);
        }
        for(int k = 0; k <= i_shop; k++) {
            char *tmp1 = (char*)malloc((strlen(product[k].product_name) + 1) * sizeof(char));
            strcpy(tmp1, product[k].product_name);
            for(int i = 0; tmp1[i]; i++){
                tmp1[i] = tolower(tmp1[i]);
            }
            if(strcmp(tmp1, tmp2) == 0 && product2[j].is_finded == 0) {
                counter++;
                product_number++;
                if(counter >= size_of_sorted_struct) {
                    size_of_sorted_struct *= 2;
                    product3 = (sorted_list*)realloc(product3, size_of_sorted_struct * sizeof(*product3));
                } 
                product3[counter].list_product_name = (char*)malloc((strlen(product2[j].product_name) + 1) * sizeof(char));
                strcpy(product3[counter].list_product_name, product2[j].product_name);
                product3[counter].finded_product_name = (char*)malloc((strlen(product[k].product_name) + 1) * sizeof(char));
                strcpy(product3[counter].finded_product_name, product[k].product_name);
                product3[counter].shelf_number_out = product[k].shelf_number;
                product3[counter].list_number_out = product2[j].list_number;
                product3[counter].product_number_out = product_number;
                product2[j].is_finded = 1;
            }
            if(product2[j].is_finded == 1) {
                free(tmp1);
                break;
            }
            free(tmp1);
        }
        for(int k = 0; k <= i_shop; k++) {
            char *tmp1 = (char*)malloc((strlen(product[k].product_name) + 1) * sizeof(char));
            strcpy(tmp1, product[k].product_name);
            for(int i = 0; tmp1[i]; i++){
                tmp1[i] = tolower(tmp1[i]);
            }
            if(strstr(tmp1, tmp2) && strcmp(tmp1, tmp2) != 0 && product2[j].is_finded == 0) {

                counter++;
                product_number++;
                if(counter >= size_of_sorted_struct) {
                    size_of_sorted_struct *= 2;
                    product3 = (sorted_list*)realloc(product3, size_of_sorted_struct * sizeof(*product3));
                } 
                product3[counter].list_product_name = (char*)malloc((strlen(product2[j].product_name) + 1) * sizeof(char));
                strcpy(product3[counter].list_product_name, product2[j].product_name);
                product3[counter].finded_product_name = (char*)malloc((strlen(product[k].product_name) + 1) * sizeof(char));
                strcpy(product3[counter].finded_product_name, product[k].product_name);
                product3[counter].shelf_number_out = product[k].shelf_number;
                product3[counter].list_number_out = product2[j].list_number;
                product3[counter].product_number_out = product_number;
                product2[j].is_finded = 1;
            }
            if(product2[j].is_finded == 1) {
                free(tmp1);
                break;
            }
            free(tmp1);
        }
        free(tmp2);
    }

    for(int j = 0; j <= i_list; j++) {
        if(product2[j].is_finded == 0) {
            counter++;
            product_number++;
            if(counter >= size_of_sorted_struct) {
                size_of_sorted_struct *= 2;
                product3 = (sorted_list*)realloc(product3, size_of_sorted_struct * sizeof(*product3));
            } 
            product3[counter].list_product_name = (char*)malloc((strlen(product2[j].product_name) + 1) * sizeof(char));
            strcpy(product3[counter].list_product_name, product2[j].product_name);
            product3[counter].finded_product_name = NULL;
            product3[counter].shelf_number_out = input_shelf_number + 1;
            product3[counter].list_number_out = product2[j].list_number;
            product3[counter].product_number_out = product_number;
            product2[j].is_finded = -1;
        }
    }

    int c = -1;
    for(int k = 0; k <= input_stage; k++) {
        printf("Optimalizovany seznam:\n");
        for(int q = 0; q <= input_shelf_number + 1; q++) {
            for(int j = 0; j <= counter; j++) {
                if(product3[j].shelf_number_out == q && product3[j].list_number_out == k && product3[j].shelf_number_out != (input_shelf_number + 1)) {
                    c++;
                    printf(" %d. %s -> #%d %s\n", c, product3[j].list_product_name, product3[j].shelf_number_out, product3[j].finded_product_name);
                } else if(product3[j].shelf_number_out == q && product3[j].list_number_out == k && product3[j].shelf_number_out == (input_shelf_number + 1)) {
                    c++;
                    printf(" %d. %s -> N/A\n", c, product3[j].list_product_name);
                }
            }
        }
        c = -1;
    }

    free(input);
    for(int j = 0; j <= i_shop; j++) {
        free(product[j].product_name);
    }
    for(int j = 0; j <= i_list; j++) {
        free(product2[j].product_name);
    }
    for(int j = 0; j <= counter; j++) {
        free(product3[j].list_product_name);
        free(product3[j].finded_product_name);
    }
    free(product);
    free(product2);
    free(product3);
    
    return(0);
}