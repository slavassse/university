#include <stdio.h>
#include <ctype.h>
#define MAX_ARRAYSIZE (26)

int main(void) {
    int max = 0;
    double number_of_parties, number_of_miners;
    double number_of_votes[MAX_ARRAYSIZE];
    double number_of_seats[MAX_ARRAYSIZE]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double number_of_votes_final[MAX_ARRAYSIZE];
    char party_name[MAX_ARRAYSIZE];
    char possible_party_names[MAX_ARRAYSIZE]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char full_input_check;

    printf("Pocet stran:\n");
    if(scanf(" %lf",&number_of_parties) !=1 || number_of_parties < 2 || number_of_parties > 26) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Strany a pocet hlasu:\n");
    for(int i = 0; i < number_of_parties; i++) {
        if(scanf(" %c",&party_name[i]) != 1 || !(party_name[i] >= 'A' && party_name[i] <= 'Z') || isdigit(party_name[i]) == 1) {
            printf("Nespravny vstup.\n");
            return 1;
        }

        full_input_check = getchar();

        if(full_input_check == 0x0A) {
            if(isdigit(party_name[i]) == 0) printf("Pocet horniku:\n");
            printf("Nespravny vstup.\n");
            return 1;
        }

        if(scanf(" %lf",&number_of_votes[i]) !=1 || number_of_votes[i] <= 0) {
            printf("Nespravny vstup.\n");
            return 1;
        }

        for(int y = 0; y < MAX_ARRAYSIZE; y++) {
            if((party_name[i] == possible_party_names[y]) && (y >= number_of_parties)) {
                printf("Nespravny vstup.\n");
                return 1;
            }
        }

        for(int y = 0; y < i; y++) {
            if((party_name[i] == party_name[y]) && (y != i)) {
                printf("Nespravny vstup.\n");
                return 1;
            }
        }

    }

    printf("Pocet horniku:\n");
    if(scanf(" %lf",&number_of_miners) != 1 || number_of_miners == 1 || number_of_miners <= 0) {
        if(number_of_miners == 1) printf("Nelze rozdelit.\n");
        else printf("Nespravny vstup.\n");
        return 1;
    }

    for(int y = 0; y < number_of_miners; y++) {
        for(int i = 0; i < number_of_parties; i++) {
            if(number_of_seats[i] == 0) {
                number_of_votes_final[i] = number_of_votes[i] / 1.42;
            } else if(number_of_seats[i] > 0) {
                number_of_votes_final[i] = number_of_votes[i] / (number_of_seats[i] + 1);
            }
        }

        for(int i = 0; i < number_of_parties; i++) {
            if (number_of_votes_final[i] > number_of_votes_final[max]) {
                max = i;
            }
        }
        
        number_of_seats[max] += 1;
    }

    printf("Pridelene pocty:\n");
    for(int y = 0; y < number_of_parties; y++) {
        for(int i = 0; i < number_of_parties; i++) {
            if(possible_party_names[y] == party_name[i]) printf("%c: %g\n", party_name[i], number_of_seats[i]);
        }
        
    }

    return 0;
}