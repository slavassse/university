#include <stdio.h> 
#include <math.h> 
int main(){ 
 printf("Zadejte kreditni urok [%%]:\n"); 
 double kredit; 
    if (scanf(" %lf",&kredit) !=1 || kredit<=0){ 
     printf ("Nespravny vstup.\n"); 
     return 1; 
    } 
    printf("Zadejte debetni urok [%%]:\n"); 
    double debet; 
    if (scanf(" %lf",&debet) !=1  || debet<=0){ 
     printf ("Nespravny vstup.\n"); 
     return 1; 
    } 
    int den0 = 0; 
    int den1 = 0; 
    int castka; 
    double sum=0; 
    int i = 0; 
    printf("Zadejte transakce:\n"); 
        while(castka !=0){ 
        if(scanf("%d, %d", &den1, &castka)!=2) {
            printf("Nespravny vstup.\n");
            return 1;
        } 
        if (den0>den1){ 
            printf ("Nespravny vstup.\n"); 
        return 1; 
        } 
            for (i = 0; i!=(den1-den0); i++ ) { 
                if (sum<0){ 
                sum += (debet/100)*sum; 
                sum = ceil(sum * 100) / 100; 
                } 
                else if (sum>0){ 
                sum += (kredit/100)*sum; 
                sum = floor(sum * 100) / 100; 
                } 
            } 
        sum += castka; 
        den0 = den1; 
        } 
         
        printf("Zustatek: %.2lf\n", sum); 
 return 0; 
}