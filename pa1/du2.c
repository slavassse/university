#include <stdio.h>
#include <math.h>
#define DBL_EPSILON __DBL_EPSILON__

int compare(double a, double b) {
    double c = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    return c <= DBL_EPSILON * fmax(a, b) * 1000;;
}

int main(void) {
    double x1, x2, x3, y1, y2, y3;
    printf("Bod A:\n");
    if(scanf(" %lf %lf", &x1, &y1) != 2) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Bod B:\n");
    if(scanf(" %lf %lf", &x2, &y2) != 2) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Bod C:\n");
    if(scanf(" %lf %lf", &x3, &y3) != 2) {
        printf("Nespravny vstup.\n");
        return 0;
    }

    if(((x1 == x2) && (y1 == y2)) || ((x2 == x3) && (y2 == y3)) || ((x1 == x3) && (y1 == y3)) || ((x1 == x2) && (x2 == x3) && (x1 == x3) && (y1 == y2) && (y2 == y3) && (y1 == y3))) {
        printf("Nektere body splyvaji.\n");
        return 0;
    }

    if(compare((x3 - x1) * (y2 - y1), (y3 - y1) * (x2 - x1))) {
        printf("Body lezi na jedne primce.\n");
        if(((x2 >= x1) && (y2 >= y1) && (x2 <= x3) && (y2 <= y3)) || ((x2 >= x3) && (y2 >= y3) && (x2 <= x1) && (y2 <= y1))) {
            printf("Prostredni je bod B.\n");
        } else if(((x1 >= x2) && (y1 >= y2) && (x1 <= x3) && (y1 <= y3)) || ((x1 >= x3) && (y1 >= y3) && (x1 <= x2) && (y1 <= y2))) {
            printf("Prostredni je bod A.\n");
        } else if(((x3 >= x2) && (y3 >= y2) && (x3 <= x1) && (y3 <= y1)) || ((x3 >= x1) && (y3 >= y1) && (x3 <= x2) && (y3 <= y2))) {
            printf("Prostredni je bod C.\n");
        }
    } else {
        printf("Body nelezi na jedne primce.\n");
    }

    return 0;
}