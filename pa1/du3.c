#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#endif /* __PROGTEST__ */


int is_date_sunday(int year, int month, int day) {
    int day_of_the_week = (day += month < 3 ? (year--) : (year - 2), ((23 * month) / 9) + day + 4 + (year / 4) - (year / 100) + (year / 400)) % 7;
    return day_of_the_week;
}

int is_y_leap(int y)
{
    if(((y % 4 == 0) && (y % 100 != 0)) || ((y % 400 == 0) && (y % 4000 != 0))) return 1;
    else return 0;
}

int checking_dates(int y, int m, int d, int h, int i)
{
    if(    (y < 1600)
        || (m < 1 || m > 12)
        || (h < 0 || h > 23)
        || (i < 0 || i > 59)
        || (( (m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d > 30))
        || ((is_y_leap(y) == 1) && (m == 2) &&  (d > 29))
        || ((is_y_leap(y) == 0) && (m == 2) && (d > 28))
        || (d > 31 || d < 1)) {
        return 0;
    } else return 1;

}

int date_comparison( int y1, int m1, int d1, int h1, int i1,
             int y2, int m2, int d2, int h2, int i2)
{
    if(    (y2 < y1)
        || ((y1 == y2) && (m2 < m1))
        || ((y1 == y2) && (m2 == m1) && (d2 < d1))
        || ((y1 == y2) && (m2 == m1) && (d2 == d1) && (h2 < h1))
        || ((y1 == y2) && (m2 == m1) && (d2 == d1) && (h2 == h1) && (i2 < i1))) {
        return 0;
    } else return 1;
}

int bells ( int y1, int m1, int d1, int h1, int i1,
            int y2, int m2, int d2, int h2, int i2,
            long long int * b1, long long int * b2 )
{
    if(checking_dates(y1, m1, d1, h1, i1) == 0 || checking_dates(y2, m2, d2, h2, i2) == 0 || date_comparison(y1, m1, d1, h1, i1, y2, m2, d2, h2, i2) == 0) {
        return 0;
    }
    
    int d_diff, s_copy, d1_copy = d1, h1_copy = h1, h2_copy = 0, i1_copy = i1, i2_copy = 0, h_diff, i_diff = 0, bells_1 = 0, bells_2 = 0;
    
    if((is_date_sunday(y1, m1, d1) == 0 && is_date_sunday(y2, m2, d2) == 0) || ((h1 == h2 && i1 == i2) && i1 != 0)) {
        //printf("time_1 and time_2 are sunday or the hours and minutes are the same\n");
    } else if(is_date_sunday(y1, m1, d1) != 0 && is_date_sunday(y2, m2, d2) != 0) {

        if(d2 > d1) {
            h_diff = (h2 + 24) - h1;
            //printf("h_diff = %d\n", h_diff);
            if(i1 != 0) {
                h1_copy++;
                h_diff--;
            }
            for(int h_counter = 0; h_counter <= h_diff; h1_copy++, h_counter++) {
                if (h1_copy == 0 || h1_copy == 12) bells_2 += 12;
                if (h1_copy == 1 || h1_copy == 13) bells_2 += 1;
                if (h1_copy == 2 || h1_copy == 14) bells_2 += 2;
                if (h1_copy == 3 || h1_copy == 15) bells_2 += 3;
                if (h1_copy == 4 || h1_copy == 16) bells_2 += 4;
                if (h1_copy == 5 || h1_copy == 17) bells_2 += 5;
                if (h1_copy == 6 || h1_copy == 18) bells_2 += 6;
                if (h1_copy == 7 || h1_copy == 19) bells_2 += 7;
                if (h1_copy == 8 || h1_copy == 20) bells_2 += 8;
                if (h1_copy == 9 || h1_copy == 21) bells_2 += 9;
                if (h1_copy == 10 || h1_copy == 22) bells_2 += 10;
                if (h1_copy == 11 || h1_copy == 23) bells_2 += 11;
                if (h1_copy == 24) {
                    bells_2 += 12;
                    h1_copy = 0;
                    d1_copy++;
                }
            }
            h1_copy--;
        } else if(d1 == d2) {
            h_diff = h2- h1;
            //printf("h_diff = %d\n", h_diff);
            if(i1 != 0) {
                h1_copy++;
                h_diff--;
            }
            for(int h_counter = 0; h_counter <= h_diff; h1_copy++, h_counter++) {
                if (h1_copy == 0 || h1_copy == 12) bells_2 += 12;
                if (h1_copy == 1 || h1_copy == 13) bells_2 += 1;
                if (h1_copy == 2 || h1_copy == 14) bells_2 += 2;
                if (h1_copy == 3 || h1_copy == 15) bells_2 += 3;
                if (h1_copy == 4 || h1_copy == 16) bells_2 += 4;
                if (h1_copy == 5 || h1_copy == 17) bells_2 += 5;
                if (h1_copy == 6 || h1_copy == 18) bells_2 += 6;
                if (h1_copy == 7 || h1_copy == 19) bells_2 += 7;
                if (h1_copy == 8 || h1_copy == 20) bells_2 += 8;
                if (h1_copy == 9 || h1_copy == 21) bells_2 += 9;
                if (h1_copy == 10 || h1_copy == 22) bells_2 += 10;
                if (h1_copy == 11 || h1_copy == 23) bells_2 += 11;
                if (h1_copy == 24) {
                    bells_2 += 12;
                    h1_copy = 0;
                    d1_copy++;
                }
            }
            h1_copy--;
        } else if(d1 > d2) {
            h_diff = h2- h1;
            //printf("h_diff = %d\n", h_diff);
            if(i1 != 0) {
                h1_copy++;
                h_diff--;
            }
            for(int h_counter = 0; h_counter <= h_diff; h1_copy++, h_counter++) {
                if (h1_copy == 0 || h1_copy == 12) bells_2 += 12;
                if (h1_copy == 1 || h1_copy == 13) bells_2 += 1;
                if (h1_copy == 2 || h1_copy == 14) bells_2 += 2;
                if (h1_copy == 3 || h1_copy == 15) bells_2 += 3;
                if (h1_copy == 4 || h1_copy == 16) bells_2 += 4;
                if (h1_copy == 5 || h1_copy == 17) bells_2 += 5;
                if (h1_copy == 6 || h1_copy == 18) bells_2 += 6;
                if (h1_copy == 7 || h1_copy == 19) bells_2 += 7;
                if (h1_copy == 8 || h1_copy == 20) bells_2 += 8;
                if (h1_copy == 9 || h1_copy == 21) bells_2 += 9;
                if (h1_copy == 10 || h1_copy == 22) bells_2 += 10;
                if (h1_copy == 11 || h1_copy == 23) bells_2 += 11;
                if (h1_copy == 24) {
                    bells_2 += 12;
                    h1_copy = 0;
                    d1_copy++;
                }
            }
            h1_copy--;
        }

        if(d1 < d2) {
            i_diff = ((h2 * 60) + i2 + 1440) - ((h1 * 60) + i1);
        } else if(d1 == d2) {
            i_diff = ((h2 * 60) + i2) - ((h1 * 60) + i1);
        }
        if(i1_copy > 0 && i1_copy < 15) {
            i1_copy = 15;
            i_diff -= (15 - i1);
        } else if(i1_copy > 15 && i1_copy < 30) {
            i1_copy = 30;
            i_diff -= (30 - i1); 
        } else if(i1_copy > 30 && i1_copy < 45) {
            i1_copy = 45;
            i_diff -= (45 - i1); 
        } else if(i1_copy > 45 && i1_copy < 60) {
            i1_copy = 0;
            i_diff -= (60 - i1);
        }
        if(d2 < d1) {
            int i_diff2 = i_diff;
            i_diff = fabs(i_diff2);
        }
        //printf("i_diff = %d\n", i_diff);
        for(int i_counter = 0; i_counter <= i_diff; i1_copy += 15, i_counter += 15) {
            if(i1_copy == 0) bells_1 += 4;
            if(i1_copy == 15) bells_1 += 1;
            if(i1_copy == 30) bells_1 += 2;
            if(i1_copy == 45) bells_1 += 3;
            if(i1_copy == 60) {
                bells_1 += 4;
                i1_copy = 0;
            }
        }
        i1_copy -= 15;

        //printf("Fitted date (time_1 and time_2 are not sunday): %d:%d:%d\nbells_1 = %d, bells_2 = %d\n", d1_copy, h1_copy, i1_copy, bells_1, bells_2);
    } else if(is_date_sunday(y1, m1, d1) != 0 && is_date_sunday(y2, m2, d2) == 0) {
        h_diff = 23 - h1;
        //printf("h_diff = %d\n", h_diff);
        if(i1 != 0) {
            h1_copy++;
            h_diff--;
        }
        for(int h_counter = 0; h_counter <= h_diff; h1_copy++, h_counter++) {
            if (h1_copy == 0 || h1_copy == 12) bells_2 += 12;
            if (h1_copy == 1 || h1_copy == 13) bells_2 += 1;
            if (h1_copy == 2 || h1_copy == 14) bells_2 += 2;
            if (h1_copy == 3 || h1_copy == 15) bells_2 += 3;
            if (h1_copy == 4 || h1_copy == 16) bells_2 += 4;
            if (h1_copy == 5 || h1_copy == 17) bells_2 += 5;
            if (h1_copy == 6 || h1_copy == 18) bells_2 += 6;
            if (h1_copy == 7 || h1_copy == 19) bells_2 += 7;
            if (h1_copy == 8 || h1_copy == 20) bells_2 += 8;
            if (h1_copy == 9 || h1_copy == 21) bells_2 += 9;
            if (h1_copy == 10 || h1_copy == 22) bells_2 += 10;
            if (h1_copy == 11 || h1_copy == 23) bells_2 += 11;
            if (h1_copy == 24) {
                    bells_2 += 12;
                    h1_copy = 0;
                    d1_copy++;
                }
        }
        h1_copy--;
        
        i_diff = 1425 - ((h1 * 60) + i1);
        if(i1_copy > 0 && i1_copy < 15) {
            i1_copy = 15;
            i_diff -= (15 - i1);
        } else if(i1_copy > 15 && i1_copy < 30) {
            i1_copy = 30;
            i_diff -= (30 - i1); 
        } else if(i1_copy > 30 && i1_copy < 45) {
            i1_copy = 45;
            i_diff -= (45 - i1); 
        } else if(i1_copy > 45 && i1_copy < 60) {
            i1_copy = 0;
            i_diff -= (60 - i1);
        }
        if(d2 < d1) {
            int i_diff2 = i_diff;
            i_diff = fabs(i_diff2);
        }
        //printf("i_diff = %d\n", i_diff);
        for(int i_counter = 0; i_counter <= i_diff; i1_copy += 15, i_counter += 15) {
            if(i1_copy == 0) bells_1 += 4;
            if(i1_copy == 15) bells_1 += 1;
            if(i1_copy == 30) bells_1 += 2;
            if(i1_copy == 45) bells_1 += 3;
            if(i1_copy == 60) {
                bells_1 += 4;
                i1_copy = 0;
            }
        }
        i1_copy -= 15;

        d1_copy++;

        //printf("Fitted date (time_2 is sunday): %d:%d\nbells_1 = %d, bells_2 = %d\n", h1_copy, i1_copy, bells_1, bells_2);
    } else if(is_date_sunday(y1, m1, d1) == 0 && is_date_sunday(y2, m2, d2) != 0) {
        h_diff = h2;
        //printf("h_diff = %d\n", h_diff);
        for(int h_counter = 0; h_counter <= h_diff; h2_copy++, h_counter++) {
            if (h2_copy == 0 || h2_copy == 12) bells_2 += 12;
            if (h2_copy == 1 || h2_copy == 13) bells_2 += 1;
            if (h2_copy == 2 || h2_copy == 14) bells_2 += 2;
            if (h2_copy == 3 || h2_copy == 15) bells_2 += 3;
            if (h2_copy == 4 || h2_copy == 16) bells_2 += 4;
            if (h2_copy == 5 || h2_copy == 17) bells_2 += 5;
            if (h2_copy == 6 || h2_copy == 18) bells_2 += 6;
            if (h2_copy == 7 || h2_copy == 19) bells_2 += 7;
            if (h2_copy == 8 || h2_copy == 20) bells_2 += 8;
            if (h2_copy == 9 || h2_copy == 21) bells_2 += 9;
            if (h2_copy == 10 || h2_copy == 22) bells_2 += 10;
            if (h2_copy == 11 || h2_copy == 23) bells_2 += 11;
            if (h1_copy == 24) {
                    bells_2 += 12;
                    h1_copy = 0;
                    d1_copy++;
                }
        }
        h2_copy--;

        i_diff = (h2 * 60) + i2;
        //printf("i_diff = %d\n", i_diff);
        for(int i_counter = 0; i_counter <= i_diff; i2_copy += 15, i_counter += 15) {
            if(i2_copy == 0) bells_1 += 4;
            if(i2_copy == 15) bells_1 += 1;
            if(i2_copy == 30) bells_1 += 2;
            if(i2_copy == 45) bells_1 += 3;
            if(i2_copy == 60) {
                bells_1 += 4;
                i2_copy = 0;
            }
        }
        i2_copy -= 15;

        //printf("Fitted date (time_1 is sunday): %d:%d\nbells_1 = %d, bells_2 = %d\n", h2_copy, i2_copy, bells_1, bells_2);
    }

    int d1_counter = 0, d2_counter = 0, y1_copy = y1, m1_copy = m1;

    for(s_copy = 1600; s_copy < y1; s_copy++) {
        if(is_y_leap(s_copy) == 1) d1_counter += 366;
        if(is_y_leap(s_copy) == 0) d1_counter += 365;
    }
    for(s_copy = 1600; s_copy < y2; s_copy++) {
        if(is_y_leap(s_copy) == 1) d2_counter += 366;
        if(is_y_leap(s_copy) == 0) d2_counter += 365;
    }

    for(s_copy = 1; s_copy < m1; s_copy++) {
        if(s_copy == 1 || s_copy == 3 || s_copy == 5 || s_copy == 7 || s_copy == 8 || s_copy == 10 || s_copy == 12) d1_counter += 31;
        if(s_copy == 4 || s_copy == 6 || s_copy == 9 || s_copy == 11) d1_counter += 30;
        if(s_copy == 2 && is_y_leap(y1) == 1) d1_counter += 29;
        if(s_copy == 2 && is_y_leap(y1) == 0) d1_counter += 28;
    }
    for(s_copy = 1; s_copy < m2; s_copy++) {
        if(s_copy == 1 || s_copy == 3 || s_copy == 5 || s_copy == 7 || s_copy == 8 || s_copy == 10 || s_copy == 12) d2_counter += 31;
        if(s_copy == 4 || s_copy == 6 || s_copy == 9 || s_copy == 11) d2_counter += 30;
        if(s_copy == 2 && is_y_leap(y1) == 1) d2_counter += 29;
        if(s_copy == 2 && is_y_leap(y1) == 0) d2_counter += 28;
    }

    d1_counter += d1_copy;
    d2_counter += d2;

    d_diff = d2_counter - d1_counter;
    //printf("d_diff = %d\n", d_diff);

    for(int counter = 0; counter < d_diff; d1_copy++, counter++) {
        if(is_date_sunday(y1_copy, m1_copy, d1_copy) != 0) {
            bells_2 += 156;
            bells_1 += 240;
        } 
        if(d1_copy == 31 && ((m1_copy == 1) || (m1_copy == 3) || (m1_copy == 5) || (m1_copy == 7) || (m1_copy == 8) || (m1_copy == 10) || (m1_copy == 12))) {
            d1_copy = 0;
            m1_copy++;
            if(m1_copy == 13) {
                y1_copy++;
                m1_copy = 1;
            }
        }
        if(d1_copy == 30 && ((m1_copy == 4) || (m1_copy == 6) || (m1_copy == 9) || (m1_copy == 11))) {
            d1_copy = 0;
            m1_copy++;
        }
        if(d1_copy == 29 && (m1_copy == 2) && is_y_leap(y1_copy) == 1) {
            d1_copy = 0;
            m1_copy++;
        }
        if(d1_copy == 28 && (m1_copy == 2) && is_y_leap(y1_copy) == 0) {
            d1_copy = 0;
            m1_copy++;
        }
        //printf("bells: bells_1 = %d, bells_2 = %d, day of the week %d:%d:%d = %d\n", bells_1, bells_2, y1_copy, m1_copy, d1_copy, is_date_sunday(y1_copy, m1_copy, d1_copy));
    }

    //printf("%d:%d:%d:%d:%d\n%d:%d:%d:%d:%d\n", y1_copy, m1_copy, d1_copy, h1_copy, i1_copy, y2, m2, d2, h2, i2);

    //printf("Final bells: bells_1 = %d, bells_2 = %d\n", bells_1, bells_2);

    if((is_y_leap(y1) == 0 && is_y_leap(y2) == 1)) {
        bells_1 += 240;
        bells_2 += 156;
    }


    for(* b1 = 0; * b1 < bells_1; * b1 += bells_1);
    for(* b2 = 0; * b2 < bells_2; * b2 += bells_2);
    if ((bells_1 == * b1) && (bells_2 == * b2)) {
        return 1;
    }
    else {
        return 0;
    }
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int b1, b2;

  assert ( bells ( 2022, 10,  1, 13, 15,
                   2022, 10,  1, 18, 45, &b1, &b2 ) == 1
           && b1 == 56
           && b2 == 20 );
  assert ( bells ( 2022, 10,  3, 13, 15,
                   2022, 10,  4, 11, 20, &b1, &b2 ) == 1
           && b1 == 221
           && b2 == 143 );
  assert ( bells ( 2022, 10,  1, 13, 15,
                   2022, 10,  2, 11, 20, &b1, &b2 ) == 1
           && b1 == 106
           && b2 == 65 );
  assert ( bells ( 2022, 10,  2, 13, 15,
                   2022, 10,  3, 11, 20, &b1, &b2 ) == 1
           && b1 == 115
           && b2 == 78 );
  assert ( bells ( 2022, 10,  1, 13, 15,
                   2022, 10,  3, 11, 20, &b1, &b2 ) == 1
           && b1 == 221
           && b2 == 143 );
  assert ( bells ( 2022,  1,  1, 13, 15,
                   2022, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 56861
           && b2 == 36959 );
  assert ( bells ( 2019,  1,  1, 13, 15,
                   2019, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 57101
           && b2 == 37115 );
  assert ( bells ( 2024,  1,  1, 13, 15,
                   2024, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 57341
           && b2 == 37271 );
  assert ( bells ( 1900,  1,  1, 13, 15,
                   1900, 10,  5, 11, 20, &b1, &b2 ) == 1
           && b1 == 57101
           && b2 == 37115 );
  assert ( bells ( 2022, 10,  1,  0,  0,
                   2022, 10,  1, 12,  0, &b1, &b2 ) == 1
           && b1 == 124
           && b2 == 90 );
  assert ( bells ( 2022, 10,  1,  0, 15,
                   2022, 10,  1,  0, 25, &b1, &b2 ) == 1
           && b1 == 1
           && b2 == 0 );
  assert ( bells ( 2022, 10,  1, 12,  0,
                   2022, 10,  1, 12,  0, &b1, &b2 ) == 1
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2022, 11,  1, 12,  0,
                   2022, 10,  1, 12,  0, &b1, &b2 ) == 0
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2022, 10, 32, 12,  0,
                   2022, 11, 10, 12,  0, &b1, &b2 ) == 0
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2100,  2, 29, 12,  0,
                   2100,  2, 29, 12,  0, &b1, &b2 ) == 0
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2000,  2, 29, 12,  0,
                   2000,  2, 29, 12,  0, &b1, &b2 ) == 1
           && b1 == 4
           && b2 == 12 );
  assert ( bells ( 2004,  2, 29, 12,  0,
                   2004,  2, 29, 12,  0, &b1, &b2 ) == 1
           && b1 == 0
           && b2 == 0 );
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */