#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TITEM
{
    int distance;
    int height;
} points;

int main(void) 
{
    int start, input = 0, temp_distance = 0, temp_height = 0, checker = 0, i = -1, size = 2;

    points* point = (points*)malloc(size * sizeof(points)); 

    printf("Cyklotrasa:\n");

    scanf("%d", &start);

    while((input = scanf(" + %u %u", &temp_distance, &temp_height)) != EOF) {
        i++;
        if(i >= size) {
            size *= 2;
            point = (points*)realloc(point, size * sizeof(point));
        }
        if(input != 2 || (i > 0 && temp_distance < checker)) {
            printf("Nespravny vstup.\n");
            free(point);
            return 0;
        }
        checker = temp_distance;

        point[i].distance = temp_distance;
        point[i].height = temp_height;
    }   

    int max_height = 0, max_distance = 0, counter = 0;
    for(int j = 0; j <= i; j++) {
        for(int k = j + 1; k <= i; k++) {
            
            if(point[j].height >= 0 && point[k].height >= 0) {
                if(((point[j].height - point[k].height) > max_height || (fabs(point[j].distance - point[k].distance) > max_distance && (point[j].height - point[k].height) == max_height)) && (fabs(point[j].height - point[k].height) > 0)) {
                    max_distance = point[k].distance - point[j].distance;
                    max_height = fabs(point[j].height - point[k].height);
                    counter = 1;
                } else if((point[j].height - point[k].height) == max_height && fabs(point[j].distance - point[k].distance) == max_distance) {
                    counter++;
                }
            } else if(point[j].height >= 0 && point[k].height < 0) {
                if(((point[j].height - point[k].height) > max_height || ((point[j].distance + fabs(point[k].distance)) > max_distance && (point[j].height - point[k].height) == max_height)) && ((point[j].height + fabs(point[k].height)) > 0)) {
                    max_distance = point[k].distance - point[j].distance; 
                    max_height = fabs(point[j].height - point[k].height);
                    counter = 1;
                } else if((point[j].height - point[k].height) == max_height && (point[j].distance + fabs(point[k].distance)) == max_distance) {
                    counter++;
                }
            } else if(point[j].height < 0 && point[k].height < 0) {
                if(((point[j].height - point[k].height) > max_height || ((fabs(point[j].distance) + fabs(point[k].distance)) > max_distance && (point[j].height - point[k].height) == max_height)) && (fabs(point[j].height) + fabs(point[k].height)) > 0) {
                    max_distance = point[k].distance - point[j].distance; 
                    max_height = fabs(point[j].height) + fabs(point[k].height);
                    counter = 1;
                } else if((point[j].height - point[k].height) == max_height && (fabs(point[j].distance) + fabs(point[k].distance)) == max_distance) {
                    counter++;
                }
            }
        }
    }
 
    if(max_distance == 0 && max_height == 0) {
        printf("Nenalezeno.\n");
    } else {
        printf("%d km, klesani: %d m, varianty: %d\n", max_distance, max_height, counter);
        for(int j = 0; j <= i; j++) {
            for(int k = j + 1; k <= i; k++) {
                if((point[k].distance - point[j].distance) == max_distance && (fabs(point[j].height - point[k].height) == max_height || (point[j].height + fabs(point[k].height)) == max_height || (fabs(point[j].height) + fabs(point[k].height)) == max_height)) {
                    printf("+ %d (%d) -> + %d (%d)\n", point[j].distance, point[j].height, point[k].distance, point[k].height);
                }
            }
        }
    }

    free(point);

    return 0;
}