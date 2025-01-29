#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_COUNTRIES 46

// STRUCT TO STORE COUNTRY AND ITS CAPITAL
typedef struct
{
    char country[50];
    char capital[50];
} CountryCapital;

// ARRAY OF COUNTRIES AND THEIR RESPECTIVE CAPITALS
CountryCapital capitals[NUM_COUNTRIES] = {
    {"Albania", "Tirana"},
    {"Andorra", "Andorra la Vella"},
    {"Austria", "Vienna"},
    {"Belarus", "Minsk"},
    {"Belgium", "Brussels"},
    {"Bosnia and Herzegovina", "Sarajevo"},
    {"Bulgaria", "Sofia"},
    {"Croatia", "Zagreb"},
    {"Cyprus", "Nicosia"},
    {"Czech Republic", "Prague"},
    {"Denmark", "Copenhagen"},
    {"Estonia", "Tallinn"},
    {"Finland", "Helsinki"},
    {"France", "Paris"},
    {"Germany", "Berlin"},
    {"Greece", "Athens"},
    {"Hungary", "Budapest"},
    {"Iceland", "Reykjavik"},
    {"Ireland", "Dublin"},
    {"Italy", "Rome"},
    {"Kosovo", "Pristina"},
    {"Latvia", "Riga"},
    {"Liechtenstein", "Vaduz"},
    {"Lithuania", "Vilnius"},
    {"Luxembourg", "Luxembourg City"},
    {"Malta", "Valletta"},
    {"Moldova", "Chisinau"},
    {"Monaco", "Monaco"},
    {"Montenegro", "Podgorica"},
    {"Netherlands", "Amsterdam"},
    {"North Macedonia", "Skopje"},
    {"Norway", "Oslo"},
    {"Poland", "Warsaw"},
    {"Portugal", "Lisbon"},
    {"Romania", "Bucharest"},
    {"Russia", "Moscow"},
    {"San Marino", "San Marino"},
    {"Serbia", "Belgrade"},
    {"Slovakia", "Bratislava"},
    {"Slovenia", "Ljubljana"},
    {"Spain", "Madrid"},
    {"Sweden", "Stockholm"},
    {"Switzerland", "Bern"},
    {"Ukraine", "Kyiv"},
    {"United Kingdom", "London"},
    {"Vatican City", "Vatican City"}};
