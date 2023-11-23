#include <stdio.h>
#include <stdlib.h>

typedef struct TITEM 
{
    int zatez;
    int start;
    int stop;
} SEZNAM;

typedef struct TITEM2 
{
    int start;
    int stop;
} SEZNAM2;

int main(void) 
{
    int i = -1, size1 = 2, input, x, y, z;
    SEZNAM* uloha = (SEZNAM*)malloc(size1 * sizeof(SEZNAM));
    printf("Zatez:\n");
    while((input = scanf(" %d: %d..%d", &x, &y, &z)) != EOF) {
        if(input != 3) {
            printf("Nespravny vstup.\n");
            free(uloha);
            return 0;
        }
        i++;
        if(i >= size1) {
            size1 *= 2;
            uloha = (SEZNAM*)realloc(uloha, size1 * sizeof(*uloha));
        }
        uloha[i].zatez = x;
        uloha[i].start = y;
        uloha[i].stop = z;
    }

    int nejz = 0;
    for(int j = 0; j <= i; j++) {
        for(int k = 0; k <= i; k++) {
            if(uloha[j].stop > uloha[k].start && uloha[j].start < uloha[k].stop && uloha[j].stop <= uloha[k].stop && j != k) {
                if(nejz < uloha[j].zatez + uloha[k].zatez) {
                    nejz = uloha[j].zatez + uloha[k].zatez;
                }
            }
        }
    }
    
    printf("Nejvyssi zatez: %d\n", nejz);

    int vstart1 = -1, vstop1 = -1, vstart2 = -1, vstop2 = -1, ii = 0;
    for(int j = 0; j <= i; j++) {
        for(int k = j + 1; k <= i; k++) {
            if(uloha[j].stop > uloha[k].start && uloha[j].start < uloha[k].stop && uloha[j].stop <= uloha[k].stop) {
                    if(uloha[j].start >= uloha[k].start) {
                        vstart1 = uloha[j].start;
                    } else {
                        vstart1 = uloha[k].start;
                    }
                    
                    if(uloha[k].stop <= uloha[j].stop) {
                        vstop1 = uloha[k].stop;
                    } else {
                        vstop1 = uloha[j].stop;
                    }  

                    if(vstop2 == vstart1) {
                        vstart1 = vstart2;
                        vstop2 = vstop1;
                        ii++;
                    } else {
                        if(uloha[j].stop > vstart1 && uloha[j].start < vstop1 && uloha[j].stop <= vstop1 && j != k) { 
                            printf("%d..%d\n", vstart1, vstop1);
                        }
                        ii = 0;
                        if(uloha[j].start >= uloha[k].start) {
                            vstart2 = uloha[j].start;
                        } else {
                            vstart2 = uloha[k].start;
                        }
                        
                        if(uloha[k].stop <= uloha[j].stop) {
                            vstop2 = uloha[k].stop;
                        } else {
                            vstop2 = uloha[j].stop;
                        } 
                    }
                }         
            }
        }

        if(ii > 0) {
            printf("%d..%d\n", vstart1, vstop1);
        }

    return 0;
}