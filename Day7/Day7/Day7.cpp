#include <iostream>
#include <algorithm>
#include <queue>
#include "Program.h"

using namespace std;
using namespace IntCode;

const long long int programTemplate[] = { 3,8,1001,8,10,8,105,1,0,0,21,34,55,68,93,106,187,268,349,430,99999,3,9,102,5,9,9,1001,9,2,9,4,9,99,3,9,1001,9,5,9,102,2,9,9,101,2,9,9,102,2,9,9,4,9,99,3,9,101,2,9,9,102,4,9,9,4,9,99,3,9,101,4,9,9,102,3,9,9,1001,9,2,9,102,4,9,9,1001,9,2,9,4,9,99,3,9,101,2,9,9,1002,9,5,9,4,9,99,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,99,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,99,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,99,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,99 };
int minPhase = 5;
int maxPhase = 9;


int runAmplification(int phases[5])
{
    queue<long long int> ioqueues[5];
    Program<QueueIOHandler>* programs[5];

    // Initialize
    for (int i = 0; i < 5; i++)
    {
        ioqueues[i].push(phases[i]);
        programs[i] = new Program<QueueIOHandler>(programTemplate, sizeof(programTemplate), new QueueIOHandler(&(ioqueues[i]), &(ioqueues[(i + 1) % 5])));
    }

    ioqueues[0].push(0);
    int i = 0;
    while(programs[i]->get_state() != RUN_STATE::HALT)
    {
        programs[i]->Run();
        i = (i + 1) % 5;
    }

    if (i != 0) throw "Ended on wrong amplifier";

    return programs[4]->get_IOHandler()->outputs->front();
}


int main()
{
    int maxSignal = 0;

    for (int a = minPhase; a <= maxPhase; a++)
    {
        for (int b = minPhase; b <= maxPhase; b++)
        {
            if (b == a) continue;
            for (int c = minPhase; c <= maxPhase; c++)
            {
                if (c == b || c == a) continue;
                for (int d = minPhase; d <= maxPhase; d++)
                {
                    if (d == c || d == b || d == a) continue;
                    for (int e = minPhase; e <= maxPhase; e++)
                    {
                        if (e == d || e == c || e == b || e == a) continue;
                        int phases[5] = { a,b,c,d,e };
                        int output = runAmplification(phases);
                        if (output > maxSignal)
                            maxSignal = output;
                    }
                }
            }
        }
    }

    std::cout << maxSignal;
}

