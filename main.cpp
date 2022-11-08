#include <stdio.h>

int day_of_week(int day, int month, int year)
{
    int cent;

    /* adjust months so February is the last one */
    month -= 2;
    if (month < 1)
    {
        month += 12;
        --year;
    }
    /* split by century */
    cent = year / 100;
    year %= 100;
    return ((26 * month - 2) / 10 + day + year + year / 4 + cent / 4 + 5 * cent) % 7;
}


int main()
{
    int sundcount = 0;
    int w;
    for(int year = 1901; year < 2001; year++){
        for(int month = 1; month <= 12; month++){
            w = day_of_week(1, month, year);
            if(w == 0)
                sundcount++;
        }
    }

    printf("%d\n", sundcount);

    return 0;
}