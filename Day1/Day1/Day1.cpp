// Day1.cpp
/*
The Elves quickly load you into a spacecraft and prepare to launch.

At the first Go / No Go poll, every Elf is Go until the Fuel Counter-Upper. They haven't determined the amount of fuel required yet.

Fuel required to launch a given module is based on its mass. Specifically, to find the fuel required for a module, take its mass, divide by three, round down, and subtract 2.

For example:

For a mass of 12, divide by 3 and round down to get 4, then subtract 2 to get 2.
For a mass of 14, dividing by 3 and rounding down still yields 4, so the fuel required is also 2.
For a mass of 1969, the fuel required is 654.
For a mass of 100756, the fuel required is 33583.
The Fuel Counter-Upper needs to know the total fuel requirement. To find it, individually calculate the fuel needed for the mass of each module (your puzzle input), then add together all the fuel values.

What is the sum of the fuel requirements for all of the modules on your spacecraft?

--- Part Two ---
During the second Go / No Go poll, the Elf in charge of the Rocket Equation Double-Checker stops the launch sequence. Apparently, you forgot to include additional fuel for the fuel you just added.

Fuel itself requires fuel just like a module - take its mass, divide by three, round down, and subtract 2. However, that fuel also requires fuel, and that fuel requires fuel, and so on. Any mass that would require negative fuel should instead be treated as if it requires zero fuel; the remaining mass, if any, is instead handled by wishing really hard, which has no mass and is outside the scope of this calculation.

So, for each module mass, calculate its fuel and add it to the total. Then, treat the fuel amount you just calculated as the input mass and repeat the process, continuing until a fuel requirement is zero or negative. For example:

A module of mass 14 requires 2 fuel. This fuel requires no further fuel (2 divided by 3 and rounded down is 0, which would call for a negative fuel), so the total fuel required is still just 2.
At first, a module of mass 1969 requires 654 fuel. Then, this fuel requires 216 more fuel (654 / 3 - 2). 216 then requires 70 more fuel, which requires 21 fuel, which requires 5 fuel, which requires no further fuel. So, the total fuel required for a module of mass 1969 is 654 + 216 + 70 + 21 + 5 = 966.
The fuel required by a module of mass 100756 and its fuel is: 33583 + 11192 + 3728 + 1240 + 411 + 135 + 43 + 12 + 2 = 50346.
What is the sum of the fuel requirements for all of the modules on your spacecraft when also taking into account the mass of the added fuel? (Calculate the fuel requirements for each module separately, then add them all up at the end.)
*/

#include <iostream>
int const input[] = {
    98541,
    129056,
    134974,
    66390,
    121382,
    94570,
    107586,
    98767,
    65101,
    56320,
    63431,
    112200,
    119262,
    142745,
    143941,
    148764,
    70301,
    149623,
    125170,
    114562,
    136701,
    76971,
    52292,
    127671,
    107547,
    77460,
    55268,
    119986,
    104257,
    82814,
    64527,
    74279,
    98542,
    54710,
    96317,
    105670,
    146248,
    134587,
    104028,
    65286,
    91788,
    106723,
    137825,
    139949,
    74403,
    106574,
    133990,
    96165,
    121316,
    94072,
    76612,
    109470,
    147556,
    113157,
    67117,
    85237,
    134232,
    94622,
    76160,
    107532,
    120637,
    51505,
    82847,
    105600,
    97719,
    113114,
    68177,
    149213,
    116125,
    145577,
    83921,
    134810,
    138804,
    90125,
    70621,
    103245,
    51584,
    93437,
    125352,
    100578,
    53497,
    112023,
    92999,
    107998,
    148030,
    101185,
    65777,
    92272,
    145846,
    81488,
    61957,
    69551,
    125625,
    146328,
    123666,
    102629,
    121996,
    94172,
    128023,
    123472
};

int CalculateFuel(int mass) {
    int fuel = (mass / 3) - 2;
    if (fuel <= 0)
        return 0;

    return fuel + CalculateFuel(fuel);
}

int main()
{
    int fuelTotal = 0;
    for (int i = 0; i < (sizeof(input) / sizeof(*input)); i++)
    {
        fuelTotal += CalculateFuel(input[i]);
    }
    printf("%d", fuelTotal);
}
