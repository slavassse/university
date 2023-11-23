#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int h, m, s, ms;
    int h2, m2, s2, ms2;
    int hc = 0, mc = 0, sc = 0;
    char q1, q2, q3, q4, q5, q6;
    printf("Zadejte cas t1:\n");
    if (scanf("  %d %c %d %c %d %c %d", &h, &q1, &m, &q2, &s, &q3, &ms) != 7 || (h > 23) || (m > 59) || (s > 59) || (ms > 999) || (q1 != ':') || (q2 != ':') || (q3 != ',') ||
    (h < 0) || (m < 0) || (sc < 0) || (ms < 0)) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    int count1 = (h * 3600000) + (m * 60000) + (s * 1000) + ms;
    if(count1 < 0) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Zadejte cas t2:\n");
    if (scanf("  %d %c %d %c %d %c %d", &h2, &q4, &m2, &q5, &s2, &q6, &ms2) != 7 || (h2 > 23) || (m2 > 59) || (s2 > 59) || (ms2 > 999) || (q4 != ':') || (q5 != ':') || (q6 != ',') ||
    (h2 < 0) || (m2 < 0) || (s2 < 0) || (ms2 < 0) ) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    int count2 = (h2 * 3600000) + (m2 * 60000) + (s2 * 1000) + ms2;
    if(count2 < 0) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    int count = count2 - count1;
    if(count1 > count2) {
            printf("Nespravny vstup.\n");
            return 0;
    }
        while(count >= 3600000) {
            count -= 3600000;
            hc++;
        }
        while(count >= 60000) {
            count -= 60000;
            mc++;
        }
        while(count >= 1000) {
            count -= 1000;
            sc++;
        }      
    if(hc >= 10) { printf("Doba: %d:%02d:%02d,%03d\n", hc, mc, sc, count); }
    if(hc < 10) { printf("Doba:  %d:%02d:%02d,%03d\n", hc, mc, sc, count); }
    return 0;
}