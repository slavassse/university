#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100000000

int main(void) {
    int number, input_number, i = 0, sum = 0, start = 0, end = 0, number_of_parts = 0;
    int sequence[2000] = {0};
    int *parts;
    parts = (int*)malloc(MAX_ARRAY_SIZE * sizeof(int));

    for(int i = 0; i < MAX_ARRAY_SIZE; i++) {
        parts[i] = 0;
    }

    printf("Posloupnost:\n");
    while((input_number = scanf(" %d", &number)) != EOF) {
        if(input_number != 1 || i == 2000) {
            printf("Nespravny vstup.\n");
            free(parts);
            return 1;
        }
        sequence[i] = number;
        i++;
    }
    if(i < 1) {
        printf("Nespravny vstup.\n");
        free(parts);
        return 1;
    }

    for(; start < i; start++) {
        end = start + 1;
        for(; end < i; end++) {
            for(number = start; number <= end; number++) {
                sum += sequence[number];
            }
            parts[sum]++;
            if(parts[sum] >= 2) {
                number_of_parts += (parts[sum] - 1);
            } 
            sum = 0;
        }
        
    }

    printf("Pocet dvojic: %d\n", number_of_parts);
    free(parts);

    return 0;
}