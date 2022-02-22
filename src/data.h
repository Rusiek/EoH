#ifndef DATA_H
#define DATA_H
#include "clock.h"
#define size_t unsigned long long

namespace data {
    constexpr size_t range_age          =   10'000'000;
    constexpr size_t max_age            =   120;
    constexpr size_t death_prob[120]    =   {55635, 3869, 2360, 1800, 1455, 1320, 1230, 1150, 1075, 995, 965, 1040, 1305, 1795, 2470, 3205, 3959, 4770, 5625, 6495, 7420, 8330, 9090, 9645, 10055, 10415, 10820, 11270, 11810, 12415, 13045, 13660, 14295, 14920, 15565, 16270, 17025, 17770, 18475, 19195, 20024685, 91635, 99030, 106270, 113160, 120100, 127985, 137135, 147190, 158240, 170650, 185130, 201895, 220705, 241714, 265400, 293285, 325245, 359980, 397340, 438635, 486535, 542035, 604240, 673560, 751180, 838499, 936739, 1046790, 1169185, 1304130, 1451655, 1611644, 1783890, 1968065, 2163775, 2359515, 2551780, 2736815, 2910725, 3069590, 3237200, 3414035, 3600615, 3797470, 4005185, 4224350, 4455610, 4699635, 4957140, 5228865, 5515610, 5818215, 6137555, 6474565, 6830240, 7205615, 7594220, 7973930, 8372630, 8791260};

    const Clock preg_time(9);
    const Clock after_preg_time(6, 2);

    constexpr size_t hair_poss      =   2;
    constexpr size_t eye_poss       =   3;
    constexpr size_t tounge_poss    =   2;

    constexpr char hair_color[2]    =   {'D', 'L'};         // Dark     / Light
    constexpr char eye_color[3]     =   {'B', 'G', 'S'};    // Brown    / Green     / Sky
    constexpr char tounge_roll[2]   =   {'Y', 'N'};         // Yes      / No
}

#endif