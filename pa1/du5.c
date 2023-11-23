#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DBL_EPSILON __DBL_EPSILON__

int compare(double a, double b) {
    double c = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    return c <= DBL_EPSILON * fmax(a, b) * 1000;
}
typedef struct aircrafts {
    double x;
    double y;
    char name_of_aircraft[199];
} aircraft_list;

int main(void) {
    int i = -1, input, counter = 0, min = 0, count = 0, size_of_structure = 2;    
    float distance, min_distance = 0;
    char input_aircraft[200];
    double x, y;
    aircraft_list* aircraft = (aircraft_list*)malloc(size_of_structure * sizeof(aircraft_list));

    printf("Pozice letadel:\n");
    while((input = scanf("%lf,%lf: %199s", &x, &y, input_aircraft)) != EOF) {
        if(input != 3) {
            printf("Nespravny vstup.\n");
            free(aircraft);
            return 0;
        }
        i++;
        if(i >= size_of_structure) {
            size_of_structure *= 2;
            aircraft = (aircraft_list*)realloc(aircraft, size_of_structure * sizeof (*aircraft));
        }
        aircraft[i].x = x;
        aircraft[i].y = y;
        strcpy(aircraft[i].name_of_aircraft, input_aircraft);
    }
    if(i < 2) {
        printf("Nespravny vstup.\n");
        free(aircraft);
        return 0;
    }
    for(int first_element = 0; first_element <= i; first_element++) {
        for(int loop_element = first_element + 1; loop_element <= i; loop_element++) {
            if(first_element == 0 && loop_element == 1) {
                distance = sqrt(pow(aircraft[loop_element].x - aircraft[first_element].x, 2) + pow(aircraft[loop_element].y - aircraft[first_element].y, 2));
                min_distance = distance;
                count++;
            } else {
                distance = sqrt(pow(aircraft[loop_element].x - aircraft[first_element].x, 2) + pow(aircraft[loop_element].y - aircraft[first_element].y, 2));
                if(distance < min_distance) {
                    min_distance = distance;
                    min = 1;
                    count = 0;
                }
                if(compare(distance, min_distance)) {
                    count++;
                    counter++;
                }
                if(counter == 0 && min == 1) {
                    count = 1;
                }
                counter = min = 0;
            }   
        }    
    }

    printf("Vzdalenost nejblizsich letadel: %lf\n", min_distance);
    printf("Nalezenych dvojic: %d\n", count);
    for(int first_element = 0; first_element <= i; first_element++) {
        for(int loop_element = first_element + 1; loop_element <= i; loop_element++) {
            distance = sqrt(pow(aircraft[loop_element].x - aircraft[first_element].x, 2) + pow(aircraft[loop_element].y - aircraft[first_element].y, 2));
            if(compare(distance, min_distance)) {
                printf("%s - %s\n", aircraft[first_element].name_of_aircraft, aircraft[loop_element].name_of_aircraft);
            }
        }    
    }

    free(aircraft);

    return 0;
}