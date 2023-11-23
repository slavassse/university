#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dateToIndex(int day, int month, int year, int *idx) {
    if((((year % 4000 != 0) && (year % 100 != 0 || year % 400 == 0) && year % 4 == 0) && month == 2 && day > 29)
        ||(year < 2000)
        ||(day < 1)
        ||(month < 1 || month > 12)
        ||(((year % 4000 == 0) && (year % 100 == 0 || year % 400 != 0) && year % 4 != 0) && month == 2 && day >= 29)
        ||(year % 4 != 0 && month == 2 && day >= 29) || (year % 4000 == 0 && month == 2 && day >= 29)
        ||((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        ||((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)) { return 0; }
    if(month >= 2) { day += 31; }
    if(month >= 3) { if(((year % 4000 != 0) && (year % 100 != 0 || year % 400 == 0) && year % 4 == 0)) { day += 29; } else { day += 28; } }
    if(month >= 4) { day += 31; }
    if(month >= 5) { day += 30; }
    if(month >= 6) { day += 31; }
    if(month >= 7) { day += 30; }
    if(month >= 8) { day += 31; }
    if(month >= 9) { day += 31; }
    if(month >= 10) { day += 30; }
    if(month >= 11) { day += 31; }
    if(month >= 12) { day += 30; }
    for(* idx = 0; * idx < day; * idx += 1) {
        if(day == 31) { month++; }
    }
    printf("%d\n",day);
    if (day == * idx) { return 1; }
    else { return 0; }
}

#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;
    assert(dateToIndex( 27,  6, 196000, &idx) == 1 && idx == 178);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    assert(dateToIndex(27, 6, 196000, &idx) == 1 && idx == 178);
    assert(dateToIndex(32, 1, 2000, &idx) == 0);
    assert(dateToIndex(30, 11, 124000, &idx) == 1 && idx == 334);
    assert(dateToIndex(31, 2, 258800, &idx) == 0);
    assert(dateToIndex(31, 9, 126800, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */
