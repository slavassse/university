#include <stdio.h>
#include <math.h>
#define DBL_EPSILON __DBL_EPSILON__

int compare(double a, double b) {
    double c = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    double d = DBL_EPSILON * fmax(a, b);
    return c <= d;
}

int main(void) {
    double a, b, c, d = 0;
    char binary_sign, equal_sign = '=';

    printf("Zadejte rovnici:\n");
    if(scanf("%lf %c %lf %c %lf", &a, &binary_sign, &b, &equal_sign, &c) != 5 || (b == 0 && binary_sign == '/') || equal_sign != '=') {
        printf("Nespravny vstup.\n");
        return 1;
    }

    switch(binary_sign) {
        case('+'):
            d = a + b;
            break;
        case('-'): 
            d = a - b;
            break;
        case('*'):
            d = a - b;
            break;
        case('/'):
            if((a / b) > 0) {
                d = floor(a / b);
            } else {
                d = ceil(a / b);
            }
            break;    
        default: 
            printf("Nespravny vstup.\n");
            return 1;
    }

    if(compare(d, c)) {
        printf("Rovnice je spravne.\n");
    } else {
        printf("%g != %g\n", d, c);
        return 1;
    }
    
    return 0;
}