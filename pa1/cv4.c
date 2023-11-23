#include <stdio.h>
#include <math.h>

int main(void) {
    int range, range1, count1, count = 0;
    printf("Rozsah:\n");
    if(scanf("%d", &range) != 1 || (range <= 0)) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    count = (int)log10((double)(range * range)) + 1;
    for(count1 = count; count1 > 0; count1--) {
        printf(" ");
    }
    printf("|");
    for(range1 = range; range1 > 0; range1--) {
        printf("%*d", count + 1, range1);
    }
    printf("\n");
    for(count1 = count; count1 > 0; count1--) {
        printf("-");
    }
    printf("+");    
    for(int rangex = (count * range) + range; rangex > 0; rangex--) {
        printf("-");
    }
    printf("\n");
    
    for(int rangefrom0 = 1; rangefrom0 <= range; rangefrom0++) {
        printf("%*d|", count, rangefrom0);
        for(range1 = range; range1 > (rangefrom0 - 1); range1--) {
            printf("%*d", count + 1, range1 * rangefrom0);
        }
        printf("\n");
    }
    return 0;
}